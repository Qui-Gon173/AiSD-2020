#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void RandomArray(string fileName, int* arr, int size, int min, int max)
{
    ofstream fout;
    fout.open(fileName);
    for (int i = 0; i < size; i++)
    {
        arr[i] = min + rand() % (max - min);
        fout << arr[i] << " ";
    }
    fout.close();

    fout.open("unsorted.txt");
    for (int i = 0; i < size; i++)
    {
        fout << arr[i] << " ";
    }
    fout.close();
}

void MergeSort(const char* fileName)
{
    int i, j,
        seriesLength = 1,
        numberOfElements = 0,
        series1, series2;

    fstream majorFile,
            minorFile_1,
            minorFile_2;

    majorFile.open(fileName, ios::in);
    if (!majorFile.is_open())
        cout << "File read error!\n\n";
    else
    {
        while (!majorFile.eof())
        {
            majorFile >> series1;
            numberOfElements++;
        }
        majorFile.close();
    }
    //
    // Распределение
    //
    while (seriesLength < numberOfElements)
    {
        majorFile.open(fileName, ios::in);
        minorFile_1.open("firstFile", ios::out);
        minorFile_2.open("secondFile", ios::out);

        if (!majorFile.eof())
            majorFile >> series1;
        while (!majorFile.eof())
        {
            for (i = 0; i < seriesLength && !majorFile.eof(); i++)
            {
                minorFile_1 << series1 << " ";
                majorFile >> series1;
            }
            for (j = 0; j < seriesLength && !majorFile.eof(); j++)
            {
                minorFile_2 << series1 << " ";
                majorFile >> series1;
            }
        }
        minorFile_2.close();
        minorFile_1.close();
        majorFile.close();
        //
        // Слияние
        //
        majorFile.open(fileName, ios::out);
        minorFile_1.open("firstFile", ios::in);
        minorFile_2.open("secondFile", ios::in);

        if (!minorFile_1.eof())
            minorFile_1 >> series1;
        if (!minorFile_2.eof())
            minorFile_2 >> series2;
        while (!minorFile_1.eof() && !minorFile_2.eof())
        {
            i = j = 0;
            while (i < seriesLength && j < seriesLength && !minorFile_1.eof() && !minorFile_2.eof())
            {
                if (series1 < series2)
                {
                    majorFile << series1 << " ";
                    minorFile_1 >> series1;
                    i++;
                }
                else
                {
                    majorFile << series2 << " ";
                    minorFile_2 >> series2;
                    j++;
                }
            }
            while (i < seriesLength && !minorFile_1.eof())
            {
                majorFile << series1 << " ";
                minorFile_1 >> series1;
                i++;
            }
            while (j < seriesLength && !minorFile_2.eof())
            {
                majorFile << series2 << " ";
                minorFile_2 >> series2;
                j++;
            }
        }
        while (!minorFile_1.eof())
        {
            majorFile << series1 << " ";
            minorFile_1 >> series1;
        }
        while (!minorFile_2.eof())
        {
            majorFile << series2 << " ";
            minorFile_2 >> series2;
        }

        minorFile_2.close();
        minorFile_1.close();
        majorFile.close();
        seriesLength *= 2;
    }
    remove("firstFile");
    remove("secondFile");
}

int main()
{
    srand(time(0));
    system("chcp 1251 > NUL");

    int size;
    char file[] = "array.txt";
    cout << "Input array size: "; cin >> size;
    cout << endl << endl;

    int* arr = new int[size];
    RandomArray(file, arr, size, -100, 100);
    cout << "Array generated!\n\n";

    delete[] arr;

    MergeSort(file);

    return 0;
}
