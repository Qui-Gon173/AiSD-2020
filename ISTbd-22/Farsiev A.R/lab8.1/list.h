#pragma once
#include <iostream>


class List;
class Elem
{
	long data;
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
		int Count;

	public:
		List()
		{
			Head = 0;
			Tail = 0;
			Count = 0;

		}

		void Add(long data)
		{
			Elem* temp = new Elem(data, NULL);
			if (Head != NULL)
			{
				Tail->Next = temp;
				Tail = temp;
				Count += 1;
			}
			else
			{
				Head = Tail = temp;
			}
		};

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

		void Delete(int x)
		{
			if ((Head != NULL) && (x < Count) && (x >= 0))
			{
				Elem* temp = Head;
				Elem* helping = Head;
				for (int i = 0; i < x; i++)
				{
					helping = temp;
					temp = temp->Next;
				}

				if (temp == Head)
				{
					Head = temp->Next;
				}
				else
				{
					helping->Next = temp->Next;
				}
				free(temp);
				Count--;
			}
		};

		void Index(long element)
		{
			Elem* current = this->Head;
			int ind = 0;
			if ((current->data) == element)
			{
				std::cout << "Element index: " << ind << std::endl;
			}
			else
			{
				while (((current->data) != element) && (ind != Count - 1))
				{
					current = current->Next;
					ind++;
				}
				if (ind != 0)
					std::cout << "Element index: " << ind << std::endl;
			}
		};

		void Print()
		{
			if (!Head) { std::cout << "List is empty" << std::endl; }
			else {
				Elem* temp = Head;
				do {
					std::cout << temp->data << " ";
					temp = temp->Next;
				} while (temp != NULL);
			}
		};

		void GetCount()
		{
		std::cout << Count;
		};

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

		void Clear()
		{
			while (Head) {
				Delete(0);
			}
		};
};
