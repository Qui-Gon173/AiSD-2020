#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>

const int N = 20000; // количество чисел
const int RANGE = 100; // диапазон чисел в массиве [0;N)

// функция распределения
void splitFiles(char* fileName, int lehgth) 
{
    int splitLength = lehgth;// длина серий
    int currentNum; // текущее число
    FILE* sourceFile, * firstPart, * secondPart; // файлы - основной и два вспомогательных

    // открываем для чтения главный файл и для записи вспомогательные
    sourceFile = std::fopen(fileName, "r");
    firstPart = std::fopen("fisrtPartFile", "w");
    secondPart = std::fopen("secondPartFile", "w");

    // читаем первый элемент
    if (!std::feof(sourceFile))
    {
        std::fscanf(sourceFile, "%d", &currentNum);
    }

    //распределяем серии по двум файлам
    while (!std::feof(sourceFile))
    {
        //записываем серию в первый файл
        for (int l = 0; l < splitLength && !std::feof(sourceFile); l++)
        {
            std::fprintf(firstPart, "%d ", currentNum);
            std::fscanf(sourceFile, "%d", &currentNum);
        }
        //записываем серию в второй файл
        for (int l = 0; l < splitLength && !std::feof(sourceFile); l++)
        {
            std::fprintf(secondPart, "%d ", currentNum);
            std::fscanf(sourceFile, "%d", &currentNum);
        }
    }

    // закрываем файлы
    std::fclose(sourceFile);
    std::fclose(firstPart);
    std::fclose(secondPart);
}

// ограничение в 50 строк кода нарушено для удобочитаемости
void mergeSort(char* fileName) 
{
    int firstCompareNum, secondCompareNum; // элементы двух сравниваемых серий
    
    // счётчики элементов серии
    int i; // для элементов первого файла
    int j; // для элементов второго файла
    int seriesLength = 1; // длина текущей серии
    FILE* file, * part1, * part2; // файлы - основной и два вспомогательных

    // сортировка
    while (seriesLength < N) 
    {
        //разделяем основной файл на 2 вспомогательных, записываем серии в них - распределение
        splitFiles(fileName, seriesLength);

        // открываем для записи главный файл и для чтения вспомогательные
        file = std::fopen(fileName, "w"); 
        part1 = std::fopen("fisrtPartFile", "r");
        part2 = std::fopen("secondPartFile", "r");

        // читаем первые элементы из каждого файла
        if (!std::feof(part1) && !std::feof(part2))
        {
            std::fscanf(part1, "%d", &firstCompareNum);
            std::fscanf(part2, "%d", &secondCompareNum);
        }

        // сливаем N-ые серии в 2*N-ые серии, попутно сортируя их
        // пока не достигли конца одного файлов
        while (!std::feof(part1) && !std::feof(part2)) 
        {
            // обнуляем счётчики элементов серий 
            i = 0;
            j = 0;

            // записываем первые n чисел, сортируя их
            while (i < seriesLength && j < seriesLength && !std::feof(part1) && !std::feof(part2)) 
            {
                // сравниваем числа серий 
                // записываем наименьшее в основной файл
                if (firstCompareNum < secondCompareNum) 
                { 
                    std::fprintf(file, "%d ", firstCompareNum);
                    std::fscanf(part1, "%d", &firstCompareNum);
                    i++;
                }
                else 
                {
                    std::fprintf(file, "%d ", secondCompareNum);
                    std::fscanf(part2, "%d", &secondCompareNum);
                    j++;
                }
            }
            // дописываем серии до конца
            while (i < seriesLength && !std::feof(part1)) 
            {
                std::fprintf(file, "%d ", firstCompareNum);
                std::fscanf(part1, "%d", &firstCompareNum);
                i++;
            }
            while (j < seriesLength && !std::feof(part2)) 
            {
                std::fprintf(file, "%d ", secondCompareNum);
                std::fscanf(part2, "%d", &secondCompareNum);
                j++;
            }
        }

        // если не дописали полностью серию из какого-то файла
        // дописываем
        while (!std::feof(part1)) 
        {
            std::fprintf(file, "%d ", firstCompareNum);
            std::fscanf(part1, "%d", &firstCompareNum);
        }
        while (!std::feof(part2)) 
        {
            std::fprintf(file, "%d ", secondCompareNum);
            std::fscanf(part2, "%d", &secondCompareNum);
        }

        // закрываем файлы
        std::fclose(file);
        std::fclose(part1);
        std::fclose(part2);

        // увеличиваем серии в два раза (двойки, четвёрки, восьмёрки и т.д.)
        seriesLength *= 2;
    }

    // удаляем вспомогательные файлы
    std::remove("fisrtPartFile");
    std::remove("secondPartFile");
}

//заполнение файла рандомными числами
void generateRandom(char* fileName)
{
    std::srand(time(0)); // "семя" рандома

    FILE* f = std::fopen(fileName, "w");
    for (int i = 0; i < N; i++)
        std::fprintf(f, "%d ", std::rand() % RANGE); // заполнение

    std::fclose(f);
}

int main()
{
    char sortFile[16] = "sortNumbers.txt";
    generateRandom(sortFile);
    mergeSort(sortFile);
    return 0;
}
