#include <iostream>

using namespace std;

void Hanoi(int n, int i, int k) {
    if (n == 1) cout << "��������� ���� 1 �� ������� " << i << " �� �������� " << k <<endl;
    else {
        int tmp = 6 - i - k;
        Hanoi(n - 1, i, tmp);
        cout<< "��������� ���� "<< n <<" �� ������� " << i << " �� �������� " << k <<endl;
        Hanoi(n - 1, tmp, k);
    }
 }
int main() {
    setlocale(LC_ALL, "Russian");
    cout << " ������� ���������� ��������: ";
    int num;
    cin >> num;
    cout <<endl;
    Hanoi(num, 1, 3);
    system("pause");
    return 0;
}
