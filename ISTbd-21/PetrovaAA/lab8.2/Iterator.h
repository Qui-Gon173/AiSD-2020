#pragma once
#include <iostream>
#include <algorithm>
#include "Node.h"

class Iterator : public std::iterator<std::input_iterator_tag, long>
{
	friend class LinkedList;

private:
	Node* node;
public:
	Iterator(Node* node) : node(node) {}
	Iterator(const Iterator& iterator) : node(iterator.node) {}

	bool operator!=(Iterator const& other) const {
		return node != other.node;
	}

	bool operator==(Iterator const& other) const {
		return node == other.node;
	}

	typename Iterator::reference operator*() const {
		return node->elem;
	}

	Iterator& operator++() {
		this->node = this->node->next;
		return *this;
	}
};
