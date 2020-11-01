#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    
    setlocale(LC_ALL, "ru-RU");
    // задаем массив и числа
    int h = 12; // задаем размерность массива
    int mas[h]={1,2,3,4,5,6,7,8,9,10,11,12};
    int b = 0;
    //вывод массива
    for (int i=0; i<h; i++)
    {
       cout<<mas[i]<<endl;
       cout<<"--"<<endl;
    }
    int got = 5; // задаем переменную для поиска нужного нам числа.
    if (got>h) // проверка от неправильного ввода числа
    { 
    cout<<"Задайте корректное число!"<<endl;
    getch();
    return 0;
    }
    else {   
    }
    for (int i=0; i<h; i++)
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
