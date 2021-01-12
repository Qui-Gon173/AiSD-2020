#include <iostream>
#include <algorithm>
#include <cmath>
#include "ListIterator.h"
#include "ExponentialGenerator.h"

using namespace std;

/// <summary>
/// Генератор значений показательной функции
/// </summary>
/// <param name="list">Список для генерации</param>
/// <param name="base">Основание степени</param>
/// <param name="max">Верхняя граница генерации</param>
template <typename T>
void ExpGenerator(DoubleList<T>* list, int base, unsigned long long max)
{
    bool isNegative = base < 0;
    
    if (isNegative) base = -base;

    /* 
        чтобы можно было вводить любую границу, 
        и при этом функция не вылетала в бесконечный цикл: 
    */

    int degree = (log(max) / log(base)) + 1; // log[b](a) = ln (a) / ln (b)
    max = pow(base, degree);

    //--------------------------------------------------//

    auto generator = ExponentialGenerator(base, max);

    if (isNegative)
    {
        bool flag = true; // чередователь знака элемента
        for (auto& item : generator)
        {
            if (flag)
            {
                list->push_back(-item);
            }
            else
            {
                list->push_back(item);
            }
            flag = !flag;
        }
    }
    else
    {
        for (auto& item : generator)
        {
            list->push_back(item);
        }
    }
}

int main()
{
    system("chcp 1251 > NUL");

    //--------------------------------------------------//

    /* 
        по варианту нужен список элементов типа byte, 
        но у byte слишком маленький диапазон значений,
        поэтому генерация не будет корректно работать
    */
    DoubleList<int> myList;

    ExpGenerator(&myList, -2, 135494);

    //--------------------------------------------------//

    cout << "Вывод элементов списка:\n\n";
    for (auto& item : myList)
    {
        cout << (int)item << " ";
    }
    cout << "\n\n";

    int sum = 0;
    for (auto& item : myList)
    {
        sum += item;
    }
    cout << "Сумма: " << sum << "\n\n";

    int count = 0;
    for (auto& item : myList)
    {
        ++count;
    }
    cout << "Среднее значение: " << sum / count << "\n\n";
    
    //--------------------------------------------------//

    auto min = min_element(myList.begin(), myList.end());
    cout << "Минимальное значение: " << (int)*min << endl
        << "\tЕго индекс: " << myList.search(*min) << endl;

    cout << endl;

    auto max = max_element(myList.begin(), myList.end());
    cout << "Максимальное значение: " << (int)*max << endl
        << "\tЕго индекс: " << myList.search(*max) << endl;

    //--------------------------------------------------//

    cout << endl;
    system("pause");
    return 0;
}

