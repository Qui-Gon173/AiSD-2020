#include <iostream>
using namespace std;

//Функция перемещения одного кольца
void moving(char firstPoint, char secondPoint);
//Функция перемещения всей башни
void towerMoving(int count, char firstPoint, char secondPoint, char freePoint);

int main()
{
	setlocale(LC_ALL, "rus");
	int count;
	cout << "Ханойские башни. Всего 3 стержня - А, Б, В." << endl << "Перемещаем башню со стержня А на стержень Б." << endl;
	cout << "Введите количество колец: "; cin >> count;
	cout << endl << "Алгоритм:" << endl;
	towerMoving(count, 'А', 'Б', 'В');
	return 0;
}

void moving(char firstPoint, char secondPoint)
{
	cout << "Из стержня " << firstPoint << " в стержень " << secondPoint << endl;
}

void towerMoving(int count, char firstPoint, char secondPoint, char freePoint)
{
	if (count == 0) { return; } //Если количество дисков равно 0, то выхожу из функции

	towerMoving(count - 1, firstPoint, freePoint, secondPoint);
	moving(firstPoint, secondPoint);
	towerMoving(count - 1, freePoint, secondPoint, firstPoint);
}