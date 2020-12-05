#include <iostream>

using namespace std;

void hanoi(int n, int i, int k) {
    if (n == 1) {
        cout << "Move disk 1 from pin " << i << " to " << k << endl;
    }
    else {
        int tmp = 6 - i - k;
        hanoi(n - 1, i, tmp);
        cout << "Move disk " << n << " from pin " << i << " to " << k << endl;
        hanoi(n - 1, tmp, k);
    }
}

int main()
{
    int x;
    cin >> x;
    hanoi(x, 1, 2);
}
