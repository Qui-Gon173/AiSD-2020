#pragma once
#include <iostream>


class List;
class Elem
{
	long data; // Данные экземпляра
	Elem* Next;
	friend class List;

public:
	Elem(long data = NULL, Elem* Next = NULL)
	{
		data = 0;
		Next = 0;
	};
};

class List
{
		Elem* Head;
		Elem* Tail;
		int Count; //Количество элементов

	public:
		List()
		{
			Head = 0;
			Tail = 0;
			Count = 0;

		}


		//функция добавления
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
			Elem* temp = new Elem;
			temp->data = data;
			temp->Next = tf->Next;
			tf->Next = temp;
			++(this->Count);
		}


		//Функция удаления
		void Delete(int x) //x - позиция удаляемого элемента
		{
			if ((Head != NULL) && (x < Count) && (x >= 0))
			{
				Elem* temp = Head;
				Elem* helping = Head;

				for (int i = 0; i < x; i++)
				{
					helping = temp; // Предыдущее значение temp
					temp = temp->Next;
				}

				if (temp == Head) // Если элемент, который надо удалить, первый
				{
					Head = temp->Next;
				}
				else
				{
					helping->Next = temp->Next;
				}
				free(temp);
				Count--; // Уменьшаю размер списка
			}
		};

		//Функция получения индекса элемента по значению
		void Index(long element)
		{
			Elem* current = this->Head;
			int ind = 0;
			if ((current->data) == element)
			{
				std::cout << "Индекс элемента: " << ind << std::endl;
			}
			else
			{
				while (((current->data) != element) && (ind != Count - 1))
				{
					current = current->Next;
					ind++;
				}
				if (ind != 0)
					std::cout << "Индекс элемента: " << ind << std::endl;
			}
		};


		//Функция вывода на экран
		void Print()
		{
			if (!Head) { std::cout << "Список пуст" << std::endl; }
			else {
				Elem* temp = Head;
				do {
					std::cout << temp->data << " "; // Вывод значения элемента p
					temp = temp->Next; // Переход к следующему узлу
				} while (temp != NULL);
			}
		};


		// Получить количество
		void GetCount()
		{
		std::cout << Count;
		};


		//Сумма всех значений
		void Summa()
		{
			long sum = 0;
			Elem* current = this->Head;
			for (int i = 0; i < Count; i++)
			{
				sum = sum + current->data;
				current = current->Next;
			}
			std::cout << sum;
		};
		

		//Среднее значение
		void Srednee()
		{
			long sum = 0;
			Elem* current = this->Head;
			for (int i = 0; i < Count; i++)
			{
				sum = sum + current->data;
				current = current->Next;
			}
			int sr = sum / Count;
			std::cout << sr;	
		};


		//Значение минимального элемента
		void Min()
		{
			Elem* current = this->Head;
			long minim = current->data;
			for (int i = 0; i < Count; i++)
			{
				if (current->data < minim)
					minim = current->data;
				current = current->Next;
			}
			std::cout << minim;
		};


		//Значение максимального элемента
		void Max()
		{
			Elem* current = this->Head;
			long maxim = current->data;
			for (int i = 0; i < Count; i++)
			{
				if (current->data > maxim)
					maxim = current->data;
				current = current->Next;
			}
			std::cout << maxim;
		};


		//Полная очистка контейнера
		void Clear()
		{
			while (Head) {
				Delete(0);
			}
		};
};




