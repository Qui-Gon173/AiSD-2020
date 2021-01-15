#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <locale.h>
#include "list.h"

int main()
{
    std::cout << "Singly linked linear list" << std::endl;

    List* Spisok = new List;
    Spisok->Insert(0, 0); Spisok->Insert(3, 1); Spisok->Insert(-58, 2); Spisok->Insert(-6527, 4); Spisok->Insert(489, 3);

    std::cout << "List:" << std::endl;
    Spisok->Print();

    std::cout << "" << std::endl << std::endl << "Add an element by choosing a position for it" << std::endl;
    long value;
    std::cout << "Element: ";
    std::cin >> value;
    int value_index;
    std::cout << "Item position: ";
    std::cin >> value_index;
    Spisok->Insert(value, value_index);
    std::cout << "The item was successfully added to the list" << std::endl << std::endl;

    std::cout << "Modified list:" << std::endl;
    Spisok->Print();

    std::cout << "" << std::endl << std::endl << "Remove item from position" << std::endl;
    long delete_index;
    std::cout << "Item position: ";
    std::cin >> delete_index;
    Spisok->Delete(delete_index);
    std::cout << "Item was successfully removed from the list" << std::endl << std::endl;

    std::cout << "Modified list:" << std::endl;
    Spisok->Print();

    std::cout << "" << std::endl << std::endl << "Get the index of an element by value" << std::endl;
    long value_poisk;
    std::cout << "Element: ";
    std::cin >> value_poisk;
    Spisok->Index(value_poisk);

    std::cout << "" << std::endl << "Number of items in the list: ";
    Spisok->GetCount();

    std::cout << "" << std::endl << "The sum of all values: ";
    Spisok->Summa();

    std::cout << "" << std::endl << "Average value: ";
    Spisok->Srednee();

    std::cout << "" << std::endl << "Minimum element value: ";
    Spisok->Min();

    std::cout << "" << std::endl << "Maximum element value: ";
    Spisok->Max();
    std::cout << "" << std::endl;

    std::cout << "" << std::endl << "To clear the list, press 1: ";
    int och;
    std::cin >> och;
    if (och == 1)
    {
        Spisok->Clear();
        std::cout << "The list is completely cleared" << std::endl << std::endl;
    }
    std::cout << "Modified list:" << std::endl;
    Spisok->Print();


    return 0;
}


