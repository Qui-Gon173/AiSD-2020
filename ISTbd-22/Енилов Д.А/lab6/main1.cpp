
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

  unsigned long L=12345678;
  
  int *ip=(int *)&L;
  char *cp=(char *)&L;
  long *lp=(long *)&L;

  std::cout <<"\n&L = "<<&L; 
  std::cout <<"\nL = "<<L<<"\n";

  printf("%u",*cp);//чтобы модифицировать программу, надо не использовать char*, 
  //12345678 в ASCII символах равен N, но N в ASCII коде равно 78
  //поэтому даже если мы типизируем вывод, чтобы нам выдавали unsigned long,
  //то есть применим строку std::cout <<"\n*cp = "<<(unsigned long)*cp;
  //будет выводится 78, а не 12345678
  std::cout <<"\n*cp = "<<(unsigned long)*cp; 
  std::cout <<"\n*ip = "<<*ip;
  std::cout <<"\n*lp = "<<*lp;
  
}