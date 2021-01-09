#pragma once
#include <iostream>
#include <algorithm>
#include "GeneratorIterator.h"
#include "Elem.h"


class Generator
{
private:
	long b1; // Первый член геометрической прогрессии
	long q; //Знаменатель геометрической прогрессии
	int n; //Порядковый номер члена прогрессии

public:
	Generator(long first, long znamenatel, int kol)
	{
		b1 = first;
		q = znamenatel;
		n = kol;
	};

	typedef GeneratorIterator iterator;
	typedef GeneratorIterator const_iterator;

	iterator begin() { return iterator(b1, q, 1);}

	iterator end() { return iterator(b1, q, n + 1);}

	const_iterator begin() const { return iterator(b1, q, 0);}

	const_iterator end() const { return iterator(b1, q, n);}
};

