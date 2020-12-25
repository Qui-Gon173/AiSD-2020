#pragma once
template<typename T>
class List
{
private:
	int size=0;
	template<typename T>
	class Node
	{
	public:
		T data;
		Node<T> *next;
		Node<T> *prev;
		
		Node()
		{
			prev = nullptr;
			next = nullptr;
			T = nullptr;
		}
		Node(T data, Node<T>* prev = nullptr, Node<T>* next = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
		Node<T>* get_prev()
		{
			return this->prev;
		}
		Node<T>* get_next()
		{
			return this->next;
		}
		T get_data()
		{
			return this->data;
		}
		
	};
	Node<T>* head;
	Node<T>* tail;
public:
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

	
	void append(T data)
	{
		if (size == 0)
		{
			head = new Node<T>(data);
			tail = head;
		}
		else
		{
			Node<T>* tmp = new Node<T>(data);
			tail->next = tmp;
			tail->next->prev = tail;
			tail = tmp;
			
		}
		size++;
	}
	void insert(T data, int ind)
	{
		if (size == 0)
		{
			head = new Node<T>(data);
			tail = head;
		}
		else
		{
			
			Node<T>* tmp = new Node<T>(data);
			Node<T>* Current = head;
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
			Node<T>* Current = head;
			Node<T>* Buff = head;
			Buff = Current->next;
			delete head;
			head = Buff;
		}
		else
		{
			Node<T>* Current = head;
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
			Node<T>* Current = head;
			Node<T>* Buff = head;
			Buff = Current->next;
			delete head;
			head = Buff;
			size--;
		}
	}
	int search_ind(T data)
	{
		//Node<T>* Current = head;
		int ind = 0;
		for (Node<T>* Current = head; Current != nullptr; Current = Current->next)
		{
			if (Current->data == data)
			{
				return ++ind;
				//std::cout << "Индекс искомого эл-та " << ++ind << std::endl;
			}
			ind++;
		}

	}
	void print_list()
	{
		Node<T>* Current = head;
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
		Node<T>* Current = tail;

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
		T sum = 0, avg = 0, min, max;
		min = max = tail->get_data();

		for (Node<T>* Current = tail; Current != nullptr; Current = Current->get_prev())
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

