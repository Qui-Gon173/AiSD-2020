#pragma once
#include "Node.cpp"
#include <algorithm>

class my_iterator: public std::iterator<std::input_iterator_tag, int>
{
    friend class List;
private:

    my_iterator(Node* p);
public:

    my_iterator(const my_iterator &it);
   
    bool operator!=(my_iterator const& other) const;
    bool operator==(my_iterator const& other) const; 
    typename my_iterator::reference operator*() const;
    my_iterator& operator++();
private:
    Node* p;
};

my_iterator::my_iterator(Node *p) : p(p) {}


my_iterator::my_iterator(const my_iterator &it) : p(it.p)
{
}

bool my_iterator::operator!=(my_iterator const &other) const
{  
    return p != other.p;
}

bool my_iterator::operator==(my_iterator const &other) const
{
    return p == other.p;
}

typename my_iterator::reference my_iterator::operator*() const
{
    return p->data;
}

my_iterator &my_iterator::operator++()
{
    p=p->pNext;
    return *this;
}