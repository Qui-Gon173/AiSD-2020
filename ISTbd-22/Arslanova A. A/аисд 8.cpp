#include <iostream>
#include "Node.h"
using namespace std;


class List
{

public:
	List();
	~List();
	void pop_front();
	void push_front(unsigned long data);
	void push_back(unsigned long data);
	void clear();
	int GetSize() { return Size; }
	unsigned long operator[](const int index);
	void insert(unsigned long data, int index);
	void removeAt(int index);
	int GetIndex(unsigned long value);
	void GetValue(int index);
	unsigned long sum();
	unsigned long srzn();
	unsigned long min();
	unsigned long max();
	void Print();
private:
	int Size;
	Node* head;
};


List::List()
{
	Size = 0;
	head = nullptr;
}


List::~List()
{
	clear();
}


void List::pop_front()
{
	Node* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

void List::push_back(unsigned long data)
{
	if (head == nullptr)
	{
		head = new Node(data);
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

unsigned long List::operator[](const int index)
{
	int counter = 0;

	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

void List::push_front(unsigned long data)
{
	head = new Node(data, head);
	Size++;
}

void List::insert(unsigned long data, int index)
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

void List::GetValue(int index)
{
	Node* current = this->head;
	int i = 0;
	if ((current->data) == index)
	{
		cout << "Значение искомого элемента: " << current;
	}
	else
	{
		while (((current->data) != index) && (i != Size - 1))
		{
			current = current->pNext;
			i++;
		}
		if (i != 0) 
			cout << "Индекс искомого элемента " << current << endl;
	};
}

int List::GetIndex(unsigned long data)
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
}

unsigned long List::sum()
{
	unsigned long sum = 0;
	Node* current = this->head;
	while (current->pNext != nullptr)
	{
		sum += current->data;
		current = current->pNext;
	}
	return sum;
}

unsigned long List::srzn()
{
	unsigned long average;
	average = sum() / Size;
	return average;
}

unsigned long List::min()
{
	Node* current = this->head;
	unsigned long min = current->data;
	while ((current->pNext) != nullptr)
	{
		if (current->data < min)
			min = current->data;
		current = current->pNext;
	}
	return min;
}

unsigned long List::max()
{
	Node* current = this->head;
	unsigned long max = current->data;
	while ((current->pNext) != nullptr)
	{
		current = current->pNext;
		if (current->data > max)
			max = current->data;

	}
	return max;
}

void List::Print()
{
	Node* current = this->head;
	for (int i = 0; i < Size; i++)
	{
		cout << current->data << "    ";
		current = current->pNext;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	List lst;
	lst.push_back(5);
	lst.push_back(7);
	lst.push_back(10);
	lst.push_back(15);
	lst.push_back(48);
	lst.push_back(12);
	lst.push_back(4);
	lst.push_back(2);
	lst.push_back(67);
	lst.push_back(29);
	lst.push_back(35);
	lst.push_back(8);

	cout << "Вывод списка: " << endl;
	lst.Print();

	cout << endl << "Добавление элемента в конец: " << endl;
	lst.push_back(8);
	lst.Print();

	cout << endl << "Вывод размера: " << endl;
	int s = lst.GetSize();
	cout << s;

	cout << endl << "Вставка элемента по индексу: " << endl;
	lst.insert(99, 4);
	lst.Print();

	cout << endl << "Удаление по индексу: " << endl;
	lst.removeAt(4);
	lst.Print();

	cout << endl << "Получение индекса по значению элемента: ";
	int l = lst.GetIndex(10);
	cout << l << endl;

	cout << "Получение элемента по индексу: " << lst[5] << endl;

	cout << "Сумма элементов: " << lst.sum() << endl;

	cout << "Среднее значение: " << lst.srzn() << endl;

	cout << "Min: " << lst.min() << endl;

	cout << "Max: " << lst.max() << endl;

	lst.clear();
	return 0;
}
