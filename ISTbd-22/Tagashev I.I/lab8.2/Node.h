#pragma once
class Node
{
	friend class ListIterator;
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data, Node* prev = nullptr, Node* next = nullptr);
	Node* get_prev();
	Node* get_next();
	int get_data();
};