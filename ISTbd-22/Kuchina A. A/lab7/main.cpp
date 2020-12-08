#include <iostream>

using namespace std;

void Hanoi(int n, int i, int k) {
    if (n == 1) cout << "Перенести диск 1 со стержня " << i << " на стержень " << k <<endl;
    else {
        int tmp = 6 - i - k;
        Hanoi(n - 1, i, tmp);
        cout<< "Перенести диск "<< n <<" со стержня " << i << " на стержень " << k <<endl;
        Hanoi(n - 1, tmp, k);
    }
 }
int main() {
    setlocale(LC_ALL, "Russian");
    cout << " Введито количество стержней: ";
    int num;
    cin >> num;
    cout <<endl;
    Hanoi(num, 1, 3);
    system("pause");
    return 0;
}
