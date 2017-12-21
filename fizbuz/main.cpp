#include <iostream>
using namespace std;

void divisibleFunction(int usersNumber){

  if(usersNumber % 7 == 0 && usersNumber % 11 == 0){
    cout << "FIZZBUZZ" << endl;
  }
  else if (usersNumber % 7 == 0){
    cout << "FIZZ" << endl;
  }
  else if (usersNumber % 11 == 0){
    cout << "BUZZ" << endl;
  }
  else{
    cout << "Your number sucks enter a new one" << endl;
  }

}


int getNumber(){
  int posNumber = 0;

  while(true){
    cout << "Enter a positive number" << endl;
    cin >> posNumber;
    if (!cin.good()){
      cout << "I said number dumbass" << endl;
      cin.clear();
      cin.ignore(INT_MAX, '\n');
    }
    else if (posNumber > 0){
      break;
    }
  }
  return posNumber;
}

int main(void){

  while(true){
    int something = getNumber();

    divisibleFunction(something);
  }



}