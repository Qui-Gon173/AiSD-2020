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
            for(int b=0;b<8;b++){
                std::cout<<arr[b]<<" ";
            }
            std::cout<<"\n";
        }
        if(first<opornii-1)SortOfHoar(arr,first,opornii-1);
        if(opornii+1<last)SortOfHoar(arr,opornii+1,last);
}
int main()
{
    int ar[8]={9,6,3,4,10,8,2,7};
    int i;
    int *uk=&ar[0];
    for(i=0;i<8;i++){
        std::cout<<ar[i]<<" ";
    }
    std::cout<<"\n";
    SortOfHoar(uk,0,7);
    for(i=0;i<8;i++){
        std::cout<<ar[i]<<" ";
    }
}