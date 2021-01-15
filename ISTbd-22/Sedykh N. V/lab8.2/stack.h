#pragma once
#include <iostream>
#include <ctime>
#include "iterator.h"

using namespace std;

class Stack
{
private:
	float* stackElements;
	int stackSize;
	int topIndex;
public:
	Stack(int = 10);
	Stack(ProgressionGenerator& generator)
	{
		stackSize = generator.lenght() * 8;
		stackElements = new float[stackSize];
		for (float& item : generator)
			push(item);
	}
	~Stack();
	void push(float newElement);
	void pushElements(float* array, int length);
	void pushFromAnotherStack(Stack& anotherStack, int n);
	float pop();
	float* popMultipleElements(int n);
	void clearStack();
	float topElement();

	typedef StackIterator iterator;
	typedef StackIterator const_iterator;

	iterator begin()
	{
		return iterator(stackElements + topIndex - 1);
	}
	iterator end()
	{
		return iterator(stackElements - 1);
	}
	iterator rbegin()
	{
		return iterator(stackElements + topIndex - 1);
	}
	iterator rend()
	{
		return iterator(stackElements - 1);
	}
	const_iterator cbegin() const
	{
		return const_iterator(stackElements + topIndex - 1);
	}
	const_iterator cend() const
	{
		return const_iterator(stackElements - 1);
	}
};

Stack::Stack(int size)
{
	Stack::stackSize = size;
	stackElements = new float[stackSize];
	topIndex = 0;
}

Stack::~Stack()
{
	delete[] stackElements;
}

void Stack::push(float newElement)
{
	if (topIndex == stackSize) {
		cout << "Stack if full!" << endl;
	}
	stackElements[topIndex++] = newElement;
}

void Stack::pushElements(float* array, int length)
{
	for (int i = 0; i < length; i++)
		push(array[i]);
}

void Stack::pushFromAnotherStack(Stack& anotherStack, int n)
{
	int anotherTopIndex = anotherStack.topElement();
	if (n <= anotherTopIndex)
		for (int i = 0; i < n; i++)
			this->push(anotherStack.pop());

}

float Stack::topElement()
{
	return topIndex;
}

void Stack::clearStack()
{
	this->topIndex = 0;
}

float Stack::pop()
{
	if (topIndex < 0)
		cout << "The last item cannot be deleted!" << endl;
	else
		return stackElements[--topIndex];
}

float* Stack::popMultipleElements(int n)
{
	if (topIndex <= n)
		cout << "The stack is too small!" << endl;
	else
	{
		float* array = new float[n];
		for (int i = 0; i < n; i++)
			array[i] = this->pop();
		return array;
	}
	/*
	if (n > stackSize)
	{
		cout << "The number of items to remove is larger than the stack size!";
		exit(0);
	}

	float* poppedArray = new float[n];
	for (int i = 0; i < n; i++)
		poppedArray[i] = pop();

	return poppedArray;
	*/
}