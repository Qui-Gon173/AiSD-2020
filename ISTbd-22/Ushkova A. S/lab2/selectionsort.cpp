#include <iostream>

 using namespace std;

void SelectionSort(int array[], int k)
{
  int i,j, min, temp;
  for(i=0;i<k-1; i++)
  {
    min=i;
    for (j=i+1;j<k;j++)
    {
      if(array[j]<array[min])
      min=j;
    }
    if (min!=i)
    {
    std::swap(array[i], array[min]);
    min=i;
    }
  }
}

int main()
{
  int length=8;
  int array[length]={7,0,8,19,3,8,2,6};
  cout<<" Sourse array "<<endl;
  for(length=0; length<8; ++length)
  {std::cout << array[length] << ' ';}
   SelectionSort(array,length);
   cout<<"\n Sorted array "<<endl;
   for (int i = 0; i < length; ++i)
		{std::cout << array[i] << ' ';}
}
