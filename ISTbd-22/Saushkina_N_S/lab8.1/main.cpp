#include <iostream>
using namespace std;

//расширяемый список
template<typename T>
class List
{
public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(T data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	T& operator[](const int index);

	//добавление элемента в начало списка
	void push_front(T data);

	//поиск индекса по значению
	int searchindex(T data);

	//добавление элемента в список по указанному индексу
	void insert(T data, int index);

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
	int Size;
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
int List<T>::sum()
{
	Node<T>* current = this->head;
	int all = 0;
	while (current != nullptr)
	{
		all += current->data;
		current = current->pNext;
	}
	return all;
}
template<typename T>
int List<T>::min()
{
	Node<T>* current = this->head;
	int x = current->data;
	while (current != nullptr)
	{
		if (current->data < x) x = current->data;
		current = current->pNext;
	}
	return x;
}
template<typename T>
int List<T>::max()
{
	Node<T>* current = this->head;
	int x = current->data;
	while (current != nullptr)
	{
		if (current->data > x) x = current->data;
		current = current->pNext;
	}
	return x;
}
template<typename T>
int List<T>::medium()
{
	
	return sum() / Size;;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}
template<typename T>
void List<T>::print()
{
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->pNext;
	}

}
template<typename T>
void List<T>::push_back(T data)
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
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

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
int List<T>::searchindex(T data)
{
	int counter = 0;

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
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
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
void List<T>::pop_back()
{
	removeAt(Size - 1);
}


int main()
{

	setlocale(LC_ALL, "ru");


	List<int> lst;
	lst.push_front(5);
	lst.push_front(7);
	lst.push_front(101);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "pop_back " << endl << endl;

	lst.pop_back();

	for (int i = 0; i < lst.GetSize(); i++) // еще один вариант для распечатки
	{
		cout << lst[i] << endl;//обращение к элементу по индексу
	}

	cout<<"index of 101"<<lst.searchindex(101)<<endl; //поиск индекса по элементу

	lst.insert(9, 0);//добавление по индексу

    lst.removeAt(1);//удаление по индексу

	lst.print();//метод для распечатки
	cout << endl;
	cout <<"sum"<< lst.sum() << endl;
	cout << endl;
	cout << "medium" << lst.medium() << endl;
	cout << endl;
	cout << "min" << lst.min() << endl;
	cout << endl;
	cout << "max" << lst.max() << endl;
	return 0;
}