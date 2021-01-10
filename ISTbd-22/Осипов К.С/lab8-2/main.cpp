#include <iostream>
#include <algorithm>
#include "ListIterator.h"

using namespace std;

int main()
{
    system("chcp 1251 > NUL");
    srand(time(0));

    DoubleList<byte> byteList;

    size_t listSize = 10;
    while(listSize)
    {
        byteList.push_back(rand() % 256);
        --listSize;
    }

    cout << "Вывод элементов списка:\n\n";
    for (auto& item : byteList)
    {
        cout << *item << " ";
    }
    cout << "\n\n";

    int sum = 0;
    for (auto& item : byteList)
    {
        sum += item;
    }
    cout << "Сумма: " << sum << "\n\n";

    int count = 0;
    for (auto& item : byteList)
    {
        ++count;
    }
    cout << "Среднее значение: " << sum / count << "\n\n";
    
    

    auto min = min_element(byteList.begin(), byteList.end());
    cout << "Минимальное значение: " << *min << endl;

    auto max = max_element(byteList.begin(), byteList.end());
    cout << "Максимальное значение: " << *max << endl;

    system("pause");
    return 0;
}

