#include <iostream>

using namespace std;

void Swap(int *Massiv, int i)//функция обмена
{
int temp;
temp=Massiv[i];
Massiv[i]=Massiv[i-1];
Massiv[i-1]=temp;
}

void ShakerSort(int *Massiv, int Start, int N)//функция шейкерной сортировки
{
int Left, Right, i;
Left=Start;
Right=N-1;
while (Left<=Right)
{
for (i=Right; i>=Left; i--)
if (Massiv[i-1]>Massiv[i]) Swap(Massiv, i);
Left++;
for (i=Left; i<=Right; i++)
if (Massiv[i-1]>Massiv[i]) Swap(Massiv, i);
Right--;
}
}

int main()
{
setlocale(LC_ALL,"Rus");
int sizeArr, i;
cout<<"Введите размер массива  "; cin>>sizeArr;
int *arr=new int[sizeArr];
for (i=0; i<sizeArr; i++)
{ cout<<"Введите "<<i+1<<" элемент  "; cin>>arr[i]; }
ShakerSort(arr, 1, sizeArr);
cout<<"Результирующий массив: ";
for (i=0; i<sizeArr; i++)
    {cout<<" "<<arr[i];}

}
