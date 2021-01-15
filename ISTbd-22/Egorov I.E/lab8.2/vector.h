#pragma once
#include <iostream>
#include "iter.h"


using namespace std;

template<typename T>
class vector_list{
    
   
     private :
        T* data;
        int size;

    public:
        T& operator[](const int idx){
           int schet=0; 

           while(schet<size){
               if(schet==idx){
                 return(data);
               }
           ++schet;
           }
           
        }

        void VivodPoocheredniy(){
            int schet=0; 

           while(schet<size){  
           cout<<data[schet]<<endl;
           ++schet;
           }
           if(size==0){
               cout<<"Vector pust"<<endl;
           }
        }

        void VvodElem(T val){
            T* NV = new T[size+1];
            for (int i = 0; i < size; i++)
            {
             NV[i] = data[i];
            }    

            NV[size] = val;

            size++;

            delete[] data;

            data=NV;        
        }

        void VvodPosit(T val , int pos){
            T* NV = new T[size+1]; 
             for (int i = 0; i < pos; i++)
            {
             NV[i] = data[i];
            }   

            NV[pos]=val;

            size++;

            for(int i = pos+1 ; i < size;i++){
                NV[i] = data[i-1];
            }

            delete[] data;

            data=NV;
        }

        void DelPosit(int pos){
            T* NV = new T[size-1]; 
             for (int i = 0; i < pos; i++)
            {
             NV[i] = data[i];
            }    

            size--;

            for(int i = pos ; i < size;i++){
                NV[i] = data[i+1];
            }

            delete[] data;

            data=NV;
        }

        int IndSearch(T val){
          int schet=0; 

           while(schet<size){  
           if(data[schet]==val){
               return(schet);
           }
           ++schet;
           }
           if(size==0){
               cout<<"Vector pust"<<endl;
           }
               
           return(-1);
            
           
        }

        void DelLastElem(){
             T* NV = new T[size-1];
            for (int i = 0; i < size; i++)
            {
             NV[i] = data[i];
            }    

            size--;

            delete[] data;

            data=NV; 
        }

        void DelVec(){
            while(size){
            DelLastElem();
            }
        }

        T SummZnach(){
            T summ = 0;
            for(int i=0;i<size;i++){
                summ +=data[i];
            }
            return(summ);
        }

        T SrednZnach(){
            T sred = 0;
            for(int i=0;i<size;i++){
                sred +=data[i];
            }
            sred=sred/size;
            return(sred);
        }

        T MinZnach(){
            T min = data[0];
            for(int i=1;i<size;i++){
                if(data[i]<min){
                    min=data[i];
                }
            }
            return(min);
        }

        T MaxZnach(){
            T max = data[0];
            for(int i=1;i<size;i++){
                if(data[i]>max){
                    max=data[i];
                }
            }
            return(max);
        }

        int KolElem(){
            return(size);
        }

        vector_list(){
            this->data=nullptr;
            this->size=0;
        }

        typedef vec_iter<const T> mi;

        mi begin(){
            return(data);
        }

        mi end(){
            return(data+size);
        }

};