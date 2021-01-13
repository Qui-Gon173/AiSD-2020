#include <algorithm>
#include <cstddef>
#include <iterator>
#include <windows.h>
#include <memory>
#include <iostream>
#include <fstream>


using namespace std;

void Simple_Merging_Sort (char *name){
  int a1, a2, k, i, j, kol, tmp;
  fstream Mas1;
  string Mas2;
  fstream FirstPart_1;
  fstream FirstPart_2;
  kol = 0;
  Mas1.open(name, fstream::in);
  Mas1>>Mas2;
  if ( !Mas1 )
  cout<<"Source file not open..."<<endl;
  else {
    while ( !Mas1.eof() ) {
      Mas1>>a1;
      kol++;
    }
   Mas1.close();
  }
  k = 1;
  while ( k < kol ){
   Mas1.open(name, fstream::in);
   FirstPart_1.open("FirstPart_1.txt", fstream::out);
   FirstPart_2.open("FirstPart_2.txt", fstream::out);
    if ( !Mas1.eof() ) Mas1>>a1;;
    while ( !Mas1.eof() ){
      for ( i = 0; i < k && !Mas1.eof() ; i++ ){
        FirstPart_1<<a1<<endl;
        Mas1>>a1;
      }
      for ( j = 0; j < k && !Mas1.eof() ; j++ ){
        FirstPart_2<<a1<<endl;
        Mas1>>a1;
      }
    }
    FirstPart_1.close();
    FirstPart_2.close();
    Mas1.close();

    Mas1.open(name, fstream::out);
    FirstPart_1.open("FirstPart_1.txt", fstream::in);
    FirstPart_2.open("FirstPart_2.txt", fstream::in);
    if ( !FirstPart_1.eof() )  FirstPart_1>>a1;
    if ( !FirstPart_2.eof() )  FirstPart_2>>a2;
    while ( !FirstPart_1.eof() && !FirstPart_2.eof() ){
      i = 0;
      j = 0;
      while ( i < k && j < k && !FirstPart_1.eof() && !FirstPart_2.eof() ) {
        if ( a1 < a2 ) {
          Mas1<<a1<<endl;
          FirstPart_1>>a1;
          i++;
        }
        else {
          Mas1<<a2<<endl;
          FirstPart_2>>a2;
          j++;
        }
      }
      while ( i < k && !FirstPart_1.eof() ) {
        Mas1<<a1<<endl;
          FirstPart_1>>a1;
        i++;
      }
      while ( j < k && !FirstPart_2.eof() ) {
        Mas1<<a2<<endl;
        FirstPart_2>>a2;
        j++;
      }
    }
    while ( !FirstPart_1.eof() ) {
      Mas1<<a1<<endl;
      FirstPart_1>>a1;
    }
    while ( !FirstPart_2.eof() ) {
      Mas1<<a2<<endl;
      FirstPart_2>>a2;
    }
    Mas1.close();
    FirstPart_1.close();
    FirstPart_2.close();
    k *= 2;
  }
  remove("FirstPart_1.txt");
  remove("FirstPart_2.txt");
}

int main(){
    setlocale(LC_ALL,NULL);
    int elCt=0;
    cout<<"\nMerge sort:\n"<<endl;
    cout<<"Enter the number of array elements:";
    cin>>elCt;
    int elArr [elCt+1];
    int OutelArr [elCt+1];
    cout<<"Enter array elements:";
    for(int i=0;i<elCt;i++){
        cin>>elArr[i];
    }

    ofstream fout("mass.txt");
    for(int i=0;i<elCt;i++){
        fout << elArr[i]<<endl;
    }
    fout.close();


    char msv[] ="mass.txt";
    Simple_Merging_Sort(msv);

    ifstream tuof("mass.txt");
    for(int i=0;i<elCt;i++){
      tuof>>elArr[i];
    }

    cout<<"Array output:";
    for(int i=0;i<elCt;i++){
        cout<<elArr[i]<<" ";
    }
    system("pause");
   return 0;
}
