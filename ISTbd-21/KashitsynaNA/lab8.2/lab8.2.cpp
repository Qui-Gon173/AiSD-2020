#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "list.h"
#include "Elem.h"
#include "Generator.h"


void Print(List list);
void chislaGener(List& list, long first, long znamenatel, int kol);
void Summa(List list);
void Srednee(List list, int kol);
bool Compare(Elem& elem1, Elem& elem2);


int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Односвязный линейный список. Итератор." << std::endl << "*********************************************" << std::endl;
    List Spisok;
    chislaGener(Spisok, 2, 3, 8);
    
    std::cout << "Список:" << std::endl;
    Print(Spisok);

    std::cout << "" << std::endl << "Сумма всех значений: ";
    Summa(Spisok);

    std::cout << "" << std::endl << "Среднее значение: ";
    Srednee(Spisok, 8);

    List::const_iterator minVal = std::min_element(Spisok.begin(), Spisok.end(), Compare);
    List::const_iterator maxVal = std::max_element(Spisok.begin(), Spisok.end(), Compare);
    std::cout << "" << std::endl << "Значение минимального элемента: ";
    std::cout << (*minVal).data_return();
    std::cout << "" << std::endl << "Значение максимального элемента: ";
    std::cout << (*maxVal).data_return() << std::endl;

    int minInd = std::distance(Spisok.begin(), minVal);
    int maxInd = std::distance(Spisok.begin(), maxVal);
    std::cout << "Индекс минимального элемента: ";
    std::cout << minInd << std::endl;;
    std::cout << "Индекс максимального элемента: ";
    std::cout << maxInd << std::endl;

    return 0;
}


//Поочередный вывод элементов контейнера
void Print(List list)
{
    for (auto& item : list) 
    {
        std::cout << item.data_return() << " ";
    }
    std::cout << "" << std::endl;
}


//Генератор чисел геометрической прогрессии
void chislaGener(List& list, long first, long znamenatel, int kol)
{
    auto generator = Generator(first, znamenatel, kol);
    
        for (auto& item : generator) {
            list.Add(item);
        }
};


//Сумма всех значений
void Summa(List list)
{
    int sum = 0;
    for (auto& item : list) {
        sum = sum + item.data_return();
    }
    std::cout << sum << " ";
}


//Среднее значение
void Srednee(List list, int kol)
{
    int sum = 0;
    for (auto& item : list) {
        sum = sum + item.data_return();
    }
    int average;
    average = sum / kol;
    std::cout << average << " ";
}


//Сравниваю числа
bool Compare(Elem& elem1, Elem& elem2)
{
    return elem1.data_return() < elem2.data_return();
}

