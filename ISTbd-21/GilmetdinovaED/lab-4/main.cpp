#include <iostream>

using namespace std;

void Heapify(int arr[], int n, int i) // функция "просеивания"
{
    int maximum = i; // Инициализация наибольшего корня
    int left = 2*i + 1; // левый потомок
    int right = 2*i + 2; // правый потомок


    if (left < n && arr[left] > arr[maximum]) // Если левый дочерний элемент больше корня
       maximum = left; //то наибольший корень полагаем равным этому элементу


    if (right < n && arr[right] > arr[maximum])// Если правый дочерний элемент больше "нового" корня
        maximum = right;


    if (maximum != i)// Если самый большой элемент не корень
    {
        swap(arr[i], arr[maximum]);// меняем значения

        Heapify(arr, n, maximum);// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
    }
}

//Пирамидальная сортировка
void HeapSort(int arr[], int n)
{
  // построение "кучи"
    for (int i = n / 2 - 1; i >= 0; i--)
       {
            Heapify(arr, n, i);
       }

   //извлекаем элемениты
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]); // Перемещаем текущий корень в конец
        Heapify(arr, i, 0);// вызываем процедуру просеивания на уменьшенной куче
    }
}

int main()
{
   int sizeArr;
	cout << "Enter the size of the array:" << endl;
	cin >> sizeArr;
	int* arr = new int[sizeArr];
	cout << "Enter the array elements:" << endl;
	for (int i = 0; i < sizeArr; i++)
	{
		cin >> arr[i];
	}
	HeapSort(arr, sizeArr);
	 cout << "Result: ";
	 for (int j = 0; j < sizeArr; j++)
	 {
		 cout << arr[j] << " ";
	 }
	 cout << endl;
}
