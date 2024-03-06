// A program that converts seconds - inputted by the user -  to days, hours,
// minutes, and the remaining seconds

#include <iostream>
using namespace std;

int main() {

  long long int userSeconds, days, hours, minutes, seconds, remainder;

  // getting the number of seconds from the user

  cout << "Enter seconds" << endl;
  cin >> userSeconds;

  // outputting the seconds

  cout << "Total seconds: " << userSeconds << endl << endl;

  if (userSeconds <= 0) {
    cout << "Total seconds must be greater than zero" << endl;
  } else {

    // calculations

    days = userSeconds / 86400;
    remainder = userSeconds % 86400;

    hours = remainder / 3600;
    remainder = remainder % 3600;

    minutes = remainder / 60;
    remainder = remainder % 60;

    seconds = remainder;

    // outputting the values

    if (days > 0) {
      cout << days << " day(s)" << endl;
    }

    if (hours > 0) {
      cout << hours << " hour(s)" << endl;
    }

    if (minutes > 0) {
      cout << minutes << " minute(s)" << endl;
    }

    if (seconds > 0) {
      cout << seconds << " second(s)" << endl;
    }
  }

  return 0;
}
