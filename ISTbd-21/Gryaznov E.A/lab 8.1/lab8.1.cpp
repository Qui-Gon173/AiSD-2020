#include <iostream>
using namespace std;

//расширяемый список
template<typename T>
class List
{
 public:
	List();
	~List();

	//добавление элемента в начало списка
	void push_front(T data);

	//добавление элемента в конец списка
	void push_back(T data);

	//добавление элемента в список по указанному индексу
	void insertInd(T data, int index);

	//поиск индекса по значению
	int searchIndex(T data);
	
	//удаление первого элемента в списке
	void pop_front();
	
	//удаление последнего элемента в списке
	void pop_back();

	//удаление элемента в списке по указанному индексу
	void removeInd(int index);
	
	// очистить список
	void clear();
	
	// получить количество елементов в списке
	int getSize();

	// перегруженный оператор [] 
	T& operator[](const int index);

	//сумма всех элементов
	int sum();

	//среднее значение
	int medium();

	//Значение минимального элемента
	int min();

	//Значение максимального элемента
	int max();

	//распечатка списка
	void print();

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
	int size;
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	size = 0;
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
	return sum() / size;
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}


template<typename T>
void List<T>::print()
{
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->pNext;
	}
    
	cout << endl;
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
	size++;
}


template<typename T>
void List<T>::clear()
{
	while (size)
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
int List<T>::searchIndex(T data)
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
int List<T>::getSize()
{
	return size;
}


template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}


template<typename T>
void List<T>::insertInd(T data, int index)
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

		size++;
	}
}


template<typename T>
void List<T>::removeInd(int index)
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
		size--;
	}
}


template<typename T>
void List<T>::pop_back()
{
	removeInd(size - 1);
}


int main()
{
	setlocale(LC_ALL, "ru");

	cout << "Добавление элементов в начало списка " << endl;
	List <unsigned int> lst;
	lst.push_front(5);
	lst.push_front(21);
	lst.push_front(14);
	lst.push_front(2);
	lst.print();
	cout << endl;
	
	cout << "Добавление элемента в конец списка " << endl;
	lst.push_back(7);
	lst.print();
	cout << endl;

	cout << "Удаление последнего элемента в списке" << endl;
	lst.pop_back();
	lst.print();
	cout << endl;

	cout << "Поиск индекса по значению (21)" << endl;
	cout <<"Индекс = "<< lst.searchIndex(21) << endl; 
	cout << endl;

	cout << "Удаление элемента по индексу (0)" << endl;
	lst.removeInd(0);
	lst.print();
	cout << endl;

	cout << "Добавление элемента(8) по индексу(0)" << endl;
	lst.insertInd(8, 0);
	lst.print();
	cout << endl;

	cout << "Количество элементов в контейнере: " << lst.getSize() << endl;
	
	cout << "Сумма всех значений: " << lst.sum() << endl;

	cout << "Среднее значение: " << lst.medium() << endl;

	cout << "Значение минимального элемента: " << lst.min() << endl;

	cout << "Значение максимального элемента: " << lst.max() << endl;
	cout << endl;

	cout << "Полная очистка контейнера:";
	lst.clear();
	lst.print();
	cout << "Контейнер пуст!" << endl;
	
	return 0;
}
