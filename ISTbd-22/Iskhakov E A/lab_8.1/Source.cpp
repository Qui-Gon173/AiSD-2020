#include <iostream>
#include <cstring>
#include <clocale>

typedef unsigned char byte;

using namespace std;

class List
{
public:
    List();
    ~List();

    ///���������� � �����
    void push_back(byte data);

    ///c������
    int GetSize() { return Size; }

    ///���������� �������� �� ��������� �������
    void insert(byte data, int index);

    ///�������� �������� � ������ �� ���������� �������
    void removeAt(int index);

    ///�������� ������� �������� � ������
    void pop_front();

    ///�������� ������
    void clear();

    ///����� ������� �� ������������� ��������
    void poisk_index(byte value);

    ///������ ������
    void printList();

    ///����� ���� ��������
    byte summ();

    ///������� ��������
    byte avarage();

    ///����������� ��������
    byte Min();

    ///������������ ��������
    byte Max();

private:

    /// ����� ������ �������� ������
    class Node
    {
    public:

        Node* pNext; // ��������� �� ��������� �������
        byte data;  // ���� ������

        /// ����������� ������
        Node(byte data = NULL, Node* pNext = NULL)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;   // ���������� ��-�� � ������
    Node* head; // ��������� �� ������ ������
};

/// ����������� ��� �������� �������
List::List()
{
    this->Size = 0;
    this->head = NULL;
}

/// ����������
List::~List()
{
}

///���������� � �����
void List::push_back(byte data) {

    if (head == NULL) // ���� ������ ����
    {
        head = new Node(data); // ������� ������� � ����������� ������ ������ ��� ��������
    }
    else
    {
        Node* current = this->head; // ������� ��������� ��������� �� ������ � ����������� ��� ����� ������ ������

        while (current->pNext != NULL)  // ���� ����� ���������� �������� ������
        {
            current = current->pNext;
        }
        current->pNext = new Node(data); // � ����, �������� ����� ���������� �������, ����������� ����� ������ ��������

    }

    Size++; // ����������� ������ ������
}

///���������� �������� �� ��������� �������
void List::insert(byte data, int index)
{
    /// ��������, ���� ������ ����
    if (index == 0)
    {
        head = new Node(data, head);
        Size++;
    }
    else
    {
        /// ������������ ������ ��������� ��������� head. 
        /// ������������ ����������� ��� ����, ����� �� �������� ��������� �� ������� ������
        Node* previous = this->head;

        /// ����� �������
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        /// ������ ����� ����
        Node* newNode = new Node(data, previous->pNext);

        previous->pNext = newNode;

        Size++;
    }
}

///�������� ������� �������� � ������
void List::pop_front()
{

    Node* temp = this->head;

    head = head->pNext; //���������� ��������� �� ���� ������� ������

    delete temp; //������� �������

    Size--; //�������� ����� ��������� � ������

}

///�������� �������� � ������ �� ���������� �������
void List::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        /// ������������ ������ ��������� ��������� head. 
        /// ������������ ����������� ��� ����, ����� �� �������� ��������� �� ������� ������
        Node* previous = this->head;

        //����� ��������� �� ������� �������
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }


        Node* toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        Size--;
    }
}

/// ������� ������
void List::clear()
{
    /// ���� ������ �� �������� ������� ������ ������
    while (Size)
    {
        pop_front();
    }
}

///����� ������� �� ������������� ��������
void List::poisk_index(byte value)
{
    /// ������������ ������ ��������� ��������� head. 
    /// ������������ ����������� ��� ����, ����� �� �������� ��������� �� ������� ������
    Node* current = this->head;
    int i = 0;
    if ((current->data) == value)
    {
        cout << "\n������ ��������: " << i << endl;
    }
    else
    {
        while (((current->data) != value) && (i != Size - 1))
        {
            current = current->pNext;
            i++;
        }
        if (i != 0)
            cout << "\n������ ��������: " << i << endl;
    }

}

///������ ������
void List::printList()
{
    /// ������������ ������ ��������� ��������� head. 
    /// ������������ ����������� ��� ����, ����� �� �������� ��������� �� ������� ������
    Node* current = this->head;

    // ���� ��� ���� ��������
    for (int i = 0; i < Size; i++)
    {
        // ������� ��� ��-��
        cout << (int)current->data << ' ';

        // ��������� �� ��������� �������
        current = current->pNext;
    }
}

///����� ���� ��������
byte List::summ()
{
    byte summ = 0;
    /// ������������ ������ ��������� ��������� head. 
    /// ������������ ����������� ��� ����, ����� �� �������� ��������� �� ������� ������
    Node* current = this->head;
    for (int i = 0; i < Size; i++)
    {
        summ += current->data;
        current = current->pNext;
    }
    return summ;
}

///������� ��������
byte List::avarage()
{
    byte ava;
    ava = summ() / GetSize();
    return ava;
}

///����������� ��������
byte List::Min()
{
    /// ������������ ������ ��������� ��������� head. 
    /// ������������ ����������� ��� ����, ����� �� �������� ��������� �� ������� ������
    Node* current = this->head;
    byte min = current->data;
    for (int i = 0; i < Size; i++)
    {
        if (current->data < min)
            min = current->data;
        current = current->pNext;
    }
    return min;
}

///������������ ��������
byte List::Max()
{
    /// ������������ ������ ��������� ��������� head. 
    /// ������������ ����������� ��� ����, ����� �� �������� ��������� �� ������� ������
    Node* current = this->head;
    byte max = current->data;
    for (int i = 0; i < Size; i++)
    {
        if (current->data > max)
            max = current->data;
        current = current->pNext;
    }
    return max;
}

int main()
{
    setlocale(LC_ALL, "ru");

    /// c������ ������ ������ List
    List list;

    /// ��������� ��������
    list.push_back(5);
    list.push_back(0x15);

    cout << "\n����� ������: ";
    list.printList();
    cout << endl;

    /// ��������� ��������
    list.push_back(7);
    list.push_back(10);

    /// ��������� ������� �� ������� � �������� 1(����� ��������, ��� ������� ������� ����������)
    list.insert(3, 1);

    cout << "\n����� ������ ����� ���������� �� ������� � �������� 1: ";
    list.printList();
    cout << endl;

    /// ������� ������� � �������� 2
    list.removeAt(2);

    cout << "\n����� ������ ����� �������� �������� � �������� 2: ";
    list.printList();
    cout << endl;

    /// ����� ������� �������� �� ��������� 3
    list.poisk_index(3);


    cout << "\n������ ������: " << (int)list.GetSize() << endl;;
    cout << "\n����� ���� ���������: " << (int)list.summ() << endl;
    cout << "\n������� �������� ���� ���������: " << (double)list.avarage() << endl;
    cout << "\n����������� �������: " << (int)list.Min() << endl;
    cout << "\n������������ �������: " << (int)list.Max() << endl;

    return 0;
}