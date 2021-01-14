class my_iterator: public std::iterator<std::input_iterator_tag, unsigned long>
{
    friend class List;
private:
//�����������, ����������� ��������� �� ����
    my_iterator(Node* p);
public:
    my_iterator(const my_iterator &it);
    bool operator!=(my_iterator const& other) const;
    bool operator==(my_iterator const& other) const; //need for BOOST_FOREACH
    typename my_iterator::reference operator*() const;
    my_iterator& operator++();
private:
//��������� �� ����
    Node* p;
};
//���������� ������������, ������������ ��������� �� ����
//                           |������ p �� ����������� ��������� �� ����
my_iterator::my_iterator(Node *p) : p(p) {}//p - ��������� �� ����

//���������� ������������, ������������ ����� ����
my_iterator::my_iterator(const my_iterator &it) : p(it.p)//p - ����� ����
{
}
//�������� �� �����, ��������� ����� ���������
bool my_iterator::operator!=(my_iterator const &other) const
{   //���������� ��� ��������� ��������� �� ���� ��������� ��������?
    return p != other.p;
}
//������������� ������� �����, ��������� ����� ���������
bool my_iterator::operator==(my_iterator const &other) const
{//����������, ��� ��������� ��������� �� ���� ��������� ��������?
    return p == other.p;
}
//������������ �������� �������������
typename my_iterator::reference my_iterator::operator*() const
{//���������� ��������������� ���������
    return p->field_data;
}

my_iterator &my_iterator::operator++()
{
    p=p->pNext;
    return *this;
}
