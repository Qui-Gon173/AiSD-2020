#include <iostream>
using namespace std;

int perv,posled,n;
int *Mas2=new int[n];
void vvod2 (int Mas2[]) // функция ввода элемента и размерности массива
{

    cout<<"Введите размерность массива: ";
    cin>>n;
    cout<<"Исходный массив: ";
    for ( int i=0; i<n; i++)
    {
    cin>>Mas2[i];
    }
}

void fastsort(int *mas, int perv, int posled) // функция быстрой сортировки
{
    int mid, count;
    int f=perv, l=posled;
    mid=mas[(f+l) / 2]; //вычисление эдемента
    do
    {
    while (mas[f]<mid)
        {
            f++;
        }
    while (mas[l]>mid)
    {
     l--;
    }
    if (f<=l)
    {
    count=mas[f]; // обмениваем переменнами
    mas[f]=mas[l];
    mas[l]=count;
    f++;
    l--;
    }
}
    while (f<l);
    if (perv<l)
    {
      fastsort(mas, perv, l);
    }
    if (f<posled)
    {
      fastsort(mas, f, posled);
    }
}
void vivod(int perv,int posled,int Mas2[]) // функция вывода отсортированного массива
{
    perv=0; posled=n-1;
    fastsort(Mas2, perv, posled);
    cout<<"--------------------------"<<endl;
    cout<<"Отсортиртированный массив: ";
    for (int i=0; i<n; i++)
    {
      cout<<Mas2[i]<<" ";
    }
     cout<<"\n--------------------------"<<endl;
    system("pause");
}
int main()
{
setlocale(LC_ALL,"Rus");
vvod2(Mas2);
vivod(perv,posled,Mas2);
}
