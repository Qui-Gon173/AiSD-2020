#include <iostream>
#include <algorithm>
#include "List.h"
#include <list>
#include "fibonacci_numbers_generator.cpp"
#include "iterator.cpp"
using namespace std;

void Print(List& container){
	cout<<"Size: "<<container.GetSize()<<endl;
	
	for(auto& item:container){
		cout<<item<<endl;
	}
}

void Sum(List& container){
	
	unsigned long s=0;
	for(auto& item:container){
		s+=item;
	}
    cout<<"Sum: "<<s<<endl;
}

void MidValue(List& container){
	unsigned long s=0;
	for(auto& item:container){
		s+=item;
	}
    s=s/container.GetSize();
    cout<<"MidValue: "<<s<<endl;
}
void fibonacci(List& container,int first,int max,int second){
	auto generator= fibonacci_numbers_generator(first,max,second);

	for(auto& item:generator){
		container.push_back(item);
	}
}
void MaxValueIndex(List& container){

    auto s=max_element(container.begin(),container.end());
    cout<<"MaxValueIndex: "<<container.searchindex(*s)<<endl;
    
}

 void MinValue(List& container){
    auto s=min_element(container.begin(),container.end());
     cout<<"MinValue: "<<*s<<endl;
 }


void MaxValue(List& container){
    auto s=max_element(container.begin(),container.end());
    cout<<"MaxValue: "<<*s<<endl;
}


void MinValueIndex(List& container){

    auto s=min_element(container.begin(),container.end());
    cout<<"MinValueIndex: "<<container.searchindex(*s)<<endl;
   
}





int main()
{
 

    // List lst;
	
	// lst.push_front(5);
	// lst.push_front(7);
	// lst.push_front(101);
    // lst.print();
      auto container=new List;
    container->push_back(2);
    container->push_back(12);
    fibonacci(*container,1,21,0);
     Print(*container);
     Sum(*container);
     MidValue(*container);
     MinValue(*container);
     MaxValue(*container);
     MinValueIndex(*container);
     MaxValueIndex(*container);
   // container->print();
    container->clear();
    system("pause");
    return 0;
}