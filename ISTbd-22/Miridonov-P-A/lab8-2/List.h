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
void CreateNodeInTargetPlace(int place, unsigned int field_data);//����� ����������� ���� �� �������
void Add_last_special_for_generator(unsigned int field_data); //!!!!!!!
void PrintListAhead();//����� ��������� ��� �������� �� ������ �� �����
void PrintListBack();//����� ��������� ��� �������� � ����� �� ������
int getsize() {return size;};
void DeleteTargetedElement(int target);
void pop_front();//�������� ������� ��������
void clear();//������ ���������
void SearchByValue(unsigned int value);//����� ������� �� ��������
unsigned int SumOfValues();//����� ���� ���������
unsigned int AverageValue();//������� �������� ���� �������� ���������
unsigned int SearchMinValue();//����� ������������ ��������
unsigned int SearchMaxValue();//����� ������������� ��������
unsigned int& operator[](const int index);//����� �������� �� �������

private:


    int size;
    Node *head;//������ �������-������
    Node *tail;//��������� �������-�����
public:

    //����������� ���� � ������ begin � end
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

//����������� ������
void List::NewNode(unsigned int field_data)
{
    if (head == nullptr)
    {
         head  =  new Node(field_data);
        Node *current  =  head;
        cout << "��� ������ ������ �������: " << " pPrevious = " << current->pPrevious;
        cout << ";  ����� �������� ��������  =  " << current;
        cout << "; ����������  =  " << field_data;
        cout << "; pNext  =  " << current->pNext << endl;
    }
    else
    {
        Node *current  =  this->head;//������� ���������, ����������� �� ������-1�� �������
        if(size  ==  1 )
            {//���� ��� ������ �������
        Node *current_this;//��������� ��� ������������ �������� ������ ������
        current->pNext = new Node(field_data, current);//������� ����� �����, �������� pNext ���� ����� ����
        tail = current->pNext;//������� ������, ��� ��� ������� ���
        current_this = current->pNext;//������������ ����� ������ ��� ������
        current = current->pNext;//������� current �� �����, ��� ������ ��� ����������
        cout << "��� ������ ��������� �������: " << " ����� ����������� �������� = " << current->pPrevious;
        cout << "; ����� �������� = " << current_this;
        cout << "; ���������� = " << field_data;
        cout << "; ����� ���������� ��������:" << current->pNext << ";" << endl;
        }//���� �����, ��� ������
        else
        {
        Node *container_for_uk;
        Node *current_this;//��������� �� ����������� �������
        container_for_uk  =  current->pNext;//��������� � ��������� ��������� �� ��������� ������� ������
        current->pNext  =  new Node(field_data,head,container_for_uk);//�������� ������ ����
        current  =  current->pNext;//������������ �� ����. ����
        current_this  =  current;//��������������� ������ ����� ���� ��� ������ � ��������
        current  =  current->pNext;//������������ �� ����, ��� ����� ������� ��������� �� ����������
        current->pPrevious  =  current_this;//��������� ��������� �� ������� �������(2��� ��������, ����� �������� �� ��������� ���� �����) �� ���������� ��������� �� ����������� ����
        cout << "��� ������ �������: " << " ����� ����������� ��������  =  " << head;
        cout << "; ����� ����� ��������  =  " << current_this;
        cout << "; ����������  =  " << field_data;
        cout << "; ����� ���������� ��������:" << container_for_uk << ";" << endl;
        }
    }
    size++;
}

void List::Add_last_special_for_generator(unsigned int field_data) //!!!!!!!!
{
    Node *current = this->tail;
    Node *container_for_uk;
    container_for_uk = current;//������������ ���������
    current->pNext = new Node(field_data,container_for_uk);//������� ���� � �����
    current = current->pNext;
    tail = current;
    cout<<"��� ������: "<<"����� �����������  =  "<<current->pPrevious;
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
    container_for_uk = current->pNext;//������������ ���������
    current->pNext = new Node(field_data,current,container_for_uk);//������� ���� ��� ��������� �������
    current = current->pNext;//������������ ����� ���������� �� ������� ������� �� �������
    container_for_uk = current;//������������ ��� �����
    current = current->pNext;//������������ �� �������, ������� ����� ����������
    current->pPrevious = container_for_uk;//���������� ��������� �� ����������
    };
    size++;
    cout << "������� ��������" << endl;
}

//��������� ������
void List::PrintListAhead()
{
    Node *current = this->head;
    for(int i = 0; i < size; i++)
    {
        cout << "������� " << i << ":" << " ����� ����������� �������� = " << current->pPrevious;
        cout << "; ���������� = " << current->field_data;
        cout << "; ����� ���������� �������� = " << current->pNext << ";" << endl;
        current = current->pNext;
    }
}

void List::PrintListBack()
{
    Node *current = this->tail;
    for(int i = size - 1; i != -1; i--)
    {
        cout << "������� " << i <<":" << " ����� ����������� �������� = " << current->pPrevious;
        cout << "; ���������� = " << current->field_data;
        cout << "; ����� ���������� �������� = " << current->pNext << ";" << endl;
        current = current->pPrevious;
    }
}

//��������� ������
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
    container_for_uk = current;//������������ ����� ���������� ����� �������� ��������
    current = current->pPrevious;//��������� �� ��������� �������
    uk_to_delete = current;//���������� ����� ����������
    current = current->pPrevious;//��������� �� ������� �� ����������
    current->pNext = container_for_uk;//������������� ����� ���������� �� ����� ����� ����������
    container_for_uk = current;//���������� ����� ��������
    current = current->pNext;//��������� �� ������� ����� ���������� �� ������������ ����
    current->pPrevious = container_for_uk;//������������� ��������� �� ���������� � ���������� ��������
    delete uk_to_delete;
    }
    else
        {
        current = tail;
        tail = tail->pPrevious;
        delete current;
    }
    size--;

    cout << "������� ������" << endl;
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

//������ ������
void List::SearchByValue(unsigned int value)
{
    Node *current = this->head;
    int i = 0;
    if((current->field_data) == value)
        {
        cout << "������ �������� �������� " << i;
    }
    else
        {
    while(((current->field_data) != value) && (i != size -1))
    {
        current = current->pNext;
        i++;
    }
    if(i != 0)
    cout << "������ �������� �������� " << i <<endl;
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
