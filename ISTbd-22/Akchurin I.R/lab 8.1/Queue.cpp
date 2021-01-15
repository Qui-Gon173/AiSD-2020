#include "Queue.h"
using namespace std;

Queue::Queue()
{
	tail = nullptr;
	head = nullptr;
	Size = 0;
}

void Queue::addNumber(int number)
{
	Element* newElem = new Element(nullptr, number);

	if (tail != nullptr)
	{
		head->setPrev(newElem);
		head = newElem;
		head->setPrev(nullptr);
	}
	else
	{
		head = newElem;
		tail = newElem;
	}
	Size++;
}

void Queue::addNumbers(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		this->addNumber(numbers[i]);
	}
}

void Queue::checkLast()
{
	cout << tail->getData() << endl;
}

void Queue::display()
{
	if (Size > 0)
	{
		for (Element* current = tail; current != nullptr; current = current->getPrev())
		{
			cout << current->getData() << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Очередь пуста" << endl;
	}

}

int Queue::extractLast()
{
	int element = tail->getData();
	Element* buff = new Element(nullptr, 0);
	buff = tail->getPrev();
	delete tail;
	tail = buff;
	Size--;
	return element;
}

int* Queue::extractLast(int count)
{
	int* resultArr = new int[count - 1];
	for (int i = 0; i < count; i++)
	{
		resultArr[i] = this->extractLast();
	}
	return resultArr;
}

Queue Queue::remake(int count)
{
	Queue newQueue;
	int* transferArr = new int[count - 1];
	transferArr = this->extractLast(count);

	for (int i = 0; i < count; i++)
	{
		newQueue.addNumber(transferArr[i]);
	}

	return newQueue;
}
void Queue::clearAll()
{
	this->extractLast(Size);
	Size = 0;
}

int Queue::sum() {
	int sum = 0;
	for (Element* current = tail; current != nullptr; current = current->getPrev())
	{
		sum += current->getData();
	}
	return sum;
	
}
int Queue::average() {
	int average = 0;
	average = sum() / Size;
	return average;
}

int Queue::min() {
	int min;
	min = tail->getData();
	for (Element* current = tail; current != nullptr; current = current->getPrev())
	{
		if (current->getData() < min)
		{
			min = current->getData();
		}
	}
	return min;
}
int Queue::max() {
	int max;
	max = tail->getData();
	for (Element* current = tail; current != nullptr; current = current->getPrev())
	{
		if (current->getData() > max)
		{
			max = current->getData();
		}
	}
	return max;
}