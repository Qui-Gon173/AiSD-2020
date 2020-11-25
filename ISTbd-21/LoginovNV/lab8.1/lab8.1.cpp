#include <iostream>
#include "Turn.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Тест работы." <<std::endl;

    Turn exampleTurn;
    float numb = 5.1;
    std::cout << "Добавляем один эл-т" << std::endl;
    exampleTurn.pushElem(numb);

    float numbers[13] = { 1.1, 1.2, 3.6, 0.7, 12.9, 4.6, 9.1 , 5.7, 6.8, 3.145, 6.5215, 12.8, 444.545};
    std::cout << "Добавляем массив из 12 эл-ов" << std::endl;
    exampleTurn.pushArr(numbers, 13);
    
    std::cout << "Вся очередь:" << std::endl;
    exampleTurn.printTurn();

    std::cout << "Кол-во эл-ов: " << std::endl << exampleTurn.retSize() << std::endl;

    std::cout << "Смотрим последний эл-т:" << std::endl;
    exampleTurn.checkLast();

    std::cout << "Извлекаем этот эл-т: " <<  std::endl << exampleTurn.getElem() << std::endl;
    
    std::cout << "Вся очередь:" << std::endl;
    exampleTurn.printTurn();

    std::cout << "Извлекаем массив из 3 эл-ов: " << std::endl;
    float* massiv = exampleTurn.getElem(3);
    for (int i = 0; i < 3; i++)
    {
        std::cout << massiv[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Вся очередь:" << std::endl;
    exampleTurn.printTurn();

    exampleTurn.showCharacters(); // показываем характеристики

    std::cout << "Переносим 3 эл-та в новую очередь" << std::endl;
    Turn newTurn;
    newTurn = exampleTurn.transfer(3);
    
    std::cout << "Новая очередь:" << std::endl;
    newTurn.printTurn();

    std::cout << "Старая очередь:" << std::endl;
    exampleTurn.printTurn();

    std::cout << "Удаляем обе очереди" << std::endl;
    exampleTurn.deleteTurn();
    newTurn.deleteTurn();
    std::cout << "Пытаемся их распечатать:" << std::endl;
    exampleTurn.printTurn();
    newTurn.printTurn();

    char m; // вместо паузы
    std::cin >> m;
}
