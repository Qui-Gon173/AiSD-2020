#pragma once
#include "Element.h"

class Turn
{
private:
	// брать эл-ы будем с конца - это tail
	// пояснение - он ближе всех к извлечению - первый в очереди
	Element* tail;

	// добавлять в начало - это head
	// пояснение - он дальше всех от извлечения - последний в очереди
	Element* head;

	// кол-во эл-ов в контейнере
	int turnSize;

public:
	// конструктор по умолчанию
	Turn();

	// добавить элемент(ы)
	void pushElem(unsigned long number);
	void pushArr(unsigned long numbers[], int count);

	// просмотреть последний эл-т 
	void checkLast();

	// извлечь эл-т(ы)
	unsigned long getElem();
	unsigned long* getElem(int count);

	// перенести N эл-ов в новую очередь
	Turn transfer(int count);

	// вывести все элементы на экран
	void printTurn();

	// очистить очередь
	void deleteTurn();

	// вывести кол-во элементов в очереди
	int retSize()
	{
		return turnSize;
	}

	// вывести max, min, sum значения
	void showCharacters();
};

