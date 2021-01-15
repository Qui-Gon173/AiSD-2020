class my_iterator: public std::iterator<std::input_iterator_tag, unsigned long>
{
    friend class List;
private:
//Конструктор, принимающий указатель на узел
    my_iterator(Node* p);
public:
    my_iterator(const my_iterator &it);
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
my_iterator::my_iterator(Node *p) : p(p) {}//p - указатель на узел

//Реализация конструктора, принимающего адрес узла
my_iterator::my_iterator(const my_iterator &it) : p(it.p)//p - адрес узла
{
}
//Оператор не равно, принимает адрес итератора
bool my_iterator::operator!=(my_iterator const &other) const
{   //возвращает при равенстве указателя на узел указателю прошлому?
    return p != other.p;
}
//Перегруженный ператор равно, принимает адрес итератора
bool my_iterator::operator==(my_iterator const &other) const
{//возвращает, при равенстве указателя на узел указателю прошлому?
    return p == other.p;
}
//ерегруженный оператор разыменования
typename my_iterator::reference my_iterator::operator*() const
{//Возвращает разыменовывание указателя
    return p->field_data;
}

my_iterator &my_iterator::operator++()
{
    p=p->pNext;
    return *this;
}
