#pragma once
#include <iostream>
#include "Node.cpp"
#include "my_iterator.cpp"

using namespace std;

class List
{
 public:
    List();
    ~List();
    //добавление в конец
    void push_back(unsigned int data);
    //Счетчик
    int GetSize(){return Size;}
    //Возврат значение по индексу
    unsigned int& operator[](const int index);
    //Добавление элемента в начало списка
    void push_front(unsigned int data);
    //Добавление элемента по заданному индексу
    void insert(unsigned int data, int index);
    //удаление элемента в списке по указанному индексу
	void removeAt(int index);
    //удаление первого элемента в списке
	void pop_front();
    //Очистить список
	void clear();
    //Вывод индекса по определенному значению
    void poisk_index(unsigned int value);
    //Печать списка
    void printList();
    //Сумма всех значений
    unsigned int summ();
    //Среднее значение
    unsigned int average();
    //Минимальное значение
    unsigned int min();
    //Максимальное значение
    unsigned int max();
   

 private:
        int Size;
        Node *head;
        Node *last;
 public:
    ////////////////////////////////////////Explosion ZONE
    //Опрпеделяем типы и методы begin и end
    typedef my_iterator const_iterator;
    const_iterator begin() const{
        return const_iterator(head);
    };
    const_iterator end() const{
        return const_iterator(nullptr);
    };
};

List::List() : head(nullptr) 
{
    Size=0;
}
List::~List()
{
}

unsigned int& List::operator[](const int index)
{
   int count = 0;
   Node * current = this->head;
   while(current!=NULL)
   {
       if(count==index)
       {
           return current->data;
       }
      current = current->pNext;
      count++;
   }
   if (count == 0) 
   cout<<"Item not found";
}

void List::push_back(unsigned int data){

   if (head == NULL)
	{
		head = new Node(data);
	}
	else
	{
		Node *current = this->head;

		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);

	}

	Size++;
}
void List::push_front(unsigned int data)
{
	head = new Node(data, head);
	Size++;
}

void List::insert(unsigned int data, int index)
{
  if (index == 0)
	{
		push_front(data);
	}
    else
	{
		Node *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node *newNode = new Node(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
    }
  }

void List::pop_front()
{
	Node *temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

void List::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		
		Node *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}

void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}

void List::poisk_index(unsigned int value)
 {
     Node *current = this->head;
    int i=0;
    if((current->data)==value)
    {
        cout<<"\nThe index of this item: "<<i<<endl;
    }
    else
    {
        while (((current->data)!=value) && (i!=Size-1))
        {
            current=current->pNext;
            i++;
        }
        if(i!=0)
        cout<<"\nThe index of this item: "<<i<<endl;
    }
    
 }
    
void List::printList()
{
    Node *current=this->head;
    cout<<"Print List"<<endl;
    for(int i=0;i<Size;i++)
    {
        cout<<current->data<<' ';
        current=current->pNext;
    }
}

unsigned int List::summ()
{
    unsigned int summ = 0;
    Node *current= this->head;
    for(int i=0; i<Size; i++)
    {
       summ+=current->data;
       current=current->pNext;
    }
    return summ;
}

unsigned int List::average()
{
    unsigned int ava;
    ava= summ()/GetSize();
    return ava;
}

unsigned int List::min()
{
    Node *current=this->head;
    unsigned int min = current->data;
    for(int i=0; i<Size; i++)
    {
       if(current->data<min)
       min=current->data;
       current=current->pNext;
    }
    return min;
}

unsigned int List::max()
{
    Node *current=this->head;
    unsigned int max = current->data;
    for(int i=0; i<Size; i++)
    {
       if(current->data>max)
       max=current->data;
       current=current->pNext;
    }
    return max;
}
