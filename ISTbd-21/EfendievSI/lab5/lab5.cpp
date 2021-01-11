#include <iostream>
#include <fstream>

using namespace std;

void SimpleMergeSorting(char* filename)
{
	std::fstream file;
	int x1 = 0, x2 = 0, k = 0, i = 0, j = 0, kol = 0;

	file.open(filename, std::fstream::in);
	if (!file) {
		std::cout << "ERROR: The file is not open!";
	}
	else {
		while (file) {
			file >> x1;
			kol++;
		}
		file.close();
	}
	k = 1;

    while (k < kol) {
        file.open(filename, std::fstream::in);
        std::fstream file1;
        file1.open("text1.txt", std::fstream::out);
        std::fstream file2;
        file2.open("text2.txt", std::fstream::out);
        if (file) file >> x1;
        while (file) {
            for (i = 0; i < k && file; i++) {
                file1 << x1 << std::endl;
                file >> x1;
            }
            for (j = 0; j < k && file; j++) {

                file2 << x1 << std::endl;
                file >> x1;
            }
        }
        file1.close();
        file.close();
        file2.close();


        file.open(filename, std::fstream::out);
        file1.open("arr1.txt", std::fstream::in);
        file2.open("arr2.txt", std::fstream::in);

        if (file1) file1 >> x1;
        if (file2) file2 >> x2;
        while (file1 && file2) {
            i = 0;
            j = 0;
            while (i < k && j < k && file1 && file2) {
                if (x1 < x2) {
                    file << x1 << std::endl;
                    file1 >> x1;
                    i++;
                }
                else {
                    file << x2 << std::endl;
                    file2 >> x2;
                    j++;
                }
            }
            while (i < k && file1) {
                file << x1 << std::endl;
                file1 >> x1;
                i++;
            }
            while (j < k && file2) {
                file << x2 << std::endl;
                file2 >> x2;
                j++;
            }
        }


        while (file1) {
            file << x1 << std::endl;
            file1 >> x1;

        }
        while (file2) {
            file << x2 << std::endl;
            file2 >> x2;
        }
        file2.close();
        file1.close();
        file.close();
        k *= 2;
    }
}

int main()
{
    char filename[] = "array.txt";
    SimpleMergeSorting(filename);
}
