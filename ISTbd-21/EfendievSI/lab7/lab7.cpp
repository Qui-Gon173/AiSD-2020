#include <iostream>

void hanoi(int n, int i, int k)
{
    if (n == 1) {
        std::cout << "Move disk 1 from pin " << i << " to " << k << std::endl;
    }
    else {
        int tmp = 6 - i - k;
        hanoi(n - 1, i, tmp);
        std::cout << "Move disk " << n << " from pin " << i << " to " << k << std::endl;
        hanoi(n - 1, tmp, k);
    }
}

int main()
{
    hanoi(3, 1, 2);
}