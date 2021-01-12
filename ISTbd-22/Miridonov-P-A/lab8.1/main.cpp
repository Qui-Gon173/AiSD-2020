#include <iostream>

using namespace std;

class List
{
public:
List();
~List();
void NewNode(unsigned int field_data);
void CreateNodeInTargetPlace(int place, unsigned int field_data);//����� ����������� ���� �� ��������� �������
void PrintListAhead();//�����, ��������� ��� �������� �� ������ �� �����
void PrintListBack();//�����, ��������� ��� �������� � ����� �� ������
int getsize() {
    return size;};
void DeleteTargetedElement(int target);
void pop_front();//�������� ������� ��������
void clear();//������ ����������
void SearchByValue(unsigned int value);//����� ������� �� ��������
unsigned int SumOfValues();//����� ���� ���������
unsigned int AverageValue();//������� �������� ���� �������� ���������
unsigned int SearchMinValue();//����� ������������ ��������
unsigned int SearchMaxValue();//����� ������������� ��������
private:

class Node
    {
    public:
        Node *pNext;
        Node *pPrevious;
        unsigned int field_data;
        Node(unsigned int field_data = 123, Node *pPrevious = nullptr,Node *pNext = nullptr)
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
void List::NewNode(unsigned int field_data)
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
void List::CreateNodeInTargetPlace(int place, unsigned int field_data)
{
    Node *current = this->head;
    int i = 0;
    if(place == 0)
        {
        current->pPrevious = new Node(field_data, nullptr, current);
        head = current->pPrevious;
    }
    else
    {
    while(place - i != 1)
    {
        current = current->pNext;
        i++;
    };
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
void List::PrintListAhead()
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

void List::PrintListBack()
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
void List::DeleteTargetedElement(int target)
{
    Node *current = this->head;
    int i = 0;
    if(target == 0)
        {
        current = head;
        head = head->pNext;
        delete current;
    }
    if(target > 0 && target < (size - 1))
    {
    while(i - target != 1)
    {
        current = current->pNext;
        i++;
    };
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
    };
    if(target == (size -1))
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
void List::SearchByValue(unsigned int value)
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

unsigned int List::SumOfValues()
{
    unsigned int sum = 0;
    Node *current = this->head;
    while(current->pNext != nullptr)
    {
        sum += current->field_data;
        current = current->pNext;
    }
    return sum;
}

unsigned int List::AverageValue()
{
    unsigned int average;
    average = SumOfValues()/size;
    return average;
}

unsigned int List::SearchMinValue()
{
    Node *current = this->head;
    unsigned int min = current->field_data;
    while((current->pNext) != nullptr)
    {
        if(current->field_data < min)
        min = current->field_data;
        current = current->pNext;
    }
    return min;
}

unsigned int List::SearchMaxValue()
{
    Node *current = this->head;
    unsigned int max = current->field_data;
    while((current->pNext) != nullptr)
    {
        current = current->pNext;
        if(current->field_data > max)
        max = current->field_data;

    }
    return max;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List lst;
    lst.NewNode(1);
    lst.NewNode(2);
    lst.NewNode(3);
    lst.NewNode(4);
    lst.NewNode(999);
    cout << endl << "����� ���������� ��������� � ������ - " << lst.getsize() << endl;
    cout << endl << "��������� ������ �� ������ �� �����" << endl << "-------------------" << endl;;
    lst.PrintListAhead();
    lst.CreateNodeInTargetPlace(2,88);
    cout << endl << "C����� � ����� �� ������ � ����������� ���������" << endl << "-------------------" << endl;;
    lst.PrintListBack();
    cout << endl << "������ �� ������ �� ����� � ����������� ���������" << endl << "-------------------" << endl;;
    lst.PrintListAhead();
    lst.DeleteTargetedElement(3);
    cout << endl << "������ �� ������ �� ����� ����� �������� ��������" << endl << "-------------------" << endl;;
    lst.PrintListAhead();
    cout << endl << "����� ���������� ��������� � ������ - " << lst.getsize() << endl;
    lst.SearchByValue(999);
    cout << "����� ���� ��������� ������ - ";
    cout << lst.SumOfValues();
    cout << endl << "������� �������� ��������� ������ - ";
    cout << lst.AverageValue();
    cout << endl << "M���������� ������� - ";
    cout<<lst.SearchMinValue();
    cout << endl << "M����������� ������� - ";
    cout<<lst.SearchMaxValue();
    lst.clear();
    return 0;
}
