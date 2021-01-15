#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

void FillArray(int count, int array[])
{
    for (int i = 0; i < count; i++)
    {
        cin >> array[i];
    }
}


void ShowArray(int count, int array[])
{
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void sortXoapa(int array[], int last)
{
    int i = 0, j = last, center;
    center = array[last >> 1];

    do {
        while (array[i] < center) i++;
        while (array[j] > center) j--;

        if (i <= j)
        {
            swap(array[i], array[j]);
            i++; j--;
        }
    } while (i <= j);
    if (j > 0) sortXoapa(array, j);
    if (last > i) sortXoapa(array + i, last - i);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �3  \n ��������� ��������� ��. �����-22 \n ������ ����  \n �������� �������������  \n ������������ ������ ���������\n---------------------------\n ";
    cout << "�������: \n  �� ����� C++ ����������� ���������� ������� �����.\n---------------------------\n ";
    int array[20];
    int count;
    int left = 0, element;
    cout << " ������� ���-�� ��������� �������:   ";
    cin >> count;
    int rigth = count;
    cout << " ������� �������� �������:   ";
    FillArray(count, array);
    cout << " �������� ������ �������������:   ";
    ShowArray(count, array);
    int last = count - 1;
    sortXoapa(array, last);
    cout << " ��������������� ������ �������������:   ";
    ShowArray(count, array);
}