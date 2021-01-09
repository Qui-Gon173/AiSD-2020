#include <iostream>

using namespace std;

int tower_Of_Hanoi(int nDisks, char A, char B, char C)
{
  int nMoves;
  if (nDisks == 1)
  {
    cout << endl << A << " -> " << B;
    nMoves = 1;
  }
  else
  {
    nMoves = tower_Of_Hanoi(nDisks - 1, A, C, B);
    cout << endl << A << " -> " << B;
    nMoves++;
    nMoves += tower_Of_Hanoi(nDisks - 1, C, B, A);
  }
  return nMoves;
}

int main()
{
  char a='A', b='B', c='C';
  int nDisks, nMoves;
  cout << "Enter the number of disks: ";
  cin >> nDisks;
  nMoves = tower_Of_Hanoi(nDisks, a, b, c);
  cout << endl << endl << nDisks << " disks have been moved around " << nMoves << " times.";
  return 0;
}