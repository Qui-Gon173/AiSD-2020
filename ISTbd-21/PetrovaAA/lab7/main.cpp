#include <iostream>
#include <cstdlib>

using namespace std;

void HanoiTowers (int amount, int from, int to)
{
    if (amount == 1)
        cout << "Move disk 1 from pin " << from << " to " << to << "\n";
    else
    {
        int temp = 6 - (from + to);
        HanoiTowers(amount-1, from, temp);
        cout << "Move disk " << amount << " from pin " << from << " to " << to << "\n";
        HanoiTowers(amount-1, temp, to);
    }
    
}

int main()
{
    int amount, from, temp;
    cout << "Insert the numbers of disks: ";
    cin >> amount;
    HanoiTowers(amount, 1, 2);
}