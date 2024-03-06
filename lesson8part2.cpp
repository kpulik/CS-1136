// a program that will convert a set of temperatures from Fahrenheit to Celsius
// and Kelvin

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

void header() {
  cout << setw(18) << right << "Fahrenheit";
  cout << setw(18) << right << "Celsius";
  cout << setw(18) << right << "Kelvin";
  cout << endl;

  return;
}

double toCelsius(double fahrenheit) {
  return (fahrenheit - 32) / 1.8;
  ;
}

double toKelvin(double celcius) { return celcius + 273.15; }

void displayResults(double start, double end, double increment) {
  double currentNum = start;
  header();
  for (int i = start; currentNum <= end; i += increment) {
    cout << fixed << setprecision(4);
    cout << showpoint << setw(18) << right << currentNum;
    cout << setw(18) << right << toCelsius(currentNum);
    cout << setw(18) << right << toKelvin(toCelsius(currentNum));
    cout << endl;
    currentNum += increment;
  }

  return;
}

void readValues() {
  double startFahren = 0;
  double endFahren = 0;
  double incrementNum = 0;

  cin >> startFahren >> endFahren >> incrementNum;

  if ((startFahren <= endFahren) && (incrementNum > 0)) {
    displayResults(startFahren, endFahren, incrementNum);
  } else {
    cout << "Starting temperature must be <= ending temperature and increment "
            "must be > 0.0"
         << endl;
    readValues();
  }

  return;
}

int main() {
  readValues();
  return 0;
}
