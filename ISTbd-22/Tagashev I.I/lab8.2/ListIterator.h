#pragma once
#include <iostream>
#include "Node.h"
#include <algorithm>


class ListIterator : public std::iterator<std::input_iterator_tag, int>
{
	friend class List;
private:
	Node* node;
public:
	ListIterator(Node* node) : node(node) {}
	ListIterator(const ListIterator& it) : node(it.node) {}

	bool operator!=(ListIterator const& other) const;

	bool operator==(ListIterator const& other) const;

	typename ListIterator::reference operator*() const {
		return node->data;
	}

	ListIterator& operator++();
};