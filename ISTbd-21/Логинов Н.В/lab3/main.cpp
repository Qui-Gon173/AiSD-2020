#include <iostream>
#include <time.h>
#include <string>

const int RANGE = 100; //диапазон чисел в массиве [0;N]
const int N = 10; //количество элементов массива

int getRand();
void filling(int arr[], int sizeArr);
void print(int arr[], int sizeArr, std::string nameArr);
void xoaraSort(int arr[], int low, int top);

int main()
{
    int randArray[N];
    filling(randArray, N);
    print(randArray, N, "Initial array");

    xoaraSort(randArray, 0, N-1);
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

void xoaraSort(int arr[], int low, int top)
{
    int leftElem = low;
    int rightElem = top;
    int separator = arr[(low + top) / 2];

    do
    {
        while(arr[leftElem] < separator)
        {
            leftElem++;
        }

        while(arr[rightElem] > separator)
        {
            rightElem--;
        }

        if(leftElem <= rightElem)
        {
            if(arr[leftElem] > arr[rightElem])
            {
                int supportElem = arr[leftElem];
                arr[leftElem] = arr[rightElem];
                arr[rightElem] = supportElem;
            }
            leftElem++;
            rightElem--;
        }
    } while(leftElem <= rightElem);

    if(leftElem < top)
        xoaraSort(arr, leftElem, top);
    if(rightElem > low)
        xoaraSort(arr, low, rightElem);
}
