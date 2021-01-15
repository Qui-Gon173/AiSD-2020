#pragma once
class Node
{
	friend class _iterator;
public:
	Node* pNext;
	unsigned long data;

	Node(unsigned long data = unsigned long(), Node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};