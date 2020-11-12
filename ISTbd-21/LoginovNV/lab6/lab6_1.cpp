//убрал из include библиотеку sdafx.h
#include <iostream>
using namespace std;
int main() {
	unsigned long L = 12345678;

	// в следующих строках мы разыменовываем адрес L, то есть
	// получаем целое число, лежащее по адресу L и приводим его к определённому типу
	// в 11 строке компилятор интерпретирует целое значение 12345678 как номер символа по таблице ASCII
	// в данном случае 12345678 = N
	char* cp = (char *)&L;
	int* ip = (int *)&L;
	long* lp = (long *)&L;

	cout << "\n&L = " << &L;
	cout << "\nL = " << L;
	cout << "\n*cp = " << *cp;
	cout << "\n*ip = " << *ip;
	cout << "\n*lp = " << *lp;

	// в таблице ASCII нет символа '12345678', для его получения можно использовать массив символов и функцию itoa 
	// результат представим в виде указателя на массив
	char* result = new char[9];
	itoa(L, result, 10); // 10 - система счисления

	cout << "\nresult = " << result << endl;
	
	system("pause");
	return 0;
}