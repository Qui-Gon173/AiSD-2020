#include <iostream>
using namespace std;
int main(){
  setlocale(LC_ALL, "ru");
  int x=10;
  int y=10;
  int *xptr=&x;
  int *yptr=&y;
  
//сравниваем указатели
  if (xptr == yptr) 
    cout << "Указатели равны\n";
     else  
    cout << "Указатели неравны\n";

//сравниваем значения, на которое указывает указатель
  if (*xptr == *yptr) {
    cout << "Значения равны\n";
    } else { 
    cout << "Значения неравны\n";}
  return 0;
}