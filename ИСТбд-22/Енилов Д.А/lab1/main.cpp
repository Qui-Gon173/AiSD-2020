#include <iostream>
using namespace std;

int main()
{
    int arr[14]={0,5,7,8,13,15,18,25,30,36,40,42,43,46};
    int isk,numfirst=0,numlast=13,Nmiddle,flag=0;
    for(int i=0;i<14;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout <<"\nEnter searched element"<<std::endl; 
    std::cin>>isk;
    while(flag<1){
        Nmiddle=(numfirst+numlast)/2;
        if(arr[Nmiddle]==isk){
        std::cout<<"Number element is "<<Nmiddle;
        flag+=1;
        }
        if(isk>arr[Nmiddle]){
            numfirst=Nmiddle;
        }else{
            numlast=Nmiddle;
        }
    }
    std::cout <<"\nElement not found";
    return 0;
}