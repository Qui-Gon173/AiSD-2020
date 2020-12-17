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
    return count_conteiner;};
void delete_target_element(int target);
void pop_front();//удаление первого элемента
void clear();//чистка контейнера
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

int count_conteiner;
Node *head;//первый элемент-голова
Node *tail;//последний элемент-хвост
};

List::List()
{
    count_conteiner = 0;
    head = nullptr;
}
List::~List()
{
}

unsigned long & List::operator[](const int index)
{
    int counter = 0;
    Node *current = this->head;
    while(current != nullptr)
    {
        if(counter == index){
            return current->field_data;
        }
        current = current->pNext;
        counter++;
    }

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
        if(count_conteiner == 1 )
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
        Node *current_prev;//создание указателя предыдущего элемента
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
    count_conteiner++;
}

void List::creation_node_in_target_place(int place, unsigned long field_data)
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
    conteiner_for_uk = current->pNext;//аккумулирование указателя
    current->pNext = new Node(field_data, current, conteiner_for_uk);//создание узла под выбранным номером
    current = current->pNext;//перемещение узла
    conteiner_for_uk = current;//аккумулирование его адреса
    current = current->pNext;//перемещение на элемент, стоящий после созданного
    current->pPrevious=conteiner_for_uk;//исправление указателя на предыдущий
    };
    count_conteiner++;
    cout << "Элемент добавлен" << endl;
}
//Методы вывода списка на консоль
void List::print_list_ahead()
{
    Node *current = this->head;
    for(int i = 0; i < count_conteiner; i++)
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
    for(int i = count_conteiner - 1; i != -1; i--)
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
    int i = 0;
    if(target == 0)
        {
        current = head;
        head = head->pNext;
        delete current;
    }
    if(target > 0 && target < (count_conteiner - 1))
    {
    while(i - target != 1)
    {
        current = current->pNext;
        i++;
    };
    Node *conteiner_for_uk;
    Node *uk_to_delete;
    conteiner_for_uk = current;//аккумулирование адреса следующего после удаления элемента
    current = current->pPrevious;//переход на удаляемый элемент
    uk_to_delete = current;//сохранение адреса удаляемого элемента
    current = current->pPrevious;//переход на элемент до удаляемого
    current->pNext = conteiner_for_uk;//переназначение адрес следующего на адрес после следующего
    conteiner_for_uk = current;//сохранение адреса текущего элемента
    current = current->pNext;//переход на элемент после удаляемого по обновленному пути
    current->pPrevious = conteiner_for_uk;//переназначение указателя на предыдущий с удаляемого элемента
    delete uk_to_delete;
    };
    if(target == (count_conteiner -1))
        {
        current = tail;
        tail = tail->pPrevious;
        delete current;
    }
    count_conteiner--;

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
    count_conteiner--;
    }
    else
    {
         delete head;
         count_conteiner--;
    }
}

void List::clear()
{
    while(count_conteiner)
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
        cout << "IИндекс искомого элемента " << i;
    }
    else
        {
    while(((current->field_data) != value) && (i != count_conteiner -1))
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
    unsigned long mid;
    mid = sum_values_list()/count_conteiner;
    return mid;
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
