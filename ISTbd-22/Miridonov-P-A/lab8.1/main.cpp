#include <iostream>

using namespace std;

class List
{
public:
List();
~List();
void NewNode(unsigned int field_data);
void CreateNodeInTargetPlace(int place, unsigned int field_data);//метод вставляющий узел на указанную позицию
void PrintListAhead();//метод, выводящий все элементы от начала до конца
void PrintListBack();//метод, выводящий все элементы с конца до начала
int getsize() {
    return size;};
void DeleteTargetedElement(int target);
void pop_front();//удаление первого элемента
void clear();//чистка контейнера
void SearchByValue(unsigned int value);//поиск индекса по значению
unsigned int SumOfValues();//сумма всех элементов
unsigned int AverageValue();//среднее значение всех значений элементов
unsigned int SearchMinValue();//поиск минимального значения
unsigned int SearchMaxValue();//поиск максимального значения
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
void List::NewNode(unsigned int field_data)
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
void List::PrintListAhead()
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

void List::PrintListBack()
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
    container_for_uk = current;//аккумулирование адреса следующего после удаления элемента
    current = current->pPrevious;//переход на удаляемый элемент
    uk_to_delete = current;//сохранение адреса удаляемого элемента
    current = current->pPrevious;//переход на элемент до удаляемого
    current->pNext = container_for_uk;//переназначение адрес следующего на адрес после следующего
    container_for_uk = current;//сохранение адреса текущего элемента
    current = current->pNext;//переход на элемент после удаляемого по обновленному пути
    current->pPrevious = container_for_uk;//переназначение указателя на предыдущий с удаляемого элемента
    delete uk_to_delete;
    };
    if(target == (size -1))
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
void List::SearchByValue(unsigned int value)
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
    cout << endl << "Общее количество элементов в списке - " << lst.getsize() << endl;
    cout << endl << "Стартовый список от начала до конца" << endl << "-------------------" << endl;;
    lst.PrintListAhead();
    lst.CreateNodeInTargetPlace(2,88);
    cout << endl << "Cписок с конца до начала с добавленным элементом" << endl << "-------------------" << endl;;
    lst.PrintListBack();
    cout << endl << "Список от начала до конца с добавленным элементом" << endl << "-------------------" << endl;;
    lst.PrintListAhead();
    lst.DeleteTargetedElement(3);
    cout << endl << "Список от начала до конца после удаления элемента" << endl << "-------------------" << endl;;
    lst.PrintListAhead();
    cout << endl << "Общее количество элементов в списке - " << lst.getsize() << endl;
    lst.SearchByValue(999);
    cout << "Сумма всех элементов списка - ";
    cout << lst.SumOfValues();
    cout << endl << "Среднее значение элементов списка - ";
    cout << lst.AverageValue();
    cout << endl << "Mинимальный элемент - ";
    cout<<lst.SearchMinValue();
    cout << endl << "Mаксимальный элемент - ";
    cout<<lst.SearchMaxValue();
    lst.clear();
    return 0;
}
