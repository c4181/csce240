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
using std::cin;
using std::cout;
using std::endl;
using std::string;

class DoTheWork {
 public:
  DoTheWork();
  virtual ~DoTheWork();

  void ProcessInput();

 private:
};
#endif  // DOTHEWORK_H
