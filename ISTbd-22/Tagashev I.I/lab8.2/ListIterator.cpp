#include "ListIterator.h"

bool ListIterator::operator!=(ListIterator const& other) const {
	return node != other.node;
}
bool ListIterator::operator==(ListIterator const& other) const {
	return node == other.node;
}

ListIterator& ListIterator::operator++() {
	node = node->next;
	return *this;
}
