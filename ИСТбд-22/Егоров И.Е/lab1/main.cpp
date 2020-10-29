#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

cout<<"Algoritm lineinogo poiska"<<endl;
cout<<endl;

cout<<"Vvedite chislo elementov"<<endl;
int num;
cin>>num;
int m[num];
for(int i=0;i<num;i++){
 m[i]=rand()%(9-0);
}

cout<<"Nash massiv:"<<endl;
for(int i=0;i<num;i++){
 cout<<m[i]<<endl;
}
cout<<endl;

cout<<"Vvedite kluch"<<endl;
int key;
cin>>key;
for(int i=0;i<num;i++){
 if(m[i]==key){
     cout<<"element c indexom "<<i<<" podhodit usloviu lineinogo poiska"<<endl;
 }
}
system("pause");
return 0;
}