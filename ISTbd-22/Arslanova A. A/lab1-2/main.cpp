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

void Sort(int arr[], int array_length)
{
    if (!array_length) {
        return;
    }

    for (int i = 0; i < array_length - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < array_length; j++) {
            if (arr[j] < arr[min_i]) {
                min_i = j;
            }
        }

        if (min_i != i) {
            swap(arr[i], arr[min_i]);
            min_i = i;
        }
    }
}

int DvSort(int arr[], int left, int rigth, int element)
{
	while (left <= rigth)
	{
		int m = (unsigned)left + ((unsigned)rigth - (unsigned)left) / 2;
		if (arr[m] == element)
			return m;
		else if (arr[m] < element)
			left = m + 1;
		else
			rigth = m - 1;
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������������ ������ �1 (� �2) \n ��������� ������� ��. �����-22 \n ��������� ������\n �������� ������������� \n ������������ ������ ���������\n";
	cout << "�������:\n 1) ����������� �������� ��������� ������ � ������� ������� ��������� ������ (������� �3).  \n 2) ����������� �������� ���������� ������� �������� (������� �3). \n\n";
	int MyArr[20];
	int cnt;
	int left = 0, element;
	cout << "������� ���-�� ��������� �������: ";
	cin >> cnt;
	int rigth = cnt;
	cout << "������� �������� �������: ";
	Filling(cnt, MyArr);
	cout << "������� ������� ��� ������: ";
	cin >> element;
	cout << "�������� ������ �������������:  ";
	Res(cnt, MyArr);
	Sort(MyArr, cnt);
	if (DvSort(MyArr, left, rigth, element) == -1)
	{
		cout << "������ �������� �� ����������!\n";
	}
	else
	{
		cout << "������� ��������:  ";
		cout << DvSort(MyArr, left, rigth, element) << "\n";
	}
	cout << "��������������� ������ �������������:";
	Res(cnt, MyArr);
}

