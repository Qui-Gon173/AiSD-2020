#include "Node.h"

Node::Node(int data, Node* prev, Node* next)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}

Node * Node::get_prev()
{
	return this->prev;
}
Node* Node::get_next()
{
	return this->next;
}
int Node::get_data()
{
	return this->data;
}