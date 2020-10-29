#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
    
    setlocale(LC_ALL, "ru-RU");
    // задаем массив и числа
    int mas[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    int b = 0;
    //вывод массива
    for (int i=0; i<12; i++)
    {
       cout<<mas[i]<<endl;
       cout<<"--"<<endl;
    }
    int got = 2; // задаем переменную для поиска нужного нам числа.
    for (int i=0; i<12; i++)
    {
        if (mas[i] == got) // делаем проверку, равен ли наш массив к переменной  got
        {
            mas[b++] = i; 
        }
    }
        if (b!=0) // делаем проверку на совпадение нужного нам индекса массива.
        {
           for (int i = 0; i < b; i++) 
           {
               cout<< "Число "<< got << " в индексе массива " << mas[i] <<endl;
           }
        }
           else {
               cout<< "К сожалению, массив не найден"<<endl;
           }
    getch();
    return 0;
}
