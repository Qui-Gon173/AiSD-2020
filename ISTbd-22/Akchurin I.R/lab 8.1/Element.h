#pragma once
#include <iostream>

class Element
{
private:
	Element* prev;
	int data;

public:
	Element(Element* newPrev, int newData)
	{
		prev = newPrev;
		data = newData;
	}

	void setPrev(Element* newPrev)
	{
		prev = newPrev;
	}

	Element* getPrev()
	{
		return prev;
	}

	int getData()
	{
		return data;
	}
};