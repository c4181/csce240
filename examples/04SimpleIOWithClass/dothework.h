/****************************************************************
 * Header for the 'DoTheWork' class.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
 *
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
/****************************************************************
 * Constructors and destructors for the class.
**/
  DoTheWork();
  virtual ~DoTheWork();

/****************************************************************
 * General functions.
**/
  string ToString();

 private:
/****************************************************************
 * Variables.
**/
  string name_string_;

  void Init();
};
#endif  // DOTHEWORK_H
