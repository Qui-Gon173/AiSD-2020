#pragma once
#include <algorithm>

class ExponentialFunctionGenerator: public std::iterator<std::input_iterator_tag, unsigned int>
{

public:
    ExponentialFunctionGenerator(const unsigned int A, const unsigned int max, int N);
    ~ExponentialFunctionGenerator();

    typedef ExponentialFunctionGenerator const_iterator;

    bool operator != (ExponentialFunctionGenerator const& other) const;
    bool operator == (ExponentialFunctionGenerator const& other) const;
    typename ExponentialFunctionGenerator::reference operator*() const;
    ExponentialFunctionGenerator& operator++();

    const_iterator begin() const;
    const_iterator end() const;
private:
    unsigned int* _state;
    int N;
    const unsigned int A;
    const unsigned int _borderValue;
};


ExponentialFunctionGenerator::ExponentialFunctionGenerator(unsigned int A,unsigned int borderValue, int N) : A(A), _borderValue(borderValue), N(N), _state(new unsigned int(A))
{
}

ExponentialFunctionGenerator::~ExponentialFunctionGenerator(){
    delete _state;
}

bool ExponentialFunctionGenerator::operator != (ExponentialFunctionGenerator const &other) const
{
    return *_state != *other;
}

bool ExponentialFunctionGenerator::operator == (ExponentialFunctionGenerator const &other) const
{
    return *_state == *other._state;
}

typename ExponentialFunctionGenerator::reference ExponentialFunctionGenerator::operator*() const
{
    //return *_state;
    *_state = 1;
			for (int i = 0; i < N; i++) {
				*_state *= A;
			}
			return *_state;
}

ExponentialFunctionGenerator &ExponentialFunctionGenerator::operator++()
{
    int previous_state = *_state;
    delete _state;
    _state = new unsigned int(previous_state^N);
    N = N+1;
    return *this;
}

ExponentialFunctionGenerator::const_iterator ExponentialFunctionGenerator::begin() const{
    return const_iterator(this->A,this->_borderValue,this->N);
}

ExponentialFunctionGenerator::const_iterator ExponentialFunctionGenerator::end() const{
    return const_iterator(this->_borderValue,this->_borderValue,this->N);
}
