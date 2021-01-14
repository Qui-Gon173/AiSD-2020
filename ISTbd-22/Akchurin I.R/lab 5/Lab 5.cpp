#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;


void mergeSort(string &filename, int n) {
    string FirstFile = "file1", SecondFile = "file2";
    int first, last;
    int k = 1;

    while (k < n) {
        ifstream givenFileRead(filename);
        ofstream helpFile1Write(FirstFile);
        ofstream helpFile2Write(SecondFile);

        if (!givenFileRead.eof()) {
            givenFileRead >> first;
        }
        while (!givenFileRead.eof()) {
            for (int i = 0; i < k && !givenFileRead.eof(); i++) {
                helpFile1Write << first << " " << " ";
                givenFileRead >> first;
            }
            for (int j = 0; j < k && !givenFileRead.eof(); j++) {
                helpFile2Write << first << " " << " ";
                givenFileRead >> first;
            }
        }
        givenFileRead.close();
        helpFile1Write.close();
        helpFile2Write.close();

        ofstream givenFileWrite(filename);
        ifstream helpFile1Read(FirstFile);
        ifstream helpFile2Read(SecondFile);

        if (!helpFile1Read.eof()) {
            helpFile1Read >> first;
        }
        if (!helpFile2Read.eof()) {
            helpFile2Read >> last;
        }

        while (!helpFile1Read.eof() && !helpFile2Read.eof()) { 
            int i = 0;
            int j = 0;
            while (i < k && j < k && !helpFile1Read.eof() && !helpFile2Read.eof())
            {
                if (first < last)
                {
                    givenFileWrite << first << " ";
                    helpFile1Read >> first;
                    i++;
                }
                else
                {
                    givenFileWrite << last << " ";
                    helpFile2Read >> last;
                    j++;
                }
            }
            while (i < k && !helpFile1Read.eof())
            {
                givenFileWrite << first << " ";
                helpFile1Read >> first;
                i++;
            }
            while (j < k && !helpFile2Read.eof())
            {
                givenFileWrite << last << " ";
                helpFile2Read >> last;
                j++;
            }
        }
        while (!helpFile1Read.eof())
        {
            givenFileWrite << first << " ";
            helpFile1Read >> first;
        }
        while (!helpFile2Read.eof())
        {
            givenFileWrite << last << " ";
            helpFile2Read >> last;
        }
        givenFileWrite.close();
        helpFile1Read.close();
        helpFile2Read.close();

        k *= 2;
    }

    remove(FirstFile.c_str());
    remove(SecondFile.c_str());
}

int main()
{
    setlocale(LC_ALL, "Rus");
    string filename;
    int N;

    cout << "Введите название файла: ";
    getline(cin, filename);
    cout << "Введите количество чисел: ";
    cin >> N;

    mergeSort(filename, N);

    cout << "Выполнено" << endl;
}