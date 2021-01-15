#include "stack.h"
#include "stack_functions.h"
#include "progression_generator.h"

using namespace std;

int main()
{
	ProgressionGenerator generator(3.4, 1, 1, 8);
	Stack stackFirst(generator);
	cout << "Stack: ";
	printStack(stackFirst);
	cout << "Min: " << minElement(stackFirst) << endl;
	cout << "Max: " << maxElement(stackFirst) << endl;
	cout << "Sum: " << sumElements(stackFirst) << endl;
	cout << "Average: " << meanValue(stackFirst) << endl;
}