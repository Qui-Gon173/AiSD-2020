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
		cout << "Указатели равны." << endl;
	else
		cout << "Указатели не равны." << endl;

	//сравниваем значения, на которое указывает указатель
	if (*xptr == *yptr)
		cout << "Значения равны." << endl;
	else
		cout << "Значения не равны." << endl;
	system("pause");
	return 0;
}