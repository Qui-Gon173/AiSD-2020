#include <iostream>
#include "list.h"
#include <algorithm>
#include "ArifmProgression.h"

using namespace std;
void print_container(List& container) {
	for (auto& item : container) {
		cout << item << endl;
	}
}
void sum(List& container) {
	int s = 0;
	for (auto& item : container) {
		s += item;
	}
	cout << "Sum: " << s << endl;
}
void average(List& container) {
	int s = 0;
	for (auto& item : container) {
		s += item;
	}
	s = s / container.get_size();
	cout << "Average: " << s << endl;
}

void min_value(List& container) {
	auto s = min_element(container.begin(), container.end());
	cout << "min_value: " << *s << endl;
}

void max_value(List& container) {
	auto s = max_element(container.begin(), container.end());
	cout << "max_value: " << *s << endl;
}

void min_value_index(List& container) {

	auto s = min_element(container.begin(), container.end());
	cout << "min_value_index: ";
	container.search_ind(*s);
}

void max_value_index(List& container) {

	auto s = max_element(container.begin(), container.end());
	cout << "max_value_index: ";
	container.search_ind(*s);
}

void init_container(List& container, int first, int borderValue, int denominator) {
	auto generator = ArifmProgression(first, borderValue, denominator);

	for (auto& item : generator) {
		container.append(item);
	}
}

int main()
{
	auto container = new List;
	init_container(*container, 1, 33, 1);
	print_container(*container);
	max_value(*container);
	max_value_index(*container);
	min_value(*container);
	min_value_index(*container);
	sum(*container);
	average(*container);

	return 0;
}