#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

void Filling(int cnt, int arr[])
{
	for (int i = 0; i < cnt; i++)
	{
		cin >> arr[i];
	}
}


void Res(int cnt, int arr[])
{
	for (int i = 0; i < cnt; i++)
	{
		cout << arr[i] << " ";
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
	cout << "������������ ������ �3 \n �������� ������� ��. �����-22 \n ��������� ������\n �������� ������������� \n ������������ ������ ���������\n";
	cout << "�������: ����������� �������� ���������� ������� �����.\n";
    int MyArr[20];
    int cnt;
    int element;
	cout << "������� ���-�� ��������� �������: ";
	cin >> cnt;
	cout << "������� �������� �������: ";
	Filling(cnt, MyArr);
	cout << "������� ������� ��� ������: ";
	cin >> element;
	cout << "�������� ������ �������������:  ";
	Res(cnt, MyArr);
    int last = cnt - 1;
    sortXoapa(MyArr, last);
	cout << "��������������� ������ �������������:";
	Res(cnt, MyArr);
}
