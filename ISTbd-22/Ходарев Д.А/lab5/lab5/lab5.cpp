#include <iostream>
#include <fstream>

using namespace std;

void SimpleMergeSorting(char* filename) {
	int a1, a2, k, i, j, kol, tmp;
	fstream file;
	
    kol = -1;

	file.open(filename, fstream::in);
	if (!file) {
		cout << "ERROR: The file is not open. \n";
	}
	else {
		while (file) {
			file >> a1;
			kol++;
		}
		file.close();
	}
	k = 1;

    while (k < kol) {
        file.open(filename, fstream::in);
        fstream file1;
        file1.open("smsort_1.txt", fstream::out);
        fstream file2;
        file2.open("smsort_2.txt", fstream::out);
        if (file) file >> a1;
        while (file) {
            for (i = 0; i < k && file; i++) {
                file1 << a1 << endl;
                file >> a1;
            }
            for (j = 0; j < k && file; j++) {

                file2 << a1 << endl;
                file >> a1;
            }
        }
        file1.close();
        file.close();
        file2.close();


        file.open(filename, fstream::out);
        file1.open("Arr1.txt", fstream::in);
        file2.open("Arr2.txt", fstream::in);

        if (file1) file1 >> a1;
        if (file2) file2 >> a2;
        while (file1 && file2) {
            i = 0;
            j = 0;
            while (i < k && j < k && file1 && file2) {
                if (a1 < a2) {
                    file << a1 << endl;
                    file1 >> a1;
                    i++;
                }
                else {
                    file << a2 << endl;
                    file2 >> a2;
                    j++;
                }
            }
            while (i < k && file1) {
                file << a1 << endl;
                file1 >> a1;
                i++;
            }
            while (j < k && file2) {
                file << a2 << endl;
                file2 >> a2;
                j++;
            }
        }


        while (file1) {
            file << a1 << endl;
            file1 >> a1;

        }
        while (file2) {
            file << a2 << endl;
            file2 >> a2;
        }
        file2.close();
        file1.close();
        file.close();
        k *= 2;
    }
}

int main() {
	char filename[] = "Array.txt";
	SimpleMergeSorting(filename);
	return 0;
}