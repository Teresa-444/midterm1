#include <iostream>

template <typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;

public:
    Vector() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    Vector(int n) {
        size = n;
        capacity = n;
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = T();
        }
    }

    Vector(const Vector& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~Vector() {
        delete[] data;
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    void push_back(T value) {
        if (size == capacity) {
            int newCapacity;
            if (capacity == 0) {
                newCapacity = 1;
            } else {
                newCapacity = capacity * 2;
            }
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size] = value;
        size++;
    }

    void pop_back() {
        if (size == 0) {
            std::cout << "Error: vector is empty" << std::endl;
            return;
        }
        size--;
    }

    T& operator[](int index) {
        return data[index];
    }

    T& at(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Error: index out of range" << std::endl;
            return data[0];
        }
        return data[index];
    }

    Vector operator+(const Vector& other) {
        Vector result;
        for (int i = 0; i < size; i++) {
            result.push_back(data[i]);
        }
        for (int i = 0; i < other.size; i++) {
            result.push_back(other.data[i]);
        }
        return result;
    }

    Vector& operator+=(const Vector& other) {
        Vector copy(other);
        for (int i = 0; i < copy.size; i++) {
            push_back(copy.data[i]);
        }
        return *this;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void print() {
        std::cout << "[ ";
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "]  size = " << size << ", capacity = " << capacity << std::endl;
    }
};

int main() {
    Vector<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.print();

    a.pop_back();
    a.print();

    a[0] = 99;
    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "a.at(1) = " << a.at(1) << std::endl;

    Vector<int> b(a);
    b.push_back(777);
    a.print();
    b.print();

    Vector<int> c;
    c = a;
    c += b;
    c.print();

    Vector<int> d = a + b;
    d.print();

    Vector<double> e;
    e.push_back(1.5);
    e.push_back(2.5);
    e.print();

    return 0;
}