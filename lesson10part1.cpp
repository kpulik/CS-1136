#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void displayResults(char studentChoiceAnswer[], char answerSheetArray[],
                    int studentAnswerTotal, int answerSheetTotal);
int readInputFile(char array[30], string fileName);

int main() {
  string studentFileName = "";
  string answerFileName = "";

  // arrays for the data
  char studentChoicesArray[30] = {};
  char answerSheetArray[30] = {};
  int studentAnswersTotal = 0;
  int answerSheetTotal = 0;

  // user input of the file names
  cout << "Enter student answers file name" << endl;
  cin >> studentFileName;
  // opening files
  studentAnswersTotal = readInputFile(studentChoicesArray, studentFileName);

  if (studentAnswersTotal != -1) {
    cout << "Enter correct answer file name" << endl;
    cin >> answerFileName;
    answerSheetTotal = readInputFile(answerSheetArray, answerFileName);
    if (answerSheetTotal == -1) {
      cout << "File "
           << "\"" << answerFileName << "\""
           << " could not be opened" << endl;
    } else if (studentAnswersTotal < answerSheetTotal ||
               studentAnswersTotal > answerSheetTotal) {
      cout << "The student answers file has " << studentAnswersTotal
           << " entries and the correct answers file has " << answerSheetTotal
           << " entries" << endl;
      cout << "Grading cannot be done if they are not the same" << endl;
    } else if (studentAnswersTotal == 0 && answerSheetTotal == 0) {
      cout << "The number of student answers and correct answers are both 0"
           << endl;
      cout << "No grade can be calculated" << endl;
    } else {
      displayResults(studentChoicesArray, answerSheetArray, studentAnswersTotal,
                     answerSheetTotal);
    }

  } else {
    cout << "File "
         << "\"" << studentFileName << "\""
         << " could not be opened" << endl;
  }
  return 0;
}

//***************************************************************************
//                                                                          *
//                                                                          *
//                                                                          *
//                                                                          *
//***************************************************************************
int readInputFile(char array[30], string fileName) {
  char answer = 'B';
  int index = 0;

  fstream file;
  file.open(fileName);

  if (file) {
    while (file >> answer) {
      if (index < 30) {
        array[index] = answer;
      } else {
        file.close();
        return 30;
      }
      index++;
    }
    file.close();
    return index;
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
void displayResults(char studentChoicesAnswer[], char answerSheetArray[],
                    int studentAnswerTotal, int answerSheetTotal) {
  int studentCorrectAnswerTotal = 0;

  for (int i = 0; i < studentAnswerTotal; i++) {
    if (studentChoicesAnswer[i] == answerSheetArray[i]) {
      studentCorrectAnswerTotal++;
    } else {
      cout << "Question " << i + 1 << " has incorrect answer "
           << "\'" << studentChoicesAnswer[i] << "\'"
           << ", the correct answer is "
           << "\'" << answerSheetArray[i] << "\'" << endl;
    }
  }

  double grade = (double(studentCorrectAnswerTotal) / answerSheetTotal) * 100.0;

  if (studentCorrectAnswerTotal == answerSheetTotal) {
    cout << "0 questions were missed out of " << answerSheetTotal << endl;
    cout << fixed << showpoint << setprecision(1) << "The student grade is "
         << grade << "%" << endl;
    cout << "The student passed" << endl;
  } else {
    cout << studentAnswerTotal - studentCorrectAnswerTotal
         << " questions were missed out of " << answerSheetTotal << endl;
    cout << fixed << showpoint << setprecision(1) << "The student grade is "
         << grade << "%" << endl;

    if (grade >= 70) {
      cout << "The student passed" << endl;
    } else {
      cout << "The student failed" << endl;
    }
  }

  return;
}
