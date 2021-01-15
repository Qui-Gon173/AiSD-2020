#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Queue item;
	float number = 4.4;
	const int SIZE = 3;
	float array[SIZE] = { 6.3, 7.9, 1.4 };

	cout << "Добавление элементов в очередь" << endl;
	
	item.pushSomeElements(array, SIZE);
	item.push(number);

	cout << "Вывод очереди" << endl;
	item.printAll();

	cout << "Число элементов в очереди = " << item.getSize() << endl;

	cout << "Посмотреть элемент" << endl;
	item.lookAtLast();

	cout << "Извлечь элемент: " << item.pop() << endl;

	cout << "Вывод очереди" << endl;
	item.printAll();

	
	cout << "Сумма всех значений: " << item.getSum() << endl;
	cout << "Среднее значение: " << item.getAverageValue()<< endl;
	cout << "Значение минимального элемента: " << item.getMinValue()<< endl;
	cout << "Значение максимального элемента: " << item.getMaxValue() << endl;


	cout << "Перенос n элементов в новый экземпляр" << endl;
	Queue newItem = item.transferElements(2);

	cout << "Новая очередь:" << endl;
	newItem.printAll();

	cout << "Старая очередь:" << endl;
	item.printAll();

	cout << "Полная очистка контейнеров" << endl;
	item.deleteAll();
	newItem.deleteAll();

	cout << "Получаем" << endl;
	item.printAll();
	newItem.printAll();

	return 0;
}

