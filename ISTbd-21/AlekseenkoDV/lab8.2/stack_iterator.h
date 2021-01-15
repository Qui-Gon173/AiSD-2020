#pragma once

#include <iterator>
#include "stack.h"
#include "geometric_progression_generator.h"

using namespace std;

class StackIterator : public iterator<input_iterator_tag, int>
{
	private:
		int* pointer;
	public:
		StackIterator(int* pointer) : pointer(pointer) {};
		StackIterator(const StackIterator& iteration) : pointer(iteration.pointer) {};
		bool operator!=(StackIterator const& another) const;
		typename StackIterator::reference operator*() const;
		bool operator==(StackIterator const& other) const;
		StackIterator& operator++();
};

bool StackIterator::operator!=(StackIterator const& another) const
{
	return pointer != another.pointer;
}

typename StackIterator::reference StackIterator::operator*() const
{
	return *pointer;
}

StackIterator& StackIterator::operator++()
{
	--pointer;
	return *this;
}

bool StackIterator::operator==(StackIterator const& another) const
{
	return pointer == another.pointer;
}