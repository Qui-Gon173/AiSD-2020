#pragma once
class Node
{
	friend class ListIterator;
public:
	int data;
	Node *next;
	Node *prev;

	Node()
	{
		prev = nullptr;
		next = nullptr;
	}
	Node(int data, Node* prev = nullptr, Node* next = nullptr)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
	Node* get_prev()
	{
		return this->prev;
	}
	Node* get_next()
	{
		return this->next;
	}
	int get_data()
	{
		return this->data;
	}

};