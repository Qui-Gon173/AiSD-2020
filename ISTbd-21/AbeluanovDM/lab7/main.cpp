#include <iostream>



void hanoi(int height, int from, int to) {
  if (height == 1) {
    std::cout << "Move: " << from << " -> " << to << std::endl;
  } else {
    int temp = 6 - from - to;
    hanoi(height - 1, from, temp);
    std::cout << "Move: " << from << " -> " << to << std::endl;
    hanoi(height - 1, temp, to);
  }

}

int main() {
  int from;
  int to;
  int height;

  std::cout << "Insert height: ";
  std::cin >> height;

  std::cout << "Insert from tower (1 <= x <= 3): ";
  std::cin >> from;

  std::cout << "Insert to tower (1 <= x <= 3): ";
  std::cin >> to;
  
  if (0 < from && from < 4) {
    if (0 < to && to < 4) {
        hanoi(height, from, to);
    }
  } else {
    std::cout << "You need to insert towers from 1 to 3!" << std::endl;
  }
}
