#include <iostream>
#include <algorithm>
#include "Queue.h"
#include "Element.h"
using namespace std;

void iteratorOperations(Queue newQueue);
void algorithmOperations(Queue newQueue);
bool compare(Element& first, Element& second);


int main()
{
    setlocale(LC_ALL, "Russian");

    Queue newQueue;
    cout << "Cгенерированная арифметическая прогрессия:" << endl;
    newQueue.generate(2, 8, 11);
    newQueue.display();
    cout << endl;

    iteratorOperations(newQueue);
    algorithmOperations(newQueue);

    system("Pause");
}


void iteratorOperations(Queue newQueue)
{
    cout << "Вывод очереди с помощью итератора:" << endl;
    for (auto& item : newQueue)
    {
        cout << item.getData() << " ";
    }
    cout << endl;

    int sum = 0;
    for (auto& item : newQueue)
    {
        sum += item.getData();
    }
    int nAverage = sum / newQueue.getSize();

    cout << "Сумма, вычисленная с помощью итератора:" << endl; 
    cout << sum << endl;
    cout << "Среднее арифметическое, вычисленное с помощью итератора:" << endl; 
    cout << nAverage << endl << endl;
}

void algorithmOperations(Queue newQueue)
{
    Queue::const_iterator min = min_element(newQueue.begin(), newQueue.end(), compare);
    cout << "Значение минимального элемента:" << endl; 
    cout << (*min).getData() << endl;

    Queue::const_iterator max = max_element(newQueue.begin(), newQueue.end(), compare);
    cout << "Значение максимального элемента:" << endl;
    cout << (*max).getData() << endl;

    int minIndex = distance(newQueue.begin(), min);
    int maxIndex = distance(newQueue.begin(), max);

    cout << "Индекс минимального элемента:" << endl; 
    cout << minIndex << endl;
    cout << "Индекс максимального элемента:" << endl; 
    cout << maxIndex << endl;
}

bool compare(Element& first, Element& second)
{
    return first.getData() < second.getData();
}
