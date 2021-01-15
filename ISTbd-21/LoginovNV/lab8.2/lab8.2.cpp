#include <iostream>
#include <algorithm>
#include "Turn.h"
#include "Element.h"

// применение итератора к контейнеру
void showCharactersByIterator(Turn turn);
// применение алгоритмов к контейнеру
void showCharactersByAlgorithms(Turn turn);

// чтобы компилятор мог сравнить объекты Element
bool compareElem(Element &first, Element &second);

int main()
{
    setlocale(LC_ALL, "Russian");

    Turn exampleTurn;
    float numbers[13] = { 1.1, 1.2, 3.6, 0.7, 12.9, 4.6, 9.1 , 5.7, 6.8, 3.145, 6.5215, 12.8, 444.545};
    exampleTurn.pushArr(numbers, 13);

    showCharactersByIterator(exampleTurn);
    showCharactersByAlgorithms(exampleTurn);

   
    exampleTurn.deleteTurn();
    std::cout << "Арифмитическая последовательность:" << std::endl;
    exampleTurn.generateArifm(5.0, 1.5, 5);
    exampleTurn.printTurn();
    
    system("Pause");
}

void showCharactersByIterator(Turn turn)
{
    // поочерёдный вывод эл-ов
    std::cout << "Элементы очереди:" << std::endl;
    for (auto& item : turn)
    {
        std::cout << item.getData() << " ";
    }
    
    // подсчёт суммы
    float sum = 0;
    for (auto& item : turn)
    {
        sum += item.getData();
    }

    // подсчёт среднего
    float avg = sum / turn.retSize();

    // вывод суммы и среднего
    std::cout << "\nSum = " << sum << " avg = " << avg << std::endl;

    std::cout << "Сравним с тем, что покажет метод контейнера:" << std::endl;
    turn.showCharacters();
}

// для сравнения чисел
bool compareElem(Element& first, Element& second)
{
    return first.getData() < second.getData();
}

void showCharactersByAlgorithms(Turn turn)
{
    // находим минимальный эл-т
    Turn::const_iterator min = std::min_element(turn.begin(), turn.end(), compareElem);
    std::cout << "Минимальный эл-т: " << (*min).getData() << std::endl;

    // находим максимальный эл-т
    Turn::const_iterator max = std::max_element(turn.begin(), turn.end(), compareElem);
    std::cout << "Максимальный эл-т: " << (*max).getData() << std::endl;

    // находим их индексы
    int minIndex = std::distance(turn.begin(), min);
    int maxIndex = std::distance(turn.begin(), max);

    std::cout << "Индекс минимального: " << minIndex << std::endl;
    std::cout << "Индекс максимального: " << maxIndex << std::endl;
}