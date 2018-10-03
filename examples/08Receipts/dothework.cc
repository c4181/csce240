#include "dothework.h"

static const char kTag[] = "DOTHEWORK: ";

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'DoTheWork' for the grocery receipt computation.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 August 2018
 *
 * This class has nothing more than a function to read and process the data.
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
 * We read the input data into a 'vector' of 'Xact' records.
 * We then process the 'vector' to print the detail, compute a
 * running total, and print the total.
**/
void DoTheWork::ProcessInput() {
  cout << kTag << "enter ProcessInput" << endl;

  // Read the data into the 'vector' named 'the_data_'.
  this->ReadData();

  // Now process the 'vector'.
  // Loop through the entries, compute cost per transaction, and total
  // into the running total.
  running_total_cost_ = 0.0;
  for (int i = 0; i < number_of_transactions_; ++i) {
    Xact local_xact = the_data_.at(i);
    cost_this_transaction_ = local_xact.GetNumberOfItems()
                                  * local_xact.GetCostPerItem();
    running_total_cost_ += cost_this_transaction_;

    cout << kTag << local_xact.GetNumberOfItems() << " "
         << local_xact.GetItemName() << " " << local_xact.GetCostPerItem()
         << " " << cost_this_transaction_ << " " << running_total_cost_
         << endl;
  }

  // And print the total.
  cout << kTag << "The total is $" << running_total_cost_ << "." << endl;

  cout << kTag << "leave ProcessInput" << endl;
}  // void DoTheWork::ProcessInput()

/******************************************************************************
 * Function 'ReadData'.
 * We read from stdin the input data into a 'vector' of 'Xact' named 'the_data_'.
 * This is simple.
 * Get the number of input transactions, then run a loop to create an
 * instance of 'Xact' and let that instance read itself from the input.
 *
 * THERE IS NO BULLETPROOFING OF THE INPUT.
**/
void DoTheWork::ReadData() {
  cout << kTag << "enter ReadData" << endl;

  cin >> number_of_transactions_;
  for (int i = 0; i < number_of_transactions_; ++i) {
    Xact local_xact = Xact();
    local_xact.ReadData();
    the_data_.push_back(local_xact);
  }

  cout << kTag << "leave ReadData" << endl;
}  // void DoTheWork::ReadData()
