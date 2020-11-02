#include <iomanip>
#include <iostream>

using namespace std;

int QuickSort(int *array,int left,int right)
{
    long base, opposite, p;
    int c;
    base=left;
    opposite=right;
    while (base!=opposite)
    {
        if((array[base]>array[opposite])^(base>opposite))
        {
            c=array[base];
            array[base]=array[opposite];
            array[opposite]=c;

            p=base;
            base=opposite;
            if(p<opposite)
            opposite=p+1;
            else
            opposite=p-1;
        }
        else
        {
            if (base<opposite)
            opposite--;
            else opposite++;
        }
    }

    if (left<base-1) QuickSort(array,left,base-1);
    if (base+1<right) QuickSort(array,base+1,right);
}

void Raspechatka (int cout, int array[])
{
    for(int i=0; i<cout; ++i)
    cout << array[i] << ' ';
}

int main()
{

  int i = 8;
  int array[i]={9,6,3,4,10,8,2,7};
  cout<<" Sourse array "<<endl;
  for(i=0; i<8; ++i)
  cout << array[i] << ' ';
  QuickSort(array,0,7);
  cout<<"\n";
  cout<<"\n Sorted array"<<endl;
  for(i=0; i<8; ++i)
  cout<<array[i]<<' ';
  cout<<"\n";



}