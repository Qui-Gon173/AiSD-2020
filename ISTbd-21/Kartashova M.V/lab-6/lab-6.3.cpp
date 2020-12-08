#include <iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "RUS");

	int x = 10;
	int y = 10;
	int *xptr = &x;
	int *yptr = &y;

	//сравниваем указатели
	if (xptr == yptr)
		cout << "Указатели равны\n";
	else
		cout << "Указатели равны\n";

	//сравниваем значения, на которое указывает указатель
	if (*xptr == *yptr) {
		cout << "Значения равны\n";
	}
	else {
		cout << "Значения равны\n";
	}
	system("pause");
	return 0;
}