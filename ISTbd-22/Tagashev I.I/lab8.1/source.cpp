#include <iostream>
#include "list.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	std::cout << "Тест работы." << std::endl;

	List<int>* list1 = new List<int>;
	list1->print_list();
	unsigned long var = 5;
	unsigned long var2 = 1;
	unsigned long var3 = 2;
	unsigned long var4 = 7;

	std::cout << "Добавляем эл-т " << var << std::endl;
	list1->append(var);
	std::cout << "Добавляем эл-т " << var2 << std::endl;
	list1->append(var2);
	std::cout << "Добавляем эл-т " << var3 << std::endl;
	list1->append(var3);
	std::cout << std::endl;

	std::cout << "Печать списка:" << std::endl;
	list1->print_list();
	std::cout << std::endl;

	std::cout << "Добавляем эл-т " << var4 << " на третье место" << std::endl;
	list1->insert(var4, 3);

	std::cout << "Печать списка:" << std::endl;
	list1->print_list();
	std::cout << std::endl;

	std::cout << "Удаляем эл-т с индксом " << 3 << std::endl;
	list1->delete_ind(3);

	std::cout << "Печать списка:" << std::endl;
	list1->print_list();
	std::cout << std::endl;

	std::cout << "Печать обратного списка:" << std::endl;
	list1->print_list_reverse();
	std::cout << std::endl;

	std::cout << "Индекс искомого эл-та " << var3 << " равен " << list1->search_ind(var3) << std::endl;

	std::cout << "Кол-во эл-ов: " << std::endl << list1->get_size() << std::endl;

	list1->properties_list();

	std::cout << "Удаление списка" << std::endl;
	list1->delete_front();
	std::cout << "Печать списка:" << std::endl;
	list1->print_list();

}