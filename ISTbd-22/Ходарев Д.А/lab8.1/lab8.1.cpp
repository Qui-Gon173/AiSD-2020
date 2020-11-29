#include <iostream>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void delete_first_element();

	void add_element_back(T data);

	void clear();

	double getSize() { return Size; }

	T& operator[](const double index); 

	void add_element_front(T data); 

	double search_index(T data); 

	void add_element_index(T data, double index);

	void delete_index(double index); 

	void delete_element_back(); 

	void print_list(); 

	double sum();

	double medium();

	double min();
	double max();

private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	double Size;
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
double List<T>::sum()
{
	Node<T>* current = this->head;
	double all = 0;
	while (current != nullptr)
	{
		all += current->data;
		current = current->pNext;
	}
	return all;
}
template<typename T>
double List<T>::min()
{
	Node<T>* current = this->head;
	double x = current->data;
	while (current != nullptr)
	{
		if (current->data < x) x = current->data;
		current = current->pNext;
	}
	return x;
}
template<typename T>
double List<T>::max()
{
	Node<T>* current = this->head;
	double x = current->data;
	while (current != nullptr)
	{
		if (current->data > x) x = current->data;
		current = current->pNext;
	}
	return x;
}
template<typename T>
double List<T>::medium()
{

	return sum() / Size;;
}

template<typename T>
void List<T>::delete_first_element()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}
template<typename T>
void List<T>::print_list()
{
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->pNext;
	}

}
template<typename T>
void List<T>::add_element_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		delete_first_element();
	}
}


template<typename T>
T& List<T>::operator[](const double index)
{
	double counter = 0;

	Node<T>* current = this->head;

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

template<typename T>
double List<T>::search_index(T data)
{
	double counter = 0;

	Node<T>* current = this->head;

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

template<typename T>
void List<T>::add_element_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::add_element_index(T data, double index)
{

	if (index == 0)
	{
		add_element_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (double i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename T>
void List<T>::delete_index(double index)
{
	if (index == 0)
	{
		delete_first_element();
	}
	else
	{
		Node<T>* previous = this->head;
		for (double i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}
template<typename T>
void List<T>::delete_element_back()
{
	delete_index(Size - 1);
}


int main()
{

	setlocale(LC_ALL, "ru");


	List<double> lst;
	lst.add_element_front(5);
	lst.add_element_front(7);
	lst.add_element_front(101);

	for (double i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "delete_element_back " << endl << endl;

	lst.delete_element_back();

	for (double i = 0; i < lst.getSize(); i++) // еще один вариант для распечатки
	{
		cout << lst[i] << endl;//обращение к элементу по индексу
	}

	cout << "index of 101" << lst.search_index(101) << endl; //поиск индекса по элементу

	lst.add_element_index(9, 0);//добавление по индексу

	lst.delete_index(1);//удаление по индексу

	lst.print_list();//метод для распечатки
	cout << endl;
	cout << "sum" << lst.sum() << endl;
	cout << endl;
	cout << "medium" << lst.medium() << endl;
	cout << endl;
	cout << "min" << lst.min() << endl;
	cout << endl;
	cout << "max" << lst.max() << endl;
	return 0;
}