// a program that determines if a magic sqaure is valid

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

const int MAX_SIZE = 21;

int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName);
void displaySquare(int square[MAX_SIZE][MAX_SIZE], int size);
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size);

int main() {
  // creating a 2 dimensionsal array
  int square[MAX_SIZE][MAX_SIZE];

  string inputFileName;

  // getting input from the user
  cout << "Enter input file name";
  cin >> inputFileName;

  int size = readSquare(square, inputFileName);
  displaySquare(square, size);
  bool b = validateSquare(square, size);
  if (b) {
    cout << "Valid magic square" << endl;
  } else {
    cout << "Invalid magic square" << endl;
  }

  return 0;
}
int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName) {
  // defining the input stream for the data file
  ifstream dataIn;
  int size;
  // opeing the input file
  dataIn.open(inputFileName.c_str());
  // checking if the file name is valid
  if (dataIn.fail()) {
    cout << "" << endl;
    cout << "File \"" << inputFileName << "\" could not be opened" << endl;
    exit(0);
  } else {
    dataIn >> size;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        dataIn >> square[i][j];
      }
    }
    // closing the intput file
    dataIn.close();
  }
  return size;
}
void displaySquare(int square[MAX_SIZE][MAX_SIZE], int size) {
  cout << "" << endl;
  cout << "Magic square" << endl;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << square[i][j] << "\t";
    }
    cout << endl;
  }
}

// this function will check if the square is a magic square
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size) {

  int n = 1;
  int flag = 0;

  int val = size * (size * size + 1) / 2;
  /* this block of nested for-loops will check
   * whether the square has the numbers
   * that fall in between the range
   */
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (square[i][j] < 1 && square[i][j] > val)
        return false;
    }
  }

  /* this block of nested for-loops will check
   * if the square contains the unique numbers
   * that fall in the range
   */
  for (int i = 0; i < size * size; i++) {
    flag = 0;
    for (int j = 0; j < size; j++) {
      for (int k = 0; k < size; k++) {
        if (square[j][k] == n) {
          flag = 1;
        }
      }
    }
    if (flag == 0) {
      return false;
    } else {
      n++;
    }
  }

  // creating the arrays
  int sumDiag[2], sumCol = 0, sumRow = 0;
  // Creating array dynamically
  int *rowSum = new int[size];
  int *colSum = new int[size];

  // calculating the sum of each row in the array
  for (int row = 0; row < size; row++) {
    sumRow = 0;
    for (int col = 0; col < size; col++) {
      sumRow += square[row][col];
      rowSum[row] = sumRow;
    }
  }

  // calculating the sum of each column in the array
  for (int col = 0; col < size; col++) {
    sumCol = 0;
    for (int row = 0; row < size; row++) {
      sumCol += square[row][col];
      colSum[col] = sumCol;
    }
  }
  sumDiag[0] = 0;
  // calculating the sum of Diagonal 0
  for (int row = 0; row < size; row++) {
    sumDiag[0] += square[row][row];
  }

  sumDiag[1] = 0;
  // calculating the sum of Diagonal 1
  for (int row = 0; row < size; row++) {
    sumDiag[1] += square[row][size - 1 - row];
  }

  /* checking whether sum of elements in each row, column,
   * and diagonal are equal
   * If yes, The square array is a Magic Square
   * if not, The square array is not a Magic Square
   */
  bool boolean = true;
  int sum = rowSum[0];
  for (int i = 1; i < size; i++) {
    boolean = boolean && (sum == rowSum[i]);
  }
  for (int i = 0; i < size; i++) {
    boolean = boolean && (sum == colSum[i]);
  }
  for (int i = 0; i < 2; i++) {
    boolean = boolean && (sum == sumDiag[i]);
  }

  delete[] rowSum;
  delete[] colSum;

  if (boolean) {
    return true;
  } else {
    return false;
  }
}
