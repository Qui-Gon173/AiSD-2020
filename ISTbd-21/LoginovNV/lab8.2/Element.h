#pragma once
#include <iostream>

class Element
{
private:
	// указатель на предыдущий элемент
	Element* prev;
	// сами данные - float, вариант 6
	float data;

public:
	// конструктор
	Element(Element* newPrev, float newData)
	{
		prev = newPrev;
		data = newData;
	}

	// установить предыдущий
	void setPrev(Element* newPrev)
	{
		prev = newPrev;
	}

	// получить предыдущий
	Element* getPrev()
	{
		return prev;
	}

	float getData()
	{
		return data;
	}

	// для итератора
	float* getPointer()
	{
		return &data;
	}
};

