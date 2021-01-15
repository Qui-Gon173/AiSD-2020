//Операции над указателями

#include <iostream>
using namespace std;

int main()
{
  int a, b, c;
  int *ca, *cb;
  int *sa, *sb, *sc;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  c = a + b;

  sa = &a; //инициализация указателей через взятие адреса
  sb = &b;
  sc = &c;
  *sc = c + a - b; //присваивание указателю значения выражения
  ca = sa; //присваивание указателю значения другого указателя
  cb = sb;
  *sa = 12; //присваивание указателю значения константы

  cout << endl << "*ca = " << *ca << endl;
  cout << "*sa = " << *sa << endl;
  cout << "*cb = " << *cb << endl;
  cout << "*sb = " << *sb << endl;
  cout << "*sc = " << *sc << endl;

  cout << endl << "ca = " << ca << endl;
  cout << "cb = " << cb << endl;
  cout << "sc = " << sc << endl;

  cout << endl << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;

  cout << endl << "&a = " << &a << endl;
  cout << "&b = " << &b << endl;
  cout << "&c = " << &c << endl;

  cout << endl << "*&a = " << *&a << endl;

  cout << endl << "*cb - *ca = " << *cb - *ca << endl;
  cout << "*cb + *ca = " << *cb + *ca << endl;
  *cb += 2; //сложение с константой
  cout << "cb = " << cb << endl;
  cb++; //инкремент
  cout << "cb = " << cb << endl;
  ca--; //декремент
  cout << "ca = " << ca << endl;
  cout << "cb - ca = " << cb - ca << endl;
  system("pause");
  return 0;
}