#include <iostream>

long long power9(int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result = result * 9;
    }
    return result;
}

long long countNumbers(int n) {
    if (n == 1) {
        return 0;
    }
    return power9(n) - countNumbers(n - 1);
}

int main() {
    int n;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << countNumbers(n) << std::endl;
}