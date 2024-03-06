// A program that uses user-inputted values to calculate speed through different
// elements

#include <iomanip>
#include <iostream>
using namespace std;

const int AIR = 1100, WATER = 4900, STEEL = 16400;

int main() {

  unsigned int menuChoice;
  double mediumSpeed, distance;

  // displaying the menu and assigning user choices to variables

  cout << "Select the medium that sound is traveling through:" << endl;
  cout << "1 Air" << endl;
  cout << "2 Water" << endl;
  cout << "3 Steel" << endl;

  cin >> menuChoice;
  if (menuChoice < 1 || menuChoice > 3) {
    cout << "The menu value is invalid. Please run the program again." << endl;
  } else {
    // gets the distance from user

    cout << "Enter distance (in feet)" << endl;
    cin >> distance;

    if (distance > 0) {
      cout << fixed << setprecision(4);

      // testing the menu choices

      switch (menuChoice) {
      case 1:
        mediumSpeed = distance / AIR;
        cout << "Air: " << distance << " ft" << endl;
        cout << "Traveled for " << mediumSpeed << " seconds" << endl;
        break;
      case 2:
        mediumSpeed = distance / WATER;
        cout << "Water: " << distance << " ft" << endl;
        cout << "Traveled for " << mediumSpeed << " seconds" << endl;
        break;
      case 3:
        mediumSpeed = distance / STEEL;
        cout << "Steel: " << distance << " ft" << endl;
        cout << "Traveled for " << mediumSpeed << " seconds" << endl;
        break;
      default:
        cout << "The menu value is invalid. Please run the program again."
             << endl;
        break;
      }
    } else {
      cout << "The distance must be greater than zero" << endl;
    }
  }

  return 0;
}
