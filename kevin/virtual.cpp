#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
  virtual void sayHello ()
  {
    cout << "hello" << endl;
  }
};

class Derived : public Base
{
public:
  void sayHello ()
  {
    cout << "derived hello" << endl;
  }
};

void someFunc (Base& obj)
{
  obj.sayHello();
}

int main ()
{
  Derived obj;
  someFunc(obj);

}


#if 0
class AA
{
public:
  void nonvirtualFunc () const
  {
    std::cout << "AA::nonvirtualFunc" << std::endl;
  }

  virtual void virtualOverriddenFunc () const
  {
    std::cout << "AA::virtualOverriddenFunc" << std::endl;
  }

  virtual void virtualNonOverriddenFunc () const
  {
    std::cout << "AA::virtualNonOverriddenFunc" << std::endl;
  }
};

class BB : public AA
{
public:
  void nonvirtualFunc () const
  {
    std::cout << "BB::nonvirtualOverriddenFunc" << std::endl;
  }

  virtual void virtualOverriddenFunc () const
  {
    std::cout << "BB::virtualOverriddenFunc" << std::endl;
  }
};

int main ()
{
  AA aa;
  BB bb;

  AA& bb_as_aa = bb;

  std::cout << "nonvirtualFunc" << std::endl;
  aa.nonvirtualFunc();
  bb.nonvirtualFunc();
  bb_as_aa.nonvirtualFunc();

  std::cout << "virtualOverriddenFunc" << std::endl;
  aa.virtualOverriddenFunc();
  bb.virtualOverriddenFunc();
  bb_as_aa.virtualOverriddenFunc();

  std::cout << "virtualNonOverriddenFunc" << std::endl;
  aa.virtualNonOverriddenFunc();
  bb.virtualNonOverriddenFunc();
  bb_as_aa.virtualNonOverriddenFunc();
}
#endif