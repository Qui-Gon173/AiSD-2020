#include <iostream>
#include "List.h"
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
	cout << "Сумма всех элементов: " << s << endl;
}
void average(List& container) {
	int s = 0;
	for (auto& item : container) {
		s += item;
	}
	s = s / container.get_size();
	cout << "Среднее значение: " << s << endl;
}

void min(List& container) {
	auto s = min_element(container.begin(), container.end());
	cout << "Минимальное значение: " << *s << endl;
}

void max_value(List& container) {
	auto s = max_element(container.begin(), container.end());
	cout << "Максимальное значение: " << *s << endl;
}

void min_ind(List& container) {

	auto s = min_element(container.begin(), container.end());
	cout << "Минимальное значение индекса: ";
	container.search_ind(*s);
}

void max_ind(List & container) {

	auto s = max_element(container.begin(), container.end());
	cout << "Максимальное значение индекса: ";
	container.search_ind(*s);
}

void init_container(List& container, int first, int borderValue, int denominator) {
	auto generator = ArifmProgression(first, borderValue, denominator);

	for (auto& item : generator) {
		container.push_back(item);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	auto container = new List;
	init_container(*container, 1, 25, 3);
	print_container(*container);
	max_value(*container);
	max_ind(*container);
	min(*container);
	min_ind(*container);
	sum(*container);
	average(*container);

	return 0;
}