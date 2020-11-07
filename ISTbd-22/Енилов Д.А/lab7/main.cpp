#include <iostream>

using namespace std;

void Move_ring(int* f_r,int* s_r,int* t_r,int from,int target){
    int i,j;
    if((target==2)&&(from==1)){//Перенос кольца с 1ого на 2ой стержень
        i=0;j=0;//для поиска номера свободных элементов массива
        while(f_r[i]!=0)
        i++;//берем отсюда
        i-=1;
        while(s_r[j]!=0)
        j++;//кладем сюда
        s_r[j]=f_r[i];
        f_r[i]=0;
        cout<<"Switch from 1 to 2\n";
    }
    if(target==3&&from==1){//Перенос кольца с 1ого на 3ий стержень
        i=0;j=0;//для поиска номера свободных элементов массива
        while(f_r[i]!=0)
        i++;//берем отсюда
        i-=1;
        while(t_r[j]!=0)
        j++;//кладем сюда
        t_r[j]=f_r[i];
        f_r[i]=0;
        cout<<"Switch from 1 to 3\n";
    }
    if((target==3)&&(from==2)){//Перенос кольца со 2ого на 3иий стержень
        i=0;j=0;//для поиска номера свободных элементов массива
        while(s_r[i]!=0)
        i++;//берем отсюда
        i-=1;
        while(t_r[j]!=0)
        j++;//кладем сюда
        t_r[j]=s_r[i];
        s_r[i]=0;
        cout<<"Switch from 2 to 3\n";
    }
    if((target==1)&&(from==2)){ //Перенос кольца со 2ого на 1ый стержень
        i=0;j=0;//для поиска номера свободных элементов массива
        while(s_r[i]!=0)
        i++;//берем отсюда
        i-=1;
        while(f_r[j]!=0)
        j++;//кладем сюда
        f_r[j]=s_r[i];
        s_r[i]=0;
        cout<<"Switch from 2 to 1\n";
    }
    if((target==1)&&(from==3)){//Перенос кольца со 3его на 1ый стержень
        i=0;j=0;//для поиска номера свободных элементов массива
        while(t_r[i]!=0)
        i++;//берем отсюда
        i-=1;
        while(f_r[j]!=0)
        j++;//кладем сюда
        f_r[j]=t_r[i];
        t_r[i]=0;
        cout<<"Switch from 3 to 1\n";
    }
    if((target==2)&&(from==3)){//Перенос кольца со 3ого на 2ый стержень
        i=0;j=0;//для поиска номера свободных элементов массива
        while(t_r[i]!=0)
        i++;//берем отсюда
        i-=1;
        while(s_r[j]!=0)
        j++;//кладем сюда
        s_r[j]=t_r[i];
        t_r[i]=0;
        cout<<"Switch from 3 to 2\n";
    }
}

void Hanoi(int* f_r,int* s_r,int* t_r,int from, int count_rings, int target)
{
    if(count_rings==1)
    Move_ring(f_r,s_r,t_r,from,target);
    else
    {
    int next_rod=6-from-target;
    Hanoi(f_r,s_r,t_r,from,count_rings-1,next_rod);
    Move_ring(f_r,s_r,t_r,from,target);
    Hanoi(f_r,s_r,t_r,next_rod,count_rings-1,target);
    }
}


int main(){
    int first_rod[8]={5,4,3,2,1,0,0,0};
    int second_rod[8]={0,0,0,0,0,0,0,0};
    int third_rod[8]={0,0,0,0,0,0,0,0};
    int *uk1=&first_rod[0];
    int *uk2=&second_rod[0];
    int *uk3=&third_rod[0];
    int i;//узнаем количество колец
    while(first_rod[i]!=0){i++;};
    Hanoi(uk1,uk2,uk3,1,i,3);
    for(int i=0;i<8;i++)
    std::cout<<first_rod[i]<<" ";
    cout<<"\n";
    for(int i=0;i<8;i++)
    std::cout<<second_rod[i]<<" ";
    cout<<"\n";
    for(int i=0;i<8;i++)
    std::cout<<third_rod[i]<<" ";
}