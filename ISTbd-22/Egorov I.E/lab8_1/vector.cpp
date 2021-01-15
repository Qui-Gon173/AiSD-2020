#include <iostream>
#include "vector.h"


using namespace std;

int main () {
   vector_list<long> vec;
   
   cout<<"Vvod elementov :"<<endl;

   long a=2;

   vec.VvodElem(a);

   a=10;

   vec.VvodElem(a);

   a=9;

   vec.VvodElem(a);

   a=16;

   vec.VvodElem(a);

   a=200;

   vec.VivodPoocheredniy();

   cout<<"Vstavka elementa 200 pod indexom 1 :"<<endl;

   vec.VvodPosit(a,1);

   vec.VivodPoocheredniy();

   cout<<"Udalenie elementa pod indexom 1 :"<<endl;

   vec.DelPosit(1);

   vec.VivodPoocheredniy();

   cout<<"Poisk indeksa po znacheniu 10 :"<<endl;

   cout<<vec.IndSearch(10)<<endl;

   cout<<"Vvivod kollichestva elementov :"<<endl;

    cout<<vec.KolElem()<<endl;

    cout<<"Nash vector :"<<endl;

    vec.VivodPoocheredniy();

    cout<<vec.SummZnach()<<" - Summa znacheniy vectora"<<endl;

    cout<<vec.SrednZnach()<<" - Srednee znachenie vectora"<<endl;

    cout<<vec.MaxZnach()<<" - Maximalnoe znachenie vectora"<<endl;

    cout<<vec.MinZnach()<<" - Minimalnoe znachenie vectora"<<endl;

    vec.DelVec();

    cout<<"Ochistka vectora:"<<endl;

    vec.VivodPoocheredniy();

    system("pause");
    
}