#include <iostream>

class IntPtr {
    int* ptr;

public:
    IntPtr(int value) {
        ptr = new int(value);
    }

    IntPtr(int* p) {
        ptr = p;
    }

    ~IntPtr() {
        delete ptr;
    }

    void reset() {
        delete ptr;
        ptr = nullptr;
    }

    
    void print() {
        if (ptr == nullptr) {
            std::cout << "Pointer is empty" << std::endl;
        } else {
            std::cout << *ptr << std::endl;
        }
    }
};

int main() {
    IntPtr a(42);
    a.print();          

    IntPtr b(new int(7));
    b.print();          

    b.reset();
    b.print();          
}