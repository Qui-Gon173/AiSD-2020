#pragma once

#include <iostream>
#include <ctime>
#include "stack_iterator.h"

using namespace std;

class stack
{
private:
	float* stackPointer;
	int stackSize;
	int head;
public:
	stack(int = 10);
	stack(Exponential_Generator& generator)
	{
		stackSize = generator.lenght() * 8;
		stackPointer = new float[stackSize];
		for (float& item : generator)
			push(item);
	}
	~stack();
	void push(float newElement);
	void push_Multiple_Elements(float* array, int arraySize);
	float pop();
	float* pop_Multiple_Elements(int n);
	void delete_Stack();
	int return_head();
	void push_From_Another_Stack(stack& anotherStack, int n);
	typedef StackIterator iterator;
	typedef StackIterator const_iterator;
	iterator begin()
	{
		return iterator(stackPointer + head - 1);
	}
	iterator end()
	{
		return iterator(stackPointer - 1);
	}
	iterator rbegin()
	{
		return iterator(stackPointer + head - 1);
	}
	iterator rend()
	{
		return iterator(stackPointer - 1);
	}
	const_iterator cbegin() const
	{
		return const_iterator(stackPointer + head - 1);
	}
	const_iterator cend() const
	{
		return const_iterator(stackPointer - 1);
	}
};

stack::stack(int size)
{
	stack::stackSize = size;
	stackPointer = new float[stackSize];
	head = 0;
}

stack::~stack()
{
	delete[] stackPointer;
}

void stack::push(float newElement)
{
	if (head == stackSize)
		cout << "Стек полный :C" << endl;
	else
		stackPointer[head++] = newElement;
}

void stack::push_Multiple_Elements(float* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
		push(array[i]);
}

float stack::pop()
{
	if (head < 0)
		cout << "Последний элемент нельзя удалить!" << endl;
	else
		return stackPointer[--head];
}

float* stack::pop_Multiple_Elements(int n)
{
	if (head <= n)
		cout << "Стек слишком мал!" << endl;
	else
	{
		float* array = new float[n];
		for (int i = 0; i < n; i++)
			array[i] = this->pop();
		return array;
	}
}

void stack::delete_Stack()
{
	this->head = 0;
}

int stack::return_head()
{
	return head;
}

void stack::push_From_Another_Stack(stack& anotherStack, int n)
{
	int anotherHead = anotherStack.return_head();
	if (n <= anotherHead)
		for (int i = 0; i < n; i++)
			this->push(anotherStack.pop());

}