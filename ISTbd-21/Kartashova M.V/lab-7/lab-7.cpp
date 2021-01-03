#include <iostream>

using namespace std;

void hanoi_towers(int quantity, int from, int to, int buf_peg)
{
	if (quantity != 0)
	{
		hanoi_towers(quantity - 1, from, buf_peg, to);

		cout << "Перемещаем диск " << quantity << " с столбика  " << from << " на столбик  " << to << endl;

		hanoi_towers(quantity - 1, buf_peg, to, from);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int start_peg, destination_peg, buffer_peg, disk_quantity;
	cout << "Номер первого столбика:" << endl;
	cin >> start_peg;
	cout << "Номер конечного столбика:" << endl;
	cin >> destination_peg;
	cout << "Номер промежуточного столбика:" << endl;
	cin >> buffer_peg;
	cout << "Количество дисков:" << endl;
	cin >> disk_quantity;

	hanoi_towers(disk_quantity, start_peg, destination_peg, buffer_peg);
	return 0;
}