#pragma once
#include <iostream>
#include "Node.h"
#include "QueueIterator.h"

class Queue
{
private:

	Node* rear;
	Node* head;
	int size;

public:

	// ���������� ���������
	typedef QueueIterator iterator;
	typedef QueueIterator const_iterator;

	iterator begin()
	{
		return iterator(rear);
	}

	iterator end()
	{
		return iterator(head->next);
	}

	const_iterator begin() const
	{
		return iterator(rear);
	}
	const_iterator end() const
	{
		return iterator(head);
	}
	
	Queue();

	// �������� ������� � �������
	void push(float number);

	// �������� ��������� ��������� � �������
	void pushSomeElements(float array[], int size);

	// ����������� ������� � ����� �������
	void lookAtLast();

	// ������� ���� ������� 
	float pop();

	// ��������� n ��-�� � ����� ���������
	Queue transferElements(int count);

	// ������� ��������� ���������
	float* popElements(int count);

	// ������� ��� �� ������� �� ���������� �������� �������
	void printAll();

	// ������ ������� ����������
	void deleteAll();

	// �������� ���-�� ��������� � �������
	int getSize();

	//�������� c���� ���� ��������
	float getSum();

	//�������� ������� �������� ���������
	float getAverageValue();

	//�������� �������� ������������ ��������
	float getMinValue();

	//�������� �������� ������������� ��������
	float getMaxValue();
};