#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MAX_COLUMNS = 5;

// read the input file and populate the array
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName);

// for the array
double average(double values[][MAX_COLUMNS], int numberRows);

// for a specified column (column)
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows);

// for each row
void smallestRowValue(double values[][MAX_COLUMNS], int numberRows);

int main() {
  const int MAX_ROWS = 30;
  string inputFileName = "";
  double grades[MAX_ROWS][MAX_COLUMNS];

  cout << "Enter input file name" << endl;
  cin >> inputFileName;

  int actualRows = readFile(grades, MAX_ROWS, inputFileName);

  // a switch case for next step
  switch (actualRows) {
  case -1:
    cout << "File "
         << "\"" << inputFileName << "\""
         << " could not be opened" << endl;
    break;
  case 0:
    cout << "The input file "
         << "\"" << inputFileName << "\""
         << " did not contain any data" << endl;
    break;
  default:
    // the process
    cout << "Processing " << actualRows << " rows, and " << MAX_COLUMNS
         << " columns" << endl;

    // the average
    cout << fixed << setprecision(2);
    cout << "Average for all values is " << average(grades, actualRows) << endl;

    for (int i = 0; i < MAX_COLUMNS; i++) {
      cout << "Average for column " << i << " is "
           << columnAverage(grades, i, actualRows) << endl;
    }

    // the smallest row value
    smallestRowValue(grades, actualRows);
    break;
  }

  return 0;
}

//***************************************************************************
//                                                                          *
//                                                                          *
//                                                                          *
//                                                                          *
//***************************************************************************
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName) {
  fstream file;
  file.open(inputFileName);

  double value = 0.0;
  int rowsInFile = 0;
  int numColumn = 0;
  bool endOfFile = false;

  if (file) {
    for (int row = 0; row < maxRows; row++) {
      for (int col = 0; col < MAX_COLUMNS; col++) {
        if (file >> value) {
          values[row][col] = value;
        } else {
          endOfFile = true;
          break;
        }
        numColumn = col;
      }

      if (endOfFile) {
        rowsInFile = row;
        break;
      }

      rowsInFile++;
    }

    if (rowsInFile < maxRows) {
      return rowsInFile;
    } else if (rowsInFile == maxRows) {
      return maxRows;
    } else if (rowsInFile == 0 && numColumn < 5) {
      return 0;
    }
  }

  file.close();
  return -1;
}

//***************************************************************************
//                                                                          *
//                                                                          *
//                                                                          *
//                                                                          *
//***************************************************************************
double average(double values[][MAX_COLUMNS], int numberRows) {
  double sum = 0;
  int totalValues = numberRows * MAX_COLUMNS;

  for (int row = 0; row < numberRows; row++) {
    for (int col = 0; col < MAX_COLUMNS; col++) {
      sum += values[row][col];
    }
  }
  double avg = sum / totalValues;

  return avg;
}

//***************************************************************************
//                                                                          *
//                                                                          *
//                                                                          *
//                                                                          *
//***************************************************************************
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows) {
  double sum = 0;
  int totalValues = numberRows;

  for (int row = 0; row < numberRows; row++) {
    sum += values[row][column];
  }

  double avg = sum / totalValues;

  return avg;
}

//***************************************************************************
//                                                                          *
//                                                                          *
//                                                                          *
//                                                                          *
//***************************************************************************
void smallestRowValue(double values[][MAX_COLUMNS], int numberRows) {
  double smallestValue = values[0][0];

  for (int row = 0; row < numberRows; row++) {
    smallestValue = values[row][0];
    for (int col = 0; col < MAX_COLUMNS; col++) {
      if (smallestValue > values[row][col]) {
        smallestValue = values[row][col];
      }
    }
    cout << "Smallest value for row " << row << " is " << smallestValue << endl;
  }
}
