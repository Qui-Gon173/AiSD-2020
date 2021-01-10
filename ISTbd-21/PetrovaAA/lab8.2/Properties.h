#pragma once
#include <iostream>
#include "LinkedList.h"
#include "GeometricProgression.h"
void Print(LinkedList& container)
{
	for (auto& element : container) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

void Fill(LinkedList& container, long start, long stop, long multiplier)
{
	auto generator = GeometricProgression(start, stop, multiplier);

	for (auto& element : generator) {
		container.AddElement(element);
	}
}

void Sum(LinkedList& container)
{
	long sum = 0;
	for (auto& element : container) {
		sum += element;
	}

	std::cout << sum << std::endl;
}

void AverageValue(LinkedList& container)
{
	long sum = 0;
	for (auto& element : container) {
		sum += element;
	}

	std::cout << (float)sum / container.GetSize() << std::endl;
}
