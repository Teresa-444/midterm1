#include <iostream>
int main () {
    int x[] = {1, 2, 3, 1, 2, 3, 1, 1, 0, 8, 0};
    int n = sizeof(x) / sizeof(x[0]);
    
    int result = 0;
    for (int i = 0; i < n; i ++)
        result ^= x[i];
        
    std::cout << "unique element:" << result << std::endl;
    return 0;
}
