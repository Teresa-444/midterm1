#include <iostream>

int main() {
    int x = 10;
    int y = 20;

   
    const int* p1 = &x;
    //*p1 = 11;
    p1 = &y;          
    std::cout << "p1 -> " << *p1 << "\n";

    int* const p2 = &x;
    *p2 = 11;        
    //p2 = &y;    //ERROR   
    std::cout << "x = " << x << "\n";

   
    const int* const p3 = &x;
    //*p3 = 5;       // ERROR
    //p3 = &y;       // ERROR
    std::cout << "p3 -> " << *p3 << "\n";

   
    int& r1 = x;      
    r1 = 50;          
    std::cout << "x = " << x << "\n";


    const int& r3 = 5;  
     //r3 = 6;        // ERROR
    std::cout << "r3 = " << r3 << "\n";

    
    std::cout << "sizeof(int)     = " << sizeof(int)     << "\n";
    std::cout << "sizeof(double)  = " << sizeof(double)  << "\n";
    std::cout << "sizeof(int*)    = " << sizeof(int*)    << "\n";
    std::cout << "sizeof(double*) = " << sizeof(double*) << "\n";
    std::cout << "sizeof(char*)   = " << sizeof(char*)   << "\n";

    return 0;
}