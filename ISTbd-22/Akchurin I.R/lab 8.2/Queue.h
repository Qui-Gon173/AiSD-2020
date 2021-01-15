#pragma once
#include "Element.h"
#include "QueueIterator.h"
#include "Generator.h"

class Queue
{
private:
	Element* tail;
	Element* head;
	int Size;

public:
	typedef QueueIterator iterator;
	typedef QueueIterator const_iterator;

	iterator begin()
	{
		return iterator(tail);
	}

	iterator end()
	{
		return iterator(head->getPrev());
	}

	const_iterator begin() const
	{
		return iterator(tail);
	}
	const_iterator end() const
	{
		return iterator(head);
	}

	Queue();

	void addNumber(int number);//���������� ������ ��������
	void addNumbers(int numbers[], int count);//���������� ���������� ���������

	void checkLast();//����������� ��������� ������� 

	int extractLast();//������� ��������� �������
	int* extractLast(int count);//������� ��������� ��������� � �����


	Queue remake(int count);//������� n ��������� � ����� ���������


	void display();//������� �������
	void clearAll();//�������� �������

	int getSize()//������� ���������� ��������� � �������
	{
		return Size;
	}

	int sum();//�����
	int average();//������� ��������
	int min();//����������� ��������
	int max();//������������ ��������

	void generate(int firstElem, int raznost, int count);
};