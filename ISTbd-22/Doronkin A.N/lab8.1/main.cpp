#include <iostream>
#include <ctime>

using namespace std;

class stack
{
private:
	float* stackPointer; // указатель
	int stackSize;
	int head;
public:
	stack(int = 10); //размер стека равен 10 элементам
	~stack(); // деструктор
	void push(float newElement);
	void push_Multiple_Elements(float* array, int arraySize);
	float pop();
	float* pop_Multiple_Elements(int n);
	void print_Stack();
	void delete_Stack();
	int return_head();
	float Summa_znah(); // сумма
	float Srednie_znah(); // ср
	float Max_znah(); //макс элемент
	float Min_znah();//мин элемент
	void push_From_Another_Stack(stack& anotherStack, int n);
};
// стек
stack::stack(int size)
{
	stack::stackSize = size;
	stackPointer = new float[stackSize];
	head = 0;
}
// деструктор стека
stack::~stack()
{
	delete[] stackPointer;
}
// функция добавления элемента в стек
void stack::push(float newElement)
{
	if (head == stackSize)
		cout << "Stack is full!" << endl;
	else
		stackPointer[head++] = newElement;
}
//Вставка нескольких значений
void stack::push_Multiple_Elements(float* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
		push(array[i]);
}

float stack::pop()
{
	if (head < 0)
		cout << "Last element can't be deleted!" << endl;
	else
		return stackPointer[--head];
}

float* stack::pop_Multiple_Elements(int n)
{
	if (head <= n)
		cout << "Stack is too small!" << endl;
	else
	{
		float* array = new float[n];
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

float stack::Summa_znah()
{
	float sum = 0;
	for (int i = 0; i < head; i++)
		sum += stackPointer[i];
	return sum;
}

float stack::Srednie_znah()
{
	if (head > 0)
		return (float)this->Summa_znah() / (float)head;
	else
		return 0;
}

float stack::Max_znah()
{
	if (head > 0)
	{
		float max = stackPointer[0];
		for (int i = 0; i < head; i++)
			if (max < stackPointer[i])
				max = stackPointer[i];
		return max;
	}
	else
		return 0;
}

float stack::Min_znah()
{
	if (head > 0)
	{
		float min = stackPointer[0];
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
float random(float min, float max)
{
    return (float)(rand())/RAND_MAX*(max - min) + min;
}

void generate_Random_Array(float array[], int nVar)
{

	srand((unsigned int)time(0));
	for (int i = 0; i < nVar; i++)
		array[i] = random(-1.235, 157.456);


}

void print_Array(float array[], int nVar)
{
	for (int i = 0; i < nVar; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
	stack stack1;
	int nVar = 10;
	float* array1 = new float[nVar];
	cout << "Генерация начального случайного массива:" << endl;
	generate_Random_Array(array1, nVar);
	cout << "============================================================================================================="<<endl;
	cout << "Исходный случайный массив: ";
	print_Array(array1, nVar);
	stack1.push_Multiple_Elements(array1, nVar);
	cout << "Исходный начальный стек: ";
	stack1.print_Stack();
	cout << "============================================================================================================="<<endl;
	cout << "Сумма: " << stack1.Summa_znah();
	cout << " Ср.значение: " << stack1.Srednie_znah();
	cout << " Мин.значение: " << stack1.Min_znah();
	cout << " Макс.значение: " << stack1.Max_znah() << endl;
	int nElementsToBePopped = 5;
	float* array2 = new float[nElementsToBePopped];
	cout << "Перемещение " << nElementsToBePopped << " элементов из стека в новый массив" << endl;
	array2 = stack1.pop_Multiple_Elements(nElementsToBePopped);
	cout << "Массив перемещенных  элементов: ";
	print_Array(array2, nElementsToBePopped);
	cout << "Стек после перемещение: ";
	stack1.print_Stack();
	stack stack2;
	int nElementsToBePushed = 2;
	cout << "Перемещение " << nElementsToBePushed << " элементов из stack1 в stack2..." << endl;
	stack2.push_From_Another_Stack(stack1, nElementsToBePushed);
	cout << "Stack2: ";
	stack2.print_Stack();
	cout << "Stack1: ";
	stack1.print_Stack();
}
