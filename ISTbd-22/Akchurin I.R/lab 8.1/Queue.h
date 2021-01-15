#pragma once
#include "Element.h"

class Queue
{
private:
	Element* tail;
	Element* head;
	int Size;//количество элементов

public:
	Queue();

	void addNumber(int number);//добавление одного элемента
	void addNumbers(int numbers[], int count);//добавление нескольких элементов

	void checkLast();//просмотреть последний элемент 

	int extractLast();//извлечь последний элемент
	int* extractLast(int count);//извлечь несколько элементов с конца

	
	Queue remake(int count);//перенос n элементов в новый экземпл€р

	
	void display();//вывести очередь
	void clearAll();//очистить очередь

	int getSize()//вывести количество элементов в очереди
	{
		return Size;
	}

	int sum();//сумма
	int average();//среднее значение
	int min();//минимальное значение
	int max();//максимальное значение
};
