#include <iostream>
#include <cstring>
#include <clocale>
#include <algorithm>
#include <ctime>

#include "List.h"
#include "utils.h"

typedef unsigned char byte_t;

using namespace std;


int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    RandomGenerator gen(10);
    List list(gen);
    print(list);

    cout << "Size: " << (int)list.GetSize() << endl;;
    cout << "Sum: " << (int)sum(list) << endl;
    cout << "Average: " << (double)average(list) << endl;
    const auto min = min_element(list.begin(), list.end());
    const auto max = max_element(list.begin(), list.end());
    cout << "Min: " << (int)*min << endl;
    cout << "Max: " << (int)*max << endl;
    cout << "Min index: " << distance(list.begin(), min) << endl;
    cout << "Max index: " << distance(list.begin(), max) << endl;

    return 0;
}