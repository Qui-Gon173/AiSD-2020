#include "stack.h"
#include "stack_functions.h"
#include "geometric_progression_generator.h"

using namespace std;

int main()
{
	GeometricProgressionGenerator generator(2, 2, 12);
	stack stack1(generator);
	cout << "Initial stack: ";
	print_Stack(stack1);
	cout << "Min: " << min(stack1) << endl << "Max: " << max(stack1) << endl << "Sum: " << sum(stack1) << endl << "Average: " << average(stack1) << endl;
}