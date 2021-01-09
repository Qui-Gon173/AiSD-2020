#pragma once
#include <iostream>
#include "Elem.h"
#include "OwnIterator.h"
#include "Generator.h"


class List
{
	Elem* Head;
	Elem* Tail;
	int Count; //Количество элементов

public:
	typedef OwnIterator iterator;
	typedef OwnIterator const_iterator;

	iterator begin()
	{
		return iterator(Head);
	};

	iterator end()
	{
		return iterator(nullptr);
	};

	const_iterator begin() const
	{
		return const_iterator(Head);
	};

	const_iterator end() const
	{
		return const_iterator(nullptr);
	};

	
	List()
	{
		Head = NULL;
		Tail = NULL;
		Count = 0;
	};

	
	//Функция добавления
	void Add(long data)
	{
		Elem* temp = new Elem(data, NULL);
		if (Head != NULL) //Если список не пуст
		{
			Tail->Next = temp; //Указываю адрес следующего за хвостом элемента
			Tail = temp;
			Count += 1; //Меняю адрес хвоста
		}
		else //Если список пустой
		{
			//Предыдущий элемент указывает в пустоту
			Head = Tail = temp;
		}
	};


	//Функция добавления элемента на позицию
	void Insert(long data, int index)
	{
		if (index <= 0 && !(this->Head)) {
			Add(data); ++(this->Count); return;
		}
		Elem* tf = this->Head;
		for (int i = 1; i < index && tf->Next; ++i)
			tf = tf->Next;
		Elem* temp = new Elem(data, tf->Next);
		tf->Next = temp;
		++(this->Count);
	};


	//Функция удаления
	void Delete(int x) //x - позиция удаляемого элемента
	{
		if ((Head != NULL) && (x < Count) && (x >= 0))
		{
			Elem* temp = Head;
			Elem* helping = Head;

			for (int i = 0; i < x; i++)
			{
				helping = temp; // предыдущее значение temp
				temp = temp->Next;
			}

			if (temp == Head) // если элемент который надо удалить первый
			{
				Head = temp->Next;
			}
			else
			{
				helping->Next = temp->Next;
			}
			free(temp);
			Count--; // уменьшаем размер списка
		}
	};


	//Полная очистка контейнера
	void Clear()
	{
		while (Head) {
			Delete(0);
		}
	};
};

