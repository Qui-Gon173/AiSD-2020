#pragma once
#include <iostream>

class Queue
{
private:
	struct Node
	{
		Node* next;
		float data;
		Node(Node* next, float data)
		{
			this->next = next;
			this->data = data;
		}
	};

	Node* rear;
	Node* head;
	int size;

public:
	
	Queue();

	// добавить элемент в очередь
	void push(float number);

	// добавить несколько элементов в очередь
	void pushSomeElements(float array[], int size);

	// просмотреть элемент в конце очереди
	void lookAtLast();

	// извлечь один элемент 
	float pop();

	// перенести n эл-ов в новый экземпляр
	Queue transferElements(int count);

	// извлечь несколько элементов
	float* popElements(int count);

	// вывести все от первого до последнего элемента очереди
	void printAll();

	// Полная очистка контейнера
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