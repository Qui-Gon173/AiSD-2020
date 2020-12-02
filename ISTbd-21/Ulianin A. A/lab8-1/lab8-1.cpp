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

    ///добавление в конец
    void push_back(byte data);

    ///cчетчик
    int GetSize() { return Size; }

    ///Добавление элемента по заданному индексу
    void insert(byte data, int index);

    ///удаление элемента в списке по указанному индексу
    void removeAt(int index);

    ///удаление первого элемента в списке
    void pop_front();

    ///очистить список
    void clear();

    ///вывод индекса по определенному значению
    void poisk_index(byte value);

    ///печать списка
    void printList();

    ///сумма всех значений
    byte summ();

    ///среднее значение
    byte avarage();

    ///минимальное значение
    byte Min();

    ///максимальное значение
    byte Max();

private:

    /// класс одного элемента списка
    class Node 
    {
        public:
        
        Node* pNext; // указатель на следующий элемент
        byte data;  // поле данных

        /// конструктор класса
        Node(byte data = NULL, Node* pNext = NULL)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;   // количество эл-ов в списке
    Node* head; // указатель на начало списка
};

/// конструктор для создания объекта
List::List()
{
    this->Size = 0;
    this->head = NULL;
}

/// деструктор
List::~List()
{
}

///добавление в конец
void List::push_back(byte data) {

    if (head == NULL) // если список пуст
    {
        head = new Node(data); // создаем элемент и присваиваем началу списка его значение
    }
    else
    {
        Node* current = this->head; // создаем временный указатель на объект и присваиваем ему адрес начала списка

        while (current->pNext != NULL)  // ищем адрес последнего элемента списка
        {
            current = current->pNext;
        }
        current->pNext = new Node(data); // в поле, хранящее адрес следующего объекта, присваиваем адрес нового элемента

    }

    Size++; // увеличиваем размер списка
}

///Добавление элемента по заданному индексу
void List::insert(byte data, int index)
{
    /// проверка, если список пуст
    if (index == 0)
    {
        head = new Node(data, head);
        Size++;
    }
    else
    {
        /// присваивание новому указателю указателя head. 
        /// присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
        Node* previous = this->head;

        /// поиск позиции
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        /// создаём новый узел
        Node* newNode = new Node(data, previous->pNext);

        previous->pNext = newNode;

        Size++;
    }
}

///удаление первого элемента в списке
void List::pop_front()
{

    Node* temp = this->head;

    head = head->pNext; //перемещаем указатель на один элемент вперед

    delete temp; //удаляем элемент

    Size--; //изменяем число элементов в списке

}

///удаление элемента в списке по указанному индексу
void List::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        /// присваивание новому указателю указателя head. 
        /// присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
        Node* previous = this->head;

        //поиск указателя на искомый элемент
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

/// очистка списка
void List::clear()
{
    /// пока список не кончится удаляем первый объект
    while (Size)
    {
        pop_front();
    }
}

///вывод индекса по определенному значению
void List::poisk_index(byte value)
{
    /// присваивание новому указателю указателя head. 
    /// присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
    Node* current = this->head;
    int i = 0;
    if ((current->data) == value)
    {
        cout << "\nИндекс элемента: " << i << endl;
    }
    else
    {
        while (((current->data) != value) && (i != Size - 1))
        {
            current = current->pNext;
            i++;
        }
        if (i != 0)
            cout << "\nИндекс элемента: " << i << endl;
    }

}

///печать списка
void List::printList()
{
    /// присваивание новому указателю указателя head. 
    /// присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
    Node* current = this->head;

    // Пока еще есть элементы
    for (int i = 0; i < Size; i++)
    {
        // выводим все эл-ты
        cout << (int)current->data << ' ';

        // Переходим на следующий элемент
        current = current->pNext;
    }
}

///сумма всех значений
byte List::summ()
{
    byte summ = 0;
    /// присваивание новому указателю указателя head. 
    /// присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
    Node *current = this->head;
    for (int i = 0; i < Size; i++)
    {
        summ += current->data;
        current = current->pNext;
    }
    return summ;
}

///среднее значение
byte List::avarage()
{
    byte ava;
    ava = summ() / GetSize();
    return ava;
}

///минимальное значение
byte List::Min()
{
    /// присваивание новому указателю указателя head. 
    /// присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
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

///максимальное значение
byte List::Max()
{
    /// присваивание новому указателю указателя head. 
    /// присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
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

    /// cоздаем объект класса List
    List list;
    
    /// добавляем элементы
    list.push_back(5);
    list.push_back(0x15);
 
    cout << "\nВывод списка: ";
    list.printList();
    cout << endl;

    /// добавляем элементы
    list.push_back(7);
    list.push_back(10);

    /// добавляем элемент на позицию с индексом 1(стоит заметить, что нулевая позиция существует)
    list.insert(3, 1);

    cout << "\nВывод списка после добавления на позицию с индексом 1: ";
    list.printList();
    cout << endl;

    /// удаляем элемент с индексом 2
    list.removeAt(2);

    cout << "\nВывод списка после удаления элемента с индексом 2: ";
    list.printList();
    cout << endl;

    /// поиск индекса элемента со значением 3
    list.poisk_index(3);


    cout << "\nРазмер списка: " << (int)list.GetSize() << endl;;
    cout << "\nСумма всех элементов: " << (int)list.summ() << endl;
    cout << "\nСреднее значение всех элементов: " << (double)list.avarage() << endl;
    cout << "\nМинимальный элемент: " << (int)list.Min() << endl;
    cout << "\nМаксимальный элемент: " << (int)list.Max() << endl;

    return 0;
}