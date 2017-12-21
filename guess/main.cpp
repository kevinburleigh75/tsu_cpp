#include <iostream>
#include <string>
using namespace std;
int main(){

  int low, high;
//Ask user for the range 2 integers.
  cout << "What is your low" << endl;
  cin >> low;
  cout << "What is your high" << endl;
  cin >> high;


  while(true){
    if (low == high){
      cout << "Your number is " << high << endl;
      break;
    }
    else if(high == low + 1){
      string ynAnswer;
      cout << "Is " << high << " your number?" << endl;
      cin >> ynAnswer;
      if(ynAnswer == "Y" || ynAnswer == "y"){
        cout << "Your number is " << high << endl;
        break;
      }
      else if(ynAnswer == "N" || ynAnswer == "n"){
        cout << "Your number is " << low << endl;
        break;
      }
    }
    else{
      int aveMid = low + high;
      int mid = aveMid/2;
      string ynAnswer;
      cout << "Is your number higher then " << mid << endl;
      cin >> ynAnswer;
      if (ynAnswer == "Y" || ynAnswer == "y"){
        low = mid;
      }
      else{
        high = mid;
      }
    }
  }

//Think of a number inside of the range.


//Until we have an answer.
  //if low equals high
    //Print out number
    //Break
  //elseif low plus 1 equals high
    //ask if low is the number
    //if yes
        //print out low number
    //else
      //print out high number
    //Break
  //else
    //find the mid between high and low
    //Ask if the number is higher then the mid number.
    //if yes
      //mid become my new low
    //else
      //mid becomes high
//
//
}