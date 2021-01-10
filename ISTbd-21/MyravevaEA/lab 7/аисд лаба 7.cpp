#include <iostream>

using namespace std;

void Bashni(int m, int a, int b, int c)
{
    if (m == 0) {
        return;
    }
    Bashni(m - 1, a, c, b);
    cout << a << " => " << b << endl;
    Bashni(m - 1, c, b, a);
}

int  main()
{
    int  amount = 5, basic = 1, finite = 2, other = 3;
    Bashni(amount, basic, other, finite);
    return 0;
}