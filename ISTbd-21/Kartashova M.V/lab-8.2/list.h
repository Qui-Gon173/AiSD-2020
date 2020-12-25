#pragma once
#include"Node.h"
#include "ListIterator.h"
class List
{
private:
	int size=0;
	Node* head;
	Node* tail;
public:
	typedef ListIterator const_iterator;
    const_iterator begin() const{
        return const_iterator(head);
	};
    const_iterator end() const{
        return const_iterator(tail->next);
	};
 
	List()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	int get_size()
	{
		return this->size;
	}

	
	void append(int data)
	{
		if (size == 0)
		{
			head = new Node(data);
			tail = head;
		}
		else
		{
			Node* tmp = new Node(data);
			tail->next = tmp;
			tail->next->prev = tail;
			tail = tmp;
			
		}
		size++;
	}
	void insert(int data, int ind)
	{
		if (size == 0)
		{
			head = new Node(data);
			tail = head;
		}
		else
		{
			
			Node* tmp = new Node(data);
			Node* Current = head;
			for (int i = 0; i < ind - 1; i++)
			{
				Current = Current->next;
			}
			Current->prev->next = tmp;
			tmp->prev = Current->prev;
			tmp->next = Current;
			Current->prev = tmp;
		}
		size++;
	}
	void delete_ind(int ind)
	{
		if (size == 0)
		{
			Node* Current = head;
			Node* Buff = head;
			Buff = Current->next;
			delete head;
			head = Buff;
		}
		else
		{
			Node* Current = head;
			for (int i = 0; i < ind - 1; i++)
			{
				Current = Current->next;
			}
			if (Current == head)
				head = Current->next;
			Current->prev->next = Current->next;
			Current->next->prev = Current->prev;
			delete Current;
		}
		size--;
	}
	void delete_front()
	{
		while (size != 0)
		{
			Node* Current = head;
			Node* Buff = head;
			Buff = Current->next;
			delete head;
			head = Buff;
			size--;
		}
	}
	void search_ind(int data)
	{
		//Node<T>* Current = head;
		int ind = 0;
		for (Node* Current = head; Current != nullptr; Current = Current->next)
		{
			if (Current->data == data)
			{
				std::cout << ++ind << std::endl;
			}
			ind++;
		}

	}
	void print_list()
	{
		Node* Current = head;
		if (size == 0)
		{
			std::cout << "Список пуст." << std::endl << std::endl;
		}
		else
		{
			while (Current != nullptr)
			{
				std::cout << Current->get_data() << " ";
				Current = Current->next;
			}

		}

	}
	void print_list_reverse()
	{
		Node* Current = tail;

		if (size == 0)
		{
			std::cout << "Список пуст." << std::endl << std::endl;
		}
		else
		{
			while (Current != nullptr)
			{
				std::cout << Current->get_data() << " ";
				Current = Current->prev;

			}

		}

	}
	void properties_list()
	{
		int sum = 0, avg = 0, min, max;
		min = max = tail->get_data();

		for (Node* Current = tail; Current != nullptr; Current = Current->get_prev())
		{
			sum += Current->get_data();
			if (Current->get_data() > max)
			{
				max = Current->get_data();
			}
			if (Current->get_data() < min)
			{
				min = Current->get_data();
			}
		}
		avg = sum / size;
		std::cout << "Переменные:" << std::endl;
		std::cout << "max = " << max << std::endl;
		std::cout << "min = " << min << std::endl;
		std::cout << "sum = " << sum << std::endl;
		std::cout << "avg = " << avg << std::endl;
	}
	
};

