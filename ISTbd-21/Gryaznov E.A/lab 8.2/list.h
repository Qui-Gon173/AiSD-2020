#pragma once
#include"Node.h"
#include "ListIterator.h"

class List
{
private:
	int size = 0;
	Node* head;
public:
	typedef ListIterator const_iterator;
	const_iterator begin() const {
		return const_iterator(head);
	};
	const_iterator end() const {
		return const_iterator(nullptr);
	};


	List()
	{
		size = 0;
		head = nullptr;
	}
	int get_size()
	{
		return this->size;
	}


	void pop_front()
	{
		Node* temp = head;

		head = head->pNext;

		delete temp;

		size--;

	}


	void print()
	{
		Node* current = this->head;

		while (current != nullptr)
		{
			std::cout << current->data << std::endl;
			current = current->pNext;
		}

	}


	void push_back(int data)
	{
		if (head == nullptr)
		{
			head = new Node(data);
			Node *current = head;
		}
		else
		{
			Node* current = this->head;

			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node(data);

		}
		size++;
	}


	void clear()
	{
		while (size)
		{
			pop_front();
		}
	}


	void search_ind(int data)
	{
		int counter = 0;

		Node* current = this->head;

		while (current != nullptr)
		{
			if (current->data == data)
			{
				std::cout << ++counter << std::endl;
			}
			current = current->pNext;
			counter++;
		}
	}


	void push_front(int data)
	{
		head = new Node(data, head);
		size++;
	}


	void insert(int data, int index)
	{
		if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Node* previous = this->head;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}

			Node* newNode = new Node(data, previous->pNext);

			previous->pNext = newNode;

			size++;
		}
	}


	void removeAt(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Node* previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}


			Node* del = previous->pNext;

			previous->pNext = del->pNext;

			delete del;

			size--;
		}
	}


	void pop_back()
	{
		removeAt(size - 1);
	}
};