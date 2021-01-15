#pragma once
#include <iostream>
#include <algorithm>
#include "stack.h"

using namespace std;

float sumElements(Stack& stack)
{
	float sum = 0;
	for (auto& i : stack)
		sum += i;
	return sum;
}

void printStack(Stack& stack)
{
	for (auto& i : stack)
		cout << i << " ";
	cout << endl;
}

float meanValue(Stack& stack)
{
	if (stack.topElement() > 0)
		return (float)sumElements(stack) / (float)stack.topElement();
	else
		return 0;
}

float maxElement(Stack& stack)
{
	const auto max = *max_element(stack.rbegin(), stack.rend());
	return max;
}

float minElement(Stack& stack)
{
	const auto min = *min_element(stack.rbegin(), stack.rend());
	return min;
}

