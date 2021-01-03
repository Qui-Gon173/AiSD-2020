#pragma once

#include <iostream>
#include <algorithm>
#include "stack.h"

using namespace std;

int sum(stack& stack)
{
	int sum = 0;
	for (auto& i : stack)
		sum += i;
	return sum;
}

void print_Stack(stack& stack)
{
	for (auto& i : stack)
		cout << i << " ";
	cout << endl;
}

float average(stack& stack)
{
	if (stack.return_head() > 0)
		return (float)sum(stack) / (float)stack.return_head();
	else
		return 0;
}

int max(stack& stack)
{
	const auto max = *max_element(stack.rbegin(), stack.rend());
	return max;
}

int min(stack& stack)
{
	const auto min = *min_element(stack.rbegin(), stack.rend());
	return min;
}

void fill(stack& stack)
{
	int a = 0;
	for (auto& i : stack)
	{
		i = a;
		a = a + 12;
	}
}