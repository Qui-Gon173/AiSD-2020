#include <iostream>

using namespace std;

class List
{
public:
List();
~List();
void just_create_node(unsigned long field_data);
void creation_node_in_target_place(int place, unsigned long field_data);//метод вставляющий узел на позицию
void printList_from_head_to_tail();//метод выводящий все элементы от начала до конца
void printList_from_tail_to_head();//метод выводящий все элементы с конца до начала
int getsize() {return count_conteiner;};
void delete_target_element(int target);
void pop_front();//удаление первого элемента
void clear();//чистим контейнер
void poisk_by_value(unsigned long value);//поиск индекса по значению
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
        Node *pPrev;
        unsigned long field_data;
        Node(unsigned long field_data=123,Node *pPrev=nullptr,Node *pNext=nullptr)
        {
            this->field_data=field_data;
            this->pPrev=pPrev;
            this->pNext=pNext;
        }
    };
    int count_conteiner;
    Node *head;//первый элемент-голова
    Node *tail;//последний элемент-хвост
};

List::List()
{
    count_conteiner=0;
    head=nullptr;
}
List::~List()
{
}
unsigned long & List::operator[](const int index)
{
    int counter=0;
    Node *current=this->head;
    while(current!=nullptr)
    {
        if(counter==index){
            return current->field_data;
        }
        current=current->pNext;
        counter++;
    }
    
}

//Добавляющие методы
void List::just_create_node(unsigned long field_data)
{
    if (head==nullptr)
    {
        head=new Node(field_data);
        Node *current=head;
        cout<<"Was created head: "<<"pPrev="<<current->pPrev<<" Address this node="<<current<<" Data="<<field_data<<" pNext="<<current->pNext<<"\n";
    }
    else
    {
        Node *current=this->head;//создаем указатель, указывающий на голову-1ый элемент
        if(count_conteiner==1){//Если это второй элемент
        Node *current_this;//указатель для демонстрации текущего адреса хвоста
        current->pNext=new Node(field_data,current);//создаем новый хвост, присвоив pNext хеда новый узел
        tail=current->pNext;//говорим хвосту, что это создали его
        current_this=current->pNext;//аккумулируем адрес хвоста для вывода
        current=current->pNext;//смещаем current на хвост, для вывода его параметров
        cout<<"Was created tail: "<<"Address Prev="<<current->pPrev<<" Address this="<<current_this<<" Data="<<field_data<<" pNext="<<current->pNext<<"\n";   
        }//Если более, чем второй
        else
        {
        Node *conteiner_for_uk;
        Node *current_this;//указатель на то, что мы создаем сейчас
        Node *current_prev;//создаем указатель предыдущего элемента
        conteiner_for_uk=current->pNext;//помещаем в контейнер указатель на следующий элемент головы
        current->pNext=new Node(field_data,head,conteiner_for_uk);//создаем новый узел
        current=current->pNext;//переключаемся на след. узел 
        current_this=current;//аккумулируем адрес этого узла для вывода и проверки
        current=current->pNext;//переключаемся на узел, где нам осталось сменить указатель на предыдущий 
        current->pPrev=current_this;//меняем указатель на прошлый элемент(2ого элемента, между которыми мы вставляем узел новый) на правильный указатель на вставляемый узел
        cout<<"Was created: "<<"Address Prev="<<head<<" Address this="<<current_this<<" Data="<<field_data<<" pNext="<<conteiner_for_uk<<"\n";   
        }
    }
    count_conteiner++;
}

void List::creation_node_in_target_place(int place,unsigned long field_data)
{
    Node *current=this->head;
    int i=0;
    if(place==0){
        current->pPrev=new Node(field_data,nullptr,current);
        head=current->pPrev;
    }
    else{
    while(place-i!=1){
        current=current->pNext;
        i++;
    };
    Node *conteiner_for_uk;
    conteiner_for_uk=current->pNext;//аккумулируем указатель
    current->pNext=new Node(field_data,current,conteiner_for_uk);//создаем узел под выбранным номером
    current=current->pNext;//перемещаемся нашим указателем на элемент который мы создали
    conteiner_for_uk=current;//аккумулируем его адрес
    current=current->pNext;//перемещаемся на элемент, стоящий после созданного
    current->pPrev=conteiner_for_uk;//исправляем указатель на предыдущий 
    };
    count_conteiner++;
}

//Вывлдящие методы
void List::printList_from_head_to_tail()
{
    Node *current=this->head;
    for(int i=0;i<count_conteiner;i++)
    {
        cout<<i<<" element:"<<" address prev="<<current->pPrev<<" data="<<current->field_data<<" address next="<<current->pNext;
        cout<<"\n";
        current=current->pNext;
    }
}

void List::printList_from_tail_to_head()
{
    Node *current=this->tail;
    for(int i=count_conteiner-1;i!=-1;i--)
    {
        cout<<i<<" element:"<<" address prev="<<current->pPrev<<" data="<<current->field_data<<" address next="<<current->pNext;
        cout<<"\n";
        current=current->pPrev;
    }
}

//Удаляющие методы
void List::delete_target_element(int target)
{
    Node *current=this->head;
    int i=0;
    if(target==0){
        current=head;
        head=head->pNext;
        delete current;
    }
    if(target>0&&target<(count_conteiner-1)){
    while(i-target!=1){
        current=current->pNext;
        i++;
    };
    Node *conteiner_for_uk;Node *uk_to_delete;
    conteiner_for_uk=current;//аккумулируем адрес следующего после удаления элемента
    current=current->pPrev;//переходим на удаляемый элемент
    uk_to_delete=current;//запоминаем адрес удаляемого
    current=current->pPrev;//переходим на элемент до удаляемого
    current->pNext=conteiner_for_uk;//переназначаем адрес следующего на адрес после следующего
    conteiner_for_uk=current;//запоминаем адрес текущего
    current=current->pNext;//переходим на элемент после удаляемого по обновленному пути
    current->pPrev=conteiner_for_uk;//переназначаем указатель на предыдущий с удаляемого элемента
    delete uk_to_delete;
    };
    if(target==(count_conteiner-1)){
        current=tail;
        tail=tail->pPrev;
        delete current;
    }
    count_conteiner--;
}

void List::pop_front()
{
    Node *temp=head;
    if(head->pNext!=nullptr){
    head=head->pNext;
    head->pPrev=nullptr;
    delete temp;
    count_conteiner--;
    }else
    {
         delete head;count_conteiner--;
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
void List::poisk_by_value(unsigned long value)
{
    Node *current=this->head;
    int i=0;
    if((current->field_data)==value){
        cout<<"Index searched is "<<i;
    }else{
    while(((current->field_data)!=value)&&(i!=count_conteiner-1))
    {
        current=current->pNext;
        i++;
    }
    if(i!=0)
    cout<<"Index searched is "<<i<<"\n";
    };
}

unsigned long List::sum_values_list()
{
    unsigned long sum=0;
    Node *current=this->head;
    while(current->pNext!=nullptr)
    {
        sum+=current->field_data;
        current=current->pNext;
    }
    return sum;
}

unsigned long List::mid_value()
{
    unsigned long mid;
    mid=sum_values_list()/count_conteiner;
    return mid;
}

unsigned long List::find_min_value()
{
    Node *current=this->head;
    unsigned long min=current->field_data;
    while((current->pNext)!=nullptr)
    {
        if(current->field_data<min)
        min=current->field_data;
        current=current->pNext;
    }
    return min;
}

unsigned long List::find_max_value()
{
    Node *current=this->head;
    unsigned long max=current->field_data;
    while((current->pNext)!=nullptr)
    {
        current=current->pNext;
        if(current->field_data>max)
        max=current->field_data;
        
    }
    return max;
}

int main()
{
    //создаем список и начальные узлы
    List lst;
    lst.just_create_node(1);//создали голову
    lst.just_create_node(1234);//создали хвост
    lst.just_create_node(123);//создали 1ый стартовый элемент
    lst.just_create_node(12);//создали 2ой стартовый элемент
    lst.printList_from_head_to_tail();//вывели стартовый список от начала до конца
    //lst.printList_from_tail_to_head();//вывели стартовый список с конца до начала
    //lst.creation_node_in_target_place(2,55);метод вставки
    //lst.delete_target_element(3);//метод удаления
    //lst.printList_from_head_to_tail();вывели список с конца до начала
    //lst.poisk_by_value(123);//метод поиска элемента со значением 123
    //cout<<lst.sum_values_list();метод возвращающий сумму значений элементов списка
    //cout<<lst.mid_value();метод возвращающий среднее значение элементов списка
    //cout<<lst.find_min_value();//метод возвращающий минимальный элемент
    //cout<<lst.find_max_value();//метод возвращающий максимальный элемент
    cout<<"\n"<<lst.getsize();//метод возвращающий количество элементов
    lst.clear();//чистка контейнера
    return 0;
}