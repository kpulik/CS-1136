// A program that will calculate different distances from user inputted values

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

double readSeconds();
double calculateEarthDistance(double seconds);
double calculateMoonDistance(double seconds);
void displaysResults(double seconds, double earthDistance, double moonDistance);

int main() {

  double seconds;
  seconds = readSeconds();

  double earthDistance;
  earthDistance = calculateEarthDistance(seconds);

  double moonDistance;
  moonDistance = calculateMoonDistance(seconds);

  displaysResults(seconds, earthDistance, moonDistance);

  return 0;
}

double readSeconds() {

  double time;

  // get the value of time from the user

  cout << "Enter the time (in seconds)" << endl;
  cin >> time;

  if (time < 0) {
    cout << "The time must be zero or more" << endl;
    exit(EXIT_SUCCESS);
  }
  return (time);
}

double calculateEarthDistance(double seconds) {

  double earthDistance;

  earthDistance = 0.5 * 9.8 * pow(seconds, 2);

  return (earthDistance);
}

double calculateMoonDistance(double seconds) {

  double moonDistance;

  moonDistance = 0.5 * 1.6 * pow(seconds, 2);

  return (moonDistance);
}

void displaysResults(double seconds, double earthDistance,
                     double moonDistance) {
  cout << fixed << setprecision(4);

  cout << "The object traveled " << earthDistance << " meters in "
       << setprecision(2) << seconds << " seconds on Earth" << endl;
  cout << "The object traveled " << setprecision(4) << moonDistance
       << " meters in " << setprecision(2) << seconds << " seconds on the Moon"
       << endl;
  return;
}
