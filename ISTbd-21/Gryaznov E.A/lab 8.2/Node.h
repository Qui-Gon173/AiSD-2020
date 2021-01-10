#pragma once
class Node
{
	friend class ListIterator;
public:
	int data;
	Node *pNext;

	Node()
	{
		pNext = nullptr;
	}
	Node(int data, Node* next = nullptr)
	{
		this->data = data;
		this->pNext = next;
	}

	Node* get_next()
	{
		return this->pNext;
	}
	int get_data()
	{
		return this->data;
	}

};
