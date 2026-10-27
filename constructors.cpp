#include <iostream>

class WithImplicit {
public:
    WithImplicit(int x) : value(x) {
        std::cout << "Implicit: " << x << "\n";
    }
    int value;
};

class WithExplicit {
public:
    explicit WithExplicit(int x) : value(x) {
        std::cout << "Explicit: " << x << "\n";
    }
    int value;
};

void showImplicit(WithImplicit w) { std::cout << "showImplicit: " << w.value << "\n"; }
void showExplicit(WithExplicit w) { std::cout << "showExplicit: " << w.value << "\n"; }

int main() {
   
    WithImplicit a = 5;          
    showImplicit(10);           

   
    WithExplicit b(5);          
    WithExplicit c{5};           
    showExplicit(WithExplicit(10));            
    WithExplicit d = static_cast<WithExplicit>(7); // cast

     WithExplicit e = 5;       // error
     showExplicit(10);         // error
}