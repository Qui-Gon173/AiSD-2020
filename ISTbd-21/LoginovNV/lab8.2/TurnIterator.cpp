#include "TurnIterator.h"

// кон-р для инициализации итератора с помощью указателя элемента
TurnIterator::TurnIterator(Element* p)
{
    currentElement = p;
}

// кон-р для инициализации итератора с помощью другого итератора
TurnIterator::TurnIterator(const TurnIterator& it)
{
    currentElement = it.currentElement;
}

// перегружаем !=, ==, *, ++ для нашего итератора
bool TurnIterator::operator!=(TurnIterator const& other) const
{
    // возвращаем результат сравнения указателей
    return (currentElement != other.currentElement);
}

bool TurnIterator::operator==(TurnIterator const& other) const
{
    // возвращаем результат сравнения указателей
    return (currentElement == other.currentElement);
}

typename TurnIterator::reference TurnIterator::operator*() const
{
    // разыменовываем указатель Element
    return *currentElement;
}

TurnIterator& TurnIterator::operator++()
{
    // так как контейнер сделан с помощью связного списка
    // операция ++ эквивалентна переходу на предыдущий эл-т
    // не совсем логично, но менять, к сожалению, поздно
    currentElement = currentElement->getPrev();
    return *this;
}
