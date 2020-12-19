#pragma once
#include <algorithm>

class fibonacci_numbers_generator: public std::iterator<std::input_iterator_tag, int>
{
    
public:
    fibonacci_numbers_generator(const int number1,const int max, int number2);
    ~fibonacci_numbers_generator();
    
    typedef fibonacci_numbers_generator const_iterator;

    bool operator!=(fibonacci_numbers_generator const& other) const;
    bool operator==(fibonacci_numbers_generator const& other) const; 
    typename fibonacci_numbers_generator::reference operator*() const;
    fibonacci_numbers_generator& operator++();
    
    const_iterator begin() const;
    const_iterator end() const;
private:
    int* _state;
    int _number2;
    int _number1;
    int _max;
};


fibonacci_numbers_generator::fibonacci_numbers_generator(int number1,int max, int number2) : _number1(number1),_max(max),_number2(number2),_state(new int(number1)) {
}

fibonacci_numbers_generator::~fibonacci_numbers_generator(){
    delete _state;
}

bool fibonacci_numbers_generator::operator!=(fibonacci_numbers_generator const &other) const
{
    return *_state!=*other;
}

bool fibonacci_numbers_generator::operator==(fibonacci_numbers_generator const &other) const
{
    return *_state==*other._state;
}

typename fibonacci_numbers_generator::reference fibonacci_numbers_generator::operator*() const
{
    return *_state;
}

fibonacci_numbers_generator &fibonacci_numbers_generator::operator++()
{
    int previous_state=*_state;
    int prev = previous_state;
    delete _state;
    _state=new int(previous_state+_number2);
    _number2=prev;
    return *this;
}

fibonacci_numbers_generator::const_iterator fibonacci_numbers_generator::begin() const{
    return const_iterator(this->_number1,this->_max,this->_number2);
}

fibonacci_numbers_generator::const_iterator fibonacci_numbers_generator::end() const{
    return const_iterator(this->_max,this->_max,this->_number2);
}