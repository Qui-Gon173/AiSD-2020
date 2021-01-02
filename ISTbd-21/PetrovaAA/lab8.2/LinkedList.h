#pragma once
#include "Node.h"
#include "Iterator.h"
#include <iostream>
class LinkedList
{
	int size;
	Node* head;
	Node* tail;

public:

	typedef Iterator const_iterator;

	const_iterator begin() const {
		return const_iterator(this->head);
	};

	const_iterator end() const {
		return const_iterator(this->tail->next);
	};

	LinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	int GetSize()
	{
		return this->size;
	}

	void SetSize(int size)
	{
		this->size = size;
	}

	Node* GetHead()
	{
		return this->head;
	}

	void SetHead(Node* head)
	{
		this->head = head;
	}

	Node* GetTail()
	{
		return this->tail;
	}

	void SetTail(Node* tail)
	{
		this->tail = tail;
	}

	void AddElement(long elem)
	{
		Node* tmp = new Node(elem);

		if (size == 0)
		{
			head = new Node(elem);
			tail = head;
		}
		else 
		{
			tail->next = tmp;
			tail->next->prev = tail;
			tail = tmp;
		}
		
		size++;
	}


	void DeleteElement(int c)
	{
		Node* tmp = this->head;

		if (head == tail)
		{
			delete tmp;
			size--;
		}
		else
		{
			if (c == 1)
			{
				head = head->next;
				delete head->prev;
				head->prev = nullptr;
			}

			if (c == size)
			{

				tail = tail->prev;
				delete tail->next;
				tail->next = nullptr;
			}

			if ((c > 1) && (c < size))
			{
			    for (int i = 1; i < c; i++)
				{
					tmp = tmp->next;
				}

				(tmp->prev)->SetNext(tmp->next);
				(tmp->next)->SetPrev(tmp->prev);
				delete tmp;
			}
			size--;
		}
	}

	void PrintList()
	{
		Node* tmp = this->GetHead();
		int position = 1;

		if (this->GetSize() == 0)
		{
			std::cout << std::endl;
			std::cout << "Список пуст." << std::endl << std::endl;
		}
		else
		{
			while (tmp != nullptr)
			{
				std::cout << position << ") ";
				long elem1 = tmp->elem;
				std::cout << tmp->elem;
				std::cout << std::endl;
				tmp = tmp->next;
				position++;
			}
		}

	}

	void PrintReversedList()
	{
		Node* tmp = this->GetTail();
		int position = 1;

		if (this->GetSize() == 0)
		{
			std::cout << std::endl;
			std::cout << "Список пуст." << std::endl << std::endl;
		}
		else
		{
			while (tmp != nullptr)
			{
				std::cout << position << ") ";
				long elem1 = tmp->elem;
				std::cout << tmp->elem;
				std::cout << std::endl;
				tmp = tmp->prev;
				position++;
			}
		}
	}

	long GetSum()
	{
		int sum = 0;

		if (this->GetSize() == 0)
		{
			std::cout << std::endl;
			std::cout << "Список пуст." << std::endl << std::endl;
		}
		else
		{
			for(Node* tmp = this->GetHead(); tmp != nullptr; tmp = tmp->next)
			{
				sum += tmp->elem;
			}
		}

		return sum;
	}

	long SearchMax()
	{
		long max = -2147483637;

		if (this->GetSize() == 0)
		{
			std::cout << std::endl;
			std::cout << "Список пуст." << std::endl << std::endl;
		}
		else
		{
			for (Node* tmp = this->GetHead(); tmp != nullptr; tmp = tmp->next)
			{
				if (tmp->elem > max)
					max = tmp->elem;
			}
		}

		return max;
	}

	long SearchMin()
	{
		long min = 2147483637;

		if (this->GetSize() == 0)
		{
			std::cout << std::endl;
			std::cout << "Список пуст." << std::endl << std::endl;
		}
		else
		{
			for (Node* tmp = this->GetHead(); tmp != nullptr; tmp = tmp->next)
			{
				if (tmp->elem < min)
					min = tmp->elem;
			}
		}

		return min;
	}

	float CountAverageValue()
	{
		int sum = 0;

		if (this->GetSize() == 0)
		{
			std::cout << std::endl;
			std::cout << "Список пуст." << std::endl << std::endl;
		}
		else
		{
			for (Node* tmp = this->GetHead(); tmp != nullptr; tmp = tmp->next)
			{
				sum += tmp->elem;
			}
		}

		return (float)sum / (this->GetSize());
	}

	int SearchIndexOf(long key)
	{
		int index = 0;
		for (Node* tmp = this->GetHead(); tmp != nullptr; tmp = tmp->next)
		{
			if (tmp->elem == key)
			{
				return index;
			}
			index++;
		}
	}

	~LinkedList() {};
};



