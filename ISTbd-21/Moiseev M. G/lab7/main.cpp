#include <iostream>


void move(int from, int to) { //Вывод действий
    std::cout << from << " " << to << std::endl;
}


void hanoi(int height, int from, int to) {
    if (height == 1) {
        move(from, to);
        return;
    }

    int tmp = 6 - from - to; //Выбор буфера
    hanoi(height - 1, from, tmp); //Перенос heght-1 элементов на буфер
    move(from, to); //Перенос на нужную
    hanoi(height - 1, tmp, to); //Перенос буфера на нужный стержень
}


int main() {
    int height;
    std::cout << "height: ";
    std::cin >> height;

    hanoi(height, 1, 3);
}
