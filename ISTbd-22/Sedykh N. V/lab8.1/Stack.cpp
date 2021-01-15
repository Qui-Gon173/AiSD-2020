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
	//���������� �����
	Stack(int size=0)
	{
		stackSize = size;
		topIndex = 0;
	};

	//���������� ����� ���������� ������� ���� float
	void generate()
	{
		srand((unsigned)time(0));
		for (int i = 0; i < stackSize; i++) {
			float fl = rand() % 10;
			stackElements.push_back(fl);
		}
		resizeStackAttributes();
	}

	//��������� ������� ����� � ������� ����
	void resizeStackAttributes()
	{
		stackSize = stackElements.size();
		topIndex = stackSize - 1;
	}

	//���������� ��������� � ����
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

	//����� �����
	void printStack()
	{
		for (int i = topIndex; i >= 0; i--)
			cout << stackElements[i] << " ";
		cout << endl;
	}

	//������� �����
	float topElement()
	{
		return stackElements[topIndex];
	}

	//�������� �����
	void clearStack()
	{
		this->topIndex = 0;
	}

	//���������� ��������� � �����
	int numberElements()
	{
		return stackSize;
	}

	//����� ��������� �����
	float sumElements()
	{
		int sum = 0;
		for (int i = 0; i < topIndex; i++)
			sum += stackElements[i];
		return sum;
	}

	//������� ��������
	float meanValue()
	{
		if (topIndex > 0)
			return (float)this->sumElements() / (float)topIndex;
		else
			return 0;
	}

	//����������� �������
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

	//������������ �������
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

	//�������� ��������� �� �����
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
			cout << "���������� ��������� ��� �������� ������ ������� �����!";
			exit(0);
		}

		float *poppedArray = new float[poppingElementsNumber];
		for (int i = 0; i < poppingElementsNumber; i++)
			poppedArray[i] = pop();

		return poppedArray;
	}
};

