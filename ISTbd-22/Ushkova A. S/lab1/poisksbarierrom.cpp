#include <iostream>


using namespace std;

int main()
{

  int array[]={2,5,3,8,0};
  int key;
  int k=5;
  cout<<"Enter the key value"<<endl;
  cin>>key;
  if(array[k-1]==key)
  cout<<"Index key "<<k-1<<endl;
  array[k-1] = key;
  int i = 0;
  while (array[i]!=key)
  {
      i++;
  }
 if (i<k-1)
  cout<<"Index key "<<i<<endl;
  else cout<<"Key not found"<<endl;

}
