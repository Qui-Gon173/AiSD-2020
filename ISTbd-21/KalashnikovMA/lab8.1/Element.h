#pragma once
#include <iostream>

class Element
{
private:
	// указатель на предыдущий элемент
	Element* prev;
	// сами данные - unsigned long, вариант 6
	unsigned long data;

public:
	// конструктор
	Element(Element* newPrev, unsigned long newData)
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

	unsigned long getData()
	{
		return data;
	}
};

