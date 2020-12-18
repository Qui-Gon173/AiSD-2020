#include <iostream>

using namespace std;

int Hanoi(int disks, char A, char B, char C)
{
	int moves;
	if (disks == 1)
	{
		cout << A << " to " << B << endl;
		moves = 1;
	}
	else
	{
		moves = Hanoi(disks - 1, A, C, B);
		cout << A << " to " << B << endl;
		moves++;
		moves += Hanoi(disks - 1, C, B, A);
	}
	return moves;
}

int main()
{
	char a = 'A', b = 'B', c = 'C';
	int disks, moves;
	cout << "Hanoi Towers" << endl;
	cout << "Enter the number of dings" << endl;
	cin >> disks;
	moves = Hanoi(disks, a, b, c);
	cout << "Completed in " << moves << " moves" <<  endl;
	return 0;
}
