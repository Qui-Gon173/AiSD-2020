#include <iostream>

 using namespace std;

int main()
{
  int length=8;
  int array[length]={7,0,8,19,3,8,2,6};
  cout<<" Sourse array "<<endl;
  for(length=0; length<8; ++length)
  std::cout << array[length] << ' ';
  
    for (int startIndex=0; startIndex<length-1; startIndex++)
    {
        int smallestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            if (array[currentIndex] < array[smallestIndex])
            smallestIndex = currentIndex;
        }
        std::swap(array[startIndex], array[smallestIndex]);
    }
   cout<<"\n Sorted array "<<endl;
   for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';
}
