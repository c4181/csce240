/****************************************************************
 * Header file for the Pullet16 interpreter.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Christopher Moyer
 * Date: 22 September 2018
**/

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::pair;
using std::string;
using std::vector;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"
#include "../../Utilities/utils.h"

#include "dabnamespace.h"

class Interpreter {
 public:
  Interpreter();
  virtual ~Interpreter();

  void DumpProgram(ofstream& out_stream);
  void PrintProgram(ofstream& out_stream);
  void ReadProgram(Scanner& infile_scanner);

 private:
  int pc_;

  string ToString();

  vector<string> memory_;

  map<string, string> code_to_mnemonic_;
  map<string, string> mnemonic_to_code_;

  string Decode(string the_ascii);
  string DecodeAddress(string the_ascii);
  void Init();
};
#endif
