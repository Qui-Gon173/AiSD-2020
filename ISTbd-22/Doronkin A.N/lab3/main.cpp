#include <iostream>
using namespace std;

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
void vivod(int Mas2[],int n) // функция вывода отсортированного массива
{
    int perv=0;
    int posled=n-1;
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
int n;
int *Mas2=new int[n];
cout<<"Введите размерность массива: ";
cin>>n;
cout<<"Исходный массив: ";
for ( int i=0; i<n; i++)
{
    cin>>Mas2[i];
}
setlocale(LC_ALL,"Rus");
vivod(Mas2,n);
}