#pragma once
#include <algorithm>

class geometric_generator: public std::iterator<std::input_iterator_tag, unsigned int>
{
    
public:
    geometric_generator(const unsigned int seed,const unsigned int max, int factor);
    ~geometric_generator();
    
    typedef geometric_generator const_iterator;

    bool operator!=(geometric_generator const& other) const;
    bool operator==(geometric_generator const& other) const; 
    typename geometric_generator::reference operator*() const;
    geometric_generator& operator++();
    
    const_iterator begin() const;
    const_iterator end() const;
private:
    unsigned int* _state;
    int Factor;
    const unsigned int _seed;
    const unsigned int _borderValue;
};


geometric_generator::geometric_generator(unsigned int seed,unsigned int borderValue, int factor) : _seed(seed),_borderValue(borderValue),Factor(factor),_state(new unsigned int(seed)) {
}

geometric_generator::~geometric_generator(){
    delete _state;
}

bool geometric_generator::operator!=(geometric_generator const &other) const
{
    return *_state!=*other;
}

bool geometric_generator::operator==(geometric_generator const &other) const
{
    return *_state==*other._state;
}

typename geometric_generator::reference geometric_generator::operator*() const
{
    return *_state;
}

geometric_generator &geometric_generator::operator++()
{
    int previous_state=*_state;
    delete _state;
    _state=new unsigned int(previous_state*Factor);
    return *this;
}

geometric_generator::const_iterator geometric_generator::begin() const{
    return const_iterator(this->_seed,this->_borderValue,this->Factor);
}

geometric_generator::const_iterator geometric_generator::end() const{
    return const_iterator(this->_borderValue,this->_borderValue,this->Factor);
}