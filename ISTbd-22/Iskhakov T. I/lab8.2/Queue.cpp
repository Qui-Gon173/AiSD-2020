#include "Queue.h"

Queue::Queue()
{
	size = 0;
	rear = nullptr;
	head = nullptr;
}

// ���������� �������� � �������
void Queue::push(float number)
{
	Node* item = new Node(nullptr, number);
	if (rear != nullptr)
	{
		head->next = item;
		head = item;
		head->next = nullptr;
	}
	else
	{
		head = rear = item;
	}
	size++;
}

// ���������� ���������� ��������� � �������
void Queue::pushSomeElements(float array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		this->push(array[i]);
	}
}

// ���������� ������� � ����� �������
void Queue::lookAtLast()
{
	std::cout << rear->data << std::endl;
}

// ������� ��� ��������
void Queue::printAll()
{
	if (size > 0)
	{
		for (Node* current = rear; current != nullptr; current = current->next)
		{
			std::cout << current->data << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "�����" << std::endl;
	}

}

// �������� ���-�� ��������� � �������
int Queue::getSize()
{
	return size;
}

// ������� ������� �������
float Queue::pop()
{
	float element = 0;
	if (size > 0)
	{
		element = rear->data;
		Node* tmp = new Node(nullptr, 0);
		tmp = rear->next;
		delete rear;
		rear = tmp;
		size--;
	}
	return element;
}

// ������� �������� �������
float* Queue::popElements(int count)
{
	float* resultArr = new float[count - 1];

    for (int i = 0; i < count; i++)
	{
		resultArr[i] = this->pop();
	}

	return resultArr;
}

// ��������� �������� �������
Queue Queue::transferElements(int count)
{
	Queue newQueue;
	float* tmpArray = new float[count - 1];
	tmpArray = this->popElements(count);

	for (int i = 0; i < count; i++)
	{
		newQueue.push(tmpArray[i]);
	}

	return newQueue;
}

// �������� �������
void Queue::deleteAll()
{
	this->popElements(size);
	size = 0;
}

// �������� ����� ���������
float Queue::getSum() 
{
	float sum = 0;
	Node* current = this->rear;
	while (current != nullptr)
	{
		sum += current->data;
		current = current->next;
	}
	return sum;
}

//�������� ������� �������� ���������
float Queue::getAverageValue() 
{
	return getSum()/size;
}

//�������� �������� ������������ ��������;
float Queue::getMinValue()
{
	float min = rear->data;
	Node* current = this->rear;
	while (current != nullptr)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return min;
}

//�������� �������� ������������� ��������
float Queue::getMaxValue()
{
	float max = rear->data;
	Node* current = this->rear;
	while (current != nullptr)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return max;
}
