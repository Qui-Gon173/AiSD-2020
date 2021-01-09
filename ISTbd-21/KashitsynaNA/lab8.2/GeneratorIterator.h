#pragma once
#include <iostream>
#include "Elem.h"


class GeneratorIterator : public std::iterator<std::input_iterator_tag, long>
{
    long b1, q;
    int n;
    long* bn; // n-ый член последовательности
public:

    GeneratorIterator(long first, long znamenatel, int kol)
    {
        b1 = first;
        q = znamenatel;
        n = kol;
        bn = new long;
        
        *bn = first;
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
        return *bn;
    };

    GeneratorIterator& operator++()
    {
        *bn = (*bn)*(q);
        n++;
        return *this;
    };
};

