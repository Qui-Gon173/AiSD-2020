#include <iostream>
#include "Stack.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int stackSize;
    cout << "Введите количество элементов в стеке: ";
    cin >> stackSize;

    Stack *stack = new Stack(stackSize);
    stack->generate();

    cout << "Сгенерированный стек: ";
    stack->printStack();

    float newElements[4] = {2.3, 33, 1.4, 10};
    stack->pushElements(newElements, 4);
    cout << "Стек с добавленными элементами: ";
    stack->printStack();

    cout << "Вершина стека: ";
    cout << stack->topElement() << endl;

    cout << "Количество элементов в стеке: ";
    cout << stack->numberElements() << endl;

    cout << "Сумма элементов стека: ";
    cout << stack->sumElements() << endl;

    cout << "Среднее значение элементов стека: ";
    cout << stack->meanValue() << endl;

    cout << "Минимальный элемент в стеке: ";
    cout << stack->minElement() << endl;

    cout << "Максимальный элемент в стеке: ";
    cout << stack->maxElement() << endl;

    int poppingElementsNumber;
    cout << "Введите количество элементов для удаления: ";
    cin >> poppingElementsNumber;

    float poppedTElement;
    float* newArray = new float[poppingElementsNumber];

    if (poppingElementsNumber == 1) 
        poppedTElement = stack->pop();
    else 
    {
        newArray = stack->popMultipleElements(poppingElementsNumber);
    }
    cout << "Стэк с удалленными элементами: ";
    stack->printStack();

    cout << "Удаленные элементы добаляются в новый стек:  ";
    Stack* secondStack = new Stack();
    secondStack->pushElements(newArray, poppingElementsNumber);
    secondStack->printStack();
}