#include <iostream>
#include "Element.h"

class QueueIterator : public std::iterator<std::input_iterator_tag, Element>
{
private:
    Element* currentElement;
public:
    QueueIterator(Element* p);
    QueueIterator(const QueueIterator& it);

    bool operator!=(QueueIterator const& other) const;
    bool operator==(QueueIterator const& other) const;
    typename QueueIterator::reference operator*() const;
    QueueIterator& operator++();
};