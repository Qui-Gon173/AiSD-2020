#pragma once
#include <iostream>

using namespace std;

typedef unsigned char byte;

template <typename T>
class ListIterator;

template <typename T>
struct Node
{
    friend class ListIterator<T>;

    Node* ptr_next;
    Node* ptr_prev;
    T data;
    Node(T data = T(), Node* ptr_next = nullptr, Node* ptr_prev = nullptr)
    {
        this->data = data;
        this->ptr_next = ptr_next;
        this->ptr_prev = ptr_prev;
    }
};

template <typename T>
class DoubleList
{
public:

    friend class ListIterator<T>;

    ListIterator<T> begin() { return head; }
    ListIterator<T> end() { return tail->ptr_next; }

    DoubleList();
    ~DoubleList();

    int getSize() { return size; }
    T getSum();
    T getAverage() { return getSum() / size; }
    T getMin();
    T getMax();

    void push_back(T data);
    void push_front(T data);

    void pop_back();
    void pop_front();

    void insert(T data, int index);
    void remove(int index);

    int search(T data);

    void clear();

    void printFromBegin();
    void printFromEnd();

    T& operator[](const int index);

private:

    // тут была структура узла //

    Node<T>* head;
    Node<T>* tail;
    size_t size;
};

template <typename T>
DoubleList<T>::DoubleList()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
DoubleList<T>::~DoubleList()
{
    clear();
}

template<typename T>
T DoubleList<T>::getSum()
{
    Node<T>* current = this->head;
    T sum = current->data;
    for (int i = 0; i < size - 1; i++)
    {
        current = current->ptr_next;
        sum += current->data;
    }
    return sum;
}

template<typename T>
T DoubleList<T>::getMin()
{
    Node<T>* current = this->head;
    T min = current->data;
    for (int i = 0; i < size - 1; i++)
    {
        current = current->ptr_next;
        if (current->data < min)
            min = current->data;
    }
    return min;
}

template<typename T>
T DoubleList<T>::getMax()
{
    Node<T>* current = this->head;
    T max = current->data;
    for (int i = 0; i < size - 1; i++)
    {
        current = current->ptr_next;
        if (current->data > max)
            max = current->data;
    }
    return max;
}

template<typename T>
void DoubleList<T>::push_front(T data)
{
    Node<T>* current = new Node<T>(data);

    if (tail != nullptr)
    {
        current->ptr_next = head;
        head->ptr_prev = current;
        head = current;
    }
    else
    {
        current->ptr_next = nullptr;
        head = tail = current;
    }
    ++size;
}

template<typename T>
void DoubleList<T>::push_back(T data)
{
    Node<T>* current = new Node<T>(data);

    if (head != nullptr)
    {
        current->ptr_prev = tail;
        tail->ptr_next = current;
        tail = current;
    }
    else
    {
        current->ptr_prev = nullptr;
        head = tail = current;
    }
    ++size;
}

template<typename T>
void DoubleList<T>::pop_back()
{
    if (size == 1)
        delete tail;
    else
    {
        Node<T>* temp = tail;
        tail = tail->ptr_prev;
        tail->ptr_next = nullptr;
        delete temp;
    }
    --size;
}

template<typename T>
void DoubleList<T>::pop_front()
{
    if (size == 1)
        delete head;
    else
    {
        Node<T>* temp = head;
        head = head->ptr_next;
        head->ptr_prev = nullptr;
        delete temp;
    }
    --size;
}

template<typename T>
void DoubleList<T>::insert(T data, int index)
{
    if (index > size || index < 0)
        cout << "Ошибка метода insert! Вставка на позицию " << index << " невозможна!!!\n\n";
    else if (index == 0)
        push_front(data);
    else if (index == size)
        push_back(data);
    else
    {
        if (index < size / 2)
        {
            Node<T>* current = this->head;
            Node<T>* temp; // указатель на элемент, следующий за current'ом до вставки

            for (int i = 0; i < index - 1; i++)
            {
                current = current->ptr_next;
            }
            Node<T>* newNode = new Node<T>(data, current->ptr_next, current->ptr_prev);

            newNode->ptr_prev = current;

            temp = current->ptr_next;
            current->ptr_next = newNode;
            temp->ptr_prev = newNode;

            newNode->ptr_next = temp;
        }
        else
        {
            Node<T>* current = this->tail;
            Node<T>* temp; // указатель на элемент, предшествующий current'у до вставки

            for (int i = size - 1; i > index; i--)
            {
                current = current->ptr_prev;
            }
            Node<T>* newNode = new Node<T>(data, current->ptr_next, current->ptr_prev);

            newNode->ptr_next = current;

            temp = current->ptr_prev;
            current->ptr_prev = newNode;
            temp->ptr_next = newNode;

            newNode->ptr_prev = temp;
        }
        ++size;
    }
}

template<typename T>
void DoubleList<T>::remove(int index)
{
    if (index > size - 1 || index < 0)
        cout << "Ошибка метода remove! Удаление с позиции " << index << " невозможно!!!\n\n";
    else if (index == 0)
        pop_front();
    else if (index == size - 1)
        pop_back();
    else
    {
        if (index < size / 2)
        {
            Node<T>* current = this->head;
            Node<T>* temp; // указатель на элемент, следующий за удаляемым

            for (int i = 0; i < index - 1; i++)
            {
                current = current->ptr_next;
            }
            Node<T>* toDelete = current->ptr_next;
            temp = toDelete->ptr_next;

            current->ptr_next = toDelete->ptr_next;
            temp->ptr_prev = toDelete->ptr_prev;

            delete toDelete;
        }
        else
        {
            Node<T>* current = this->tail;
            Node<T>* temp; // указатель на элемент, предшествующий удаляемому

            for (int i = size - 1; i > index + 1; i--)
            {
                current = current->ptr_prev;
            }
            Node<T>* toDelete = current->ptr_prev;
            temp = toDelete->ptr_prev;

            current->ptr_prev = toDelete->ptr_prev;
            temp->ptr_next = toDelete->ptr_next;

            delete toDelete;
        }
        --size;
    }
}

template<typename T>
int DoubleList<T>::search(T data)
{
    int index = 0;
    Node<T>* current = this->head;
    for (; index < size; index++)
    {
        if (current->data == data)
            break;
        current = current->ptr_next;
    }
    return index < size ? index : -1;
}

template<typename T>
void DoubleList<T>::clear()
{
    while (size)
    {
        pop_front();
    }
}

template<typename T>
void DoubleList<T>::printFromBegin() // общий, шаблонный случай вывода списка
{
    cout << "Вывод с головы списка:\n\n";
    if (size != 0)
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->ptr_next;
        }
        cout << "\n\n";
    }
    else
        cout << "Список пуст\n\n";
}

template<>
void DoubleList<byte>::printFromBegin() // вывод списка специально для типа byte
{
    cout << "Вывод с головы списка:\n\n";
    if (size != 0)
    {
        Node<byte>* current = head;
        while (current != nullptr)
        {
            cout << (int)current->data << " "; // выводится цифра, а не символ
            current = current->ptr_next;
        }
        cout << "\n\n";
    }
    else
        cout << "Список пуст\n\n";
}

template<typename T>
void DoubleList<T>::printFromEnd() // общий, шаблонный случай вывода списка
{
    cout << "Вывод с хвоста списка:\n\n";
    if (size != 0)
    {
        Node<T>* current = tail;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->ptr_prev;
        }
        cout << "\n\n";
    }
    else
        cout << "Список пуст\n\n";
}

template<>
void DoubleList<byte>::printFromEnd() // вывод списка специально для типа byte
{
    cout << "Вывод с хвоста списка:\n\n";
    if (size != 0)
    {
        Node<byte>* current = tail;
        while (current != nullptr)
        {
            cout << (int)current->data << " "; // выводится цифра, а не символ
            current = current->ptr_prev;
        }
        cout << "\n\n";
    }
    else
        cout << "Список пуст\n\n";
}

template<typename T>
T& DoubleList<T>::operator[](const int index)
{
    int counter;
    if (index < size / 2)
    {
        counter = 0;
        Node<T>* current = this->head;
        while (current != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->ptr_next;
            ++counter;
        }
    }
    else
    {
        counter = size - 1;
        Node<T>* current = this->tail;
        while (current != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->ptr_prev;
            --counter;
        }
    }
}

