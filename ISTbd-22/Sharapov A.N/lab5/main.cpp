#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void merge_sort (const string& filename, size_t amount) {
    const string temp_filename1 = "temporary_file1";
    const string temp_filename2 = "temporary_file2";

    int temp_amount1;
    int temp_amount2;

    for (size_t k = 1; k < amount; k *= 2) {
        ifstream file_read(filename);
        ofstream temp_file1_write(temp_filename1);
        ofstream temp_file2_write(temp_filename2);

        if (!file_read.eof()) {
            file_read >> temp_amount1;
        }
        while (!file_read.eof()) {
            for (int i = 0; i < k && !file_read.eof(); i++) {
                temp_file1_write << temp_amount1 << " " << " ";
                file_read >> temp_amount1;
            }
            for (int j = 0; j < k && !file_read.eof(); j++) {
                temp_file2_write << temp_amount1 << " " << " ";
                file_read >> temp_amount1;
            }
        }
        file_read.close();
        temp_file1_write.close();
        temp_file2_write.close();

        ofstream file_write(filename);
        ifstream temp_file1_read(temp_filename1);
        ifstream temp_file2_read(temp_filename2);

        if (!temp_file1_read.eof()) {
            temp_file1_read >> temp_amount1;
        }
        if (!temp_file2_read.eof()) {
            temp_file2_read >> temp_amount2;
        }

        while (!temp_file1_read.eof() && !temp_file2_read.eof())
        {
            int i = 0;
            int j = 0;
            while (i < k && j < k && !temp_file1_read.eof() && !temp_file2_read.eof())
            {
                if (temp_amount1 < temp_amount2)
                {
                    file_write << temp_amount1 << " ";
                    temp_file1_read >> temp_amount1;
                    i++;
                }
                else
                {
                    file_write << temp_amount2 << " ";
                    temp_file2_read >> temp_amount2;
                    j++;
                }
            }
            while (i < k && !temp_file1_read.eof())
            {
                file_write << temp_amount1 << " ";
                temp_file1_read >> temp_amount1;
                i++;
            }
            while (j < k && !temp_file2_read.eof())
            {
                file_write << temp_amount2 << " ";
                temp_file2_read >> temp_amount2;
                j++;
            }
        }
        while (!temp_file1_read.eof())
        {
            file_write << temp_amount1 << " ";
            temp_file1_read >> temp_amount1;
        }
        while (!temp_file2_read.eof())
        {
            file_write << temp_amount2 << " ";
            temp_file2_read >> temp_amount2;
        }
        file_write.close();
        temp_file1_read.close();
        temp_file2_read.close();
    }

    remove(temp_filename1.c_str());
    remove(temp_filename2.c_str());
}

int main()
{
    string filename;
    size_t amount;

    cout << "filename: ";
    getline(cin, filename);
    cout << "elements: ";
    cin >> amount;

    merge_sort(filename, amount);

    cout << "Sorted " << filename << "!" << endl;
}