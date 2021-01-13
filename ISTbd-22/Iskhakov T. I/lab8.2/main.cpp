#include <iostream>
#include <algorithm>
#include "Node.h"
#include "Queue.h"
#include "GeometricProgressionGenerator.h"

using namespace std;

void print(Queue queue) {

	std::cout << "Elements of Queue:" << std::endl;

	for (auto& item : queue) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
}

void sum(Queue queue) {
	float sum = 0;
	for (auto& item : queue) {
		sum += item;
	}
	std::cout << "Sum = " << sum << std::endl;
}

void average(Queue queue) {
	float sum = 0;
	for (auto& item : queue) {
		sum += item;
	}
	float avg = sum / queue.getSize();
	std::cout << "Average = " << avg << std::endl;
}

void findMinValue(Queue queue) {
	// находим минимальный эл-т
	Queue::const_iterator min = std::min_element(queue.begin(), queue.end());
	std::cout << "Min value = " << *min << std::endl;

	int minIndex = std::distance(queue.begin(), min);
	std::cout << "Index of min = " << minIndex << std::endl;
}

void findMaxValue(Queue queue) {
	// находим максимальный эл-т
	Queue::const_iterator max = std::max_element(queue.begin(), queue.end());
	std::cout << "Max value = " << *max << std::endl;
	// находим их индексы
    int maxIndex = std::distance(queue.begin(), max);
	std::cout << "Index of max = " << maxIndex << std::endl;
}

void init_container(Queue& container, float initial, float border, int  multiplier) {
	auto generator = GeomGenerator(initial, border, multiplier);

	for (auto& item : generator) {
		container.push(item);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Queue item;
	float number = 4.4;
	const int SIZE = 3;
	float array[SIZE] = { 6.3, 7.9, 1.4 };

	cout << "Добавление элементов в очередь" << endl;

	item.pushSomeElements(array, SIZE);
	item.push(number);
	print(item);
	findMaxValue(item);
	findMinValue(item);
	sum(item);
	average(item);
	item.deleteAll();

	auto container = new Queue;
	init_container(*container, 8.2, 65.6, 2);
	print(*container);

	return 0;
}

