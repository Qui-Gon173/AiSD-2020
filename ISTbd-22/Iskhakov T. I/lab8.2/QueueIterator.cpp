#include "QueueIterator.h"

QueueIterator::QueueIterator(Node* p)
{
	currentElement = p;
}

QueueIterator::QueueIterator(const QueueIterator& it)
{
	currentElement = it.currentElement;
}

bool QueueIterator::operator!=(QueueIterator const& other) const
{
	return (currentElement != other.currentElement);
}

bool QueueIterator::operator==(QueueIterator const& other) const
{
	return (currentElement == other.currentElement);
}

typename QueueIterator::reference QueueIterator::operator*() const
{
	return currentElement->data;
}

QueueIterator& QueueIterator::operator++()
{
	currentElement = currentElement->next;
	return *this;
}