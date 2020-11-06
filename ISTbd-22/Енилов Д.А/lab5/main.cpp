#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

void MergeSort(int *arr, int number_left, int number_right)
{

    //нужен массив-хранилище
    int arr_conteiner[20];
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
    //указатель на поток
    FILE* file=fopen("file.txt","r");
    if(file==0){return 1;};
    int value,counter=0;
    //здесь мы узнаем сколько чисел в массиве будет
    while(true){
        if(fscanf(file,"%d",&value)==1)
        counter++;
        if(feof(file))
        break;
    }
    int size=counter;
    //создание массива под считанные числа, выделяем блок памяти ивозвращаем указатель на начало блока
    int* array_in=(int*)malloc(sizeof(int)*size);
    //установка указателя чтения на начало файла
    fseek(file,0,SEEK_SET);
    //проходим по файлу еще раз, теперь считывая в созданный массив значения
    for (int i = 0; i < size; ++i) {
    fscanf(file, "%d", &array_in[i]);
    } 
    int *uk=&array_in[0];
    for(int i=0;i<size;i++)
    std::cout<<array_in[i]<<" ";
    MergeSort(uk,0,size-1);
    std::cout<<"\n";
    for(int i=0;i<size;i++)
    std::cout<<array_in[i]<<" ";
    //Кусочек, записывающий вместо исходного массива отсортированный
    //ofstream object;
    //object.open("file.txt");
    //for(int i=0;i<size;i++)
    //object<<array_in[i]<<" ";
}