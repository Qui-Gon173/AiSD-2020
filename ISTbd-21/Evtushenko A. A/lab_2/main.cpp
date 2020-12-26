#include <iostream>
int *shekerSort(int *arr, int count)
{
	//указатель на крайний левый и крайний правый элемент
	int *left;
	left = arr;
	int *right;
	right = &arr[count - 1];
	int *next; //следующий элемент
	int flag = 0; // если 1, то не упорядоченно
	int temp;

	while (left < right && flag > 0)//пока адрес левого указателя меньше адреса правого указателя и были перестановки в ряде
	{
		flag = 0;

		for (arr = left; arr <= right; arr++) //на последнем шаге итерации указатель р будет содержать адрес последнего элемента в ряду
		{
			next = arr + 1;
			if (*arr > *next)
			{aa
				//поменять местами значения указетелей next  и p
				temp = *arr;
				*arr = *next;
				*next = temp;

				flag = 1;       
			}
		}
		right--; //изменим адрес крайнего правого элемента в ряду

				 //в обратном направлении
		for (arr = right; arr > left; arr--)	
		{
			next = arr - 1; //содержит адрес следующего рассматриваемого элемента
			if (*next > *arr)
			{
				temp = *arr;
				*arr = *next;
				*next = temp;

				flag = 1;  //перестановка была в ряду
			}
		}
		left++;

	}
	return arr;
}
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int arr[4] = { 8,6,4,2 };
	int *rezult; //указатель на отсоритрованный массив

	rezult = shekerSort(arr, 4); //записываем адрес того, что полуилось

	for (int i = 0; i < 4; i++)
		std::cout << rezult[i] << ' ';
	std::cout << '\n';

	system("pause");
	return 0;
}