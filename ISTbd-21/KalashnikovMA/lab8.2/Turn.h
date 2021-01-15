#pragma once
#include "Element.h"
#include "TurnIterator.h"
#include "Generator.h"

class Turn
{
private:
	// брать эл-ы будем с конца - это tail
	// по¤снение - он ближе всех к извлечению - первый в очереди
	Element* tail;

	// добавл¤ть в начало - это head
	// по¤снение - он дальше всех от извлечени¤ - последний в очереди
	Element* head;

	// кол-во эл-ов в контейнере
	int turnSize;

public:
	// объ¤вление итератора
	typedef TurnIterator iterator;
	typedef TurnIterator const_iterator;

	// методы дл¤ получени¤ итераторов на конец и начало
	// допускающие и чтение, и изменение
	iterator begin()
	{
		return iterator(tail);
	}

	iterator end()
	{
		return iterator(head->getPrev());
	}

	const_iterator begin() const
	{
		return iterator(tail);
	}
	const_iterator end() const
	{
		return iterator(head);
	}

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

	// вывести max, min, sum значени¤
	void showCharacters();

	void generate(unsigned long firstElem, unsigned long raznost, int count);
};
