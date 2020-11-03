#include <iostream>


using namespace std;

  int BinarySearch(int *x, int k, int key){
  bool found = false;
  int high = k - 1, low = 0;
  int middle = (high + low) / 2;
  while ( !found && high >= low ){
    if (key == x[middle])
      found = true;
    else if (key < x[middle])
      high = middle - 1;
    else
      low = middle + 1;
      middle = (high + low) / 2;
  }
  return found ? middle : -1 ;
}

int main()
{
     setlocale(LC_ALL, "rus");
     int lengthArr;
     cout<< "¬ведите длину массива "<< endl;
     cin>> lengthArr;
    int arr[lengthArr];
    int key;
    int index;
    cout << "¬ведите числа по возрастанию или убыванию дл€ заполнени€ массива: " << endl;

  for (int i = 0; i < lengthArr; i++) {
    cin >> arr[i];
  }
  cout << endl << "¬ведите ключ: ";
  cin >> key;


  index = BinarySearch(arr,lengthArr,key);

  if (index>=0) cout << "»ндекс искомого элемента " << index <<  endl;
  else cout << "»звините, но такого элемента в массиве нет"<<endl;

    return 0;
}
