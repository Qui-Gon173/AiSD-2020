#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int ARRSIZE = 20;

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[ARRSIZE], desiredValue, i;
	int minDiaposon = 0, maxDiaposon = 20;
	int desiredIndex = -1;

	cout << "Введите искомое число: ";
	cin >> desiredValue;

	cout << endl << "Массив:" << endl;
	srand(time(0));
	//Заполняю массив случайными числами:
	for (i = 0; i < ARRSIZE; i++)
	{
		arr[i] = minDiaposon + rand() % (maxDiaposon - minDiaposon + 1);
		//Последнему элементу массива присваиваю искомое значение(барьер):
		if (i == (ARRSIZE - 1))
		{
			arr[i] = desiredValue;
		}
		//Вывожу элементы массива на экран:
		cout << arr[i] << " ";
	}

	//Выполняю поиск:
	for (i = 0; i < ARRSIZE; i++)
	{
		if (arr[i] == desiredValue)
	    {
		    desiredIndex = i;
			break;
		}
	}

	cout << endl << endl << "Индекс искомого числа: " << desiredIndex;
}
