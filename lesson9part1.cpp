// a program that will be reading sales information from a file and writing out
// a bar chart for each of the stores

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

bool readInputFile(ifstream &inputFile, unsigned int &storeNumber,
                   long long int &storeData);
void writeToOutputFile(ofstream &outputFile, unsigned &storeNumber,
                       long long int &storeData);

int main() {
  // create the input file
  ifstream inputFile;
  ofstream outputFile;

  string inputFileName = "";
  bool endOfFile = false;

  // get user input
  cout << "Enter input file name" << endl;
  cin >> inputFileName;

  // assign the file path
  inputFile.open(inputFileName);
  outputFile.open("saleschart.txt");

  // variables to hold data
  unsigned storeNumber;
  long long int storeData;

  if (outputFile) {
    outputFile << "SALES BAR CHART" << endl;
    outputFile << "(Each * equals 5,000 dollars)" << endl;
  }

  if (inputFile) {
    // the file opened successfully
    while (!endOfFile) {

      // end of the file
      endOfFile = readInputFile(inputFile, storeNumber, storeData);

      // processing the value
      if (!endOfFile) {
        writeToOutputFile(outputFile, storeNumber, storeData);
      }
    }
  } else {
    cout << "File "
         << "\"" << inputFileName << "\""
         << " could not be opened" << endl;
  }

  // close files and end the program
  inputFile.close();
  outputFile.close();
  return 0;
}

/**
 *
 * @param inputFile
 * @param storeNumber
 * @param storeData
 * @return
 */
bool readInputFile(ifstream &inputFile, unsigned int &storeNumber,
                   long long int &storeData) {

  if (inputFile >> storeNumber >> storeData) {
    // this executes only if the read worked
    if (storeNumber < 1 || storeNumber > 99) {
      cout << "The store number " << storeNumber << " is not valid" << endl;
    }

    if (storeData < 0) {
      cout << "The sales value for store " << storeNumber << " is negative"
           << endl;
    }

    return false;
  }

  return true;
}

/**
 *
 * @param outputFile
 * @param storeNumber
 * @param storeData
 */
void writeToOutputFile(ofstream &outputFile, unsigned &storeNumber,
                       long long int &storeData) {
  if (!(storeNumber < 1 || storeNumber > 99 || storeData < 0)) {
    outputFile << "Store " << setw(2) << storeNumber << ": ";
    long long int numOfStars = storeData / 5000;

    for (int i = 0; i < numOfStars; i++) {
      outputFile << "*";
    }
    outputFile << endl;
  }
}
