// a program that reads numbers from a file, validates them, and calculates the
// average

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

bool readInputFile(fstream &inputFile, double &fileValue);
void writeToOutputFile(ofstream &outputFile, double invalidNum);

int main() {
  // declaring the variables
  fstream inputFile;
  ofstream outputFile;
  string inputFileName = "";
  bool endOfFile = false;
  int totalValues = 0;
  int totalInvalid = 0;
  int totalValid = 0;
  double fileValue = 0;
  double sum = 0.0;
  double average = 0.0;

  cout << "Enter input file name" << endl;
  cin >> inputFileName;

  // open files
  inputFile.open(inputFileName);
  outputFile.open("invalid-values.txt");

  if (inputFile) {
    cout << "Reading from file "
         << "\"" << inputFileName << "\"" << endl;
    endOfFile = readInputFile(inputFile, fileValue);
    while (!endOfFile) {
      totalValues += 1;
      if (fileValue < 0 || fileValue > 105) {
        totalInvalid += 1;
        writeToOutputFile(outputFile, fileValue);
      } else {
        totalValid += 1;
        sum += fileValue;
      }
      endOfFile = readInputFile(inputFile, fileValue);
    }

    // print to the console
    cout << "Total values: " << totalValues << endl;
    cout << "Invalid values: " << totalInvalid << endl;
    cout << "Valid values: " << totalValid << endl;

    if (totalValid == 0) {
      cout << "An average cannot be calculated" << endl;
    } else {
      average = sum / totalValid;
      cout << "Average of valid values: " << fixed << setprecision(4) << average
           << endl;
    }

  } else {
    cout << "File "
         << "\"" << inputFileName << "\""
         << " could not be opened" << endl;
  }

  // close the files and end program
  inputFile.close();
  outputFile.close();
  return 0;
}

bool readInputFile(fstream &inputFile, double &fileValue) {
  if (inputFile >> fileValue) {
    return false;
  }
  return true;
}

void writeToOutputFile(ofstream &outputFile, double invalidNum) {
  outputFile << fixed << setprecision(5) << invalidNum << endl;

  return;
}
