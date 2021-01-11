#include <iostream>
using namespace std;


void hanoi(int count, int from, int to) {
    if (count == 1) {
        cout << from << "-" << to << endl;
        return;
    }

    int temp = 6 - from - to;
    hanoi(count - 1, from, temp);
    cout << from << "-" << to << endl;
    hanoi(count - 1, temp, to);
}


int main() {
    int count;
    cin >> count;
    hanoi(count, 1, 3);

    return 0;
}
