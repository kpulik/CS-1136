// A program that calculates the amount of money in a bank using user inputted
// values

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

double futureValue();
double interestRate();
int numberYears();
double presentValue(double futureValue, double interestRate, int numberYears);
void display(double future, double rate, int years, double total);

int main() {
  double future;
  future = futureValue();
  if (future <= 0) {
    cout << "The future value must be greater than zero" << endl;
    return 0;
  }

  double rate;
  rate = interestRate();

  if (rate <= 0) {
    cout << "The annual interest rate must be greater than zero" << endl;
    return 0;
  }

  int years;
  years = numberYears();

  double total;
  total = presentValue(future, rate, years);

  if (years <= 0) {
    cout << "The number of years must be greater than zero" << endl;
    return 0;
  } else {
    display(future, rate, years, total);
  }

  return 0;
}

double futureValue() {

  double future;
  cout << "Enter future value" << endl;
  cin >> future;

  return (future);
}

double interestRate() {

  double input, rate;
  cout << "Enter annual interest rate" << endl;
  cin >> input;
  rate = input / 100;

  return (rate);
}

int numberYears() {

  int years;
  cout << "Enter number of years" << endl;
  cin >> years;

  return (years);
}

double presentValue(double futureValue, double interestRate, int numberYears) {

  double total;

  total = futureValue / (pow((1 + interestRate), numberYears));

  return (total);
}

void display(double future, double rate, int years, double total) {
  cout << fixed << setprecision(2);

  cout << "Present value: $" << total << endl;
  cout << "Future value: $" << future << endl;
  cout << "Annual interest rate: " << setprecision(3) << rate * 100 << "%"
       << endl;
  cout << "Years: " << years << endl;
}
