#pragma once
#include "Node.cpp"
#include <algorithm>

class my_iterator: public std::iterator<std::input_iterator_tag, unsigned int>
{
    friend class List;
private:
//Это конструктор, принимающий указатель на узел
    my_iterator(Node* p);
public:
//Это конструктор, принимающий адрес узла
//                        |THERE WAS ERRRRRRROOOOORRRRR(was Node expect my_iterator)
    my_iterator(const my_iterator &it);
    //Всякие операторы
    bool operator!=(my_iterator const& other) const;
    bool operator==(my_iterator const& other) const; //need for BOOST_FOREACH
    typename my_iterator::reference operator*() const;
    my_iterator& operator++();
private:
//Указатель на узел
    Node* p;
};
//Реализация конструктора, принимающего указатель на узел
//                           |своему p он присваивает указатель на узел
my_iterator::my_iterator(Node *p) : p(p) {}//p это указатель на узел
//Реализация конструктора, принимающего адрес узла

my_iterator::my_iterator(const my_iterator &it) : p(it.p)//p это адрес узла
{
}
//Оператор не равно, принимает адрес итератора
bool my_iterator::operator!=(my_iterator const &other) const
{   //возвращает, РАВЕН ЛИ указатель на узел указателю прошлому?
    return p != other.p;
}
//Оператор равно, принимает адрес итератора
bool my_iterator::operator==(my_iterator const &other) const
{//возвращает, РАВЕН ЛИ указатель на узел указателю прошлому?
    return p == other.p;
}
//РАЗЫМЕНОВЫВАНИЕ
typename my_iterator::reference my_iterator::operator*() const
{//Возвращает разыменовывание казателя
    return p->data;
}

my_iterator &my_iterator::operator++()
{
    p=p->pNext;
    return *this;
}