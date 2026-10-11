#include <iostream>

class A {
public:
    A()  { std::cout << "A "; }
    ~A() { std::cout << "~A "; }
};

class B {
public:
    B()  { std::cout << "B "; }
    ~B() { std::cout << "~B "; }
};

int main()
{ A* pa = new A();
  B* pb = new B();
delete pa;
delete pb;
} 