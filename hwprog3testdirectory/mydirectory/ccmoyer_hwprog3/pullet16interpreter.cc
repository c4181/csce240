#include "pullet16interpreter.h"

/***************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456
 * Class 'Interpreter' for interpreting the Pullet16 code.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Christopher Moyer
 * Date: 28 September 2018
 *
 * This class will do the interpretation of ASCII versions of 'executable'
 * files for the Pullet16.  At the moment, for Homework 3, it simply
 * reads into memory the input and dumps a formatted version of that
 * to an output file.
 *
 * Documentation for details of the functions is done as headers for
 * the functions.
**/

/***************************************************************************
 * Constructor
**/
Interpreter::Interpreter() {
  Init();
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

  void Interpreter::Init() {
    code_to_mnemonic_.insert(pair<string, string>("000", "BAN"));
    code_to_mnemonic_.insert(pair<string, string>("001", "SUB"));
    code_to_mnemonic_.insert(pair<string, string>("010", "STC"));
    code_to_mnemonic_.insert(pair<string, string>("011", "AND"));
    code_to_mnemonic_.insert(pair<string, string>("100", "ADD"));
    code_to_mnemonic_.insert(pair<string, string>("101", "LD"));
    code_to_mnemonic_.insert(pair<string, string>("110", "BR"));
    code_to_mnemonic_.insert(pair<string, string>("1110000000000001", "RD"));
    code_to_mnemonic_.insert(pair<string, string>("1110000000000010", "STP"));
    code_to_mnemonic_.insert(pair<string, string>("1110000000000011", "WRT"));
  }

/******************************************************************************
 * Function 'Decode'.
 * This top level function decodes the ASCII of the machine code into an
 *   assembly language mnemonic plus etc.
 *
 * Note that if the machine code is just a number, the decoding will be bogus.
 *
 * Parameters:
 *   the_ascii - the ASCII to decode
 *
 * Returns:
 *   a string version of the assembly language
**/
string Interpreter::Decode(string the_ascii) {
#ifdef EBUG
  Utils::log_stream << "enter Decode" << endl;
#endif

  map<string, string>::iterator mnemonic;
  string returnvalue = "dummy string";
  string opcode = the_ascii.substr(0, 3);
  string address_type = the_ascii.substr(3, 1);

  if (opcode != "111") {
    if (code_to_mnemonic_.find(opcode) != code_to_mnemonic_.end()) {
      mnemonic = code_to_mnemonic_.find(opcode);
      returnvalue = mnemonic -> second;
    } else {
      returnvalue = "XXX";
    }
  } else if (code_to_mnemonic_.find(the_ascii) != code_to_mnemonic_.end()) {
    mnemonic = code_to_mnemonic_.find(the_ascii);
    returnvalue = mnemonic -> second;
  } else {
    returnvalue = "XXX";
  }

#ifdef EBUG
  Utils::log_stream << "leave Decode" << endl;
#endif

  return returnvalue;
}

/******************************************************************************
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
    out_stream  << memory_.at(i) << endl;
}

  for (int i=0; i < memory_.size(); ++i) {
    out_stream << Decode(memory_.at(i)) << endl;
  }

#ifdef EBUG
  Utils::log_stream << "leave DumpProgram" << endl;
#endif
}

/******************************************************************************
 * Function 'DecodeAddress'.
 * This function decodes whether it is indirect/direct addressing and prints the address.
 *
  * Parameters:
 *   the_ascii - the ASCII to decode
 *
 * Returns:
 *   a string of indirect/direct addressing and the address
**/
string Interpreter::DecodeAddress(string the_ascii) {
#ifdef EBUG
  Utils::log_stream << "enter DecodeAddress" << endl;
#endif

  string returnvalue = "dummy string";
  string opcode = the_ascii.substr(0, 3);
  string address_type = the_ascii.substr(3, 1);

  if (opcode != "111") {
    if (address_type == "1") {
      returnvalue = "*";
      returnvalue += " " + the_ascii.substr(4, the_ascii.length());
    } else {
      returnvalue = " ";
      returnvalue += " " + the_ascii.substr(4, the_ascii.length());
    }
  } else if (code_to_mnemonic_.find(the_ascii) != code_to_mnemonic_.end()) {
      if (address_type == "1") {
        returnvalue = "*";
        returnvalue += " " + the_ascii.substr(4, the_ascii.length());
      } else {
        returnvalue = " ";
        returnvalue += " " + the_ascii.substr(4, the_ascii.length());
      }
    } else {
    returnvalue = "X";
    returnvalue += " XXXXXXXXXXXX";
  }

  return returnvalue;

#ifdef EBUG
  Utils::log_stream << "leave DecodeAddress" << endl;
#endif
}
/******************************************************************************
 * Function 'GetDecimalAddress.
 * Takes the bit string address and returns the deciaml address.
 *
 * Parameters:
 *   the ascii - opcode to be conveted
**/
int Interpreter::GetDecimalAddress(string the_ascii) {
#ifdef EBUG
  Utils::log_stream << "enter GetDecimalAddress" << endl;
#endif

  const string address = the_ascii.substr(4, the_ascii.length());
  return DABnamespace::BitStringToDec(address);

#ifdef EBUG
  Utils::log_stream << "leave GetDecimalAddress" << endl;
#endif
}
/******************************************************************************
 * Function 'ReadProgram'.
 * This top level function reads the ASCII of the machine code into memory.
 *
 * Parameters:
 *   in_scanner - the scanner to read for source code
**/
void Interpreter::ReadProgram(Scanner& in_scanner) {
#ifdef EBUG
  Utils::log_stream << "enter ReadProgram" << endl;
#endif

  string next_line;

  while (in_scanner.HasNext()) {
    next_line = in_scanner.NextLine();
    memory_.push_back(next_line);
  }

#ifdef EBUG
  Utils::log_stream << "leave ReadProgram" << endl;
#endif
}

/******************************************************************************
 * Function 'PrintProgram'.
 * Prints out a formatted version of the program with the memory location,
 * opcode, mnemonic on the opcode, type of addressing, and memory address.
 *
 * Parameters:
 *   out_stream - the scanner to read for source code
**/
void Interpreter::PrintProgram(ofstream& out_stream) {
#ifdef EBUG
  Utils::log_stream << "enter PrintProgram" << endl;
#endif

  for (int i = 0; i < memory_.size(); ++i) {
    string s = "";
    string deocded_ascii = Decode(memory_.at(i));
    string address = DecodeAddress(memory_.at(i));
    int decimal_address = GetDecimalAddress(memory_.at(i));

    s = Utils::Format("MEMORY", 6);
    s += Utils::Format(i, 7);
    s += Utils::Format(memory_.at(0), 18);
    s += Utils::Format("CODE", 5);
    s += Utils::Format(" " + deocded_ascii, 5, "left");
    s += Utils::Format(address, 16);
    s += Utils::Format(decimal_address, 4);
    out_stream << s << endl;
  }

#ifdef EBUG
  Utils::log_stream << "leave PrintProgram" << endl;
#endif
}
/******************************************************************************
 * Function 'ToString'.
 *
 * This outputs in the prettyprinted string:
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

  string s = "";

  s += "PC    " + Utils::Format(pc_, 8) + "\n";

//  int twoscomplement = this->TwosComplementInteger(accum_);
//  s += "ACCUM " + Utils::Format(twoscomplement, 8)
//                + " " + DABnamespace::DecToBitString(accum_, 16)
//                + "\n\n";

  int memorysize = memory_.size();
  for (int outersub = 0; outersub < memorysize; outersub += 4) {
    s += "MEM " + Utils::Format(outersub, 4)
                + "-"
                + Utils::Format(outersub+3, 4);
    for (int innersub = outersub; innersub < outersub + 4; ++innersub) {
      if (innersub < memorysize) {
        s += " " + memory_.at(innersub);
      }
    }
    s += "\n";
  }

#ifdef EBUG
  Utils::log_stream << "leave ToString" << endl;
#endif

  return s;
}
