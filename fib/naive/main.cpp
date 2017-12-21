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

int main() {
  int x = slowFib(40);
  cout << "Final val = " << x << endl;
}

