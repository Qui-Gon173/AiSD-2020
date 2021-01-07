#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "list.h"
#include "list.cpp"

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Односвязный линейный список" << std::endl << "************************************" << std::endl;

    List* Spisok = new List;
    Spisok->Insert(0, 0); Spisok->Insert(3, 1); Spisok->Insert(-58, 2); Spisok->Insert(-6527, 4); Spisok->Insert(489, 3);

    std::cout << "Список:" << std::endl;
    Spisok->Print(); 

    std::cout << "" << std::endl << std::endl << "Добавьте элемент, выбрав для него позицию" << std::endl;
    long value;
    std::cout << "Элемент: ";
    std::cin >> value;
    int value_index;
    std::cout << "Позиция элемента: ";
    std::cin >> value_index;
    Spisok->Insert(value, value_index);
    std::cout << "Элемент успешно добавлен в список" << std::endl << std::endl; 

    std::cout << "Измененный список:" << std::endl;
    Spisok->Print(); 

    std::cout << "" << std::endl << std::endl << "Удалите элемент с позиции" << std::endl;
    long delete_index;
    std::cout << "Позиция элемента: ";
    std::cin >> delete_index;
    Spisok->Delete(delete_index);
    std::cout << "Элемент успешно удален из списка" << std::endl << std::endl;

    std::cout << "Измененный список:" << std::endl;
    Spisok->Print();

    std::cout << "" << std::endl << std::endl << "Получите индекса элемента по значению" << std::endl;
    long value_poisk;
    std::cout << "Элемент: ";
    std::cin >> value_poisk;
    Spisok->Index(value_poisk);

    std::cout << "" << std::endl << "Количество элементов в списке: ";
    Spisok->GetCount();

    std::cout << "" << std::endl << "Сумма всех значений: ";
    Spisok->Summa();

    std::cout << "" << std::endl << "Среднее значение: ";
    Spisok->Srednee();

    std::cout << "" << std::endl << "Значение минимального элемента: ";
    Spisok->Min();

    std::cout << "" << std::endl << "Значение максимального элемента: ";
    Spisok->Max();
    std::cout << "" << std::endl;

    std::cout << "" << std::endl << "Чтобы очистить список, нажмите 1: ";
    int och;
    std::cin >> och;
    if (och == 1)
    {
        Spisok->Clear();
        std::cout << "Список полностью очищен" << std::endl << std::endl;
    }
    std::cout << "Измененный список:" << std::endl;
    Spisok->Print();
    

    return 0;
}


