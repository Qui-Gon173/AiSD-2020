#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Queue item;
    int numb = 12;
    int numbers[15] = { 4, 65, 84, 23, 9, 11, 75, 5, 2, 56, 7, 3, 42, 98, 84 };

    cout << "Добавление элементов в очередь" << endl;
    
    item.addNumber(numb);
    item.addNumbers(numbers, 15);

    cout << "Вывод очереди:" << endl;
    item.display();

    cout << "Количество элементов в контейнере: " << endl;
    cout << item.getSize() << endl;

    cout << "Просмотреть элемент в конце очереди:" << endl;
    item.checkLast();
    
    cout << "Сумма = " << item.sum() << endl;
    cout << "Среднее арифметическое = " << item.average() << endl;
    cout << "Минимальное значение = " << item.min() << endl;
    cout << "Максимальное значение = " << item.max() << endl;
    
    cout << "Извлечь один элемент из конца очереди:" << endl;
    cout << item.extractLast() << endl;

    cout << "Вывод очереди:" << endl;
    item.display();

    cout << "Извлечь несколько элементов из конца очереди" << endl;
    int* extractArray = item.extractLast(4);

    cout << "Вывод очереди:" << endl;
    item.display();

    cout << "Переносим несколько элементов в новый экземпляр" << endl;
    Queue newItem;
    newItem = item.remake(3);

    cout << "Вывод новой очереди:" << endl;
    newItem.display();

    cout << "Вывод старой очереди:" << endl;
    item.display();

    cout << "Полная очистка обоих контейнеров" << endl;
    item.clearAll();
    newItem.clearAll();

    cout << "Вывод новой очереди:" << endl;
    newItem.display();

    cout << "Вывод старой очереди:" << endl;
    item.display();

    return 0;
}
