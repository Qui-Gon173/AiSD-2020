#include <iostream>
#include <algorithm>
#include "List.h"
#include <list>
#include "my_geo_generator.h"

using namespace std;
//����� ����������
void print_conteiner(List& conteiner)
{
	cout << "����� ���������� ��������� = " << conteiner.getsize() << endl;

	for(auto& item:conteiner)
        {
		cout << item << endl;
	}
}
//����� ����� ����������
void calculate_sum(List& conteiner)
{
	unsigned long s = 0;
	for(auto& item:conteiner)
	{
		s += item;
	}
    cout << "����� = " << s << endl;
}
//����� �������� �������� ����������
void calculate_average_Value(List& conteiner)
{
	unsigned long s = 0;
	for(auto& item:conteiner)
        {
		s += item;
	}
    s = s/conteiner.getsize();
    cout << "������� �������� = " << s << endl;
}

//����� ������������ ��������<algorithm>
void MinValue(List& conteiner)
{
    auto s = min_element(conteiner.begin(), conteiner.end());
    cout << "����������� ������� = " << *s << endl;
}

//����� ������������� ��������<algorithm>
void MaxValue(List& conteiner)
{
    auto s = max_element(conteiner.begin(), conteiner.end());
    cout << "������������ ��������� = " << *s << endl;
}
//����� ������� ������������ ��������<algorithm>
void MinValueIndex(List& conteiner)
{
    auto s = min_element(conteiner.begin(),conteiner.end());
    cout << "������ ������������ �������� = ";
    conteiner.search_by_value(*s);
    cout <<  endl;
}
//����� ������� ������������� ��������<algorithm>
void MaxValueIndex(List& conteiner)
{
    auto s = max_element(conteiner.begin(),conteiner.end());
    cout << "������ ������������� �������� = ";
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

    cout << endl << "����� ����������:" << endl;
    print_conteiner(*conteiner);//�������, ��������� ���������
    calculate_sum(*conteiner);//�������, ��������� ����� �������� ����������
    calculate_average_Value(*conteiner);//������� ��������� ������� ��������
    MinValue(*conteiner);//�������, ��������� ����������� ��������
    MaxValue(*conteiner);//�������, ��������� ������������ ��������
    MinValueIndex(*conteiner);//�������, ��������� ������ ������������ ��������
    MaxValueIndex(*conteiner);//�������, ��������� ������ ������������� ��������
    cout << endl << endl << endl << endl;

    List lst;
    lst.new_node(1);
    lst.new_node(12345);
    lst.new_node(1234);
    lst.new_node(123);
    lst.new_node(12);
    cout << "---------------" << endl << "������ ��������� ������ � ����� �� ������:" << endl;
    lst.print_list_back();
    cout << "---------------" << endl;
    lst.creation_node_in_target_place(2,55);//����� �������
    lst.delete_target_element(3);//����� ��������
    cout << "---------------" << endl << "������ ������ � ����� �� ������:" << endl;
    lst.print_list_ahead();
    cout << "---------------" << endl << "������ ������ �������� �� ��������� 123:" << endl;
    lst.search_by_value(123);
    cout << "����� �������� ��������� ������: " << lst.sum_values_list();
    cout << endl << "C������ �������� ��������� ������: " << lst.mid_value();
    cout << endl << "����������� ��������: " << lst.find_min_value();
    cout << endl << "������������ ��������: " << lst.find_max_value();
    cout << endl << "����� ��������� � ������: " << lst.getsize();//����� ������������ ���������� ���������
    conteiner->clear();//������ ����������
    return 0;
}
