#pragma once
#include "Element.h"

class Queue
{
private:
	Element* tail;
	Element* head;
	int Size;//���������� ���������

public:
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
};
