#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// функция заполнения массива "array" длиной "quantity" случайными числами 
void filling_array_random(int array[], int quantity)
{
    srand((unsigned)time(0));
    for (int i = 0; i < quantity; i++)
    {
        array[i] = rand() % 10;
    }
}

//функция вывода массива на экран
void array_output(int array[], int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

//функция поиска искомого элемента "element" 
int search_with_barrier(int array[], int quantity, int element)
{
    int indexElement = 0;
    if (array[quantity - 1] != element) //проверим, нет ли искомого элемента на последней позиции
    {
        array[quantity - 1] = element;  //установим барьер
        for (; array[indexElement] != element; indexElement++);  //Поиск
        indexElement++;

    }
    else return quantity;  //Если искомый элемент на последней позиции, то возвращаем размер
    return indexElement < quantity ? indexElement : 0;
}
int main()
{
    int quantity;

    cout << "Enter the number of elements in the array: ";
    cin >> quantity;

    int* array = new int[quantity];

    filling_array_random(array, quantity);

    cout << "Array: ";
    array_output(array, quantity);

    int element;

    cout << "Enter the element you are looking for: ";
    cin >> element;

    int indexElement = search_with_barrier(array, quantity, element);

    if (indexElement == 0)
        cout << "Element not found." << endl;
    else
        cout << "Element index: " << indexElement << endl;
    return 0;

}