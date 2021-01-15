#pragma once
#include <iostream>

class Queue
{
private:
	struct Node
	{
		Node* next;
		float data;
		Node(Node* next, float data)
		{
			this->next = next;
			this->data = data;
		}
	};

	Node* rear;
	Node* head;
	int size;

public:
	
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