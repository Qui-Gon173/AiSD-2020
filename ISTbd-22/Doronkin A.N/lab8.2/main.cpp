#include "stack.h"
#include "stack_functions.h"
#include "exponential_function_number_generator.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Exponential_Generator generator(2.2,1,1,8);
	stack stack1(generator);
	cout << "Начальный стек: ";
	print_Stack(stack1);
	cout << "Минимальный элемент: " << min(stack1) << endl << "Максимальный элемент: " << max(stack1) << endl << "Сумма: " << sum(stack1) << endl << "Среднее значение: " << average(stack1) << endl;
}