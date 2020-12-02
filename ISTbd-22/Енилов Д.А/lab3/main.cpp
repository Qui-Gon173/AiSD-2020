#include <iostream>

using namespace std;
void SortOfHoar(int *arr,int first, int last)
{
    int i,opornii,opposite,conteiner,schperem=0;
    if(arr[first]>arr[last]){
    opornii=first;
    opposite=last;
    }else
    {     
    opornii=last;
    opposite=first;
    }
    //while(opornii!=opposite){
        if((opornii<opposite)){
            conteiner=arr[opornii];//Перемещаем контейнеры
            arr[opornii]=arr[opposite];
            arr[opposite]=conteiner;

            conteiner=opornii;//Переименовываем значения
            opornii=opposite;
            opposite=conteiner;
        }
        for(i=first;i<last;i++)
        {
            if(arr[opornii]<arr[i]){
                conteiner=arr[opornii];//Перемещаем контейнеры
                arr[opornii]=arr[i];
                arr[i]=conteiner;
                
                conteiner=opornii;//Переименовываем значения
                opornii=i;

                schperem+=1;
            }else{
                if((arr[opornii]>arr[i])&&(schperem!=0))
                {
                conteiner=arr[opornii];//Перемещаем контейнеры
                arr[opornii]=arr[i];
                arr[i]=conteiner;
                conteiner=opornii;//Переименовываем значения
                opornii=i;
                }
            }
            for(int b=0;b<13;b++){
                std::cout<<arr[b]<<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n"<<"Opornii element "<<opornii;
        if(first<opornii-1)SortOfHoar(arr,first,opornii-1);
        if(opornii+1<last)SortOfHoar(arr,opornii+1,last);
        //opornii=opposite;}
}
int main()
{
    int ar[13]={16,14,2,6,17,15,13,4,7,8,9,10,3};
    int i,conteiner,opornii=0;
    int *uk=&ar[0];
    for(i=0;i<13;i++){
        std::cout<<ar[i]<<" ";
    }
    std::cout<<"\n";
    SortOfHoar(uk,0,12);
    for(i=0;i<13;i++){
        std::cout<<ar[i]<<" ";
    }
}