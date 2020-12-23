#include <iostream>
// Вывод массива.
void print(int size, int *array)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
// Линейный поиск.
int linearSearch(int size, int *array, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    const int size = 10;
    int arr[size] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int key;
    std::cout << "Enter the key: ";
    std::cin >> key;

    std::cout << "ARRAY: ";
    print(size, arr);

    int result = linearSearch(size, arr, key);
    std::cout << "Index: " << result;
}
