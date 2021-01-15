#pragma once
#include <iostream>
#include "Node.h"
#include "my_iterator.h"

using namespace std;

class List
{
public:
List();
~List();
void NewNode(unsigned int field_data);
void CreateNodeInTargetPlace(int place, unsigned int field_data);//метод вставляющий узел на позицию
void Add_last_special_for_generator(unsigned int field_data); //!!!!!!!
void PrintListAhead();//метод выводящий все элементы от начала до конца
void PrintListBack();//метод выводящий все элементы с конца до начала
int getsize() {return size;};
void DeleteTargetedElement(int target);
void pop_front();//удаление первого элемента
void clear();//чистим контейнер
void SearchByValue(unsigned int value);//поиск индекса по значению
unsigned int SumOfValues();//сумма всех элементов
unsigned int AverageValue();//среднее значение всех значений элементов
unsigned int SearchMinValue();//поиск минимального значения
unsigned int SearchMaxValue();//поиск максимального значения
unsigned int& operator[](const int index);//вывод значения по индексу

private:


    int size;
    Node *head;//первый элемент-голова
    Node *tail;//последний элемент-хвост
public:

    //Опрпеделяем типы и методы begin и end
    typedef my_iterator const_iterator;
    const_iterator begin() const{
        return const_iterator(head);
    };
    const_iterator end() const{
        return const_iterator(tail->pNext);
    };
};

List::List() : head(nullptr), tail(nullptr)
{
    size = 0;
}
List::~List()
{
}
unsigned int & List::operator[](const int index)
{
    int counter = 0;
    Node *current = this->head;
    while(current != nullptr)
    {
        if(counter == index){
            return current->field_data;
        }
        current = current->pNext;
        counter++;
    }

}

//Добавляющие методы
void List::NewNode(unsigned int field_data)
{
    if (head == nullptr)
    {
         head  =  new Node(field_data);
        Node *current  =  head;
        cout << "Был создан первый элемент: " << " pPrevious = " << current->pPrevious;
        cout << ";  Адрес текущего элемента  =  " << current;
        cout << "; Информация  =  " << field_data;
        cout << "; pNext  =  " << current->pNext << endl;
    }
    else
    {
        Node *current  =  this->head;//создаем указатель, указывающий на голову-1ый элемент
        if(size  ==  1 )
            {//Если это второй элемент
        Node *current_this;//указатель для демонстрации текущего адреса хвоста
        current->pNext = new Node(field_data, current);//создаем новый хвост, присвоив pNext хеда новый узел
        tail = current->pNext;//говорим хвосту, что это создали его
        current_this = current->pNext;//аккумулируем адрес хвоста для вывода
        current = current->pNext;//смещаем current на хвост, для вывода его параметров
        cout << "Был создан последний элемент: " << " Адрес предыдущего элемента = " << current->pPrevious;
        cout << "; адрес элемента = " << current_this;
        cout << "; Информация = " << field_data;
        cout << "; адрес следующего элемента:" << current->pNext << ";" << endl;
        }//Если более, чем второй
        else
        {
        Node *container_for_uk;
        Node *current_this;//указатель на создаваемый элемент
        container_for_uk  =  current->pNext;//помещение в контейнер указателя на следующий элемент головы
        current->pNext  =  new Node(field_data,head,container_for_uk);//создание нового узла
        current  =  current->pNext;//переключение на след. узел
        current_this  =  current;//аккумулирование адреса этого узла для вывода и проверки
        current  =  current->pNext;//переключение на узел, где нужно сменить указатель на предыдущий
        current->pPrevious  =  current_this;//изменение указателя на прошлый элемент(2ого элемента, между которыми мы вставляем узел новый) на правильный указатель на вставляемый узел
        cout << "Был создан элемент: " << " Адрес предыдущего элемента  =  " << head;
        cout << "; адрес этого элемента  =  " << current_this;
        cout << "; Информация  =  " << field_data;
        cout << "; адрес следующего элемента:" << container_for_uk << ";" << endl;
        }
    }
    size++;
}

void List::Add_last_special_for_generator(unsigned int field_data) //!!!!!!!!
{
    Node *current = this->tail;
    Node *container_for_uk;
    container_for_uk = current;//аккумулируем указатель
    current->pNext = new Node(field_data,container_for_uk);//создаем узел в конце
    current = current->pNext;
    tail = current;
    cout<<"Был создан: "<<"Адрес предыдущего  =  "<<current->pPrevious;
    cout<<" Data = "<<current->field_data;
    cout<<" pNext = "<<current->pNext << endl;
}

void List::CreateNodeInTargetPlace(int place,unsigned int field_data)
{
    Node *current = this->head;
    if(place == 0)
        {
        current->pPrevious = new Node(field_data, nullptr, current);
        head = current->pPrevious;
    }
    else
    {

        if (place <= size/2)
        {
            current = head;
            int i = 1;
            while ( i < place)
            {
                current = current->pNext;
                i++;
            }
        }
        else
        {
            current = tail;
        int i = 1;
        while (i <= size - place)
        {
            current = current->pPrevious;
            i++;
        }
        }
    Node *container_for_uk;
    container_for_uk = current->pNext;//аккумулируем указатель
    current->pNext = new Node(field_data,current,container_for_uk);//создаем узел под выбранным номером
    current = current->pNext;//перемещаемся нашим указателем на элемент который мы создали
    container_for_uk = current;//аккумулируем его адрес
    current = current->pNext;//перемещаемся на элемент, стоящий после созданного
    current->pPrevious = container_for_uk;//исправляем указатель на предыдущий
    };
    size++;
    cout << "Элемент добавлен" << endl;
}

//Вывлдящие методы
void List::PrintListAhead()
{
    Node *current = this->head;
    for(int i = 0; i < size; i++)
    {
        cout << "Элемент " << i << ":" << " адрес предыдущего элемента = " << current->pPrevious;
        cout << "; Информация = " << current->field_data;
        cout << "; Адрес следующего элемента = " << current->pNext << ";" << endl;
        current = current->pNext;
    }
}

void List::PrintListBack()
{
    Node *current = this->tail;
    for(int i = size - 1; i != -1; i--)
    {
        cout << "Элемент " << i <<":" << " адрес предыдущего элемента = " << current->pPrevious;
        cout << "; Информация = " << current->field_data;
        cout << "; Адрес следующего элемента = " << current->pNext << ";" << endl;
        current = current->pPrevious;
    }
}

//Удаляющие методы
void List::DeleteTargetedElement(int target)
{
    Node *current = this->head;
    if(target == 0)
        {
       cout << "Input position: ";
       cin >> target;
    }
    if(target > 0 && target < size-1)
    {
        if (target <= size/2)
        {
            current = head;
            int i = 1;
            while ( i < target)
            {
                current = current->pNext;
                i++;
            }
        }
        else
        {
            current = tail;
        int i = size;
        while (i <= size - target)
        {
            current = current->pPrevious;
            i--;
        }
        }
    Node *container_for_uk;
    Node *uk_to_delete;
    container_for_uk = current;//аккумулируем адрес следующего после удаления элемента
    current = current->pPrevious;//переходим на удаляемый элемент
    uk_to_delete = current;//запоминаем адрес удаляемого
    current = current->pPrevious;//переходим на элемент до удаляемого
    current->pNext = container_for_uk;//переназначаем адрес следующего на адрес после следующего
    container_for_uk = current;//запоминаем адрес текущего
    current = current->pNext;//переходим на элемент после удаляемого по обновленному пути
    current->pPrevious = container_for_uk;//переназначаем указатель на предыдущий с удаляемого элемента
    delete uk_to_delete;
    }
    else
        {
        current = tail;
        tail = tail->pPrevious;
        delete current;
    }
    size--;

    cout << "Элемент удален" << endl;
}

void List::pop_front()
{
    Node *temp = head;
    if(head->pNext != nullptr)
        {
    head = head->pNext;
    head->pPrevious = nullptr;
    delete temp;
    size--;
    }
    else
    {
         delete head;
         size--;
    }

}

void List::clear()
{
    while(size)
    {
        pop_front();
    }
}

//Методы поиска
void List::SearchByValue(unsigned int value)
{
    Node *current = this->head;
    int i = 0;
    if((current->field_data) == value)
        {
        cout << "Индекс искомого элемента " << i;
    }
    else
        {
    while(((current->field_data) != value) && (i != size -1))
    {
        current = current->pNext;
        i++;
    }
    if(i != 0)
    cout << "Индекс искомого элемента " << i <<endl;
    };
}

unsigned int List::SumOfValues()
{
    unsigned int sum = 0;
    Node *current = this->head;
    while(current->pNext != nullptr)
    {
        sum += current->field_data;
        current = current->pNext;
    }
    return sum;
}

unsigned int List::AverageValue()
{
    unsigned int average;
    average = SumOfValues()/size;
    return average;
}

unsigned int List::SearchMinValue()
{
    Node *current = this->head;
    unsigned int min = current->field_data;
    while((current->pNext) != nullptr)
    {
        if(current->field_data<min)
        min = current->field_data;
        current = current->pNext;
    }
    return min;
}

unsigned int List::SearchMaxValue()
{
    Node *current = this->head;
    unsigned int max = current->field_data;
    while((current->pNext) != nullptr)
    {
        current = current->pNext;
        if(current->field_data>max)
        max = current->field_data;

    }
    return max;
}
