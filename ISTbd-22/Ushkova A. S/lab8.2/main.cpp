#include <iostream>
#include <algorithm>
#include "List.h"
#include <list>
#include "geometric_generator.cpp"

using namespace std;
//вывод контейнера
void print(List& container){
	cout<<"size: "<<container.GetSize()<<endl;
	
	for(auto& item:container){
		cout<<item<<endl;
	}
}
//вывод суммы контейнера
void summ(List& container){
	//cout<<"size: "<<container.getsize()<<endl;
	unsigned long sum=0;
	for(auto& item:container){
		sum+=item;
	}
    cout<<"Sum: "<<sum<<endl;
}
//вывод среднего значения контейнера
void average(List& container){
	//cout<<"size: "<<container.getsize()<<endl;
	unsigned long a=0;
	for(auto& item:container){
		a+=item;
	}
    a=a/container.GetSize();
    cout<<"Average value of elements: "<<a<<endl;
}

//вывод минимального значения<algorithm>
void min(List& container){
    auto min=min_element(container.begin(),container.end());
    cout<<"Minimum element: "<<*min<<endl;
}

//вывод максимального значения<algorithm>
void max(List& container){
    auto max=max_element(container.begin(),container.end());
    cout<<"Maximum element: "<<*max<<endl;
}

//вывод индекса минимального значения<algorithm>
void minIndex(List& container){

    auto minIn=min_element(container.begin(),container.end());
    cout<<"Minimum index element ";
    container.poisk_index(*minIn);
}

//вывод индекса максимального значения<algorithm>
void maxIndex(List& container){

    auto maxIn=max_element(container.begin(),container.end());
    cout<<"Maximum index element ";
    container.poisk_index(*maxIn);
}

void geometric(List& container,unsigned long first,unsigned long border,int factor){
	auto generator= geometric_generator(first,border,factor);

	for(auto& item:generator){
		container.push_back(item);
	}
}

int main()
{
//    List lst;
//    lst.push_front(3);
//    lst.printList();
    auto container=new List;
    container->push_front(1);
    container->push_front(12);
    geometric(*container,2,64,2);
    print(*container);//функция, выводящая контейнер
    container->clear();//чистка контейнера
    system("pause");
    return 0;
}