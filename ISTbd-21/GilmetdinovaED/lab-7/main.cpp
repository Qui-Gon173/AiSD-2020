//Ханойские башни
#include <iostream>

using namespace std;

int hanoj(int n, char A, char B, char C)
{
  int num;
  if(n==1)
    {
        cout<<A<<" -> "<<B<<endl;
        num=1;
    }
        else
        {
            num=hanoj(n-1,A,C,B);
            cout<<A<<" -> "<<B<<endl;
            num++;
            num+=hanoj(n-1,C,B,A);
        }
        return num;
    }

int main(){
  char x='A',y='B',z='C';
  int k,h;
  cout<<"Hanoi Towers"<<endl;
  cout<<"Enter the number of rings: "<<endl;
  cin>>k;
  h=hanoj(k,x,y,z);
  cout<<"The number of transfers is "<<h<<endl;

  return 0;
}


