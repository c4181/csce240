/******************************************************************************
 * This is a program to test 'cpplint'.
 *
 * Author/copyright: Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 14 August 2018
**/
#include "main.h"

/******************************************************************************
 * Function 'main'.
**/
// The following two lines get flagged for spaces.
int main ( )
{
// The following two lines get flagged for tabs.
	int count_of_transactions = 0; // number of lines of transactions
	int number_of_items = 0;  // number of a particular item bought

  double cost_per_item = 0.0;
  double cost_this_transaction = 0.0;  // number of items times cost per item
  double running_total_cost = 0.0;

  string item = "dummystring";

// The following line DOES NOT GET FLAGGED for incorrect variable symbol.
  int MyInteger = 14;

  cout << "Execution beginning\n";
  cout << "Reading data from standard input\n";

// The following line gets flagged for spaces.
  running_total_cost=0.0;
  cin >> count_of_transactions;
  cout << "There are " << count_of_transactions <<
          " transactions in this file." << endl;

// The following line gets flagged for spaces.
  for( int i=0;i<count_of_transactions;++i ) {
// The following lines DO NOT GET FLAGGED for indentation.
  cin >> item;
  cin >> number_of_items;
// The following line gets flagged for spaces.
  cin >> cost_per_item;  

    cost_this_transaction = number_of_items * cost_per_item;
    running_total_cost += cost_this_transaction;

// The following line gets flagged for length.
    cout << number_of_items << " " << item << " " << cost_per_item << " " << cost_this_transaction << " " << running_total_cost << endl;
// The following (blank) line gets flagged.

  }

  cout << "The total is $" << running_total_cost << "." << endl;

  cout << "Execution ending\n";

  return 0;
}  // int main( )
