#include <iostream>

using namespace std;

int main()
{
  int x = 10;
  int y = 10;
  int *xptr = &x;
  int *yptr = &y;

  //сравниваем указатели
  if (xptr == yptr)
    cout << "Pointers are equal." << endl;
  else
    cout << "Pointers are unequal." << endl;

  //сравниваем значения, на которое указывает указатель
  if (*xptr == *yptr)
    cout << "Values are equal." << endl;
  else
    cout << "Values are unequal." << endl;
  system("pause");
  return 0;
}