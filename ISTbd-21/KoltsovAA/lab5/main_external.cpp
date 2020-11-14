#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


void merge_sort(const std::string& filename, size_t num) {
    const std::string aux_filename1 = "auxiliary_file1";
    const std::string aux_filename2 = "auxiliary_file2";

    int aux_num1;
    int aux_num2;

    for (size_t k = 1; k < num; k *= 2) {
        std::ifstream main_file_r(filename);
        std::ofstream aux_file1_w(aux_filename1);
        std::ofstream aux_file2_w(aux_filename2);
    
        if (!main_file_r.eof()) {
            main_file_r >> aux_num1;
        }
        while (!main_file_r.eof()) {
            for (int i = 0; i < k && !main_file_r.eof(); i++) {
                aux_file1_w << aux_num1 << " " << " ";
                main_file_r >> aux_num1;
            }
            for (int j = 0; j < k && !main_file_r.eof(); j++) {
                aux_file2_w << aux_num1 << " " << " ";
                main_file_r >> aux_num1;
            }
        }
        main_file_r.close();
        aux_file1_w.close();
        aux_file2_w.close();

        std::ofstream main_file_w(filename);
        std::ifstream aux_file1_r(aux_filename1);
        std::ifstream aux_file2_r(aux_filename2);

        if (!aux_file1_r.eof()) {
            aux_file1_r >> aux_num1;
        }
        if (!aux_file2_r.eof()) {
            aux_file2_r >> aux_num2;
        }

        while (!aux_file1_r.eof() && !aux_file2_r.eof())
        {
            int i = 0;
            int j = 0;
            while (i < k && j < k && !aux_file1_r.eof() && !aux_file2_r.eof())
            {
                if (aux_num1 < aux_num2)
                {
                    main_file_w << aux_num1 << " ";
                    aux_file1_r >> aux_num1;
                    i++;
                }
                else
                {
                    main_file_w << aux_num2 << " ";
                    aux_file2_r >> aux_num2;
                    j++;
                }
            }
            while (i < k && !aux_file1_r.eof())
            {
                main_file_w << aux_num1 << " ";
                aux_file1_r >> aux_num1;
                i++;
            }
            while (j < k && !aux_file2_r.eof())
            {
                main_file_w << aux_num2 << " ";
                aux_file2_r >> aux_num2;
                j++;
            }
        }
        while (!aux_file1_r.eof())
        {
            main_file_w << aux_num1 << " ";
            aux_file1_r >> aux_num1;
        }
        while (!aux_file2_r.eof())
        {
            main_file_w << aux_num2 << " ";
            aux_file2_r >> aux_num2;
        }
        main_file_w.close();
        aux_file1_r.close();
        aux_file2_r.close();
    }

    std::remove(aux_filename1.c_str());
    std::remove(aux_filename2.c_str());
}

int main()
{
    std::string filename;
    size_t length;

    std::cout << "filename: ";
    std::getline(std::cin, filename);
    std::cout << "number of elements: ";
    std::cin >> length;

    merge_sort(filename, length);

    std::cout << "Ok. Check " << filename << "!" << std::endl;
}
