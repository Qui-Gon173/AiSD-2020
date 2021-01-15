#include "Queue.h"

Queue::Queue()
{
	size = 0;
	rear = nullptr;
	head = nullptr;
}

// добавление элемента в очередь
void Queue::push(float number)
{
	Node* item = new Node(nullptr, number);
	if (rear != nullptr)
	{
		head->next = item;
		head = item;
		head->next = nullptr;
	}
	else
	{
		head = rear = item;
	}
	size++;
}

// добавление нескольких элементов в очередь
void Queue::pushSomeElements(float array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		this->push(array[i]);
	}
}

// посмотреть элемент в конце очереди
void Queue::lookAtLast()
{
	std::cout << rear->data << std::endl;
}

// вывести все элементы
void Queue::printAll()
{
	if (size > 0)
	{
		for (Node* current = rear; current != nullptr; current = current->next)
		{
			std::cout << current->data << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Пусто" << std::endl;
	}

}

// получить кол-во элементов в очереди
int Queue::getSize()
{
	return size;
}

// извлечь элемент очереди
float Queue::pop()
{
	float element = 0;
	if (size > 0)
	{
		element = rear->data;
		Node* tmp = new Node(nullptr, 0);
		tmp = rear->next;
		delete rear;
		rear = tmp;
		size--;
	}
	return element;
}

// извлечь элементы очереди
float* Queue::popElements(int count)
{
	float* resultArr = new float[count - 1];

    for (int i = 0; i < count; i++)
	{
		resultArr[i] = this->pop();
	}

	return resultArr;
}

// перенести элементы очереди
Queue Queue::transferElements(int count)
{
	Queue newQueue;
	float* tmpArray = new float[count - 1];
	tmpArray = this->popElements(count);

	for (int i = 0; i < count; i++)
	{
		newQueue.push(tmpArray[i]);
	}

	return newQueue;
}

// очистить очередь
void Queue::deleteAll()
{
	this->popElements(size);
	size = 0;
}

// получить сумму элементов
float Queue::getSum() 
{
	float sum = 0;
	Node* current = this->rear;
	while (current != nullptr)
	{
		sum += current->data;
		current = current->next;
	}
	return sum;
}

//получить среднее значение элементов
float Queue::getAverageValue() 
{
	return getSum()/size;
}

//получить значение минимального элемента;
float Queue::getMinValue()
{
	float min = rear->data;
	Node* current = this->rear;
	while (current != nullptr)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return min;
}

//получить значение максимального элемента
float Queue::getMaxValue()
{
	float max = rear->data;
	Node* current = this->rear;
	while (current != nullptr)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return max;
}
