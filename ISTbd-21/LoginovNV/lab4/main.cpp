#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>

const int RANGE = 10; //диапазон чисел в массиве [0;N)
const int N = 11; //количество элементов массива

int getRand();
void filling(int arr[]);
void print(int arr[], std::string nameArr);
void piramidSort(int arr[]);
void doPiramid(int arr[], int firstIndex, int lastIndex);
void changeElem(int firstIndex, int secondIndex, int arr[]);

int main()
{
    int randArray[N];
    filling(randArray);
    print(randArray, "Initial array");

    doPiramid(randArray, 0, N - 1);
    print(randArray, "Piramid array");
    piramidSort(randArray);
    print(randArray, "Sorted array");
    return 0;
}

int getRand()
{
    return ( rand() % RANGE);
}

void filling(int arr[])
{
    srand(time(0)); // для рандомных чисел
    for (int i = 0; i <= N - 1; i++)
    {
        arr[i] = getRand();
    }
}

void print(int arr[], std::string nameArr)
{
    std::cout << nameArr << ":" << std::endl;
    for (int i = 0; i <= N - 1; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void changeElem(int firstIndex, int secondIndex, int arr[])
{
    int supportElem = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = supportElem;
}

void doPiramid(int arr[], int firstIndex, int lastIndex)
{
    //for (int i = ((lastIndex - 1) / 2) ; i >= firstIndex; i--) //нумерация от 1, а не от 0, делаем пирамиду с серединного элемента
    for (int i = ((lastIndex / 2) - 1) ; i >= firstIndex; i--)
    {
        bool conditionPiramid = ( (arr[i] >= arr[2*i]) && (arr[i] >= arr[2*i + 1]) ); //условие пирамиды

        while (!conditionPiramid)//меняем местами потомков и родителя, пока не будет выполнено условие пирамиды
        {
            if (arr[2*i] > arr[2*i + 1])
            {
                changeElem(i, 2*i, arr);
                doPiramid(arr, 2*i, lastIndex);//проверяем условие пирамиды для потомка после замены
            }
            else if (arr[2*i] <= arr[2*i + 1])
            {
                changeElem(i, 2*i + 1, arr);
                doPiramid(arr, 2*i + 1, lastIndex);
            }
            conditionPiramid = ( (arr[i] >= arr[2*i]) && (arr[i] >= arr[2*i + 1]) ); //снова проверяем условие
        }
    }
}

void piramidSort(int arr[])
{
   // std::cout << std::endl;
    int sizeArr = N - 1;
    for(int i = N - 1; i >= 1; i--) // если количество < 2 - нет смысла снова менять
    {
       // std::cout << i << std::endl;
        sizeArr -= 1; //убираем из рассмотрения последний элемент
        if(arr[0] > arr[i])
        {
            changeElem(0, i, arr); //меняем местами наибольший и наименьший(первый и последний)
        }
        //print(arr, "1");
        doPiramid(arr, 0, sizeArr); //делаем пирамиду после замены
       // print(arr, "2");
    }
   // std::cout << std::endl;
}
