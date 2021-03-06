#include <iostream>
#include "LinkedList.h"


int main()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "1. Заполнение списка" << std::endl;
	LinkedList<long>* list = new LinkedList<long>;
	long *element1 = new long;
	*element1 = 12;
	long *element2 = new long;
	*element2 = 13;
	long *element3 = new long;
	*element3 = 14;
	long *element4 = new long;
	*element4 = 15;
	std::cout << "2. Добавление элементов" << std::endl;
	list->AddElement(element1,1);
	list->AddElement(element2,1);
	list->AddElement(element3,2);
	list->AddElement(element4,2);
	std::cout << "3. Печать списка" << std::endl;
	list->PrintList();
	std::cout << std::endl;
	std::cout << "4. Удаление второго элемента" << std::endl;
	list->DeleteElement(2);
	std::cout << std::endl;
	std::cout << "5. Печать списка в обратном порядке" << std::endl;
	list->PrintReversedList();
	std::cout << std::endl;
	std::cout << "6. Количество элментов в списке" << std::endl;
	std::cout << list->GetSize() << std::endl;
	std::cout << std::endl;
	std::cout << "7. Сумма всех элементов" << std::endl;
	std::cout << list->GetSum() << std::endl;
	std::cout << std::endl;
	std::cout << "8. Значение максимального элемента" << std::endl;
	std::cout << list->SearchMax() << std::endl;
	std::cout << std::endl;
	std::cout << "8. Значение минимального элемента" << std::endl;
	std::cout << list->SearchMin() << std::endl;
	std::cout << std::endl;
	std::cout << "9. Среднее значение по списку" << std::endl;
	std::cout << list->CountAverageValue() << std::endl;
    return 0;
}

