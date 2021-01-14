#pragma once
#include <iostream>
#include "Node.h"

// наследуем класс итератора
class QueueIterator : public std::iterator<std::input_iterator_tag, float>
{
	friend class Queue;
private:
	Node* currentElement;
public:
	QueueIterator(Node* p);
	QueueIterator(const QueueIterator& it);

	bool operator!=(QueueIterator const& other) const;
	bool operator==(QueueIterator const& other) const;
	typename QueueIterator::reference operator*() const;
	QueueIterator& operator++();
};