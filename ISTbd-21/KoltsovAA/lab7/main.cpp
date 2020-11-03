#include <iostream>


void move(int from, int to) {
    std::cout << from << " " << to << std::endl;
}


void hanoi(int height, int from, int to) {
    if (height == 1) {
        move(from, to);
        return;
    }

    int tmp = 6 - from - to;
    hanoi(height - 1, from, tmp);
    move(from, to);
    hanoi(height - 1, tmp, to);
}


int main() {
    int height;
    std::cout << "height: ";
    std::cin >> height;

    hanoi(height, 1, 3);
}
