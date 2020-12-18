#include <iostream>
#include <ctime>

using namespace std;

class stack
{
private:
	int* stackPointer;
	int stackSize;
	int head;
public:
	stack(int = 10);
	~stack();
	void push(int newElement);
	void push_Multiple_Elements(int* array, int arraySize);
	int pop();
	int* pop_Multiple_Elements(int n);
	void print_Stack();
	void delete_Stack();
	int return_head();
	int return_Sum();
	float return_Average();
	int return_Max();
	int return_Min();
	void push_From_Another_Stack(stack& anotherStack, int n);
};

stack::stack(int size)
{
	stack::stackSize = size;
	stackPointer = new int[stackSize];
	head = 0;
}

stack::~stack()
{
	delete[] stackPointer;
}

void stack::push(int newElement)
{
	if (head == stackSize)
		cout << "Stack is full!" << endl;
	else
		stackPointer[head++] = newElement;
}

void stack::push_Multiple_Elements(int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
		push(array[i]);
}

int stack::pop()
{
	if (head < 0)
		cout << "Last element can't be deleted!" << endl;
	else
		return stackPointer[--head];
}

int* stack::pop_Multiple_Elements(int n)
{
	if (head <= n)
		cout << "Stack is too small!" << endl;
	else
	{
		int* array = new int[n];
		for (int i = 0; i < n; i++)
			array[i] = this->pop();
		return array;
	}
}

void stack::print_Stack()
{
	for (int i = head - 1; i >= 0; i--)
		cout << stackPointer[i] << " ";
	cout << endl;
}

void stack::delete_Stack()
{
	this->head = 0;
}

int stack::return_head()
{
	return head;
}

int stack::return_Sum()
{
	int sum = 0;
	for (int i = 0; i < head; i++)
		sum += stackPointer[i];
	return sum;
}

float stack::return_Average()
{
	if (head > 0)
		return (float)this->return_Sum() / (float)head;
	else
		return 0;
}

int stack::return_Max()
{
	if (head > 0)
	{
		int max = stackPointer[0];
		for (int i = 0; i < head; i++)
			if (max < stackPointer[i])
				max = stackPointer[i];
		return max;
	}
	else
		return 0;
}

int stack::return_Min()
{
	if (head > 0)
	{
		int min = stackPointer[0];
		for (int i = 0; i < head; i++)
			if (min > stackPointer[i])
				min = stackPointer[i];
		return min;
	}
	else
		return 0;
}

void stack::push_From_Another_Stack(stack& anotherStack, int n)
{
	int anotherHead = anotherStack.return_head();
	if (n <= anotherHead)
		for (int i = 0; i < n; i++)
			this->push(anotherStack.pop());

}

void generate_Random_Array(int array[], int nVar)
{
	srand((unsigned)time(0));
	for (int i = 0; i < nVar; i++)
		array[i] = rand() % 10;
}

void print_Array(int array[], int nVar)
{
	for (int i = 0; i < nVar; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main()
{
	stack stack1;
	int nVar = 10;
	int* array1 = new int[nVar];
	cout << "Generating initial random array..." << endl;
	generate_Random_Array(array1, nVar);
	cout << "Initial random array: ";
	print_Array(array1, nVar);
	stack1.push_Multiple_Elements(array1, nVar);
	cout << "Initial stack: ";
	stack1.print_Stack();
	cout << "Sum: " << stack1.return_Sum() << endl << "Average: " << stack1.return_Average() << endl << "Min: " << stack1.return_Min() << endl << "Max: " << stack1.return_Max() << endl;
	int nElementsToBePopped = 5;
	int* array2 = new int[nElementsToBePopped];
	cout << "Popping " << nElementsToBePopped << " elements from stack to a new array..." << endl;
	array2 = stack1.pop_Multiple_Elements(nElementsToBePopped);
	cout << "Array of popped elements: ";
	print_Array(array2, nElementsToBePopped);
	cout << "Stack after popping: ";
	stack1.print_Stack();
	stack stack2;
	int nElementsToBePushed = 2;
	cout << "Pushing " << nElementsToBePushed << " elements from stack1 to stack2..." << endl;
	stack2.push_From_Another_Stack(stack1, nElementsToBePushed);
	cout << "stack2: ";
	stack2.print_Stack();
	cout << "stack1: ";
	stack1.print_Stack();
}