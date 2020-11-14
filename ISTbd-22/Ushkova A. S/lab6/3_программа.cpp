#include <iostream>
using namespace std;
int main(){
  int x=10;
  int y=10;
  int *xptr=&x;
  int *yptr=&y;

//сравниваем указатели
  if (xptr == yptr)
    cout << "Pointers are equal\n";
     else
    cout << "Pointers are not equal\n";

//сравниваем значения, на которое указывает указатель
  if (*xptr == *yptr) {
    cout << "The values are equal\n";
    } else {
    cout << "Values are not equal\n";}

  return 0;
}
