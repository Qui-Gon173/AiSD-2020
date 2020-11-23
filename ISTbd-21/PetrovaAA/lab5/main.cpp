#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#define SIZE 100

void mergeSort(char* filename,int size)
{
    
    int service_number1; 
    int service_number2; 

    int series_length = 1; 

    FILE* file; 

    
    FILE* merge_sort1; 
    FILE* merge_sort2;

    while (series_length < size)
    {
        
        file = fopen(filename, "r");
        merge_sort1 = fopen("merge_sort1", "w");
        merge_sort2 = fopen("merge_sort2", "w");

       
        if (!feof(file))
        {
            fscanf(file, "%d", &service_number1);
        }

        
        while (!feof(file))
        {
            
            for (int i = 0; i < series_length && !feof(file); i++)
            {
                fprintf(merge_sort1, "%d ", service_number1);
                fscanf(file, "%d", &service_number1);
            }
            
            for (int j = 0; j < series_length && !feof(file); j++)
            {
                fprintf(merge_sort2, "%d ", service_number1);
                fscanf(file, "%d", &service_number1);
            }
        }

        
        fclose(file);
        fclose(merge_sort1);
        fclose(merge_sort2);

        
        file = fopen(filename, "w");
        merge_sort1 = fopen("merge_sort1", "r");
        merge_sort2 = fopen("merge_sort2", "r");

        
        if (!feof(merge_sort1) && !feof(merge_sort2))
        {
            fscanf(merge_sort1, "%d", &service_number1);
            fscanf(merge_sort2, "%d", &service_number2);
        }

        
        while (!feof(merge_sort1) && !feof(merge_sort2))
        {
            
            int i = 0;
            int j = 0; 

            while (i < series_length && j < series_length && !feof(merge_sort1) && !feof(merge_sort2))
            {
                
                if (service_number1 < service_number2)
                {
                    fprintf(file, "%d ", service_number1);
                    fscanf(merge_sort1, "%d", &service_number1);
                    i++;
                }
                else
                {
                    fprintf(file, "%d ", service_number2);
                    fscanf(merge_sort2, "%d", &service_number2);
                    j++;
                }
            }

           
            while (i < series_length && !feof(merge_sort1))
            {
                fprintf(file, "%d ", service_number1);
                fscanf(merge_sort1, "%d", &service_number1);
                i++;
            }

            while (j < series_length && !feof(merge_sort2))
            {
                fprintf(file, "%d ", service_number2);
                fscanf(merge_sort2, "%d", &service_number2);
                j++;
            }
        }

        
        while (!feof(merge_sort1))
        {
            fprintf(file, "%d ", service_number1);
            fscanf(merge_sort1, "%d", &service_number1);
        }
        while (!feof(merge_sort2))
        {
            fprintf(file, "%d ", service_number2);
            fscanf(merge_sort2, "%d", &service_number2);
        }

        
        fclose(file);
        fclose(merge_sort1);
        fclose(merge_sort2);


        series_length *= 2;
    }

   
    remove("merge_sort1");
    remove("merge_sort2");
}

int main()
{
    char MergeSort[13] = "merge.txt";   
    mergeSort(MergeSort,SIZE);
    std::cout<<"Success!";
    return 0;
}