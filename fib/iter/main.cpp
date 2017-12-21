#include <iostream>
#include <vector>

using namespace std;

int fib(int n)
{
  int val;
//Check to see if the value is 0 or 1
  if (0 == n || 1 == n){
    val = 1;
  }
  else{
    int prev1 = 1;
    int prev2 = 1;
    for (int curN=2;curN<=n;curN++){
      val =  prev1 + prev2;
      prev2 = prev1;
      prev1 = val;
    }
  }
  return val;
}



int main() {
  int x = fib(44);
  cout << "Final val = " << x << endl;
}

