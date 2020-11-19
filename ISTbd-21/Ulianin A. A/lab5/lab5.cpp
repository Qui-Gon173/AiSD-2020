#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int N = 20000; // количество чисел

/// функция сортировки
void mergeSort(char* fileName,int number)
{
    /// вспомогательные числа для чтения и записи элементов
    int helpFirstNumber; 
    int helpSecondNumber; 

    int currentLengthSeries = 1; // длина текущей серии

    FILE* file; // файл основной

    /// два вспомогательных файла
    FILE* helpFirstFile; 
    FILE* helpSecondFile;

    while (currentLengthSeries < number)
    {
        /// открываем для чтения главный файл и для записи вспомогательные
        file = fopen(fileName, "r");
        helpFirstFile = fopen("helpFirstFile", "w");
        helpSecondFile = fopen("helpSecondFile", "w");

        /// читаем первый элемент
        if (!feof(file))
        {
            fscanf(file, "%d", &helpFirstNumber);
        }

        /// распределяем серии по двум вспомогательным файлам
        while (!feof(file))
        {
            /// записываем серию в первый файл
            for (int i = 0; i < currentLengthSeries && !feof(file); i++)
            {
                fprintf(helpFirstFile, "%d ", helpFirstNumber);
                fscanf(file, "%d", &helpFirstNumber);
            }
            /// записываем серию в второй файл
            for (int j = 0; j < currentLengthSeries && !feof(file); j++)
            {
                fprintf(helpSecondFile, "%d ", helpFirstNumber);
                fscanf(file, "%d", &helpFirstNumber);
            }
        }

        /// закрываем файлы
        fclose(file);
        fclose(helpFirstFile);
        fclose(helpSecondFile);

        /// открываем для записи главный файл и для чтения вспомогательные
        file = fopen(fileName, "w");
        helpFirstFile = fopen("helpFirstFile", "r");
        helpSecondFile = fopen("helpSecondFile", "r");

        /// читаем первые элементы из каждого файла
        if (!feof(helpFirstFile) && !feof(helpSecondFile))
        {
            fscanf(helpFirstFile, "%d", &helpFirstNumber);
            fscanf(helpSecondFile, "%d", &helpSecondNumber);
        }

        /// пока не достигли конца одного из файлов
        while (!feof(helpFirstFile) && !feof(helpSecondFile))
        {
            /// обнуляем счётчики элементов серий 
            int i = 0;
            int j = 0; 

            /// записываем первые n чисел, сортируя их
            while (i < currentLengthSeries && j < currentLengthSeries && !feof(helpFirstFile) && !feof(helpSecondFile))
            {
                /// сравниваем значения из 2 вспомогательных файлов и записываем наименьший в основной файл
                if (helpFirstNumber < helpSecondNumber)
                {
                    fprintf(file, "%d ", helpFirstNumber);
                    fscanf(helpFirstFile, "%d", &helpFirstNumber);
                    i++;
                }
                else
                {
                    fprintf(file, "%d ", helpSecondNumber);
                    fscanf(helpSecondFile, "%d", &helpSecondNumber);
                    j++;
                }
            }

            /// дописываем оставшиеся сортируемые элементы
            while (i < currentLengthSeries && !feof(helpFirstFile))
            {
                fprintf(file, "%d ", helpFirstNumber);
                fscanf(helpFirstFile, "%d", &helpFirstNumber);
                i++;
            }

            while (j < currentLengthSeries && !feof(helpSecondFile))
            {
                fprintf(file, "%d ", helpSecondNumber);
                fscanf(helpSecondFile, "%d", &helpSecondNumber);
                j++;
            }
        }

        /// дописываем оставшиеся неотсортированные элементы
        while (!feof(helpFirstFile))
        {
            fprintf(file, "%d ", helpFirstNumber);
            fscanf(helpFirstFile, "%d", &helpFirstNumber);
        }
        while (!feof(helpSecondFile))
        {
            fprintf(file, "%d ", helpSecondNumber);
            fscanf(helpSecondFile, "%d", &helpSecondNumber);
        }

        /// закрываем файлы
        fclose(file);
        fclose(helpFirstFile);
        fclose(helpSecondFile);

        /// увеличиваем серии в два раза (двойки, четвёрки, восьмёрки и т.д.)
        currentLengthSeries *= 2;
    }

    /// удаляем вспомогательные файлы
    remove("helpFirstFile");
    remove("helpSecondFile");
}

int main()
{
    char sortFile[13] = "textSort.txt";   
    mergeSort(sortFile,N);
    return 0;
}