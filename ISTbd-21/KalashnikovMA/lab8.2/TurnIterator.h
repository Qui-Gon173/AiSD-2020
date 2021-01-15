#include <iostream>
#include "Element.h"

// наследуем класс итератора
class TurnIterator : public std::iterator<std::input_iterator_tag, Element>
{
private:
    Element* currentElement;
public:
    // кон-р для инициализации итератора с помощью указателя элемента
    TurnIterator(Element* p);
    // кон-р для инициализации итератора с помощью другого итератора
    TurnIterator(const TurnIterator& it);

    // перегружаем !=, ==, *, ++ для нашего итератора
    bool operator!=(TurnIterator const& other) const;
    bool operator==(TurnIterator const& other) const;
    typename TurnIterator::reference operator*() const;
    TurnIterator& operator++();
};


