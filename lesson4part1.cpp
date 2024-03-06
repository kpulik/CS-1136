// A program that uses user input of mass and converts the weight on Earth, Moon
// and on Venus

#include <iomanip>
#include <iostream>
using namespace std;

const double earthAccel = 9.81;
const double moonAccel = 1.62;
const double venusAccel = 8.87;

int main() {

  double mass, earthWeight, moonWeight, venusWeight;

  // getting the mass from the user

  cout << "Enter the mass in kg\n";
  cin >> mass;

  // calculations

  earthWeight = mass * earthAccel;
  moonWeight = mass * moonAccel;
  venusWeight = mass * venusAccel;

  if (mass <= 0) {
    cout << fixed << showpoint << setprecision(4);
    cout << "The mass is " << mass << " kg" << endl;
    cout << "The mass must be greater than zero" << endl;

  } else {
    // outputting the values

    cout << fixed << showpoint << setprecision(4);
    cout << "The mass is " << mass << " kg" << endl;
    cout << setw(8) << left << "Location" << setw(14) << right << "Weight (N)"
         << endl;
    cout << setw(8) << left << "Earth" << setw(14) << right << earthWeight
         << endl;
    cout << setw(8) << left << "Moon" << setw(14) << right << moonWeight
         << endl;
    cout << setw(8) << left << "Venus" << setw(14) << right << venusWeight
         << endl;

    if (earthWeight < 5) {
      cout << "The object is light" << endl;
    } else if (earthWeight >= 1500) {
      cout << "The object is heavy" << endl;
    }
  }

  return 0;
}
