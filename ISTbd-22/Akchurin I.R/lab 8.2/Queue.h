#pragma once
#include "Element.h"
#include "QueueIterator.h"
#include "Generator.h"

class Queue
{
private:
	Element* tail;
	Element* head;
	int Size;

public:
	typedef QueueIterator iterator;
	typedef QueueIterator const_iterator;

	iterator begin()
	{
		return iterator(tail);
	}

	iterator end()
	{
		return iterator(head->getPrev());
	}

	const_iterator begin() const
	{
		return iterator(tail);
	}
	const_iterator end() const
	{
		return iterator(head);
	}

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

	void generate(int firstElem, int raznost, int count);
};