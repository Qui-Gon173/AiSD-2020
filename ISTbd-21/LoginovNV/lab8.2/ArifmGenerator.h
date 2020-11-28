#pragma once
#include "ArifmIter.h"

class ArifmGenerator
{
private:
    float a_1;
    float d;
    int n;

public:
    ArifmGenerator(float firstElem, float raznost, int count);

	typedef ArifmIter iterator;
	typedef ArifmIter const_iterator;

	iterator begin()
	{
		return iterator(a_1, d, 1);
	}

	iterator end()
	{
		return iterator(a_1, d, n + 1);
	}

	const_iterator begin() const
	{
		return iterator(a_1, d, 0);
	}
	const_iterator end() const
	{
		return iterator(a_1, d, n);
	}

};

