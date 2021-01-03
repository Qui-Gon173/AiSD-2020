#include <iostream>

using namespace std;

class DoublyLinkedList
{
public:

	DoublyLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	~DoublyLinkedList()
	{
		clear();
	}

	int getSize()
	{
		return size;
	}
	float getSum()
	{
		Node* current = this->head;
		float sum = current->data;
		for (int i = 0; i < size - 1; i++)
		{
			current = current->next;
			sum += current->data;
		}
		return sum;
	}
	float getAverage()
	{
		float average = getSum() / size;
		return average;
	}
	float getMin()
	{
		Node* current = this->head;
		float min = current->data;
		for (int i = 0; i < size - 1; i++)
		{
			current = current->next;
			if (current->data < min)
				min = current->data;
		}
		return min;
	}
	float getMax()
	{
		Node* current = this->head;
		float max = current->data;
		for (int i = 0; i < size - 1; i++)
		{
			current = current->next;
			if (current->data > max)
				max = current->data;
		}
		return max;
	}

	void push(float data)
	{
		Node* current = new Node(data);

		if (head != nullptr)
		{
			current->prev = tail;
			tail->next = current;
			tail = current;
		}
		else
		{
			current->prev = nullptr;
			head = tail = current;
		}
		++size;
	}
	void pop()
	{
		if (size == 1)
			delete tail;
		else
		{
			Node* tmp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete tmp;
		}
		--size;
	}

	void shift()
	{
		if (size == 1)
			delete head;
		else
		{
			Node* tmp = head;
			head = head->next;
			head->prev = nullptr;
			delete tmp;
		}
		--size;
	}
	void unshift(float data)
	{
		Node* current = new Node(data);

		if (tail != nullptr)
		{
			current->next = head;
			head->prev = current;
			head = current;
		}
		else
		{
			current->next = nullptr;
			head = tail = current;
		}
		++size;
	}

	void insert(float data, int index)
	{
		if (index > size || index < 0)
			std::cout << "Incorrect index" << endl;
		else if (index == 0)
			unshift(data);
		else if (index == size)
			push(data);
		else
		{
			if (index < size / 2)
			{
				Node* current = this->head;
				Node* temp;

				for (int i = 0; i < index - 1; i++)
				{
					current = current->next;
				}
				Node* newNode = new Node(data, current->next, current->prev);

				newNode->prev = current;

				temp = current->next;
				current->next = newNode;
				temp->prev = newNode;

				newNode->next = temp;
			}
			else
			{
				Node* current = this->tail;
				Node* temp;

				for (int i = size - 1; i > index; i--)
				{
					current = current->prev;
				}
				Node* newNode = new Node(data, current->next, current->prev);

				newNode->next = current;

				temp = current->prev;
				current->prev = newNode;
				temp->next = newNode;

				newNode->prev = temp;
			}
			++size;
		}
	}
	void remove(int index)
	{
		if (index > size - 1 || index < 0)
			std::cout << "Incorrect index" << endl;
		else if (index == 0)
			shift();
		else if (index == size - 1)
			pop();
		else
		{
			if (index < size / 2)
			{
				Node* current = this->head;
				Node* tmp;

				for (int i = 0; i < index - 1; i++)
				{
					current = current->next;
				}
				Node* toDelete = current->next;
				tmp = toDelete->next;

				current->next = toDelete->next;
				tmp->prev = toDelete->prev;

				delete toDelete;
			}
			else
			{
				Node* current = this->tail;
				Node* tmp;

				for (int i = size - 1; i > index + 1; i--)
				{
					current = current->prev;
				}
				Node* toDelete = current->prev;
				tmp = toDelete->prev;

				current->prev = toDelete->prev;
				tmp->next = toDelete->next;

				delete toDelete;
			}
			--size;
		}
	}

	int indexOf(float data)
	{
		int index;
		Node* current = this->head;
		for (index = 0; index < size; index++)
		{
			if (current->data == data)
				break;
			current = current->next;
		}
		return index < size ? index : -1;
	}

	void clear()
	{
		while (size)
		{
			shift();
		}
	}

	void printFromBegin()
	{
		std::cout << "Printing head-to-tail:\n\n";
		if (size != 0)
		{
			Node* current = head;
			while (current != nullptr)
			{
				std::cout << current->data << " ";
				current = current->next;
			}
			std::cout << "\n\n";
		}
		else
			std::cout << "The list is empty\n\n";
	}
	void printFromEnd()
	{
		std::cout << "Printing tail-to-head:\n\n";
		if (size != 0)
		{
			Node* current = tail;
			while (current != nullptr)
			{
				std::cout << current->data << " ";
				current = current->prev;
			}
			std::cout << "\n\n";
		}
		else
			std::cout << "The list is empty\n\n";
	}

	float& operator[](const int index)
	{
		int counter;
		if (index < size / 2)
		{
			counter = 0;
			Node* current = this->head;
			while (current != nullptr)
			{
				if (counter == index)
				{
					return current->data;
				}
				current = current->next;
				++counter;
			}
		}
		else
		{
			counter = size - 1;
			Node* current = this->tail;
			while (current != nullptr)
			{
				if (counter == index)
				{
					return current->data;
				}
				current = current->prev;
				--counter;
			}
		}
	}

private:

	struct Node
	{
		Node* next;
		Node* prev;
		float data;
		Node(float data, Node* next = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};

	Node* head;
	Node* tail;
	int size;
};


int main()
{
	DoublyLinkedList list;

	list.push(2);
	list.push(2);
	list.push(8);
	list.unshift(7);
	list.unshift(7);
	list.unshift(7);
	list.insert(322, 3);

	//list.pop();
	//list.shift();

	list.printFromBegin();

	list.remove(list.getSize() / 2);

	//list.printFromBegin();
	list.printFromEnd();

	//std::cout << "Size: " << list.getSize() << endl;

	//std::cout << "Sum: " << list.getSum() << endl;
	//std::cout << "Avg: " << list.getAverage() << endl;

	//std::cout << "Min: " << list.getMin() << endl;
	//std::cout << "Max: " << list.getMax() << endl;

	float element;
	std::cout << "\nElement to search for: ";
	cin >> element;
	if (list.indexOf(element) != -1)
		std::cout << "Your element's index: " << list.indexOf(element) << endl;
	else
		std::cout << "Your element was not found" << endl;


	std::cout << "List cleared\n\n";
	list.clear();

	std::cout << "Size: " << list.getSize() << "\n\n";
	list.printFromBegin();


	return 0;
}