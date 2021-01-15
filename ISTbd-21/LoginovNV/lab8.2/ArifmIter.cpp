#include "ArifmIter.h"

ArifmIter::ArifmIter(float firstElem, float raznost, int count)
{
    a_1 = firstElem;
    d = raznost;
    n = count;
    a_n = new float;
    *a_n = a_1 + ((n - 1) * d);
}

// перегружаем !=, ==, *, ++ для нашего итератора
bool ArifmIter::operator!=(ArifmIter const& other) const
{
    return (*a_n != *(other.a_n));
}

bool ArifmIter::operator==(ArifmIter const& other) const
{
    return (*a_n == *(other.a_n));
}

typename ArifmIter::reference ArifmIter::operator*() const
{
    
    return *a_n;
}

ArifmIter& ArifmIter::operator++()
{

    *a_n = *a_n + d;
    return *this;
}