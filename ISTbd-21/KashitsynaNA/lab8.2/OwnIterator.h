#pragma once
#include <iostream>
#include "Elem.h"

class OwnIterator : public std::iterator<std::input_iterator_tag, Elem>
{
private:
    Elem* p;

public:
    OwnIterator(Elem* c)
    {
        p = c;
    };
   
    OwnIterator(const OwnIterator& it)
    {
        p = it.p;
    };

    bool operator!=(OwnIterator const& other) const
    {
        return (this->p != other.p);
    };
    bool operator==(OwnIterator const& other) const
    {
        return (this->p == other.p);
    };
    typename OwnIterator::reference operator*() const
    {
        return *p;
    };
    OwnIterator& operator++()
    {
        p = p->next_return();
        return *this;
    };

};

