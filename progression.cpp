
#include <iostream>

void progression(int a, int d, int n)
{
    if (n == 0)
    {
        return;
    }

    std::cout << a << " ";
    progression(a + d, d, n - 1);
}

int main()
{
    progression(2, 3, 5);
    return 0;
}
