#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


void mergeSort(const string& file, int size) {
    // вспомогательные файлы
    const string firstHelpFile = "firsthelpfile";
    const string secondHelpFile = "secondhelpfile";

    // вспомогательные числа
    int n1;
    int n2;

    for (int k = 1; k < size; k *= 2) {
        ifstream rFileToSort(file);
        ofstream wFirstHelpFile(firstHelpFile);
        ofstream wSecondHelpFile(secondHelpFile);

        // распределение серии
        if (!rFileToSort.eof()) {
            rFileToSort >> n1;
        }
        while (!rFileToSort.eof()) {
            for (int i = 0; i < k && !rFileToSort.eof(); i++) {
                wFirstHelpFile << n1 << " ";
                rFileToSort >> n1;
            }
            for (int j = 0; j < k && !rFileToSort.eof(); j++) {
                wSecondHelpFile << n1 << " ";
                rFileToSort >> n1;
            }
        }
        rFileToSort.close();
        wFirstHelpFile.close();
        wSecondHelpFile.close();

        ofstream wFileToSort(file);
        ifstream rFirstHelpFile(firstHelpFile);
        ifstream rSecondHelpFile(secondHelpFile);

        if (!rFirstHelpFile.eof()) {
            rFirstHelpFile >> n1;
        }
        if (!rSecondHelpFile.eof()) {
            rSecondHelpFile >> n2;
        }

        while (!rFirstHelpFile.eof() && !rSecondHelpFile.eof()) {
            int i = 0;
            int j = 0;

            // записываем числа в правильном порядке
            while (i < k && j < k && !rFirstHelpFile.eof() && !rSecondHelpFile.eof()) {
                if (n1 < n2) {
                    wFileToSort << n1 << " ";
                    rFirstHelpFile >> n1;
                    i++;
                } else {
                    wFileToSort << n2 << " ";
                    rSecondHelpFile >> n2;
                    j++;
                }
            }
            // если какой-то вспомогательный файл кончился
            while (i < k && !rFirstHelpFile.eof()) {
                wFileToSort << n1 << " ";
                rFirstHelpFile >> n1;
                i++;
            }
            while (j < k && !rSecondHelpFile.eof()) {
                wFileToSort << n2 << " ";
                rSecondHelpFile >> n2;
                j++;
            }
        }

        // дозапись
        while (!rFirstHelpFile.eof()) {
            wFileToSort << n1 << " ";
            rFirstHelpFile >> n1;
        }
        while (!rSecondHelpFile.eof()) {
            wFileToSort << n2 << " ";
            rSecondHelpFile >> n2;
        }
        wFileToSort.close();
        rFirstHelpFile.close();
        rSecondHelpFile.close();
    }

    remove(firstHelpFile.c_str());
    remove(secondHelpFile.c_str());
}

int main() {
    string file = "array.txt";
    int size;
    cout << "size: ";
    cin >> size;

    mergeSort(file, size);

    return 0;
}
