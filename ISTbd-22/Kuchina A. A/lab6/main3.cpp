#include <iostream>
using namespace std;
int main(){
    setlocale(LC_ALL, "Russian");
  int x=10;
  int y=10;
  int *xptr=&x;
  int *yptr=&y;

//���������� ���������
  if (xptr == yptr)
    cout << "��������� �����\n";
     else
    cout << "��������� �������\n";

//���������� ��������, �� ������� ��������� ���������
  if (*xptr == *yptr) {
    cout << "�������� �����\n";
    } else {
    cout << "�������� �������\n";}
  system("pause");
  return 0;
}
