#include <iostream>
using namespace std;

void HanoiTower(int num, char from, char to, char buff)
{
    if (num != 0)
    {
        HanoiTower(num - 1, from, buff, to);
        cout << from << " -> " << to << endl;
        HanoiTower(num - 1, buff, to, from);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите количество дисков на стержне А:" << endl;
    cin >> N;
    HanoiTower(N, 'A', 'B', 'C');
    return 0;
}
