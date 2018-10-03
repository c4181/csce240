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

  string returnvalue = "placeHolder";
  returnvalue = "place_holder";

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

#ifdef EBUG
  Utils::log_stream << "leave DumpProgram" << endl;
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
