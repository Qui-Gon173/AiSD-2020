#include <iostream>
using namespace std;
// ������� ������-����������
void shackerSort(int* mass, int count)
{
	int left = 0, right = count - 1; // ����� � ������ ������� ����������� ������� �������
	int flag = 1;  // ���� ������� �����������
	// ���������� �����, ���� ����� ������� �� �������� � ������
	// � ���� � ������� ������� �����������
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //��������� ����� �������
		{
			if (mass[i] > mass[i + 1]) // ���� ��������� ������� ������ ��������,
			{             // ������ �� �������
				double t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1;      // ����������� � ���� ����� ����
			}
		}
		right--; // �������� ������ ������� �� ���������� �������
		for (int i = right; i > left; i--)  //��������� ������ ������
		{
			if (mass[i - 1] > mass[i]) // ���� ���������� ������� ������ ��������,
			{           
				double t = mass[i];  // ������ �� �������
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1;    // ����������� � ���� ����� ����
			}
		}
		left++; // �������� ����� ������� �� ��������� �������
	}
}
int main() {
	int my_array[10];
	// ������ �������� �������
	for (int i = 0; i < 10; i++) {
		cout << "my_array[" << i << "] = ";
		cin >> my_array[i];
		cout << endl;
	}
	shackerSort(my_array, 10); // �������� ������� ����������
	// ������� ��������������� �������� �������
	for (int i = 0; i < 10; i++)
		cout << my_array[i] << " ";
	return 0;
}