#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 10; ; // a global constant

int main()
{
  double tests[SIZE]; // array of double

  char inFileName[20]; // array of char (C-string) for input file name
  char outFileName[20]; // array of char (C-string) for output file name
  ifstream inFile; // an input file object
  ofstream outFile; // an output file object

  // ask the user for the file name
  cout << "Please enter the file name to input data: ";
  cin >> inFileName;
  cout << "Please enter the file name to output data: ";
  cin >> outFileName;

  // open the file for reading & writing
  inFile.open(inFileName);
  if (!inFile) {
    cerr << "Unable to open file " << inFileName << endl << endl;
    exit(1); // call system to stop
  }
  outFile.open(outFileName);
  if (!outFile) {
    cerr << "Unable to open file " << outFileName << endl << endl;
    exit(1); // call system to stop
  }

  // read numbers from the input file to the array tests
  // double the value of each element of array tests
  // output the updated array tests to the output file, one number each line

  for (int ii=0; ii<SIZE; ii++) {
    inFile >> tests[ii];
    tests[ii] = tests[ii] * 2;
  }

  for (int ii=0; ii<SIZE; ii++) {
    tests[ii] = tests[ii] * 2;
    // tests[ii] *= 2;
  }

  for (int ii=0; ii<SIZE; ii++) {
    outFile << tests[ii] << endl;
  }





  // close the file for safety
  inFile.close();
  outFile.close();

  return 0;
}
