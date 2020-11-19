#include <iostream>

using namespace std;

typedef char rod;

int HanoiTower(int disks, rod A, rod B, rod C)
{
    int count;
    if (disks == 1)
    {
        cout << "\n   From " << A << " to " << C;
        count = 1;
    }
    else
    {
        count = HanoiTower(disks - 1, A, C, B);
        cout << "\n   From " << A << " to " << C;
        count++;
        count += HanoiTower(disks - 1, B, A, C);
    }
    return count;
}

int main() 
{
    system("chcp 1251 > NUL");

    char rods[] = {'A', 'B', 'C'};  // стержни
    int disks, movements;           // диски и ходы

    cout << "\tHanoi Towers\n\n";
    cout << "Input amount of disks: "; cin >> disks;

    movements = HanoiTower(disks, rods[0], rods[1], rods[2]);
    cout << "\n\nMinimum number of movements: " << movements << endl << endl;

    system("pause");
    return 0;
}

