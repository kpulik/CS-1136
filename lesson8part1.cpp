// a program that outputs the characters that map to the ASCII codes 32 through
// 126

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

void headerFooter() {
  for (int i = 0; i < 4; i++) {
    cout << "----+";
  }
  cout << endl;
}

void displayResults(unsigned int start, unsigned int end) {
  char ascii_value = ' ';
  int count = 0;

  headerFooter();
  for (int i = start; i <= end; i++) {
    count++;
    ascii_value = i;
    cout << ascii_value;

    if (count % 20 == 0 || i == end) {
      cout << endl;
    }
  }
  headerFooter();
}

void readUserValue() {
  unsigned int lowerValue = 0;
  unsigned int upperValue = 0;

  cout << "Enter lower and upper values" << endl;
  cin >> lowerValue;
  cin >> upperValue;

  if (((upperValue - lowerValue) <= 94) && (lowerValue <= upperValue)) {
    cout << "Characters for ASCII values between " << lowerValue << " and "
         << upperValue << endl;
    displayResults(lowerValue, upperValue);
  } else {
    cout << "Values must be in range 32 to 126 inclusive" << endl;
    readUserValue();
  }

  return;
}

int main() {
  readUserValue();
  return 0;
}
