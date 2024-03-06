// a program that displays the status of an order from the fictional company
// called Acme Wholesale Copper Wire Company

#include <iomanip>
#include <iostream>
using namespace std;

bool read(int &spoolsOrdered, int &spoolsStock, double &shipAndHandle);
void display(int spoolsOrdered, int spoolsStock, double shipAndHandle);

int main() {
  int spoolsOrdered, spoolsStock;
  double shipAndHandle;
  bool valid;

  valid = read(spoolsOrdered, spoolsStock, shipAndHandle);

  if (valid) {
    display(spoolsOrdered, spoolsStock, shipAndHandle);
  }

  return 0;
}

bool read(int &spoolsOrdered, int &spoolsStock, double &shipAndHandle) {

  double shipPrice = 12.99;
  char shipTest;

  // displays the prompt, assigns the values to the variables, and tests the
  // validity

  cout << "Spools to be ordered" << endl;
  cin >> spoolsOrdered;

  if (spoolsOrdered < 1) {
    cout << "Spools order must be 1 or more" << endl;
    return false;
  }

  cout << "Spools in stock" << endl;
  cin >> spoolsStock;

  if (spoolsStock < 0) {
    cout << "Spools in stock must be 0 or more" << endl;
    return false;
  }

  cout << "Special shipping and handling (y or n)" << endl;
  cin >> shipTest;

  if (shipTest == 'y') {
    cout << "Shipping and handling amount" << endl;
    cin >> shipPrice;

    if (shipPrice < 0) {
      cout << "The spool shipping and handling charge must be 0.0 or more"
           << endl;
      return false;
    } else {
      shipAndHandle = shipPrice;
    }
  } else {
    shipAndHandle = shipPrice;
  }

  return true;
}

void display(int spoolsOrdered, int spoolsStock, double shipAndHandle) {

  int ready, backOrder;
  double subtotal, totalShip, totalCharge;

  // testing the spools order vs spools in stock

  if (spoolsOrdered > spoolsStock) {
    backOrder = spoolsOrdered - spoolsStock;
    ready = spoolsOrdered - backOrder;
  } else {
    ready = spoolsOrdered;
    backOrder = 0;
  }

  subtotal = ready * 104;
  totalShip = ready * shipAndHandle;
  totalCharge = subtotal + totalShip;

  // display order status
  cout << fixed << setprecision(2);
  cout << "Spools ready to ship: " << ready << endl;
  cout << "Spools on back-order: " << backOrder << endl;
  cout << "Subtotal ready to ship: $" << setw(10) << subtotal << endl;
  cout << "Shipping and handling:  $" << setw(10) << totalShip << endl;
  cout << "Total shipping charges: $" << setw(10) << totalCharge << endl;

  return;
}
