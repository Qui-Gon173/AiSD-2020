#include <iostream>

using namespace std;

int solveHanoi(int disks, char a, char b, char c)
{
	int moves;
	if (disks == 1)
	{
		cout << endl << a << " -> " << b;
		moves = 1;
	}
	else
	{
		moves = solveHanoi(disks - 1, a, c, b);
		cout << endl << a << " -> " << b;
		moves++;
		moves += solveHanoi(disks - 1, c, b, a);
	}
	return moves;
}

int main()
{
	char a = 'A', b = 'B', c = 'C';
	int disks, moves;
	cout << "Enter the number of disks: ";
	cin >> disks;
	moves = solveHanoi(disks, a, b, c);
	cout << "\n\nSolved in " << moves << " moves";
	return 0;
}