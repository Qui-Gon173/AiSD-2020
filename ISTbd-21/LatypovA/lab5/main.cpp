#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


void mergeSort(const string& file, int size) {
    const string tmpFile1 = "tmpFile1";
    const string tmpFile2 = "tmpFile2";

    int n1;
    int n2;

    for (int k = 1; k < size;) {
        ifstream rFileToSort(file);
        ofstream wTmpFile1(tmpFile1);
        ofstream wTmpFile2(tmpFile2);

        if (!rFileToSort.eof()) {
            rFileToSort >> n1;
        }
        while (!rFileToSort.eof()) {
            for (int i = 0; i < k && !rFileToSort.eof(); i++) {
                wTmpFile1 << n1 << " ";
                rFileToSort >> n1;
            }
            for (int j = 0; j < k && !rFileToSort.eof(); j++) {
                wTmpFile2 << n1 << " ";
                rFileToSort >> n1;
            }
        }
        rFileToSort.close();
        wTmpFile1.close();
        wTmpFile2.close();

        ofstream wFileToSort(file);
        ifstream rTmpFile1(tmpFile1);
        ifstream rTmpFile2(tmpFile2);

        if (!rTmpFile1.eof()) {
            rTmpFile1 >> n1;
        }
        if (!rTmpFile2.eof()) {
            rTmpFile2 >> n2;
        }

        while (!rTmpFile1.eof() && !rTmpFile2.eof()) {
            int i = 0;
            int j = 0;

            while (i < k && j < k && !rTmpFile1.eof() && !rTmpFile2.eof()) {
                if (n1 < n2) {
                    wFileToSort << n1 << " ";
                    rTmpFile1 >> n1;
                    i++;
                } else {
                    wFileToSort << n2 << " ";
                    rTmpFile2 >> n2;
                    j++;
                }
            }
            while (i < k && !rTmpFile1.eof()) {
                wFileToSort << n1 << " ";
                rTmpFile1 >> n1;
                i++;
            }
            while (j < k && !rTmpFile2.eof()) {
                wFileToSort << n2 << " ";
                rTmpFile2 >> n2;
                j++;
            }
        }

        // дозаписать то, что осталось
        while (!rTmpFile1.eof()) {
            wFileToSort << n1 << " ";
            rTmpFile1 >> n1;
        }
        while (!rTmpFile2.eof()) {
            wFileToSort << n2 << " ";
            rTmpFile2 >> n2;
        }
        wFileToSort.close();
        rTmpFile1.close();
        rTmpFile2.close();

        k *= 2;
    }

    remove(tmpFile1.c_str());
    remove(tmpFile2.c_str());
}


int main() {
    string file = "array.txt";
    size_t size;
    cout << "size = ";
    cin >> size;

    mergeSort(file, size);

    return 0;
}
