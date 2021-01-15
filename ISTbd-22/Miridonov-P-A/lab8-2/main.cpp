#include <iostream>
#include <algorithm>
#include "List.h"
#include <list>
#include "ExponentialFunctionGenerator.h"

using namespace std;
//����� ����������
void print_container(List& container)
{
	cout << "����� ���������� ��������� = " << container.getsize() << endl;

	for(auto& item:container)
        {
		cout << item << endl;
	}
}
//����� ����� ����������
void calculate_sum(List& container)
{
	unsigned int s = 0;
	for(auto& item:container)
	{
		s += item;
	}
    cout << "����� = " << s << endl;
}
//����� �������� �������� ����������
void calculate_average_Value(List& container)
{
	unsigned int s = 0;
	for(auto& item:container)
        {
		s += item;
	}
    s = s/container.getsize();
    cout << "������� �������� = " << s << endl;
}

//����� ������������ ��������<algorithm>
void MinValue(List& container)
{
    auto s = min_element(container.begin(), container.end());
    cout << "����������� �������� = " << *s << endl;
}

//����� ������������� ��������<algorithm>
void MaxValue(List& container)
{
    auto s = max_element(container.begin(), container.end());
    cout << "������������ �������� = " << *s << endl;
}
//����� ������� ������������ ��������<algorithm>
void MinValueIndex(List& container)
{
    auto s = min_element(container.begin(),container.end());
    cout << "������ ������������ �������� = ";
    container.SearchByValue(*s);
    cout <<  endl;
}
//����� ������� ������������� ��������<algorithm>
void MaxValueIndex(List& container)
{
    auto s = max_element(container.begin(),container.end());
    cout << "������ ������������� �������� = ";
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

    cout << endl << "����� ����������:" << endl;
    print_container(*container);//�������, ��������� ���������
    calculate_sum(*container);//�������, ��������� ����� �������� ����������
    calculate_average_Value(*container);//������� ��������� ������� ��������
    MinValue(*container);//�������, ��������� ����������� ��������
    MaxValue(*container);//�������, ��������� ������������ ��������
    MinValueIndex(*container);//�������, ��������� ������ ������������ ��������
    MaxValueIndex(*container);//�������, ��������� ������ ������������� ��������
    cout << endl << endl << endl << endl;
/*
    List lst;
    lst.NewNode(1);
    lst.NewNode(2);
    lst.NewNode(3);
    lst.NewNode(4);
    lst.NewNode(999);
    cout << "---------------" << endl << "������ ��������� ������ � ����� �� ������:" << endl;
    lst.PrintListBack();
    cout << "---------------" << endl;
    lst.CreateNodeInTargetPlace(2,55);//����� �������
    lst.DeleteTargetedElement(3);//����� ��������
    cout << "---------------" << endl << "������ ������ � ����� �� ������:" << endl;
    lst.PrintListAhead();
    cout << "---------------" << endl << "������ ������ �������� �� ��������� 123:" << endl;
    lst.SearchByValue(123);
    cout << "����� �������� ��������� ������: " << lst.SumOfValues();
    cout << endl << "C������ �������� ��������� ������: " << lst.AverageValue();
    cout << endl << "����������� ��������: " << lst.SearchMinValue();
    cout << endl << "������������ ��������: " << lst.SearchMaxValue();
    cout << endl << "����� ��������� � ������: " << lst.getsize();//����� ������������ ���������� ���������
    container->clear();//������ ���������� */
    return 0;
}
