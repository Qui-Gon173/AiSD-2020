#include <iostream>

using namespace std;

class List
{
public:
List();
~List();
void new_node(unsigned long field_data);
void creation_node_in_target_place(int place, unsigned long field_data);//метод вставляющий узел на указанную позицию
void print_list_ahead();//метод, выводящий все элементы от начала до конца
void print_list_back();//метод, выводящий все элементы с конца до начала
int getsize() {
    return size;};
void delete_target_element(int target);
void pop_front();//удаление первого элемента
void clear();//чистка контейнера
//int search(const int ind);//Поиск по индексу
void search_by_value(unsigned long value);//поиск индекса по значению
unsigned long sum_values_list();//сумма всех элементов
unsigned long mid_value();//среднее значение всех значений элементов
unsigned long find_min_value();//поиск минимального значения
unsigned long find_max_value();//поиск максимального значения
unsigned long& operator[](const int index);//вывод значения по индексу
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
Node *head;//первый элемент-голова
Node *tail;//последний элемент-хвост
};

List::List()
{
    size = 0;
    head = nullptr;
}
List::~List()
{
}
//Методы добавления элементов
void List::new_node(unsigned long field_data)
{
    if (head == nullptr)
    {
        head = new Node(field_data);
        Node *current = head;
        cout << "Был создан первый элемент: " << "; pPrevious=" << current->pPrevious;
        cout << ";  Адрес текущего элемента =  = " << current;
        cout << "; Информация = " << field_data;
        cout << "; pNext = " << current->pNext << endl;
    }
    else
    {
        Node *current = this->head;//создаем указатель, указывающий на голову-1ый элемент
        if(size == 1 )
            {//Если это второй элемент
        Node *current_this;//указатель для демонстрации текущего адреса хвоста
        current->pNext = new Node(field_data, current);//создаем новый хвост, присвоив pNext хеда новый узел
        tail = current->pNext;//говорим хвосту, что это создали его
        current_this = current->pNext;//аккумулируем адрес хвоста для вывода
        current = current->pNext;//смещаем current на хвост, для вывода его параметров
        cout << "Был создан последний элемент: " << " Адрес предыдущего элемента = " << current->pPrevious;
        cout << "; адрес элемента = " << current_this;
        cout << "; Информация = " << field_data;
        cout << "; адрес следующего элемента:" << current->pNext << ";" << endl;
        }//Если более, чем второй
        else
        {
        Node *conteiner_for_uk;
        Node *current_this;//указатель на создаваемый элемент
        conteiner_for_uk = current->pNext;//помещение в контейнер указателя на следующий элемент головы
        current->pNext = new Node(field_data,head,conteiner_for_uk);//создание нового узла
        current = current->pNext;//переключение на след. узел
        current_this = current;//аккумулирование адреса этого узла для вывода и проверки
        current = current->pNext;//переключение на узел, где нужно сменить указатель на предыдущий
        current->pPrevious = current_this;//изменение указателя на прошлый элемент(2ого элемента, между которыми мы вставляем узел новый) на правильный указатель на вставляемый узел
        cout << "Был создан элемент: " << " Адрес предыдущего элемента = " << head;
        cout << "; адрес этого элемента = " << current_this;
        cout << "; Информация = " << field_data;
        cout << "; адрес следующего элемента:" << conteiner_for_uk << ";" << endl;
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
    conteiner_for_uk = current->pNext;//аккумулирование указателя
    current->pNext = new Node(field_data, current, conteiner_for_uk);//создание узла под выбранным номером
    current = current->pNext;//перемещение узла
    conteiner_for_uk = current;//аккумулирование его адреса
    current = current->pNext;//перемещение на элемент, стоящий после созданного
    current->pPrevious=conteiner_for_uk;//исправление указателя на предыдущий
    };
    size++;
    cout << "Элемент добавлен" << endl;
}
//Методы вывода списка на консоль
void List::print_list_ahead()
{
    Node *current = this->head;
    for(int i = 0; i < size; i++)
    {
        cout << "Элемент " << i << ":" << " адрес предыдущего элемента = " << current->pPrevious;
        cout << "; Информация = " << current->field_data;
        cout << "; Адрес следующего элемента = " << current->pNext << ";" << endl;
        current = current->pNext;
    }
}

void List::print_list_back()
{
    Node *current = this->tail;
    for(int i = size - 1; i != -1; i--)
    {
        cout << "Элемент " << i <<":" << " адрес предыдущего элемента = " << current->pPrevious;
        cout << "; Информация = " << current->field_data;
        cout << "; Адрес следующего элемента = " << current->pNext << ";" << endl;
        current = current->pPrevious;
    }
}

//Удаляющие методы
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
    container_for_uk = current;//аккумулирование адреса следующего после удаления элемента
    current = current->pPrevious;//переход на удаляемый элемент
    uk_to_delete = current;//сохранение адреса удаляемого элемента
    current = current->pPrevious;//переход на элемент до удаляемого
    current->pNext = container_for_uk;//переназначение адрес следующего на адрес после следующего
    container_for_uk = current;//сохранение адреса текущего элемента
    current = current->pNext;//переход на элемент после удаляемого по обновленному пути
    current->pPrevious = container_for_uk;//переназначение указателя на предыдущий с удаляемого элемента
    delete uk_to_delete;
    }
    else
        {
        current = tail;
        tail = tail->pPrevious;
        delete current;
    }
    size--;

    cout << "Элемент удален" << endl;
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

//Методы поиска
void List::search_by_value(unsigned long value)
{
    Node *current = this->head;
    int i = 0;
    if((current->field_data) == value)
        {
        cout << "Индекс искомого элемента " << i;
    }
    else
        {
    while(((current->field_data) != value) && (i != size -1))
    {
        current = current->pNext;
        i++;
    }
    if(i != 0)
    cout << "Индекс искомого элемента " << i <<endl;
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
