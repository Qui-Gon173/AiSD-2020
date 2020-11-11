#include <iostream>
#include <time.h>
#include <string>

const int RANGE = 100; //диапазон чисел в массиве [0;N]
const int N = 10; //количество элементов массива

int getRand();
void filling(int arr[], int sizeArr);
void print(int arr[], int sizeArr, std::string nameArr);
void shakerSort(int arr[], int sizeArr);

int main()
{
    int randArray[N];
    filling(randArray, N);
    print(randArray, N, "Initial array");

    shakerSort(randArray, N);
    print(randArray, N, "Sorted array");
    return 0;
}

int getRand()
{
    return ( rand() % RANGE);
}

void filling(int arr[], int sizeArr)
{
    srand(time(0)); // для рандомных чисел
    for (int i = 0; i < sizeArr; i++)
    {
        arr[i] = getRand();
    }
}

void print(int arr[], int sizeArr, std::string nameArr)
{
    std::cout << nameArr << ":" << std::endl;
    for (int i = 0; i < sizeArr; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


void shakerSort(int arr[], int sizeArr)
{
    int low = 0;
    int top = sizeArr - 1;
    bool moov = true; //следим за перемещениями

    while ( (low < top) && (moov == true))
    {
        moov = false;

        for (int i = low; i < top; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int supportElem = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = supportElem;
                moov = true;
            }
        }
        top--;

        for (int i = top; i > low; i--)
        {
            if (arr[i] < arr[i-1])
            {
                int supportElem = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = supportElem;
                moov = true;
            }
        }
        low++;
    }
}
