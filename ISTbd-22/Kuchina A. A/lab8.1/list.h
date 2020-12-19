#include <iostream>

using namespace std;

class List
{
public:
List();
~List();
void new_node(unsigned long field_data);
void creation_node_in_target_place(int place, unsigned long field_data);//����� ����������� ���� �� ��������� �������
void print_list_ahead();//�����, ��������� ��� �������� �� ������ �� �����
void print_list_back();//�����, ��������� ��� �������� � ����� �� ������
int getsize() {
    return size;};
void delete_target_element(int target);
void pop_front();//�������� ������� ��������
void clear();//������ ����������
//int search(const int ind);//����� �� �������
void search_by_value(unsigned long value);//����� ������� �� ��������
unsigned long sum_values_list();//����� ���� ���������
unsigned long mid_value();//������� �������� ���� �������� ���������
unsigned long find_min_value();//����� ������������ ��������
unsigned long find_max_value();//����� ������������� ��������
unsigned long& operator[](const int index);//����� �������� �� �������
private:

class Node
    {
    public:
        Node *pNext;
        Node *pPrevious;
        unsigned long field_data;
        Node(unsigned long field_data = 123, Node *pPrevious = nullptr,Node *pNext = nullptr)
        {
            this->field_data = field_data;
            this->pPrevious = pPrevious;
            this->pNext = pNext;
        }
    };

int size;
Node *head;//������ �������-������
Node *tail;//��������� �������-�����
};

List::List()
{
    size = 0;
    head = nullptr;
}
List::~List()
{
}
//������ ���������� ���������
void List::new_node(unsigned long field_data)
{
    if (head == nullptr)
    {
        head = new Node(field_data);
        Node *current = head;
        cout << "��� ������ ������ �������: " << "; pPrevious=" << current->pPrevious;
        cout << ";  ����� �������� �������� =  = " << current;
        cout << "; ���������� = " << field_data;
        cout << "; pNext = " << current->pNext << endl;
    }
    else
    {
        Node *current = this->head;//������� ���������, ����������� �� ������-1�� �������
        if(size == 1 )
            {//���� ��� ������ �������
        Node *current_this;//��������� ��� ������������ �������� ������ ������
        current->pNext = new Node(field_data, current);//������� ����� �����, �������� pNext ���� ����� ����
        tail = current->pNext;//������� ������, ��� ��� ������� ���
        current_this = current->pNext;//������������ ����� ������ ��� ������
        current = current->pNext;//������� current �� �����, ��� ������ ��� ����������
        cout << "��� ������ ��������� �������: " << " ����� ����������� �������� = " << current->pPrevious;
        cout << "; ����� �������� = " << current_this;
        cout << "; ���������� = " << field_data;
        cout << "; ����� ���������� ��������:" << current->pNext << ";" << endl;
        }//���� �����, ��� ������
        else
        {
        Node *conteiner_for_uk;
        Node *current_this;//��������� �� ����������� �������
        conteiner_for_uk = current->pNext;//��������� � ��������� ��������� �� ��������� ������� ������
        current->pNext = new Node(field_data,head,conteiner_for_uk);//�������� ������ ����
        current = current->pNext;//������������ �� ����. ����
        current_this = current;//��������������� ������ ����� ���� ��� ������ � ��������
        current = current->pNext;//������������ �� ����, ��� ����� ������� ��������� �� ����������
        current->pPrevious = current_this;//��������� ��������� �� ������� �������(2��� ��������, ����� �������� �� ��������� ���� �����) �� ���������� ��������� �� ����������� ����
        cout << "��� ������ �������: " << " ����� ����������� �������� = " << head;
        cout << "; ����� ����� �������� = " << current_this;
        cout << "; ���������� = " << field_data;
        cout << "; ����� ���������� ��������:" << conteiner_for_uk << ";" << endl;
        }
    }
    size++;
}
void List::creation_node_in_target_place(int place, unsigned long field_data)
{
    Node *current = this->head;
    if(place == 0)
        {
        current->pPrevious = new Node(field_data, nullptr, current);
        head = current->pPrevious;
    }
    else
    {

        if (place <= size/2)
        {
            current = head;
            int i = 1;
            while ( i < place)
            {
                current = current->pNext;
                i++;
            }
        }
        else
        {
            current = tail;
        int i = 1;
        while (i <= size - place)
        {
            current = current->pPrevious;
            i++;
        }
        }

    Node *conteiner_for_uk;
    conteiner_for_uk = current->pNext;//��������������� ���������
    current->pNext = new Node(field_data, current, conteiner_for_uk);//�������� ���� ��� ��������� �������
    current = current->pNext;//����������� ����
    conteiner_for_uk = current;//��������������� ��� ������
    current = current->pNext;//����������� �� �������, ������� ����� ����������
    current->pPrevious=conteiner_for_uk;//����������� ��������� �� ����������
    };
    size++;
    cout << "������� ��������" << endl;
}
//������ ������ ������ �� �������
void List::print_list_ahead()
{
    Node *current = this->head;
    for(int i = 0; i < size; i++)
    {
        cout << "������� " << i << ":" << " ����� ����������� �������� = " << current->pPrevious;
        cout << "; ���������� = " << current->field_data;
        cout << "; ����� ���������� �������� = " << current->pNext << ";" << endl;
        current = current->pNext;
    }
}

void List::print_list_back()
{
    Node *current = this->tail;
    for(int i = size - 1; i != -1; i--)
    {
        cout << "������� " << i <<":" << " ����� ����������� �������� = " << current->pPrevious;
        cout << "; ���������� = " << current->field_data;
        cout << "; ����� ���������� �������� = " << current->pNext << ";" << endl;
        current = current->pPrevious;
    }
}

//��������� ������
void List::delete_target_element(int target)
{
    Node *current = this->head;
    if(target == 0)
        {
       cout << "Input position: ";
       cin >> target;
    }
    if(target > 0 && target < size-1)
    {
        if (target <= size/2)
        {
            current = head;
            int i = 1;
            while ( i < target)
            {
                current = current->pNext;
                i++;
            }
        }
        else
        {
            current = tail;
        int i = size;
        while (i <= size - target)
        {
            current = current->pPrevious;
            i--;
        }
        }
    Node *container_for_uk;
    Node *uk_to_delete;
    container_for_uk = current;//��������������� ������ ���������� ����� �������� ��������
    current = current->pPrevious;//������� �� ��������� �������
    uk_to_delete = current;//���������� ������ ���������� ��������
    current = current->pPrevious;//������� �� ������� �� ����������
    current->pNext = container_for_uk;//�������������� ����� ���������� �� ����� ����� ����������
    container_for_uk = current;//���������� ������ �������� ��������
    current = current->pNext;//������� �� ������� ����� ���������� �� ������������ ����
    current->pPrevious = container_for_uk;//�������������� ��������� �� ���������� � ���������� ��������
    delete uk_to_delete;
    }
    else
        {
        current = tail;
        tail = tail->pPrevious;
        delete current;
    }
    size--;

    cout << "������� ������" << endl;
}

void List::pop_front()
{
    Node *temp = head;
    if(head->pNext != nullptr)
        {
    head = head->pNext;
    head->pPrevious = nullptr;
    delete temp;
    size--;
    }
    else
    {
         delete head;
         size--;
    }
}

void List::clear()
{
    while(size)
    {
        pop_front();
    }
}

//������ ������
void List::search_by_value(unsigned long value)
{
    Node *current = this->head;
    int i = 0;
    if((current->field_data) == value)
        {
        cout << "������ �������� �������� " << i;
    }
    else
        {
    while(((current->field_data) != value) && (i != size -1))
    {
        current = current->pNext;
        i++;
    }
    if(i != 0)
    cout << "������ �������� �������� " << i <<endl;
    };
}

unsigned long List::sum_values_list()
{
    unsigned long sum = 0;
    Node *current = this->head;
    while(current->pNext != nullptr)
    {
        sum += current->field_data;
        current = current->pNext;
    }
    return sum;
}

unsigned long List::mid_value()
{
    unsigned long average;
    average = sum_values_list()/size;
    return average;
}

unsigned long List::find_min_value()
{
    Node *current = this->head;
    unsigned long min = current->field_data;
    while((current->pNext) != nullptr)
    {
        if(current->field_data < min)
        min = current->field_data;
        current = current->pNext;
    }
    return min;
}

unsigned long List::find_max_value()
{
    Node *current = this->head;
    unsigned long max = current->field_data;
    while((current->pNext) != nullptr)
    {
        current = current->pNext;
        if(current->field_data > max)
        max = current->field_data;

    }
    return max;
}
