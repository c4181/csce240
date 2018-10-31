/****************************************************************
 * Header file for the 'Hex' class to contain one hex operand.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Christopher Moyer
 * Date: 19 October 2018
**/

#ifndef HEX_H
#define HEX_H

#include <iostream>
#include <string>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

// #include "../../Utilities/scanner.h"
// #include "../../Utilities/scanline.h"
#include "../../Utilities/utils.h"

#include "dabnamespace.h"

class Hex {
 public:
  Hex();
  explicit Hex(string hexoperand);
  virtual ~Hex();

  string GetErrorMessages() const;
  int GetValue() const;
  string GetText() const;
  bool HasAnError() const;
  bool IsNegative() const;
  bool IsNotNull() const;
  bool IsNull() const;
  string ToString() const;

 private:
  bool is_invalid_;
  bool is_negative_;
  bool is_null_;
  int value_;
  string error_messages_;
  string text_;

  unordered_set<char> valid_hex_digits = {'0', '1', '2', '3', '4', '5', '6',
                                          '7', '8', '9', 'A', 'B', 'C', 'D',
                                          'E', 'F'};
  void Init(string hexoperand);
  void ParseHexOperand();
};
#endif
