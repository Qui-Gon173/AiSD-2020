#include <iostream>
#include <algorithm>
#include "List.h"
#include <list>
#include "my_geo_generator.h"

using namespace std;
//вывод контейнера
void print_conteiner(List& conteiner)
{
	cout << "Общее количество элементов = " << conteiner.getsize() << endl;

	for(auto& item:conteiner)
        {
		cout << item << endl;
	}
}
//вывод суммы контейнера
void calculate_sum(List& conteiner)
{
	unsigned long s = 0;
	for(auto& item:conteiner)
	{
		s += item;
	}
    cout << "Сумма = " << s << endl;
}
//вывод среднего значения контейнера
void calculate_average_Value(List& conteiner)
{
	unsigned long s = 0;
	for(auto& item:conteiner)
        {
		s += item;
	}
    s = s/conteiner.getsize();
    cout << "Среднее значение = " << s << endl;
}

//вывод минимального значения<algorithm>
void MinValue(List& conteiner)
{
    auto s = min_element(conteiner.begin(), conteiner.end());
    cout << "Минимальное знаение = " << *s << endl;
}

//вывод максимального значения<algorithm>
void MaxValue(List& conteiner)
{
    auto s = max_element(conteiner.begin(), conteiner.end());
    cout << "Максимальное значениее = " << *s << endl;
}
//вывод индекса минимального значения<algorithm>
void MinValueIndex(List& conteiner)
{
    auto s = min_element(conteiner.begin(),conteiner.end());
    cout << "Индекс минимального элемента = ";
    conteiner.search_by_value(*s);
    cout <<  endl;
}
//вывод индекса максимального значения<algorithm>
void MaxValueIndex(List& conteiner)
{
    auto s = max_element(conteiner.begin(),conteiner.end());
    cout << "Индекс максимального значения = ";
    conteiner.search_by_value(*s);
}

void init_conteiner(List& conteiner, unsigned long first, unsigned long borderValue, int denominator)
{
	auto generator =  my_geo_generator(first, borderValue, denominator);
	for(auto& item:generator)
    {
		conteiner.Add_last_special_for_generator(item);
	}
}

int main()
{
    setlocale(LC_ALL, "Russian");
    auto conteiner = new List;
    conteiner->new_node(1);
    conteiner->new_node(1212);
    conteiner->new_node(123);
    init_conteiner(*conteiner,2,16,2);

    cout << endl << "Вывод контейнера:" << endl;
    print_conteiner(*conteiner);//функция, выводящая контейнер
    calculate_sum(*conteiner);//функция, выводящая сумму значений контейнера
    calculate_average_Value(*conteiner);//функция выводящая среднее значение
    MinValue(*conteiner);//функция, выводящая минимальное значение
    MaxValue(*conteiner);//функция, выводящая максимальное значение
    MinValueIndex(*conteiner);//функция, выводящая индекс минимального значения
    MaxValueIndex(*conteiner);//функция, выводящая индекс максимального значения
    cout << endl << endl << endl << endl;

    List lst;
    lst.new_node(1);
    lst.new_node(12345);
    lst.new_node(1234);
    lst.new_node(123);
    lst.new_node(12);
    cout << "---------------" << endl << "вывели стартовый список с конца до начала:" << endl;
    lst.print_list_back();
    cout << "---------------" << endl;
    lst.creation_node_in_target_place(2,55);//метод вставки
    lst.delete_target_element(3);//метод удаления
    cout << "---------------" << endl << "вывели список с конца до начала:" << endl;
    lst.print_list_ahead();
    cout << "---------------" << endl << "Найдем индекс элемента со значением 123:" << endl;
    lst.search_by_value(123);
    cout << "Сумма значений элементов списка: " << lst.sum_values_list();
    cout << endl << "Cреднее значение элементов списка: " << lst.mid_value();
    cout << endl << "Минимальное значение: " << lst.find_min_value();
    cout << endl << "Максимальное значение: " << lst.find_max_value();
    cout << endl << "Всего элементов в списке: " << lst.getsize();//метод возвращающий количество элементов
    conteiner->clear();//чистка контейнера
    return 0;
}
