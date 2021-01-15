#pragma once
class Node
{
public:
	Node* prev;
	Node* next;
	long elem;

	Node()
	{
		prev = nullptr;
		next = nullptr;
		elem = 0;
	}

	Node(long elem, Node* prev = nullptr, Node* next = nullptr)
	{
		this->elem = elem;
		this->next = next;
		this->prev = prev;
	}

	Node* GetPrev()
	{
		return this->prev;
	}

	void SetPrev(Node* prev)
	{
		this->prev = prev;
	}

	Node* GetNext()
	{
		return this->next;
	}

	void SetNext(Node* next)
	{
		this->next = next;
	}

	long GetElem()
	{
		return this->elem;
	}

	void SetElem(long elem)
	{
		this->elem = elem;
	}

	~Node() {}
};

