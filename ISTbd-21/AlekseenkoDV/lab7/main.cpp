#include <iostream>

using namespace std;


void Hanoi(int count, int from, int to) // n - кол-во дисков, A,B,C - стержни
{  
  if (count == 1) {
      cout << "Move disk " << count << " from pin "<< from << " to " << to << endl;
      return;
    }
  else {
    int tmp = 6 -(from + to);
    Hanoi(count-1,from, tmp);
    cout << "Move disk " << count << " from pin " << from << " to " << to << endl;
    Hanoi(count-1, tmp, to);
    }
}

int main()
{
  int count, from, tmp;
  cout << "Insert the numbers of disks: ";
  cin >> count;
  Hanoi(count, 1, 2);
}
