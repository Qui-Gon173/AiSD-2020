#include <iostream>
#include <istream>
#include "vector.h"
#include <algorithm>
#include "gen.h"


using namespace std;

template<typename T>
void vec_out(vector_list<T>& vlcon){
    cout<<"Vivod conteinera :"<<endl;
    for(auto& item:vlcon){
		cout<<item<<endl;
	}
}

template<typename T>
void vec_sum(vector_list<T>& vlcon1){
    cout<<"Summa conteinera :"<<endl;
    T a=0;
    for(auto& item1:vlcon1){
		a+=item1;
	}
    cout<<a<<endl;
}

template<typename T>
void vec_sredn(vector_list<T>& vlcon2){
    cout<<"Srednee conteinera :"<<endl;
    T b =0;
    T c =0;
    for(auto& item2:vlcon2){
		b+=item2;
        c++;
	}
    T d =b/c;
    cout<<b/c<<","<<(b%c)*10/c<<endl;
}

void vector_ini(vector_list<long>& vl ,long st ,long sect , long mx){

    auto generator = fib_gen(st,sect,mx);

    for(auto& item:generator){
	 vl.VvodElem(item);
	}

}

int main () {
   vector_list<long> vec;

   long sect = 0;

   long st = 0;

   long mx = 0;

   st=0;

   cout<<"Vveden nachalniy element : "<<st<<endl; 

   sect=1;

   cout<<"Vveden sleduyushiy element : "<<sect<<endl;

   cout<<"Vvedite granicu ..."<<endl;
   cin>>mx;
   if(mx<sect){
       while(mx<sect){
       cout<<"Granica dolzna bit bolshe elementov :"<<endl;
       cin>>mx;
       }
   }
   long ft1=0;
   long ft2=1;
   long op=0;
   while(ft2<mx){
       op = ft1+ft2;
       ft1=ft2;
       ft2=op;
   }
   if(mx!=ft2){
       cout<<"Granica ne yavlyaetsa chislom fibonachi"<<endl;
       system("pause");
       mx=ft2;
       cout<<"Ustanovlena blizhaishaya granica :"<<mx<<endl;
   }
   
   
   

   

   auto vec2 = vec;

   vector_ini(vec2 , st , sect ,mx );

   const auto max=max_element(vec2.begin(),vec2.end());

   cout<<*max<<" -max"<<endl;

   const auto min=min_element(vec2.begin(),vec2.end());
   
   cout<<*min<<" -min"<<endl;

   cout<<vec2.IndSearch(*max)<<" -index of max"<<endl;

   cout<<vec2.IndSearch(*min)<<" -index of min"<<endl;

   vec_out(vec2);

   vec_sum(vec2);

   vec_sredn(vec2);

   system("pause");

}
