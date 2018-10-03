/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Example of a basic grocery receipt.
 *
 * This program reads a sequence of grocery store transactions
 * from an input file, outputs the "receipt", and runs a total.
 *
 * Author/copyright: Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 August 2018
**/
#include "main.h"  // comment this out first

/******************************************************************************
 * Function 'main'.
 *
 * We first read the number of distinct lines of input data that follow.
 * We then read each of these lines.
 * Each line is
 *   a label of the item
 *   the number of each item bought
 *   and the cost per item.
 *
 * As we read, we output the running grocery receipt and keep a running
 * total, which is then output at the end.
 *
 * We are not going to worry about formatting in this program. That will
 * come later. For now, we will be content just to output the right values.
**/
int main() {
  int count_of_transactions = 0;  // number of lines of transactions
  int number_of_items = 0;  // number of a particular item bought

  double cost_per_item = 0.0;
  double cost_this_transaction = 0.0;  // number of items times cost per item
  double running_total_cost = 0.0;

  string item = "dummystring";

  cout << "Execution beginning\n";
  cout << "Reading data from standard input\n";

  running_total_cost = 0.0;
  cin >> count_of_transactions;
  cout << "There are " << count_of_transactions <<
          " transactions in this file." << endl;

  for (int i = 0; i < count_of_transactions; ++i) {
    cin >> item;
    cin >> number_of_items;
    cin >> cost_per_item;

    cost_this_transaction = number_of_items * cost_per_item;
    running_total_cost += cost_this_transaction;

    cout << number_of_items << " " << item << " " << cost_per_item
         << " " << cost_this_transaction << " " << running_total_cost
         << endl;
  }

  cout << "The total is $" << running_total_cost << "." << endl;

  cout << "Execution ending\n";

  return 0;
}  // int main( )
