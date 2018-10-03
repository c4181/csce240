/****************************************************************
 * This is the 'hello world' program that uses a header file.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by:  Jane Random Hacker
 * Date: 12 August 2018
 *
 * Buell's political correctness commentary:
 *   You should in your dot cpp file include ONLY the dot h
 *   file that corresponds to the dot cpp. Anything that needs
 *   to be included should be included in the dot h, so you will
 *   only have to look in one place for what gets included.
**/

#include "main.h"

int main(int argc, char *argv[]) {
  string name_string = "dummy_string";

  cout << "What is your name? ";
  cin >> name_string;
  cout << "Hello, " << name_string << "!" << endl;

#ifdef WHATEVER
  cout << "WHATEVER" << endl;
#endif

  return 0;
}
