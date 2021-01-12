#include <iostream>
#include <cstring>
#include <clocale>
#include <algorithm>
#include <ctime>

#include "List.h"
#include "utils.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    Generator gen(10);
    List list(gen);
    cout << "[LIST]: ";
    print(list);

    

    cout << "SIZE = " << (int)list.getSize() << endl;
    cout << "==============================" << endl;
    cout << "AVERAGE = " << (double)average(list) << endl;
    cout << "SUM = " << (int)sum(list) << endl;
    cout << "==============================" << endl;
    const auto min = min_element(list.begin(), list.end());
    const auto max = max_element(list.begin(), list.end());
    cout << "MAX = " << (int)*max << endl;
    cout << "MIN = " << (int)*min << endl;
    cout << "==============================" << endl;
    cout << "MIN INDEX = " << distance(list.begin(), min) << endl;
    cout << "MAX INDEX = " << distance(list.begin(), max) << endl;

    return 0;
}