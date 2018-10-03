#include "main.h"

static const char kTag[] = "MAIN: ";

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Example program: basic grocery receipt, with the work of the program done
 * in a separate class.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 August 2018
 *
 * This program reads a sequence of grocery store transactions
 * from an input file, outputs the "receipt", and runs a total.
**/

/******************************************************************************
 * Function 'main'.
 *
 * We do nothing in the main except invoke a 'do_the_work' function in a class
 * of essentially the same name.
 *
**/
int main() {
  DoTheWork do_the_work;

  cout << kTag << "Execution beginning" << endl;
  cout << kTag << "Reading from standard input" << endl;

  do_the_work.ProcessInput();

  cout << kTag << "Execution ending" << endl;

  return 0;
}  // int main( )
