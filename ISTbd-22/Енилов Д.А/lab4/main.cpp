#include <iostream>

using namespace std;
//Функция проверки и построения одного корня
void HeapElement(int *array,int lookroot,int heap_size)//получает массив и индекс рассматриваемого элемента(возможного корня)
{
    int leftelement=2*lookroot+1,//определение левого элемента
    rightelement=2*lookroot+2,//определение правого элемента
    conteiner,
    largest=lookroot;//наибольший=рассматриваемый

    //Проверяем, не выходит ли номер левого элемента за границу массива и больше ли он наибольшего:
    if((leftelement<=heap_size)&&(array[leftelement]>array[largest]))
    largest=leftelement;//если да, меняем номер самого большого на номер левого, ведь он больше

    if((rightelement<=heap_size)&&(array[rightelement]>array[largest]))
    largest=rightelement;

    //Если замена была, то меняем САМИ элементы, переопределяя больший элемент, потом запускаем рекурсию 
    if (largest!=lookroot){
        conteiner=array[lookroot];
        array[lookroot]=array[largest];
        array[largest]=conteiner;
        HeapElement(array,largest,heap_size);
    }
}
//Функция постройки кучи целиком
void DoHeap(int *array,int heap_size)
{
    bool flag=false;
    while(flag==false){
    for(int i=6;i>-1;i--){//Кусочек, отвечающий за изменение кучи
    HeapElement(array,i,heap_size);
    }
    int countrightroot=0;//Проверяем, вся ли куча удовлетворяет условиям?
    for(int i=0;i<heap_size/2;i++){
        if((array[i]>array[2*i+1])&&(array[i]>array[2*i+2]))
            countrightroot+=1;
    }
    if(countrightroot==heap_size/2)
    flag=true;
    }
}
//Функция пирамидальной сортировки кучи
void PyramideSort(int *array)
{
    int conteiner,heap_size=11;
    DoHeap(array,heap_size);
    //мы перемещаем 1ый элемент(в куче он наибольший) в конец и исключаем его номер,затем снова создаем кучу
    for(int i=11;i!=0;i--){
        conteiner=array[0];
        array[0]=array[i];
        array[i]=conteiner;
        heap_size-=1;
        DoHeap(array,heap_size);
        //HeapElement(array,1,heap_size);
    }
}
int main()
{
    int array[12]={3,4,16,20,5,17,7,19,2,0,14,15};
    int *uk=&array[0];
    for(int i=0;i<12;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
    PyramideSort(uk);
        for(int i=0;i<12;i++){
        cout<<array[i]<<" ";
    }
}