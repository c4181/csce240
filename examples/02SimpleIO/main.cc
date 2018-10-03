/****************************************************************
 * Second version 'hello world' program, with input and output.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by:  Jane Random Hacker
 * Date: 12 August 2018
**/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
  string name_string = "dummystring";

  cout << "What is your name? ";
  cin >> name_string;
  cout << "Hello, " << name_string << "!" << endl;

  return 0;
}
