#include <iostream>

using namespace std;

void Hanoi_towers_sort(int one, int two, int three) {
    if (one == 1) cout << "Перенести диск 1 со стержня " << two << " на стержень " << three <<endl;
    else {
        int temp = 6 - two - three;
        Hanoi_towers_sort(one - 1, two, temp);
        cout<< "Перенести диск "<< one <<" со стержня " << two << " на стержень " << three <<endl;
        Hanoi_towers_sort(one - 1, temp, three);
    }
 }
int main() {
    cout << " Введите количество стержней: ";
    int num;
    cin >> num;
    cout <<endl;
    Hanoi_towers_sort(num, 1, 3);
    return 0;
}
