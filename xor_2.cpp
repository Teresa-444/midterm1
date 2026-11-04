#include <iostream>

int main() {
    int x[] = {1, 2, 3, 8, 6, 1, 2, 3, 7, 6};
    int n = sizeof(x) / sizeof(x[0]);

    int xorAll = 0;

    for (int i = 0; i < n; i++)
        xorAll ^= x[i];

    int r_bit = xorAll & (-xorAll);

    int b = 0, c = 0;

    for (int i = 0; i < n; i++) {
        if (x[i] & r_bit)
            b ^= x[i];
        else
            c ^= x[i];
    }

    std::cout << "uniques are: " << b << " and " << c << std::endl;

    return 0;
}