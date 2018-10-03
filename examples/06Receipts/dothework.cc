/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'DoTheWork' for the grocery receipt computation.
 *
 * Author/copyright: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 August 2018
 *
 * This class has nothing more than a function to read and process the data.
 * Detail document on that one function is located with the function.
**/
#include "dothework.h"

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
**/
void DoTheWork::ProcessInput() {
  int number_of_items = 0;  // number of a particular item bought
  int number_of_transactions = 0;  // number of lines of input

  double cost_per_item = 0.0;
  double cost_this_transaction = 0.0;  // number of items times cost per item
  double running_total_cost = 0.0;

  string item = "dummy_item";

  cout << "enter ProcessInput" << endl;

  running_total_cost = 0.0;
  cin >> number_of_transactions;
  for (int i = 0; i < number_of_transactions; ++i) {
    cin >> item;
    cin >> number_of_items;
    cin >> cost_per_item;

    cost_this_transaction = number_of_items * cost_per_item;
    running_total_cost += cost_this_transaction;

    cout << number_of_items << " " << item << " " << cost_per_item
         << " " << cost_this_transaction << " " << running_total_cost << endl;
  }

  cout << "The total is $" << running_total_cost << "." << endl;
  cout << "leave ProcessInput" << endl;
}  // void DoTheWork::ProcessInput()
