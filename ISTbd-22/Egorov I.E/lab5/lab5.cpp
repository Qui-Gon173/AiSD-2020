#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <iostream>
#include <fstream>


using namespace std;
//Код в c-style , переписать на плюсы и дать уникальные/осмысленные имена переменным
void Simple_Merging_Sort (char *name){
  int a1, a2, k, i, j, kol, tmp;
  fstream FullF("FullF.txt");
  string FullS;
  fstream FirstPartF("FirstPartF.txt");
  fstream SecondPartF("SecondPartF.txt");
  kol = 0;
  FullF>>FullS;
  if ( !FullF )
  cout<<"Source file not open..."<<endl;
  else {
    while ( !FullF.eof() ) {
      FullF>>a1;
      kol++;
    }
   FullF.close();
  }
  k = 1;
  while ( k < kol ){
   FullF.open("FullF.txt");
   FirstPartF.open("FirstPartF.txt");
   SecondPartF.open("SecondPartF.txt");
    if ( !FullF.eof() ) FullF>>a1;;
    while ( !FullF.eof() ){
      for ( i = 0; i < k && !FullF.eof() ; i++ ){
        FirstPartF<<a1<<endl;
        FullF>>a1;
      }
      for ( j = 0; j < k && !FullF.eof() ; j++ ){
        SecondPartF<<a1<<endl;
        FullF>>a1;
      }
    }
    FirstPartF.close();
    SecondPartF.close();
    FullF.close();

    FullF.open("FullF.txt");
    FirstPartF.open("FirstPartF.txt");
    SecondPartF.open("SecondPartF.txt");
    if ( !FirstPartF.eof() )  FirstPartF>>a1;
    if ( !SecondPartF.eof() )  SecondPartF>>a2;
    while ( !FirstPartF.eof() && !SecondPartF.eof() ){
      i = 0;
      j = 0;
      while ( i < k && j < k && !FirstPartF.eof() && !SecondPartF.eof() ) {
        if ( a1 < a2 ) {
          FullF<<a1<<endl;
          FirstPartF>>a1;
          i++;
        }
        else {
          FullF<<a2<<endl;
          SecondPartF>>a2;
          j++;
        }
      }
      while ( i < k && !FirstPartF.eof() ) {
        FullF<<a1<<endl;
          FirstPartF>>a1;
        i++;
      }
      while ( j < k && !SecondPartF.eof() ) {
        FullF<<a2<<endl;
        SecondPartF>>a2;
        j++;
      }
    }
    while ( !FirstPartF.eof() ) {
      FullF<<a1<<endl;
      FirstPartF>>a1;
    }
    while ( !SecondPartF.eof() ) {
      FullF<<a2<<endl;
      SecondPartF>>a2;
    }
    FullF.close();
    FirstPartF.close();
    SecondPartF.close();
    k *= 2;
  }
  remove("smsort_1");
  remove("smsort_2");
}

int main(){
    int elCt=0;
    cout<<"Sortirovka sliyaniem"<<endl;
    cout<<"Vvedite chislo elementov"<<endl;
    cin>>elCt;
    int elArr [elCt+1];
    int OutelArr [elCt+1];
    cout<<"Vvedite elementi"<<endl;
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
  
    cout<<"Vivod masiva"<<endl;
    for(int i=0;i<elCt;i++){
        cout<<elArr[i]<<endl;
    }
    system("pause");
   return 0;
}