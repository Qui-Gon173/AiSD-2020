#pragma once
#include <iostream>
#include "Node.cpp"
#include "my_iterator.cpp"
#include "List.h"

List::List() : head(nullptr) 
{
    size=0;
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
   if (current==NULL) 
   cout<<"Item not found"<<endl;
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

	size++;
}
void List::push_front(unsigned int data)
{
	head = new Node(data, head);
	size++;
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

		size++;
    }
  }

void List::pop_front()
{
	Node *temp = head;

	head = head->pNext;

	delete temp;

	size--;

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

		size--;
	}
}

void List::clear()
{
	while (size)
	{
		pop_front();
	}
}

void List::poiskIndex(unsigned int value)
 {
     Node *current = this->head;
    int i=0;
    if((current->data)==value)
    {
        cout<<"\nThe index of this item: "<<i<<endl;
    }
    else
    {
        while (((current->data)!=value) && (i!=size-1))
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
    for(int i=0;i<size;i++)
    {
        cout<<current->data<<' ';
        current=current->pNext;
    }
}

unsigned int List::summ()
{
    unsigned int summ = 0;
    Node *current= this->head;
    for(int i=0; i<size; i++)
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
    for(int i=0; i<size; i++)
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
    for(int i=0; i<size; i++)
    {
       if(current->data>max)
       max=current->data;
       current=current->pNext;
    }
    return max;
}
