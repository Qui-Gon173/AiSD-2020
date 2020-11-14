#include <iostream>

int main() {
  int x = 10;
  int y = 10;
  int *xptr = &x;
  int *yptr = &y;
  
//сравниваем указатели
  if (xptr == yptr) {
      std::cout << "Pointers are equal\n";
  } else {  
      std::cout << "Pointers are not equal\n";
  }

//сравниваем значения, на которое указывает указатель
  if (*xptr == *yptr) {
      std::cout << "The values are equal\n";
    } else { 
        std::cout << "The values are not equal\n";
    }
}
