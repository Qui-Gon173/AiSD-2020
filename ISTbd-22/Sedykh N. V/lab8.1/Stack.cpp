#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Stack {

private:
	int stackSize;
	int topIndex;
	std::vector<float> stackElements;

public:
	//Конструтор стека
	Stack(int size=0)
	{
		stackSize = size;
		topIndex = 0;
	};

	//Заполнение стека рандомными числами типа float
	void generate()
	{
		srand((unsigned)time(0));
		for (int i = 0; i < stackSize; i++) {
			float fl = rand() % 10;
			stackElements.push_back(fl);
		}
		resizeStackAttributes();
	}

	//Изменение размера стека и вершины стеа
	void resizeStackAttributes()
	{
		stackSize = stackElements.size();
		topIndex = stackSize - 1;
	}

	//Добавление элементов в стек
	void push(float newElement)
	{
			stackElements.push_back(newElement);
			resizeStackAttributes();
	}

	void pushElements(float* array, int length)
	{
		for (int i = 0; i < length; i++)
			push(array[i]);
	}

	//Вывод стека
	void printStack()
	{
		for (int i = topIndex; i >= 0; i--)
			cout << stackElements[i] << " ";
		cout << endl;
	}

	//Вершина стека
	float topElement()
	{
		return stackElements[topIndex];
	}

	//Отчистка стека
	void clearStack()
	{
		this->topIndex = 0;
	}

	//Количество элементов в стеке
	int numberElements()
	{
		return stackSize;
	}

	//Сумма элементов стека
	float sumElements()
	{
		int sum = 0;
		for (int i = 0; i < topIndex; i++)
			sum += stackElements[i];
		return sum;
	}

	//Среднее значение
	float meanValue()
	{
		if (topIndex > 0)
			return (float)this->sumElements() / (float)topIndex;
		else
			return 0;
	}

	//Минимальный элемент
	float minElement()
	{
		if (topIndex > 0)
		{
			int min = stackElements[0];
			for (int i = 0; i < topIndex; i++)
				if (min > stackElements[i])
					min = stackElements[i];
			return min;
		}
		else
			return 0;
	}

	//Максимальный элемент
	float maxElement()
	{
		if (topIndex > 0)
		{
			int max = stackElements[0];
			for (int i = 0; i < topIndex; i++)
				if (max < stackElements[i])
					max = stackElements[i];
			return max;
		}
		else
			return 0;
	}

	//Удаление элементов из стека
	float pop()
	{
		float lastElement = stackElements[topIndex];
		stackElements.pop_back();
		resizeStackAttributes();

		return lastElement;
	}

	float* popMultipleElements(int poppingElementsNumber)
	{
		if (poppingElementsNumber > stackSize)
		{
			cout << "Количество элементов для удаления больше размера стека!";
			exit(0);
		}

		float *poppedArray = new float[poppingElementsNumber];
		for (int i = 0; i < poppingElementsNumber; i++)
			poppedArray[i] = pop();

		return poppedArray;
	}
};

