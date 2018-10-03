/****************************************************************
 * Header file for a single grocery receipt transaction.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 August 2018
**/

#ifndef XACT_H
#define XACT_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#include "../../Utilities/utils.h"

class Xact {
 public:
  Xact();
  virtual ~Xact();

  double GetCostPerItem();
  string GetItemName();
  int GetNumberOfItems();

  void ReadData();
  string ToString();

 private:
  int number_of_items_;
  double cost_per_item_;
  string item_name_;
};
#endif
