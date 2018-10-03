#include "main.h"
/****************************************************************
 * Main program for Homework 2.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Christopher Moyer
 * Date: 4 September 2018
 *
 * This program will read 10 pairs of 'double' numbers (hard
 * coded as 10) from standard input into a 'vector'.
 * The pairs are taken as (x, y) coordinates in the plane.
 * The program will compute the minimum distance between any
 * two pairs and output the minimum distance as well as the
 * subscript numbers that produce the minimum.
 *
 * We do this by brute force.  We run a double loop and compute
 * the distance, saving the subscripts of the pairs with the
 * current min distance.
 **/

static const int number_of_pairs = 10;

double euclidean(pair<double, double> pair1,
                 pair<double, double> pair2) {
  double distance;
  distance = sqrt(pow(pair1.first - pair2.first, 2) +
                  pow(pair1.second - pair2.second, 2));
  return distance;
}


int main() {
  vector<pair<double, double>> points;
  pair<pair<double,double>, pair<double,double>> closest_pair;
  double closest_distance;

  // Reads a file from standard input for 10 pairs of doubles
  for (int i = 0; i < number_of_pairs; ++i) {
    double temp_x;
    double temp_y;
    pair<double, double> temp_pair;

    cin >> temp_x;
    cin >> temp_y;

    temp_pair = make_pair(temp_x, temp_y);

    points.push_back(temp_pair);
  }

  cout << "Printing Pairs" << endl;
  for (int i = 0; i < points.size(); ++i) {
      cout << points.at(i).first << "," << points.at(i).second << endl;
    }

 cout << "Finding Closest Pair" << endl;
 //Initial test to comapre against
 closest_distance = euclidean(points.at(0), points.at(1));

 for(int i=0; i<points.size(); ++i) {
   for(int j=0; j<points.size(); ++j) {
     if(i != j && euclidean(points.at(i), points.at(j)) < closest_distance) {
        closest_pair = make_pair(points.at(i), points.at(j));
     }
   }
   closest_distance = euclidean(closest_pair.first, closest_pair.second);
 }

 cout << "Closest Pair: " << closest_pair.first.first << "," << closest_pair.first.second <<
 " and " << closest_pair.second.first << "," << closest_pair.second.second << endl;

cout << "Distance: " << closest_distance << endl;

   return 0;
 }
