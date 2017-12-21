#include <iostream>
#include <vector>

using namespace std;

int slowFib(int n)
{
  cout << "Starting " << n << endl;
  int val;
  if (n==0)
    val = 1;
  else if (n==1)
    val = 1;
  else
     val = slowFib(n-1)+slowFib(n-2);
  cout << "Leaving " << n << " = " << val  << endl;
  return val;
}

int fastFib(int n, std::vector<int> &array)
{
  //if array[n] is invalid
  //  compute f(n)
  //
  //  then store in array(n)
  //
  //return array[n]

  if (array[n]<0){
    //cout << "Starting " << n << endl;
    int val;
    if (n==0)
      val = 1;
    else if (n==1)
      val = 1;
    else
      val = fastFib(n-1, array)+fastFib(n-2, array);
    //cout << "Leaving " << n << " = " << val  << endl;
    array[n] = val;
  }

  return array[n];


}

int fib(int n)
{
   std::vector<int> array(n+1,-1);
   return fastFib(n, array);
}

int main() {
  int x = fib(44);
  cout << "Final val = " << x << endl;
}

