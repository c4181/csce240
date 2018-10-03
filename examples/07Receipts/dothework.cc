#include "dothework.h"
/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class for doing grocery receipts.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 August 2018
 *
 * Detail documentation for the one function is located with the function.
**/

/******************************************************************************
 * Constructor
**/
DoTheWork::DoTheWork() {
}

/******************************************************************************
 * Destructor
**/
DoTheWork::~DoTheWork() {
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'ProcessInput'.
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
 *
 * NOTE THE DIFFERENCE BETWEEN THIS PROGRAM AND THE PREVIOUS ONE.
 * This program has the 'numberOfTransactions' and 'runningTotalCost'
 * as variables in the class. It is perhaps the case that thes two values
 * could be needed elsewhere. The individual lines of input are less likeley
 * to be needed outside this class.
 *
**/
void DoTheWork::ProcessInput() {
  int number_of_items = 0;  // number of a particular item bought

  double cost_per_item = 0.0;
  double cost_this_transaction = 0.0;  // number of items times cost per item

  string item = "dummy_item";

  cout << "enter ProcessInput" << endl;

  running_total_cost_ = 0.0;

  cin >> number_of_transactions_;
  for (int i = 0; i < number_of_transactions_; ++i) {
    cin >> item;
    cin >> number_of_items;
    cin >> cost_per_item;

    cost_this_transaction = number_of_items * cost_per_item;
    running_total_cost_ += cost_this_transaction;

    cout << number_of_items << " " << item << " " << cost_per_item
         << " " << cost_this_transaction << " "
         << running_total_cost_ << endl;
  }

  cout << "The total is $" << running_total_cost_ << "." << endl;
  cout << "leave ProcessInput" << endl;
}  // void DoTheWork::ProcessInput()
