#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>

const int RANGE = 100; //диапазон чисел в массиве [0;N]
const int N = 10; //количество элементов массива

int getRand();
void filling(int arr[], int sizeArr);
void print(int arr[], int sizeArr, std::string nameArr);
void checkNumb(int numb);
void binarySearch(int arr[], int sizeArr, int searchingNumb);

int main()
{
    int randArr[N];
    filling(randArr, N);

    std::sort(randArr, randArr + N); //бинарный поиск производится только по отсортированным структурам
    print(randArr, N, "Sorted array");

    std::cout << "Insert the number to find it in array (range of digits [0;" << RANGE - 1 << "]):";
    int insertNumber;
    std::cin >> insertNumber;
    checkNumb(insertNumber);

    binarySearch(randArr, N, insertNumber);
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

void checkNumb(int numb)
{
    if( (numb >= 0) & (numb <= (RANGE - 1)) )
    {
        return;
    }
    else
    {
        std::cout << "WARNING:check RANGE of digit!" << std::endl;
        exit(0);
    }
}

void binarySearch(int arr[], int sizeArr, int searchingNumb)
{
    int low = 0;
    int top = sizeArr - 1;
    int find_index = -1;

    while (low <= top)
    {
        int middle = (low + top) / 2;
        if (arr[middle] == searchingNumb)
        {
            find_index = middle;
            break;
        }
        else
        {
            if(arr[middle] > searchingNumb)
            {
                top = middle - 1;
            }
            else
            {
                low = middle + 1;
            }
        }
    }

    if (find_index == -1)
    {
        std::cout << "Number was not found" << std::endl;
    }
    else
    {
        std::cout << "Index of found number = " << find_index << "." << std::endl;
    }
}
