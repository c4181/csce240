/****************************************************************
 * Code file for 'DoTheWork' for the example using classes.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by:  Jane Random Hacker
 * Date: 12 August 2018
**/
#include "dothework.h"

/****************************************************************
 * Constructor.
**/
DoTheWork::DoTheWork() {
  this->Init();
}

/****************************************************************
 * Destructor.
**/
DoTheWork::~DoTheWork() {
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function for initializing the class.
 *
 * Note that Google says don't actually put real stuff in the
 * constructor.
**/
void DoTheWork::Init() {
  cout << "What is your name? ";
  cin >> name_string_;
}

/****************************************************************
 * Usual 'ToString' function.
 *
 * Returns: The 'string' version of the class.
 *          In this case, this is 'Hello, NAME!'
**/
string DoTheWork::ToString() {
  string return_value;

  return_value = "Hello, " + name_string_ + "!";

  return return_value;
}
