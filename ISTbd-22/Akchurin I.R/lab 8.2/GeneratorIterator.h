#pragma once
#include <iostream>
#include "Element.h"


class GeneratorIterator : public std::iterator<std::input_iterator_tag, int>
{
    int a, d, n;
    int* An;
public:

    GeneratorIterator(int firstNumber, int step, int kol)
    {
        a = firstNumber;
        d = step;
        n = kol;
        An = new int;

        *An = firstNumber;
    };


    bool operator!=(GeneratorIterator const& other) const
    {
        return (n != other.n);
    };

    bool operator==(GeneratorIterator const& other) const
    {
        return (n == other.n);
    };

    typename GeneratorIterator::reference operator*() const
    {
        return *An;
    };

    GeneratorIterator& operator++()
    {
        *An = (*An) + (d);
        n++;
        return *this;
    };
};