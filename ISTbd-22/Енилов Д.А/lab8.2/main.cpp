#include <iostream>
#include <algorithm>
#include "List.h"
#include <list>
#include "my_geo_generator.cpp"

using namespace std;
//вывод контейнера
void print_container(List& container){
	cout<<"size: "<<container.getsize()<<endl;
	
	for(auto& item:container){
		cout<<item<<endl;
	}
}
//вывод суммы контейнера
void calculate_sum(List& container){
	//cout<<"size: "<<container.getsize()<<endl;
	unsigned long s=0;
	for(auto& item:container){
		s+=item;
	}
    cout<<"Sum: "<<s<<endl;
}
//вывод среднего значения контейнера
void calculate_midValue(List& container){
	//cout<<"size: "<<container.getsize()<<endl;
	unsigned long s=0;
	for(auto& item:container){
		s+=item;
	}
    s=s/container.getsize();
    cout<<"MidValue: "<<s<<endl;
}

//вывод минимального значения<algorithm>
void MinValue(List& container){
    auto s=min_element(container.begin(),container.end());
    cout<<"MinValue: "<<*s<<endl;
}

//вывод максимального значения<algorithm>
void MaxValue(List& container){
    auto s=max_element(container.begin(),container.end());
    cout<<"MaxValue: "<<*s<<endl;
}

//вывод индекса минимального значения<algorithm>
void MinValueIndex(List& container){

    auto s=min_element(container.begin(),container.end());
    cout<<"MinValueIndex ";
    container.poisk_by_value(*s);
}

//вывод индекса максимального значения<algorithm>
void MaxValueIndex(List& container){

    auto s=max_element(container.begin(),container.end());
    cout<<"MaxValueIndex ";
    container.poisk_by_value(*s);
}

void init_container(List& container,unsigned long first,unsigned long borderValue,int denominator){
	auto generator= my_geo_generator(first,borderValue,denominator);

	for(auto& item:generator){
		container.Add_last_special_for_generator(item);
	}
}

int main()
{
    /*WAS BEFORE
    //создаем список и начальные узлы
    //создаем список и начальные узлы
    List lst;
    lst.just_create_node(1);//создали голову
    lst.just_create_node(1234);//создали хвост
    lst.just_create_node(123);//создали 1ый стартовый элемент
    lst.just_create_node(12);//создали 2ой стартовый элемент
    lst.printList_from_head_to_tail();//вывели стартовый список от начала до конца
    */
    //NOW
    auto container=new List;
    container->just_create_node(1);
    container->just_create_node(12);
    //container->just_create_node(123);
    init_container(*container,2,16,2);

    print_container(*container);//функция, выводящая контейнер
    //calculate_sum(*container);//функция, выводящая сумму значений контейнера
    //calculate_midValue(*container);//функция выводящая среднее значение
    //MinValue(*container);//функция, выводящая минимальное значение
    //MaxValue(*container);//функция, выводящая максимальное значение
    //MinValueIndex(*container);//функция, выводящая индекс минимального значения
    //MaxValueIndex(*container);//функция, выводящая индекс максимального значения


    //lst.printList_from_tail_to_head();//вывели стартовый список с конца до начала
    //lst.creation_node_in_target_place(2,55);метод вставки
    //lst.delete_target_element(3);//метод удаления
    //lst.printList_from_head_to_tail();вывели список с конца до начала
    //lst.poisk_by_value(123);//метод поиска элемента со значением 123
    //cout<<lst.sum_values_list();метод возвращающий сумму значений элементов списка
    //cout<<lst.mid_value();метод возвращающий среднее значение элементов списка
    //cout<<lst.find_min_value();//метод возвращающий минимальный элемент
    //cout<<lst.find_max_value();//метод возвращающий максимальный элемент
    //cout<<"\n"<<lst.getsize();//метод возвращающий количество элементов
    container->clear();//чистка контейнера
    return 0;
}