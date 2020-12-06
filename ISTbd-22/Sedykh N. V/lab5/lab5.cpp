#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include <fstream>

using namespace std;

void Simple_Merging_Sort(char* name) {
    int a1, a2, k, i, j, kol, tmp;
    fstream f, f1, f2;
    f.open(name, fstream::in);
    kol = 0;
    if (!f)
    {
        cout << " Исходный файл не может быть прочитан...";
    }
    else {
        while (f) 
        {
            f >> a1;
            kol++;
        }
        f.close();
    }
    k = 1;

    while (k < kol) {
        f.open(name, fstream::in);
        fstream f1;
        f1.open("sort_1.txt", fstream::out);
        fstream f2;
        f2.open("sort_2.txt", fstream::out);
        if (f) f >> a1;
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
        f1.open("sort_1.txt", fstream::in);
        f2.open("sort_2.txt", fstream::in);

        if (f1) f1 >> a1;
        if (f2) f2 >> a2;
        while (f1 && f2) {
            i = 0; j = 0;

            while ((i < k) && f1) 
            {
                f << a1 << endl;
                f1 >> a1;
                i++;
            }
            while ((j < k) && f2) 
            {
                f << a2 << endl;
                f2 >> a2;
                j++;
            }
            while ((i < k) && (j < k) && (f1 && f2)) 
            {
                if (a1 < a2) {
                    f << a1 << endl;
                    f1 >> a1;
                    i++;
                }
                else {
                    f << a2 << endl;
                    f2 >> a2;
                    j++;
                }
            }
        }

        while (f1)
        {
            f << a1 << endl;
            f1 >> a1;

        }
        while (f2) 
        {
            f << a2 << endl;
            f2 >> a2;
        }

        f2.close();
        f1.close();
        f.close();

        k *= 2;
    }
    remove("sort_1.txt");
    remove("sort_2.txt");
}
int main()
{
    char tmp[] = "text.txt";
    Simple_Merging_Sort(tmp);
    cout << endl << "File 'text.txt' sorted successfully!" << endl;
    return 0;
}