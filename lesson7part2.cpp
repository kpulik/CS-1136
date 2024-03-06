// a program that calculates the future value for the previous part of lesson 7

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

void read(double &presentValue, double &interestRate, int &months);
double futureValue(double presentValue, double interestRate, int months);
void display(double fValue, double presentValue, double interestRate,
             int months);

int main() {

  double presentValue, interestRate, fValue;
  int months;

  read(presentValue, interestRate, months);

  if (presentValue < 0 || interestRate < 0 || months <= 0) {
    cout << fixed << setprecision(2);
    cout << presentValue << " " << setprecision(3) << interestRate << " "
         << setprecision(0) << months << endl;
    cout << "One or more of the above values are not greater than zero" << endl;
    return 0;
  }

  interestRate /= 100.0;

  fValue = futureValue(presentValue, interestRate, months);

  display(fValue, presentValue, interestRate, months);

  return 0;
}

void read(double &presentValue, double &interestRate, int &months) {
  cout << "Enter present value" << endl;
  cin >> presentValue;

  cout << "Enter monthly interest rate" << endl;
  cin >> interestRate;

  cout << "Enter months" << endl;
  cin >> months;

  return;
}

double futureValue(double presentValue, double interestRate, int months) {
  double fValue;

  fValue = presentValue * pow((1 + interestRate), months);

  return (fValue);
}

void display(double fValue, double presentValue, double interestRate,
             int months) {
  cout << fixed;

  cout << setw(18) << "Future Value" << setw(18) << "Present Value" << setw(18)
       << "Monthly Interest" << setw(10) << "Months" << endl;

  cout << setprecision(2) << setw(18) << fValue << setw(18) << presentValue
       << setprecision(3) << setw(18) << interestRate * 100 << setprecision(0)
       << setw(10) << months << endl;

  return;
}
