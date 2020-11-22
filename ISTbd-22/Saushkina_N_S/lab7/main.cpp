#include <iostream>
using namespace std;
void Hanoi(int n, int i, int k) {
    if (n == 1) cout << "move disk 1 from pin " << i << " to " << k <<endl;
    else {
        int tmp = 6 - i - k;
        Hanoi(n - 1, i, tmp);
        cout<< "move disk "<< n <<" from pin " << i << " to " << k <<endl;
        Hanoi(n - 1, tmp, k);
    }
 }
int main() {
    int num;
    cin >> num;
    cout <<endl;
    Hanoi(num, 1, 3);
    system("pause");
    return 0;
}
