// A program that reads in the number of seconds and then calculates how far
// sound can travel in the specified medium in that many seconds.

#include <iomanip>
#include <iostream>
using namespace std;

const double CARBON_D = 258, AIR = 331.5, HELIUM = 972, HYDROGEN = 1270;

int main() {

  unsigned int menuChoice;
  double seconds, mediumSpeed;

  // displaying the menu

  cout << "Select the medium that sound is traveling through:" << endl;
  cout << "1 Carbon Dioxide" << endl;
  cout << "2 Air" << endl;
  cout << "3 Helium" << endl;
  cout << "4 Hydrogen" << endl;
  cin >> menuChoice;

  if (menuChoice < 1 || menuChoice > 4) {
    cout << "The menu value is invalid. Please run the program again." << endl;
  } else {
    // getting the seconds from the user

    cout << "Enter time (in seconds)" << endl;
    cin >> seconds;

    if (seconds >= 0 && seconds <= 30) {
      cout << fixed << setprecision(3);

      // testing the menu values

      switch (menuChoice) {
      case 1:
        mediumSpeed = seconds * CARBON_D;
        cout << "Carbon Dioxide: " << seconds << " seconds" << endl;
        cout << setprecision(4) << "Traveled " << mediumSpeed << " meters"
             << endl;
        break;
      case 2:
        mediumSpeed = seconds * AIR;
        cout << "Air: " << seconds << " seconds" << endl;
        cout << setprecision(4) << "Traveled " << mediumSpeed << " meters"
             << endl;
        break;
      case 3:
        mediumSpeed = seconds * HELIUM;
        cout << "Helium: " << seconds << " seconds" << endl;
        cout << setprecision(4) << "Traveled " << mediumSpeed << " meters"
             << endl;
        break;
      case 4:
        mediumSpeed = seconds * HYDROGEN;
        cout << "Hydrogen: " << seconds << " seconds" << endl;
        cout << setprecision(4) << "Traveled " << mediumSpeed << " meters"
             << endl;
        break;
      default:
        cout << "The menu value is invalid. Please run the program again."
             << endl;
        break;
      }
    } else {
      cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
    }
  }

  return 0;
}
