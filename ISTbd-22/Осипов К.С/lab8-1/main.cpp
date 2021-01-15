#include <iostream>

using namespace std;

typedef unsigned char byte;

template <typename T>
class DoubleList
{
public:

    DoubleList();
    ~DoubleList();

    int getSize() { return size; }
    T getSum();
    T getAverage();
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

    template <typename T>
    struct Node
    {
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

    Node<T>* head;
    Node<T>* tail;
    int size;
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
T DoubleList<T>::getAverage()
{
    T average = getSum() / size;
    return average;
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
    int index;
    Node<T>* current = this->head;
    for (index = 0; index < size; index++)
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


int main()
{
    system("chcp 1251 > NUL");

    DoubleList<byte> byteList;

    byteList.push_back(2);
    byteList.push_back(23);
    byteList.push_back(74);
    byteList.push_front(100);
    byteList.push_front(144);
    byteList.push_back(255);
    byteList.push_front(53);
    byteList.insert(38, 3);

    byteList.pop_back();
    byteList.pop_front();

    byteList.insert(120, 5);
    byteList.printFromBegin();

    cout << "Удаление элемента...\n\n";
    byteList.remove(4);

    byteList.printFromBegin();
    byteList.printFromEnd();

    cout << "Размер списка: " << byteList.getSize() << endl;

    cout << "Сумма элементов: " << (int)byteList.getSum() << endl;       // некорректные результаты из-за малого
    cout << "Среднее значение: " << (int)byteList.getAverage() << endl;  // диапазона значений типа byte (0; 255)

    cout << "Минимальное значение: " << (int)byteList.getMin() << endl;
    cout << "Максимальное значение: " << (int)byteList.getMax() << endl;

    int element;
    cout << "\nВведите искомый элемент: "; cin >> element;
    if (byteList.search(element) != -1)
        cout << "Получение индекса элемента по значению: " << byteList.search(element) << endl;
    else
        cout << "Элемент не найден" << endl;

    cout << "\n\n-----------------------------------------\n\n\n";

    cout << "Очистка списка...\n\n";
    byteList.clear();

    cout << "Размер списка: " << byteList.getSize() << "\n\n";
    byteList.printFromBegin();

    system("pause");
    return 0;
}

