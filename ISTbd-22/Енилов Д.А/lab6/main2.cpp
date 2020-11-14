//Операции над указателями

#include <iostream>

using namespace std;

int main(){
  int a,c,b;
  int  *ca, *cb;
  int *sa, *sb, *sc;
  std::cout << "a = "; cin >> a;
  std::cout << "b = "; cin >> b;
  c=a+b;

  sb=&b;//инициализация указателей через взятие адреса
  sa=&a;
  sc =&c;
  //присваивание указателю значения выражения
  //точнее присваивание ячейке памяти &c значения c+a-b
  *sc = c+a-b;
  ca=sa;//присваивание указателю значения другого указателя
  cb=sb;
  //присваивание ячейке памяти &a 12
  *sa=12;//присваивание указателю значения константы

  std::cout << "\n*ca = " << *ca;//здесь все верно, ca и sa ссылаются на одну ячейку памяти, 
  //а мы присвоили а значение 12
  std::cout << "\n*sa = " << *sa;//также все верно, ведь а=12
  std::cout << "\n*cb = " << *cb;//все верно, b=5, этот указатель ссылается на неё
  std::cout << "\n*sb = " << *sb;//все верно, b=5, аналогично с cb
  std::cout << "\n*sc = " << *sc;//все верно, c=4+5=9, потом через указатель присвоили 
  //с=9+4-5=8

  std::cout << "\nca = " << ca; 
  std::cout << "\ncb = " << cb;
  std::cout << "\nsc = " << sc;

  std::cout << "\na = " << a;
  std::cout << "\nb = " << b;
  std::cout << "\nc = " << c;

  std::cout << "\n&a = " << &a; 
  std::cout << "\n&b = " << &b;
  std::cout << "\n&c = " << &c;

  std::cout << "\n*&a = " << *&a;  
  
  std::cout << "\n*cb-*ca = " << *cb-*ca;
  std::cout << "\n*cb+*ca = " << *cb+*ca;
  *cb+=2; //сложение с константой
  std::cout << "\ncb = " << cb;
  cb++; //инкремент, к адресу прибавили 1, сменив его на адрес с
  std::cout << "\ncb = " << cb;
  ca--; //декремент, сменили адрес a на адрес c
  std::cout << "\nca = " << ca;
  std::cout << "\ncb-ca = " << cb-ca; 
  system("pause");
  return 0;
}