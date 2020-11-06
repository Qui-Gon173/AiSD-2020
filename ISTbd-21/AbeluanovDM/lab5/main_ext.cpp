#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


void merge_sort(const std::string& filename, int num) {
    const std::string help_filename1 = "help_file1";
    const std::string help_filename2 = "help_file2";

    int help_num1;
    int help_num2;

    for (int k = 1; k < num; k *= 2) {
        std::ifstream main_file_r(filename);
        std::ofstream help_file1_w(help_filename1);
        std::ofstream help_file2_w(help_filename2);
    
        if (!main_file_r.eof()) {
            main_file_r >> help_num1;
        }
        while (!main_file_r.eof()) {
            for (int i = 0; i < k && !main_file_r.eof(); i++) {
                help_file1_w << help_num1 << " " << " ";
                main_file_r >> help_num1;
            }
            for (int j = 0; j < k && !main_file_r.eof(); j++) {
                help_file2_w << help_num1 << " " << " ";
                main_file_r >> help_num1;
            }
        }
        main_file_r.close();
        help_file1_w.close();
        help_file2_w.close();

        std::ofstream main_file_w(filename);
        std::ifstream help_file1_r(help_filename1);
        std::ifstream help_file2_r(help_filename2);

        if (!help_file1_r.eof()) {
            help_file1_r >> help_num1;
        }
        if (!help_file2_r.eof()) {
            help_file2_r >> help_num2;
        }

        while (!help_file1_r.eof() && !help_file2_r.eof())
        {
            int i = 0;
            int j = 0;
            while (i < k && j < k && !help_file1_r.eof() && !help_file2_r.eof())
            {
                if (help_num1 < help_num2)
                {
                    main_file_w << help_num1 << " ";
                    help_file1_r >> help_num1;
                    i++;
                }
                else
                {
                    main_file_w << help_num2 << " ";
                    help_file2_r >> help_num2;
                    j++;
                }
            }
            while (i < k && !help_file1_r.eof())
            {
                main_file_w << help_num1 << " ";
                help_file1_r >> help_num1;
                i++;
            }
            while (j < k && !help_file2_r.eof())
            {
                main_file_w << help_num2 << " ";
                help_file2_r >> help_num2;
                j++;
            }
        }
        while (!help_file1_r.eof())
        {
            main_file_w << help_num1 << " ";
            help_file1_r >> help_num1;
        }
        while (!help_file2_r.eof())
        {
            main_file_w << help_num2 << " ";
            help_file2_r >> help_num2;
        }
        main_file_w.close();
        help_file1_r.close();
        help_file2_r.close();
    }

    std::remove(help_filename1.c_str());
    std::remove(help_filename2.c_str());
}

int main()
{
    std::string filename;
    int length;

    std::cout << "file: ";
    std::getline(std::cin, filename);
    std::cout << "quantity of elements: ";
    std::cin >> length;

    merge_sort(filename, length);

    std::cout << "all done" << std:: endl;
}
