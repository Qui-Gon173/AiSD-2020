#include <iostream>
#include <cstdio>

using namespace std;

void MergeSort(int *arr, int number_left, int number_right)
{
    //нужен массив-хранилище
    int arr_conteiner[12];
    if (number_left == number_right) {
        return;//если левая граница совпадает с правой, то мы дошли до массива в 1 элемент
    }
    //находим центр
    int middle = (number_left + number_right) / 2;

    //рекурсивно повторяем алгоритм, сместив границы
    MergeSort(arr, number_left, middle);
    MergeSort(arr, middle + 1, number_right);


    int l_cur = number_left, r_cur = middle + 1;
    //прогоняем цикл для всех элементов массива контейнера от нуля до правой границы
    for (int step = 0; step <= number_right; step++)
    {//в массив хранилище сначала выбираются и записываются меньшие элементы из пар, четверок и т д
    //если текущий правый элемент больше текущего левого, то все нормально, записываем так, если нет записываем сначала правый, ибо он больше
    //если правый текущий больше правого в общем, то уже нет смысла сравнивать кто больше, так как остались лишь элементы слева
        if ((r_cur>number_right)||((l_cur<=middle)&&(arr[l_cur]<arr[r_cur])))
        {
            std::cout<<"r_cur="<<r_cur<<"\n";
            std::cout<<"number_right="<<number_right<<"\n";
            std::cout<<arr[l_cur]<<"<"<<arr[r_cur]<<"\n";
            arr_conteiner[step]=arr[l_cur];
            l_cur++;
        }
        else 
        {
            arr_conteiner[step] = arr[r_cur];
            r_cur++;
        }
    }
    //результат записываем в основной массив
    for(int step=0;step<number_right-number_left+1;step++)
    arr[number_left+step]=arr_conteiner[step];
}

int main()
{
    int arr[12]={14,12,5,3,6,7,17,8,1,2,18,9};
    int *uk1=&arr[0];
    for(int i=0;i<12;i++)
    std::cout<<arr[i]<<" ";
    std::cout<<"\n";
    MergeSort(uk1,0,11);
    for(int i=0;i<12;i++)
    std::cout<<arr[i]<<" ";
}