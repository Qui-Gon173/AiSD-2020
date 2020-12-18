#include <iostream>

using namespace std;

int hanoj(int n , char A , char B , char C);

int hanoj(int n , char A , char B , char C){
    int num;
    if(n==1){
        cout<<A<<"->"<<B<<endl;
        num=1;
    }else{
        num=hanoj(n-1,A,C,B);
        cout<<A<<"->"<<B<<endl;
        num++;
        num+=hanoj(n-1,C,B,A);
    }
    return num;
}

int main(){
    char x='A',y='B',z='C';
    int k,h;
    cout<<"Hanoie task"<<endl;
    cout<<"Input number of rings"<<endl;
    cin>>k;
    h=hanoj(k,x,y,z);
    cout<<"Number of exchange equally :"<<h<<endl;
    system("pause");
    return 0;
}