// Выбор данных из памяти с помощью разных указателей
// Использование функций приведения типов

#include <iostream>

using namespace std;

int main()
{
  unsigned long L = 12345678;
  char *cp = (char*)&L;
  int *ip = (int*)&L;
  long *lp = (long*)&L;

  cout << "&L = " << &L << endl;
  cout << "L = " << L << endl;
  cout << "*cp = " << *cp << endl;
  cout << "*ip = " << *ip << endl;
  cout << "*lp = " << *lp << endl;
  system("pause");
  return 0;
}