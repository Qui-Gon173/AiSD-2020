#pragma once
#include <algorithm>

class my_geo_generator: public std::iterator<std::input_iterator_tag, unsigned long>
{

public:
    my_geo_generator(const unsigned long seed, const unsigned long max, int onwhatmultiply);
    ~my_geo_generator();

    typedef my_geo_generator const_iterator;

    bool operator != (my_geo_generator const& other) const;
    bool operator == (my_geo_generator const& other) const;
    typename my_geo_generator::reference operator*() const;
    my_geo_generator& operator++();

    const_iterator begin() const;
    const_iterator end() const;
private:
    unsigned long* _state;
    int again_on_what_multiply;
    const unsigned long _seed;
    const unsigned long _borderValue;
};


my_geo_generator::my_geo_generator(unsigned long seed,unsigned long borderValue, int onwhatmultiply) : _seed(seed), _borderValue(borderValue), again_on_what_multiply(onwhatmultiply), _state(new unsigned long(seed))
{
}

my_geo_generator::~my_geo_generator(){
    delete _state;
}

bool my_geo_generator::operator != (my_geo_generator const &other) const
{
    return *_state != *other;
}

bool my_geo_generator::operator == (my_geo_generator const &other) const
{
    return *_state == *other._state;
}

typename my_geo_generator::reference my_geo_generator::operator*() const
{
    return *_state;
}

my_geo_generator &my_geo_generator::operator++()
{
    int previous_state = *_state;
    delete _state;
    _state = new unsigned long(previous_state*again_on_what_multiply);
    return *this;
}

my_geo_generator::const_iterator my_geo_generator::begin() const{
    return const_iterator(this->_seed,this->_borderValue,this->again_on_what_multiply);
}

my_geo_generator::const_iterator my_geo_generator::end() const{
    return const_iterator(this->_borderValue,this->_borderValue,this->again_on_what_multiply);
}
