#include <iostream>
#include <algorithm>
#include "List.h"
#include <list>
#include "ExponentialFunctionGenerator.h"

using namespace std;
//вывод контейнера
void print_container(List& container)
{
	cout << "Общее количество элементов = " << container.getsize() << endl;

	for(auto& item:container)
        {
		cout << item << endl;
	}
}
//вывод суммы контейнера
void calculate_sum(List& container)
{
	unsigned int s = 0;
	for(auto& item:container)
	{
		s += item;
	}
    cout << "Сумма = " << s << endl;
}
//вывод среднего значения контейнера
void calculate_average_Value(List& container)
{
	unsigned int s = 0;
	for(auto& item:container)
        {
		s += item;
	}
    s = s/container.getsize();
    cout << "Среднее значение = " << s << endl;
}

//вывод минимального значения<algorithm>
void MinValue(List& container)
{
    auto s = min_element(container.begin(), container.end());
    cout << "Минимальное значение = " << *s << endl;
}

//вывод максимального значения<algorithm>
void MaxValue(List& container)
{
    auto s = max_element(container.begin(), container.end());
    cout << "Максимальное значение = " << *s << endl;
}
//вывод индекса минимального значения<algorithm>
void MinValueIndex(List& container)
{
    auto s = min_element(container.begin(),container.end());
    cout << "Индекс минимального элемента = ";
    container.SearchByValue(*s);
    cout <<  endl;
}
//вывод индекса максимального значения<algorithm>
void MaxValueIndex(List& container)
{
    auto s = max_element(container.begin(),container.end());
    cout << "Индекс максимального значения = ";
    container.SearchByValue(*s);
}

void init_container(List& container, unsigned int first, unsigned int borderValue, int denominator)
{
	auto generator =  ExponentialFunctionGenerator(first, borderValue, denominator);
	for(auto& item:generator)
    {
		container.Add_last_special_for_generator(item);
	}
}

int main()
{
    setlocale(LC_ALL, "Russian");
    auto container = new List;
    container->NewNode(1111);
    container->NewNode(9999);
    init_container(*container,2,20,1);

    cout << endl << "Вывод контейнера:" << endl;
    print_container(*container);//функция, выводящая контейнер
    calculate_sum(*container);//функция, выводящая сумму значений контейнера
    calculate_average_Value(*container);//функция выводящая среднее значение
    MinValue(*container);//функция, выводящая минимальное значение
    MaxValue(*container);//функция, выводящая максимальное значение
    MinValueIndex(*container);//функция, выводящая индекс минимального значения
    MaxValueIndex(*container);//функция, выводящая индекс максимального значения
    cout << endl << endl << endl << endl;
/*
    List lst;
    lst.NewNode(1);
    lst.NewNode(2);
    lst.NewNode(3);
    lst.NewNode(4);
    lst.NewNode(999);
    cout << "---------------" << endl << "вывели стартовый список с конца до начала:" << endl;
    lst.PrintListBack();
    cout << "---------------" << endl;
    lst.CreateNodeInTargetPlace(2,55);//метод вставки
    lst.DeleteTargetedElement(3);//метод удаления
    cout << "---------------" << endl << "вывели список с конца до начала:" << endl;
    lst.PrintListAhead();
    cout << "---------------" << endl << "Найдем индекс элемента со значением 123:" << endl;
    lst.SearchByValue(123);
    cout << "Сумма значений элементов списка: " << lst.SumOfValues();
    cout << endl << "Cреднее значение элементов списка: " << lst.AverageValue();
    cout << endl << "Минимальное значение: " << lst.SearchMinValue();
    cout << endl << "Максимальное значение: " << lst.SearchMaxValue();
    cout << endl << "Всего элементов в списке: " << lst.getsize();//метод возвращающий количество элементов
    container->clear();//чистка контейнера */
    return 0;
}
