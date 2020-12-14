#include <iostream>

using namespace std;

void zapoln (int h,int massiv[])
{

  cout<<"Введите массив:";
  for (int i = 0; i<h; i++)
    {
        cin>>massiv[i];
    }
}
void siftDown(int *number, int root, int flag)
{
  int maxindex;
  int ok = 0;
  while ((root * 2 <= flag) && (!ok))
  {
    if (root * 2 == flag)
	{
	  maxindex = root * 2;
	}

    else if (number[root * 2] > number[root * 2 + 1])
	{
      maxindex = root * 2;
	}
    else
	{
      maxindex = root * 2 + 1;//
	}
    if (number[root] < number[maxindex])
    {
      int temp = number[root];
      number[root] = number[maxindex];
      number[maxindex] = temp;
      root = maxindex;
    }
    else // иначе
	{
      ok = 1; // пирамида сформирована
	}
  }
}
// Функция сортировки
void heapSort(int *number, int array_size)
{
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(number, i, array_size - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = number[0];
    number[0] = number[i];
    number[i] = temp;
    siftDown(number, 0, i - 1);
  }
}
void vivod(int massiv[],int h)
{
    cout<<"Отсортированный массив:";
     for (int i = 0; i<h; i++)
  {
      cout<<" "<< massiv[i];
  }
}
int main()
{
  int h;
  cout<<"Введите размерность массива:";
  cin>>h;
  int massiv[h];
  zapoln(h,massiv);
  heapSort(massiv, h);
  vivod(massiv,h);
  return 0;
}
