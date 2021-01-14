#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Stack {

private:
	int stackSize;
	int topIndex;
	float* stackElements;

public:

	Stack(int size);
	~Stack();
	void generate();
	void push(float newElement);
	void pushElements(float* array, int length);
	void printStack();
	float topElement();
	void clearStack();
	int numberElements();
	float sumElements();
	float meanValue();
	float minElement();
	float maxElement();
	float pop();
	float* popMultipleElements(int poppingElementsNumber);

};

//Конструтор стека
Stack::Stack(int size = 0)
{
	stackSize = size;
	stackElements = new float[stackSize];
	topIndex = 0;
};
Stack::~Stack()
{
	delete[] stackElements;
}

//Заполнение стека рандомными числами типа float
void Stack::generate()
{
	srand((unsigned)time(0));
	for (int i = 0; i < stackSize; i++) {
		float fl = rand() % 10;
	}
	topIndex = stackSize - 1;
}

//Изменение размера стека и вершины стеа
/*void resizeStackAttributes()
{
	stackSize = stackElements.size();
	topIndex = stackSize - 1;
}*/

//Добавление элементов в стек
void Stack::push(float newElement)
{
	if (topIndex == stackSize) {
		cout << "Стек заполнен!" << endl;
	}
	stackElements[topIndex++] = newElement;
}

void Stack::pushElements(float* array, int length)
{
	for (int i = 0; i < length; i++)
		push(array[i]);
}

//Вывод стека
void Stack::printStack()
{
	for (int i = topIndex; i >= 0; i--)
		cout << stackElements[i] << " ";
	cout << endl;
}

//Вершина стека
float Stack::topElement()
{
	return stackElements[topIndex];
}

//Отчистка стека
void Stack::clearStack()
{
	this->topIndex = 0;
}

//Количество элементов в стеке
int Stack::numberElements()
{
	return stackSize;
}

//Сумма элементов стека
float Stack::sumElements()
{
	int sum = 0;
	for (int i = 0; i < topIndex; i++)
		sum += stackElements[i];
	return sum;
}

//Среднее значение
float Stack::meanValue()
{
	if (topIndex > 0)
		return (float)this->sumElements() / (float)topIndex;
	else
		return 0;
}

//Минимальный элемент
float Stack::minElement()
{
	if (topIndex > 0)
	{
		int min = stackElements[0];
		for (int i = 0; i < topIndex; i++)
			if (min > stackElements[i])
				min = stackElements[i];
		return min;
	}
	else
		return 0;
}

//Максимальный элемент
float Stack::maxElement()
{
	if (topIndex > 0)
	{
		int max = stackElements[0];
		for (int i = 0; i < topIndex; i++)
			if (max < stackElements[i])
				max = stackElements[i];
		return max;
	}
	else
		return 0;
}

//Удаление элементов из стека
float Stack::pop()
{
	if (topIndex < 0)
		cout << "Последний элемент невозможно удалить!" << endl;
	else
		return stackElements[--topIndex];
}

float* Stack::popMultipleElements(int poppingElementsNumber)
{
	if (poppingElementsNumber > stackSize)
	{
		cout << "Количество элементов для удаления больше размера стека!";
		exit(0);
	}

	float* poppedArray = new float[poppingElementsNumber];
	for (int i = 0; i < poppingElementsNumber; i++)
		poppedArray[i] = pop();

	return poppedArray;
}


