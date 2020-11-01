#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

void zapolnenie(int count, int array[])
{
	for (int i = 0; i < count; i++)
	{
		cin >> array[i];
	}
}


void vivod(int count, int array[])
{
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void sortXoapa(int array[], int last) 
	{
		int i = 0, j = last, temp, center;
		center = array[last >> 1];

	do {
		while (array[i] < center) i++;
		while (array[j] > center) j--;

		if (i <= j) 
		{
			temp = array[i]; 
			array[i] = array[j]; 
			array[j] = temp;
			i++; j--;
		}
	} 
	while (i <= j);
	if (j > 0) sortXoapa(array, j);
	if (last > i) sortXoapa(array + i, last - i);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\x1b[33m������������ ������ �1 (�2)\x1b[32m \n �������� ������� ��. �����-22\x1b[33m \n ������� ����\x1b[32m \n �������� �������������\x1b[33m \n ������������ ������ ���������\n\x1b[0m";
	cout << "\x1b[33m�������: \n \x1b[34m1)����������� ��������� ��������� ������ � ������� ��������: �������� �����, �������� ����� � ��������, �������� �����.\n ������� �3  \n 2) ����������� ��������� ����������: ������� ��������, ������-�����������, ������� ��������, ������� �������.\n ������� �1 \n\n\x1b[0m";
	int array[20];
	int count;
	int left = 0, element;
	cout << "\x1b[31m������� ���-�� ��������� �������:  \x1b[0m";
	cin >> count;
	int rigth = count;
	cout << "\x1b[31m������� �������� �������:  \x1b[0m";
	zapolnenie(count, array);
	cout << "\x1b[32m�������� ������ �������������:  \x1b[0m";
	vivod(count, array);
	int last = count - 1;
	sortXoapa(array, last);
	cout << "\x1b[32m��������������� ������ �������������:  \x1b[0m";
	vivod(count, array);
}
