#include <iostream>
#include <cstdlib>

using namespace std;

void PrintMove(int amount, int from, int to)
{
	cout << "Перемещаем диск " << amount << " со стержня № " << from << " на стержень № " << to << "\n";
}

void HanoiTowers(int amount, int from, int to)
{
	if (amount == 1)
		PrintMove(amount, from, to);
	else
	{
		int temp = 6 - (from + to);
		HanoiTowers(amount - 1, from, temp);
		PrintMove(amount, from, to);
		HanoiTowers(amount - 1, temp, to);
	}

}

int main()
{
	setlocale(LC_ALL, "rus");
	int amount;
	cout << "Введите количество дисков: ";
	cin >> amount;
	HanoiTowers(amount, 1, 2);
}