#include <iostream>

using namespace std;

void output_operation(char point1, char point2) {

	cout << "Из стержня " << point1 << " в стержень " << point2 << endl;
}

void tower(int amount, char point1, char point2, char temp) {
	
	if (amount == 0) return;

	
	tower(amount - 1, point1, temp, point2);
	output_operation(point1, point2);
	tower(amount - 1, temp, point2, point1);
}

int main()
{
	setlocale(0, "rus");

	int disk, i = 0;
	cout << "Введите количество дисков: " << endl;
	cin >> disk;

	tower(disk, 'A', 'B', 'C');
}