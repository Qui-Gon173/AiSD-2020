#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include <fstream>

using namespace std;

void Sort(char* nameFile) {
    int a1, a2, k, i, j, kol;
    fstream main;
    main.open(nameFile, fstream::in);
    kol = -1;
    if (!main)
    {
        cout << "DONT WORK PLS CREATE FILE";
    }
    else {
        while (main) {
            main >> a1;
            kol++;
        }
        main.close();
    }
    k = 1;

    while (k < kol) {
        main.open(nameFile, fstream::in);
        fstream part1;
        part1.open("sort_1.txt", fstream::out);
        fstream part2;
        part2.open("sort_2.txt", fstream::out);
        if (main) main >> a1;
        while (main) {
            for (i = 0; i < k && main; i++) {
                part1 << a1 << endl;
                main >> a1;
            }
            for (j = 0; j < k && main; j++) {

                part2 << a1 << endl;
                main >> a1;
            }
        }
        part1.close();
        main.close();
        part2.close();


        main.open(nameFile, fstream::out);
        part1.open("sort_1.txt", fstream::in);
        part2.open("sort_2.txt", fstream::in);

        if (part1) part1 >> a1;
        if (part2) part2 >> a2;
        while (part1 && part2) {
            i = 0;
            j = 0;
            while (i < k && j < k && part1 && part2) {
                if (a1 < a2) {
                    main << a1 << endl;
                    part1 >> a1;
                    i++;
                }
                else {
                    main << a2 << endl;
                    part2 >> a2;
                    j++;
                }
            }
            while (i < k && part1) {
                main << a1 << endl;
                part1 >> a1;
                i++;
            }
            while (j < k && part2) {
                main << a2 << endl;
                part2 >> a2;
                j++;
            }
        }


        while (part1) {
            main << a1 << endl;
            part1 >> a1;

        }
        while (part2) {
            main << a2 << endl;
            part2 >> a2;
        }
        part2.close();
        part1.close();
        main.close();
        k *= 2;
    }
}
int main()
{
    char name[] = "File.txt";
    Sort(name);
    cout << "WORK";

    return 0;
}