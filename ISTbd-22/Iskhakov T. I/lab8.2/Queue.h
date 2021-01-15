#pragma once
#include <iostream>
#include "Node.h"
#include "QueueIterator.h"

class Queue
{
private:

	Node* rear;
	Node* head;
	int size;

public:

	// объ€вление итератора
	typedef QueueIterator iterator;
	typedef QueueIterator const_iterator;

	iterator begin()
	{
		return iterator(rear);
	}

	iterator end()
	{
		return iterator(head->next);
	}

	const_iterator begin() const
	{
		return iterator(rear);
	}
	const_iterator end() const
	{
		return iterator(head);
	}
	
	Queue();

	// добавить элемент в очередь
	void push(float number);

	// добавить несколько элементов в очередь
	void pushSomeElements(float array[], int size);

	// просмотреть элемент в конце очереди
	void lookAtLast();

	// извлечь один элемент 
	float pop();

	// перенести n эл-ов в новый экземпл€р
	Queue transferElements(int count);

	// извлечь несколько элементов
	float* popElements(int count);

	// вывести все от первого до последнего элемента очереди
	void printAll();

	// ѕолна€ очистка контейнера
	void deleteAll();

	// получить кол-во элементов в очереди
	int getSize();

	//получить cумму всех значений
	float getSum();

	//получить среднее значение элементов
	float getAverageValue();

	//получить значение минимального элемента
	float getMinValue();

	//получить значение максимального элемента
	float getMaxValue();
};