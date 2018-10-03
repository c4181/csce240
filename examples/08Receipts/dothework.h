/****************************************************************
 * Header file for the grocery receipt program with a separate
 * class for doing the computation.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 August 2018
**/

#ifndef DOTHEWORK_H
#define DOTHEWORK_H

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#include "xact.h"

class DoTheWork {
 public:
  DoTheWork();
  virtual ~DoTheWork();

  void ProcessInput();

 private:
  int number_of_transactions_;  // number of lines of input

  double cost_this_transaction_;  // number of items times cost per item
  double running_total_cost_;

  vector<Xact> the_data_;

  void ReadData();
};
#endif
