#pragma once
#include <iostream>
#include "Node.cpp"
#include "iterator.cpp"

using namespace std;

class List
{
public:
List();
~List();



	//удаление первого элемента в списке
	void pop_front();
	//добавление элемента в конец списка
	void push_back(int data);
	// очистить список
	void clear();
	// получить количество елементов в списке
	int GetSize() { return Size; }
	// перегруженный оператор [] 
//	int& operator[](const int index);
	//добавление элемента в начало списка
	void push_front(int data);
	//поиск индекса по значению
	int searchindex(int data);
	//добавление элемента в список по указанному индексу
	void insert(int data, int index);
	//удаление элемента в списке по указанному индексу
	void removeAt(int index);
	//удаление последнего элемента в списке
	void pop_back();
	//распечатка списка
	void print();
	//сумма всех элементов
	int sum();
	//среднее значение
	int medium();
	int min();
	int max();
private:

    int Size;
    Node *head;//первый элемент-голова
  
     
public:
    
    typedef my_iterator const_iterator;
    const_iterator begin() const{
        return const_iterator(head);
    };
    const_iterator end() const{
        return const_iterator(nullptr);
    };
 
};

List::List() : head(nullptr)
{
    Size=0;
}
List::~List()
{
    clear();
}




// int & List::operator[](const int index)
// {
//     int counter=0;
//     Node *current=this->head;
//     while(current!=nullptr)
//     {
//         if(counter==index){
//             return current->data;
//         }
//         current=current->pNext;
//         counter++;
//     }
// }

int List::sum()
{
	Node* current = this->head;
	int all = 0;
	while (current != nullptr)
	{
		all += current->data;
		current = current->pNext;
	}
	return all;
}

int List::min()
{
	Node* current = this->head;
	int x = current->data;
	while (current != nullptr)
	{
		if (current->data < x) x = current->data;
		current = current->pNext;
	}
	return x;
}

int List::max()
{
	Node* current = this->head;
	int x = current->data;
	while (current != nullptr)
	{
		if (current->data > x) x = current->data;
		current = current->pNext;
	}
	return x;
}

int List::medium()
{
	
	return sum() / Size;;
}


void List::pop_front()
{
	Node* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

void List::print()
{
	Node* current = this->head;

	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->pNext;
	}

}

void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
        Node *current=head;
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

	Size++;
}


void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}

int List::searchindex(int data)
{
	int counter = 0;

	Node* current = this->head;

	while (current != nullptr)
	{
		if (current->data == data)
		{
			return counter;
		}
		current = current->pNext;
		counter++;
	}
	return -1;
}


void List::push_front(int data)
{
	head = new Node(data, head);
	Size++;
}


void List::insert(int data, int index)
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

		Size++;
	}





}


void List::removeAt(int index)
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


		Node* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

void List::pop_back()
{
	removeAt(Size - 1);
}
