#include "pullet16interpreter.h"

/***************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456
 * Class 'Interpreter' for interpreting the Pullet16 code.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Christopher Moyer
 * Date: 19 October 2018
 *
 * This class does the interpretation of ASCII versions of 'executable'
 * files for the Pullet16.
 *
 * The 'Read' function reads an executable into memory, and then the
 * 'Interpret' function simulates execution of the Pullet16 using the
 * code loaded into the memory.
 *
 * Documentation for details of the functions is done as headers for
 * the functions.
 *
 * Notes:
 *   Notice throughout that 'GetTargetLocation' does the error checking
 *   for whether a target address is in fact out of bounds and also does
 *   the indirect lookup, so the code to interpret an instruction never
 *   needs to know whether the address is indirect or not.
**/

/***************************************************************************
 * Constructor
**/
Interpreter::Interpreter() {
}

/***************************************************************************
 * Destructor
**/
Interpreter::~Interpreter() {
}

/***************************************************************************
 * Accessors and Mutators
**/

/***************************************************************************
 * General functions.
**/

/***************************************************************************
 * Function 'DoADD'.
 * This top level function interprets the 'ADD' opcode.
 *
 * Load the contents from the 'target'.
 * Convert the 16-bit value to its 2s complement version as a 32-bit value.
 * Add, storing the result in the accumulator.
 * Arithmetic overflow causes the top bits to be lost but is not flagged
 *   as an error.  It's just the way hardware works.
**/
void Interpreter::DoADD(string addr, string target) {
#ifdef EBUG
  Utils::log_stream << "enter DoADD" << endl;
#endif

  Utils::log_stream << "EXECUTE:    OPCODE ADDR TARGET " << "ADD        "
                    << addr << " " << target << endl;

  int location = GetTargetLocation("ADD", addr, target);
  string data = memory_.at(location).GetBitPattern();

  int int_data = DABnamespace::BitStringToDec(data);
  accum_ = accum_ + int_data;

#ifdef EBUG
  Utils::log_stream << "leave DoADD" << endl;
#endif
}

/***************************************************************************
 * Function 'DoAND'.
 * This top level function interprets the 'AND' opcode.
 *
 * Load the contents from the 'target', taking indirection into account.
 * AND, storing the result in the accumulator.
**/
void Interpreter::DoAND(string addr, string target) {
#ifdef EBUG
  Utils::log_stream << "enter DoAND" << endl;
#endif
  Utils::log_stream << "EXECUTE:    OPCODE ADDR TARGET " << "AND "
                    << addr << " " << target << endl;

  string and_value;

  int location = GetTargetLocation("AND", addr, target);
  string data = memory_.at(location).GetBitPattern();

  string bin_accum = DABnamespace::DecToBitString(accum_, 16);

  for (int i = 0; i < data.length(); ++i) {
    if (data.at(i) == '1' && bin_accum.at(i) == '1') {
      and_value += "1";
    } else {
      and_value += "0";
    }
  }

  accum_ = DABnamespace::BitStringToDec(and_value);

#ifdef EBUG
  Utils::log_stream << "leave DoAND" << endl;
#endif
}

/***************************************************************************
 * Function 'DoBAN'.
 * This top level function interprets the 'BAN' opcode.
 *
 * If the accumulator value is negative, branch to the target location.
 * Otherwise, just continue on continuing on.
**/
void Interpreter::DoBAN(string addr, string target) {
#ifdef EBUG
  Utils::log_stream << "enter DoBAN" << endl;
#endif
  Utils::log_stream << "OPCODE ADDR TARGET " << "BAN " << addr << " "
                    << target << endl;

  if (accum_ < 0) {
    int location = GetTargetLocation("BR", addr, target);
    pc_ = location - 1;
  }

#ifdef EBUG
  Utils::log_stream << "leave DoBAN" << endl;
#endif
}

/***************************************************************************
 * Function 'DoBR'.
 * This top level function interprets the 'BR' opcode.
 *
 * Branch unconditionally to the target location.
**/
void Interpreter::DoBR(string addr, string target) {
#ifdef EBUG
  Utils::log_stream << "enter DoBR" << endl;
#endif
  Utils::log_stream << "OPCODE ADDR TARGET " << "BR  " << addr << " "
                    << target << endl;

  int location = GetTargetLocation("BR", addr, target);
  pc_ = location - 1;

#ifdef EBUG
  Utils::log_stream << "leave DoBR" << endl;
#endif
}

/***************************************************************************
 * Function 'DoLD'.
 * This top level function interprets the 'LD' opcode.
 *
 * Load the accumulator with the contents of the target location.
**/
void Interpreter::DoLD(string addr, string target) {
#ifdef EBUG
  Utils::log_stream << "enter DoLD" << endl;
#endif
  Utils::log_stream << "EXECUTE:    OPCODE ADDR TARGET " << "LD         "
                    << addr << " " << target << endl;

  int location = GetTargetLocation("Load", addr, target);

  string data = memory_.at(location).GetBitPattern();

  int int_data = DABnamespace::BitStringToDec(data);
  accum_ = TwosComplementInteger(int_data);

#ifdef EBUG
  Utils::log_stream << "leave DoLD" << endl;
#endif
}

/***************************************************************************
 * Function 'DoRD'.
 * This top level function interprets the 'RD' opcode.
 *
 * If there is more data:
 *   scan the next line for input
 *   convert from the hex character format input into an int value
 *   store the int value in the accumulator
 * Else:
 *   crash on read past end of file
**/
void Interpreter::DoRD(Scanner& data_scanner) {
#ifdef EBUG
  Utils::log_stream << "enter DoRD" << endl;
#endif
  Utils::log_stream << "OPCODE " << "RD  " << endl;

if(data_scanner.HasNext()) {
  string next_line = data_scanner.NextLine();
  Hex the_hex(next_line);
  accum_ = the_hex.GetValue();
}
#ifdef EBUG
  Utils::log_stream << "leave DoRD" << endl;
#endif
}

/***************************************************************************
 * Function 'DoSTC'.
 * This top level function interprets the 'STC' opcode.
 *
 * Get the target location.
 * Store the accumulator at that location.
 * Zero the accumulator.
 *
 * This assumes that 'GetTargetLocation' does the error checking for invalid
 * addresses.
**/
void Interpreter::DoSTC(string addr, string target) {
#ifdef EBUG
  Utils::log_stream << "enter DoSTC" << endl;
#endif
  Utils::log_stream << "EXECUTE:    OPCODE ADDR TARGET " << "STC        "
                    << addr << " " << target << endl;

  int location = GetTargetLocation("STC", addr, target);

  string binary = DABnamespace::DecToBitString(accum_, 16);

  OneMemoryWord new_word(binary);
  memory_.at(location) = new_word;

  accum_ = 0;

#ifdef EBUG
  Utils::log_stream << "leave DoSTC" << endl;
#endif
}

/***************************************************************************
 * Function 'DoSTP'.
 * This top level function interprets the 'STP' opcode.
 *
 * Since the function one higher up interprets the 'kPCForStop' value as
 * the indicator to stop execution, all we need to do here is assign that
 * constant to the program counter.
**/
void Interpreter::DoSTP() {
#ifdef EBUG
  Utils::log_stream << "enter DoSTP" << endl;
#endif
  Utils::log_stream << "OPCODE " << "STP " << endl;

  pc_ = kPCForStop;

#ifdef EBUG
  Utils::log_stream << "leave DoSTP" << endl;
#endif
}

/***************************************************************************
 * Function 'DoSUB'.
 * This top level function interprets the 'SUB' opcode.
**/
void Interpreter::DoSUB(string addr, string target) {
#ifdef EBUG
  Utils::log_stream << "enter DoSUB" << endl;
#endif
  Utils::log_stream << "EXECUTE:    OPCODE ADDR TARGET " << "SUB        "
                    << addr << " " << target << endl;
  int location = GetTargetLocation("SUB", addr, target);
  string data = memory_.at(location).GetBitPattern();

  int int_data = DABnamespace::BitStringToDec(data);
  accum_ = accum_ - int_data;

#ifdef EBUG
  Utils::log_stream << "leave DoSUB" << endl;
#endif
}

/***************************************************************************
 * Function 'DoWRT'.
 * This top level function interprets the 'WRT' opcode.
 *
 * Convert the 16-bit accumulator to a 32-bit 2s complement value.
 * Write that value to standard output.
 *
 * Note that we actually write more than just the value itself so we can do
 * better tracing. This could/should be fixed in a final version of this code.
**/
void Interpreter::DoWRT(ofstream& out_stream) {
#ifdef EBUG
  Utils::log_stream << "enter DoWRT" << endl;
#endif
  Utils::log_stream << "EXECUTE:    OPCODE             " << "WRT" << endl;

  out_stream << TwosComplementInteger(accum_) << endl;

#ifdef EBUG
  Utils::log_stream << "leave DoWRT" << endl;
#endif
}

/***************************************************************************
 * Function 'DumpProgram'.
 * This top level function dumps the ASCII of the machine code from memory.
 *
 * Parameters:
 *   out_stream - the scanner to read for source code
**/
void Interpreter::DumpProgram(ofstream& out_stream) {
#ifdef EBUG
  Utils::log_stream << "enter DumpProgram" << endl;
#endif

  for (int i = 0; i < memory_.size(); ++i) {
    out_stream << memory_.at(i).ToString() << endl;
  }

#ifdef EBUG
  Utils::log_stream << "leave DumpProgram" << endl;
#endif
}

/***************************************************************************
 * Function 'Execute'.
 * This top level function executes the code.
 *
 * Execution is basically a switch statement based on the opcode value.
 *
 * Before executing an instruction, this function to checks how many 
 * instructions have been executed. This counter will crash the 
 * program at 100.
 *
 * Branch statements decrease the pc_ by 1 causing the next cycle to be on
 * the correct value
 *
 * Parameters:
 *   this_word - the instance of 'OneMemoryWord' to be executed.
 *   data_scanner - the 'Scanner', needed for the 'RD' instruction
 *   out_stream - the output stream , needed for the 'WRT' instruction
**/
void Interpreter::Execute(OneMemoryWord this_word, Scanner& data_scanner,
                          ofstream& out_stream) {
#ifdef EBUG
  Utils::log_stream << "enter Execute" << endl;
#endif


  if (instructions_executed_ < 100) {
    ++instructions_executed_;
  } else {
    exit(1);
  }

  if (this_word.GetMnemonicBits() == "000") {
    DoBAN(this_word.GetAddressBits(), this_word.GetIndirectFlag());
  } else if (this_word.GetMnemonicBits() == "001") {
      DoSUB(this_word.GetAddressBits(), this_word.GetIndirectFlag());
  } else if (this_word.GetMnemonicBits() == "010") {
      DoSTC(this_word.GetAddressBits(), this_word.GetIndirectFlag());
  } else if (this_word.GetMnemonicBits() == "011") {
      DoAND(this_word.GetAddressBits(), this_word.GetIndirectFlag());
  } else if (this_word.GetMnemonicBits() == "100") {
      DoADD(this_word.GetAddressBits(), this_word.GetIndirectFlag());
  } else if (this_word.GetMnemonicBits() == "101") {
      DoLD(this_word.GetAddressBits(), this_word.GetIndirectFlag());
  } else if (this_word.GetMnemonicBits() == "110") {
      DoBR(this_word.GetAddressBits(), this_word.GetIndirectFlag());
  } else if (this_word.GetMnemonicBits() == "111") {
    if (this_word.GetLastThree() == "001") {
      DoRD(data_scanner);
    } else if (this_word.GetLastThree() == "010") {
        DoSTP();
    } else if (this_word.GetLastThree() == "011") {
        DoWRT(out_stream);
    }
  }
#ifdef EBUG
  Utils::log_stream << "leave Execute" << endl << endl;
#endif
}

/***************************************************************************
 * Function 'FlagAddressOutOfBounds'.
 * Check to see if an address is between 0 and 'kMaxMemory' inclusive and
 * die with an error if this isn't the case.
 *
 * Parameter:
 *   address - the address to check for out of bounds
**/
void Interpreter::FlagAddressOutOfBounds(int address) {
#ifdef EBUG
  Utils::log_stream << "enter FlagAddressOutOfBounds" << endl;
#endif

  if (address >= kMaxMemory) {
    exit(1);
  }
#ifdef EBUG
  Utils::log_stream << "leave FlagAddressOutOfBounds" << endl;
#endif
}

/***************************************************************************
 * Function 'GetTargetLocation'.
 * Get the target location, perhaps through indirect addressing.
 *
 * Note that this function crashes the program if the target location is out
 * of bounds for this simulated computer.
 *
 * Parameter:
 *   label - the label for our tracing output
 *   address - is this indirect or not?
 *   target - the target to look up
**/
int Interpreter::GetTargetLocation(string label, string address,
                                   string target) {
#ifdef EBUG
  Utils::log_stream << "enter GetTargetLocation" << endl;
#endif

  int location = DABnamespace::BitStringToDec(address);

  if (target == "0") {
    FlagAddressOutOfBounds(location);
    return location;
  } else {
    location = DABnamespace::BitStringToDec(
               memory_.at(location).GetAddressBits());
    FlagAddressOutOfBounds(location);
    return location;
  }

#ifdef EBUG
  Utils::log_stream << "leave GetTargetLocation" << endl;
#endif

  return location;
}

/***************************************************************************
 * Function 'Interpret'.
 * This top level function interprets the code.
 *
 * Note that errors in execution will result in the program being terminated
 * from functions other than this one.
 *
 * We run a loop until we either hit the bogus PC value for the STP or we
 * encounter an error, which can include having the PC go past 4095.
 * So the interpreter runs a logically infinite loop:
 *
 * while true (execution should stop with a 'STP' instruction)
 *   decode the instruction pointed to by the PC
 *   execute the instruction
 *   check for invalid PC or infinite loop
**/
void Interpreter::Interpret(Scanner& data_scanner, ofstream& out_stream) {
#ifdef EBUG
  Utils::log_stream << "enter Interpret" << endl;
#endif

  pc_ = 0;
  instructions_executed_ = 0;

  while (pc_ < kMaxMemory) {
    Execute(memory_.at(pc_), data_scanner, out_stream);
    pc_++;
  }
#ifdef EBUG
  Utils::log_stream << "leave Interpret" << endl;
#endif
}

/***************************************************************************
 * Function 'ReadProgram'.
 * This top level function reads the ASCII of the machine code, one line
 * at a time, uses the input to create an instance of 'OneMemoryWord', and
 * stores that instance into memory.
 *
 * Parameters:
 *   in_scanner - the scanner to read for source code
**/
void Interpreter::ReadProgram(Scanner& in_scanner) {
#ifdef EBUG
  Utils::log_stream << "enter ReadProgram" << endl;
#endif

  accum_ = 0;
  pc_ = 0;

  // Read the lines of the ASCII version of the executable and put the
  // ASCII into a 'vector' of 'OneMemoryWord' instances.
  int linesub = 0;
  while (in_scanner.HasNext()) {
    string line = in_scanner.NextLine();
    OneMemoryWord one_word = OneMemoryWord(line);
    memory_.push_back(one_word);
    ++linesub;
    ++pc_;
    Utils::log_stream << "READ " << linesub << " " << pc_ << " "
                      << line << endl;
  }  // while (in_scanner.HasNext()) {

  Utils::log_stream << this->ToString() << endl;

#ifdef EBUG
  Utils::log_stream << "leave ReadProgram" << endl;
#endif
}

/***************************************************************************
 * Function 'ToString'.
 *
 * This outputs a prettyprinted string:
 *   PC, the program counter
 *   ACC, the accumulator, as an integer and as a bitstring
 *   a dump of memory from 0 through the max memory for this program
 *
 * Returns:
 *   the prettyprint string for printing
**/
string Interpreter::ToString() {
#ifdef EBUG
  Utils::log_stream << "enter ToString" << endl;
#endif

  string stars40 = "********* ********* ********* ********* ";
  string sss = "\n" + stars40 + stars40 + "\n";
  sss += "MACHINE IS NOW\n";

  sss += "PC    " + Utils::Format(pc_, 8) + "\n";

  int twoscomplement = this->TwosComplementInteger(accum_);
  sss += "ACCUM " + Utils::Format(twoscomplement, 8)
                  + " " + DABnamespace::DecToBitString(accum_, 16)
                  + "\n\n";

  int memorysize = memory_.size();
  for (int outersub = 0; outersub < memorysize; outersub += 4) {
    sss += "MEM " + Utils::Format(outersub, 4)
                + "-"
                + Utils::Format(outersub+3, 4);
    for (int innersub = outersub; innersub < outersub + 4; ++innersub) {
      if (innersub < memorysize) {
        sss += " " + memory_.at(innersub).GetBitPattern();
      }
    }
    sss += "\n";
  }
  sss += "\n" + stars40 + stars40;

#ifdef EBUG
  Utils::log_stream << "leave ToString" << endl;
#endif

  return sss;
}

/***************************************************************************
 * Function 'TwosComplementInteger'.
 *
 * This converts a 16 bit integer into the plus or minus 15 bit integer
 * that is the integer of the 2s complement bit pattern.
 *
 * Parameter:
 *   what - the integer value to convert to the integer that is the 2s compl
 *
 * Returns:
 *   the converted value
**/
int Interpreter::TwosComplementInteger(int what) {
#ifdef EBUG
  Utils::log_stream << "enter TwosComplementInteger" << endl;
#endif

  int twoscomplement = (what > 32768) ? what - 65536 : what;

#ifdef EBUG
  Utils::log_stream << "leave TwosComplementInteger" << endl;
#endif

  return twoscomplement;
}
