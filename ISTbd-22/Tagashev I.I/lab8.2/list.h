#pragma once
#include"Node.h"
#include "ListIterator.h"
class List
{
private:
	int size = 0;
	Node* head;
	Node* tail;
public:
	typedef ListIterator const_iterator;
	const_iterator begin() const {
		return const_iterator(head);
	};
	const_iterator end() const {
		return const_iterator(tail->next);
	};

	List();

	int get_size();


	void append(int data);
	void insert(int data, int ind);
	void delete_ind(int ind);
	void delete_front();
	void search_ind(int data);
	void print_list();
	void print_list_reverse();
	void properties_list();

};