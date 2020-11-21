#pragma once
#include <iostream>
#include "Element.h"

class ArifmIter : public std::iterator<std::input_iterator_tag, float>
{
private:
    // первый член последовательсноти
    float a_1;
    // разность
    float d;
    // кол-во членов
    int n;
    // текущий член, вычислим в кон-ре
    float* a_n;
public:

    ArifmIter(float firstElem, float raznost, int count);

    // перегружаем !=, ==, *, ++ для итератора последовательности
    bool operator!=(ArifmIter const& other) const;
    bool operator==(ArifmIter const& other) const;
    typename ArifmIter::reference operator*() const;
    ArifmIter& operator++();
};



