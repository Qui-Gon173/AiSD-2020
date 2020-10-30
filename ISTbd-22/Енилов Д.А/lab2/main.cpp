#include <iostream>
using namespace std;

int main()
{
    int i,arr[12]={28,14,18,29,30,6,17,3,4,3,22,1};
    bool flag=false,ready=true;
    int conteiner;
    for(i=0;i<12;i++){//Вывод массива
        std::cout<<arr[i]<<" ";
    }
    while(flag==false){
        for(i=1;i<12;i++){
            if(arr[i]<arr[i-1]){
            conteiner=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=conteiner;
            ready=false;
            }
        }
        if(ready==true)
        flag=true;
        ready=true;
    }
    std::cout<<"\n";
    for(i=0;i<12;i++){//Вывод массива
        std::cout<<arr[i]<<" ";
    }
}