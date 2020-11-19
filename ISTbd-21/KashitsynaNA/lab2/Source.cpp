#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
const int SIZE = 15;


//Функция шейкер-сортировки
void shakerSort(int arr[]);


int main() {
    setlocale(LC_ALL, "rus");
    int massive[SIZE];
    int minDiaposon = 0, maxDiaposon = 100;

    cout << "Исходный массив:" << endl;
    srand(time(0));
    //Заполняю массив случайными числами:
    for (int i = 0; i < SIZE; i++) 
    {
        massive[i] = minDiaposon + rand() % (maxDiaposon - minDiaposon + 1);
        //Вывожу элементы массива на экран:
        cout << massive[i] << " ";
    }

    //Вызываю функцию сортировки::
    shakerSort(massive); 

    //Вывожу отсортированные элементы массива:
    cout << endl << "Получившийся массив:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << massive[i] << " ";
    }
    return 0;
}


void shakerSort(int arr[])
{
    //Левая и правая границы сортируемой области массива:
    int leftBorder = 0, rightBorder = SIZE - 1;
    //Наличие перемещений:
    int flag = 1;  

    while ((leftBorder < rightBorder) && flag > 0)
    {
        flag = 0;
        for (int i = leftBorder; i < rightBorder; i++) 
        {
            if (arr[i] > arr[i + 1])
            {
                int newArr = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = newArr;
                flag = 1;      
            }
        }
        rightBorder = rightBorder - 1; 
        for (int i = rightBorder; i > leftBorder; i--) 
        {
            if (arr[i - 1] > arr[i])
            {            
                int newArr = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = newArr;
                flag = 1;   
            }
        }
        leftBorder = leftBorder + 1; 
    }
}
