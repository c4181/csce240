#include "xact.h"

static const char kTag[] = "XACT: ";

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'Xact' for a single grocery receipt transaction. This class is
 * just the data payload.
 *
 * Author/copyright:  Duncan A. Buell.  All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 August 2018
**/

/******************************************************************************
 * Constructor
**/
Xact::Xact() {
}

/******************************************************************************
 * Destructor
**/
Xact::~Xact() {
}

/******************************************************************************
 * Accessors and Mutators
**/
/******************************************************************************
 * Accessor for 'cost_per_item_'.
 *
 * Returns:
 *   'cost_per_item_'
**/
double Xact::GetCostPerItem() {
  return cost_per_item_;
}
/******************************************************************************
 * Accessor for 'item_name_'.
 *
 * Returns:
 *   'item_name_'
**/
string Xact::GetItemName() {
  return item_name_;
}
/******************************************************************************
 * Accessor for 'number_of_items_'.
 *
 * Returns:
 *   the 'number_of_items_'
**/
int Xact::GetNumberOfItems() {
  return number_of_items_;
}

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'ReadData'.
 *
 * We read the distinct lines of input data. Each line is a label
 * of the item, the number bought, and the cost per item.
 *
 * THERE IS NO BULLETPROOFING OF THE INPUT DATA.
**/
void Xact::ReadData() {
//  cout << kTag << "enter ReadData" << endl;

  cin >> item_name_;
  cin >> number_of_items_;
  cin >> cost_per_item_;
//  cout << kTag << "leave ReadData" << endl;
}  // void DoTheWork::ReadData()

/******************************************************************************
 * Function 'ToString'.
 *
 * This is the usual 'ToString' that formats this data item for printing.
**/
string Xact::ToString() {
  string s = "";

//  cout << kTag << "enter ToString" << endl;

  s += Utils::Format(item_name_, 20, "left");
  s += Utils::Format(number_of_items_, 5);
  s += Utils::Format(cost_per_item_, 6, 2);

//  cout << kTag << "leave ToString" << endl;

  return s;
}  // void DoTheWork::ReadData()
