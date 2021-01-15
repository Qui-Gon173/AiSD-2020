#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include <fstream>
using namespace std;
//Описание функции сортировки простым слиянием
void Simple_Merging_Sort(char* name) {
    int a1, a2, k, i, j, kol, tmp;
 fstream f,f1,f2;
 f.open(name, fstream::in);
 kol = 0;
    if (!f)
    {
 cout << " Исходный файл не может быть прочитан...";
    }
    else {
        while (f) {
 f >> a1;
 kol++;
        }
 f.close();
    }
 k = 1;

    while (k < kol) {
     f.open(name, fstream::in);
     f1.open("smsort_1", fstream::out);
     f2.open("smsort_2", fstream::out);
        if (f) f >>a1;
        while (f) {
            for (i = 0; i < k && f; i++) {
        f1 << a1 << endl;
                f >> a1;
            }
            for (j = 0; j < k && f; j++) {

                f2 << a1 << endl;
                f >> a1;
            }
        }
        f1.close();
        f.close();
        f2.close();


        f.open(name, fstream::out);
        f1.open("smsort_1", fstream::in);
        f2.open("smsort_2", fstream::in);

        if (f1) f1 >> a1;
        if (f2) f2 >> a2;
        while (f1 && f2) {
            i = 0;
            j = 0;
            while (i < k && j < k && f1 && f2) {
                if (a1 < a2) {
                    f << a1 <<endl;
                   f1 >> a1;
                    i++;
                }
                else {
                    f << a2 <<endl;
                    f2 >> a2;
                    j++;
                }
            }
            while (i < k && f1) {
                f << a1 <<endl;
                f1>>a1;
                i++;
            }
            while (j < k && f2) {
                f << a2 <<endl;
               f2 >>a2;
                j++;
            }
        }


        while (f1) {
            f << a1 <<endl;
            f1 >> a1;

        }
        while (f2) {
            f << a2 <<endl;
            f2 >> a2;
        }
        f2.close();
        f1.close();
        f.close();
        k *= 2;
}
  remove("smsort_1.txt");
  remove("smsort_2.txt");
}
int main()
{

    Simple_Merging_Sort("text.txt");
    return 0;
}
