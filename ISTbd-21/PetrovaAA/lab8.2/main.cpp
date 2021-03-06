#include <iostream>
#include <algorithm>
#include "Properties.h"

int main()
{
	auto container = new LinkedList;
	std::cout << "Current progression contains: ";
	Fill(*container, 1, 243, 3);
	Print(*container);
	std::cout << std::endl;
	std::cout << "Sum of this progression: ";
	Sum(*container);
	std::cout << std::endl;
	std::cout << "Average value of this progression: ";
	AverageValue(*container);
	std::cout << std::endl;

	const auto min_value = min_element(container->begin(), container->end());
	std::cout << "Minimum value of this progression: " << *min_value << std::endl;
	std::cout << std::endl;

	const auto max_value = max_element(container->begin(), container->end());
	std::cout << "Maximum value of this progression: " << *max_value << std::endl;
	std::cout << std::endl;

	std::cout << "Index of minimum value of this progression: " << container->SearchIndexOf(*min_value) << std::endl;
	std::cout << std::endl;

	std::cout << "Index of maximum value of this progression: " << container->SearchIndexOf(*max_value) << std::endl;
	std::cout << std::endl;
    return 0;
}

