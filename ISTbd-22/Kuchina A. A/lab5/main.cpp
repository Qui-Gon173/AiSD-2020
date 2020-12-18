#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <iostream>
#include <fstream>

using namespace std;

void FillArray(int array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cin >> array[i];
	}
}

void ShowArray(int array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void Simple_Merging_Sort (char *name)
{
  int a1, a2, k, i, j, kol;
  fstream FullF;
  string FullS;
  fstream ArrayFirst;
  fstream ArraySecond;
  kol = 0;
  FullF.open(name, fstream::in);
  FullF >> FullS;
  if ( !FullF )
  cout << "Невозможно открыть исходный файл" << endl;
  else
    {
    while ( !FullF.eof() )
     {
      FullF >> a1;
      kol++;
    }
   FullF.close();
  }
  k = 1;
  while ( k < kol )
    {
   FullF.open(name, fstream::in);
   ArrayFirst.open("FirstFile.txt", fstream::out);
   ArraySecond.open("SecondFile.txt", fstream::out);
    if ( !FullF.eof() ) FullF >> a1;
    while ( !FullF.eof() )
    {
      for ( i = 0; i < k && !FullF.eof() ; i++ ){
        ArrayFirst << a1 << endl;
        FullF >> a1;
      }
      for ( j = 0; j < k && !FullF.eof() ; j++ )
      {
        ArraySecond << a1 << endl;
        FullF >> a1;
      }
    }
    ArrayFirst.close();
    ArraySecond.close();
    FullF.close();

    FullF.open(name, fstream::out);
    ArrayFirst.open("FirstFile.txt", fstream::in);
    ArraySecond.open("SecondFile.txt", fstream::in);
    if ( !ArrayFirst.eof() )
        ArrayFirst >> a1;
    if ( !ArraySecond.eof() )
        ArraySecond >> a2;
    while ( !ArrayFirst.eof() && !ArraySecond.eof() )
        {
      i = 0;
      j = 0;
      while ( i < k && j < k && !ArrayFirst.eof() && !ArraySecond.eof() )
      {
        if ( a1 < a2 )
         {
          FullF << a1 << endl;
          ArrayFirst >> a1;
          i++;
        }
        else
         {
          FullF << a2 << endl;
          ArraySecond >> a2;
          j++;
        }
      }
      while ( i < k && !ArrayFirst.eof() ) {
        FullF << a1 << endl;
          ArrayFirst >> a1;
        i++;
      }
      while ( j < k && !ArraySecond.eof() ) {
        FullF << a2 << endl;
        ArraySecond >> a2;
        j++;
      }
    }
    while ( !ArrayFirst.eof() ) {
      FullF<<a1<<endl;
      ArrayFirst>>a1;
    }
    while ( !ArraySecond.eof() ) {
      FullF<<a2<<endl;
      ArraySecond>>a2;
    }
    FullF.close();
    ArrayFirst.close();
    ArraySecond.close();
    k *= 2;
  }
  remove("FirstFile.txt");
  remove("SecondFile.txt");
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int ArraySize = 0;
    cout << "Сортировка простым слиянием" << endl;
    cout << "Введите число элементов: " << endl;
    cin >> ArraySize;
    int SortedArray [ArraySize];
    int NotSortedArray [ArraySize + 1];
    cout << "Введите элементы: " << endl;
    FillArray(NotSortedArray, ArraySize);

    ofstream fout("AllArray.txt");
    for(int i = 0; i < ArraySize; i++)
    {
        fout << NotSortedArray[i] << endl;
    }
    fout.close();

    char FileName[] = "AllArray.txt";
    Simple_Merging_Sort(FileName);
    ifstream finishedf ("AllArray.txt");
    for(int i = 0; i < ArraySize; i++)
    {
      finishedf >> SortedArray[i];
    }
    cout << "Вывод массива" << endl;
    ShowArray(SortedArray, ArraySize);
    system("pause");
   return 0;
}
