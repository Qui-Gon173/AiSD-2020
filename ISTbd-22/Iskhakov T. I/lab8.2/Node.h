#pragma once
#include <iostream>

class Node
{
	friend class QueueIterator;
public:
	Node* next;
	float data;
	Node(Node* next, float data)
	{
		this->next = next;
		this->data = data;
	}
};
