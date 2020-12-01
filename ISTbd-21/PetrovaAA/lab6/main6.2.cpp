#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
  //setlocale(LC_ALL,"RUS");
  int a,c,b;
  int  *ca, *cb;
  int *sa, *sb, *sc;
  cout << "a = "; cin >> a;
  cout << "b = "; cin >> b;  
  c=a+b;

  sb=&b;//инициализация указателей через взятие адреса
  sa=&a;
  sc =&c;
  //присваивание указателю значения выражения
  *sc = c+a-b;
  ca=sa;//присваивание указателю значения другого указателя
  cb=sb;
  *sa=12;//присваивание указателю значения константы

  cout<<"\n\nValues of dereferenced pointers:";
  cout << "\n*ca = " << *ca;
  cout << "\n*sa = " << *sa; 
  cout << "\n*cb = " << *cb; 
  cout << "\n*sb = " << *sb;
  cout << "\n*sc = " << *sc;

  cout<<"\n\nAddresses of pointers:";
  cout << "\nca = " << ca; 
  cout << "\ncb = " << cb;
  cout << "\nsc = " << sc;

  cout<<"\n\nValues of integer variables:";
  cout << "\na = " << a;
  cout << "\nb = " << b;
  cout << "\nc = " << c;

  cout<<"\n\nAddresses of integer variables:";
  cout << "\n&a = " << &a; 
  cout << "\n&b = " << &b;
  cout << "\n&c = " << &c;

  cout<<"\n\nDereferenced address of integer variable a:";
  cout << "\n*&a = " << *&a;  
  
  cout<<"\n\nResults of arifmetic operations with pointers:";
  cout << "\n*cb-*ca = " << *cb-*ca;
  cout << "\n*cb+*ca = " << *cb+*ca;
  *cb+=2; //сложение с константой
  cout << "\ncb = " << cb;
  cb++; //инкремент
  cout << "\ncb = " << cb;
  ca--; //декремент
  cout << "\ncа = " << ca;
  cout << "\ncb-ca = " << cb-ca; 
  system("pause");
  return 0;
}