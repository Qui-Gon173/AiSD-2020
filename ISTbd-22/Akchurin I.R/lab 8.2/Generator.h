#pragma once
#include <iostream>
#include <algorithm>
#include "GeneratorIterator.h"
#include "Element.h"


class Generator
{
private:
	int a; //Первый член арифметической прогрессии
	int d; //Шаг арифметической прогрессии
	int n;

public:
	Generator(int firstNumber, int step, int kol)
	{
		a = firstNumber;
		d = step;
		n = kol;
	};

	typedef GeneratorIterator iterator;
	typedef GeneratorIterator const_iterator;

	iterator begin() { return iterator(a, d, 1); }

	iterator end() { return iterator(a, d, n + 1); }

	const_iterator begin() const { return iterator(a, d, 0); }

	const_iterator end() const { return iterator(a, d, n); }
};
