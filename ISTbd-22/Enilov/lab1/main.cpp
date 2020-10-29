#include <iostream>
using namespace std;

int main()
{
    int arr[14]={0,5,7,8,13,15,18,25,30,36,40,42,43,46};
    int key,numfirst=0,numlast=13,numbermiddle;
    bool flag=false;
    for(int i=0;i<14;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout <<"\nEnter searched element"<<std::endl; 
    std::cin>>key;
    while(flag==false){
        numbermiddle=(numfirst+numlast)/2;
        if((numlast-numfirst==2)&&(arr[numbermiddle] != key)){
            flag=true;
        }
        if(arr[numbermiddle]==key){
        std::cout<<"Number element is "<<numbermiddle;
        flag=true;
        return 0;
        }
        if(key>arr[numbermiddle]){
            numfirst=numbermiddle;
        }else{
            numlast=numbermiddle;
        }
    }
    std::cout <<"Element not found";
    
}