
#include <iostream>
using namespace std;
int main(){
  int x=10;
  int y=10;
  int *xptr=&x;
  int *yptr=&y;
  
//сравниваем указатели
  if (xptr == yptr) 
    std::cout << "Pointers are equal\n";
     else  
    std::cout << "Pointers are not equal\n";
//здесь все работает верно
//сравниваем значения, на которое указывает указатель
  if (*xptr == *yptr) {
    std::cout << "Value are equal\n";
    } else { 
    std::cout << "Value are not equal\n";}
  system("pause");
  return 0;
}