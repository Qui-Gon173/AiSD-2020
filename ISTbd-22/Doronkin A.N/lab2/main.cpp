#include <iostream>
using namespace std;
int h; // глоб. переменная размерности массива
void vvod(int h,int mas[]) // функция ввода массива
{
     cout<<"Введите элементы массива:";
     for (int i=0; i<h; i++)
    {
        cin>>mas[i]; // цикл ввода массива
    }
}
void vivod(int mas[]) // функция вывода введеного массива
{
    cout<<"Введенный массив:";
    for (int i=0; i<h; i++)
    {
        cout<<mas[i]<<" "; // цикл ввывода введеного массива
    }
}
void sortirovo4ka(int h,int mas[])
{
    int min; int min_temp; // переменные для поиска минимального и для занесения индекса минимального числа
    for (int i=0; i<h; i++)
    {
        min=i; // тек. индекс массива
        for ( int r=i+1; r<h; r++) // цикл для остальных элементов массива
        {
            if (mas[r]<mas[min]) // если элемент массива меньше минимального, то запоминаем индекс в переменную min 
            {
                min = r;
            }
        }
            min_temp = mas[i];
            mas[i] = mas[min];    // меняем местами индексы массива
            mas[min] = min_temp;
    }
    cout<<"\n------------------------------"<<endl;
    cout<<"Отсортированный массив:";
    for (int i=0; i<h; i++)
    {                                        // цикл ввывода отсортированного массива
        cout<<mas[i];
    }
    cout<<"\n------------------------------"<<endl;
}
int main()
{
    cout<<"Ведите размерность массива:";
    cin>>h; // ввод размерности массива
    int mas[h];
    vvod(h,mas);
    vivod(mas);
    sortirovo4ka(h,mas);
    return 0;
}
