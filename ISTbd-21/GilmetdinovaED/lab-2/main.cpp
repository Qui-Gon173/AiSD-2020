#include <iostream>

using namespace std;

void Swap(int *arr, int i)//функция обмена
{
int temp;
temp=arr[i];
arr[i]=arr[i-1];
arr[i-1]=temp;
}

void ShakerSort(int *arr, int start, int n)//функция шейкерной сортировки
{
int left, right, i;
left=start;
right=n-1;
while (left<=right)
{
for (i=right; i>=left; i--)
if (arr[i-1]>arr[i]) Swap(arr, i);
left++;
for (i=left; i<=right; i++)
if (arr[i-1]>arr[i]) Swap(arr, i);
right--;
}
}

int main()
{
setlocale(LC_ALL,"Rus");
int sizeArr, i;
cout<<"Введите размер массива  ";
    cin>>sizeArr;
int *arr=new int[sizeArr];
for (i=0; i<sizeArr; i++)
{ 
 cout<<"Введите "<<i+1<<" элемент  "; 
 cin>>arr[i]; 
}
ShakerSort(arr, 1, sizeArr);
cout<<"Результирующий массив: ";
for (i=0; i<sizeArr; i++)
{
  cout<<" "<<arr[i]; 
}

}
