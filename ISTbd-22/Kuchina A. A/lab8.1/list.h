#include <iostream>

using namespace std;

class List
{
public:
List();
~List();
void new_node(unsigned long field_data);
void creation_node_in_target_place(int place, unsigned long field_data);//Г¬ГҐГІГ®Г¤ ГўГ±ГІГ ГўГ«ГїГѕГ№ГЁГ© ГіГ§ГҐГ« Г­Г  ГіГЄГ Г§Г Г­Г­ГіГѕ ГЇГ®Г§ГЁГ¶ГЁГѕ
void print_list_ahead();//Г¬ГҐГІГ®Г¤, ГўГ»ГўГ®Г¤ГїГ№ГЁГ© ГўГ±ГҐ ГЅГ«ГҐГ¬ГҐГ­ГІГ» Г®ГІ Г­Г Г·Г Г«Г  Г¤Г® ГЄГ®Г­Г¶Г 
void print_list_back();//Г¬ГҐГІГ®Г¤, ГўГ»ГўГ®Г¤ГїГ№ГЁГ© ГўГ±ГҐ ГЅГ«ГҐГ¬ГҐГ­ГІГ» Г± ГЄГ®Г­Г¶Г  Г¤Г® Г­Г Г·Г Г«Г 
int getsize() {
    return size;};
void delete_target_element(int target);
void pop_front();//ГіГ¤Г Г«ГҐГ­ГЁГҐ ГЇГҐГ°ГўГ®ГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ 
void clear();//Г·ГЁГ±ГІГЄГ  ГЄГ®Г­ГІГҐГ©Г­ГҐГ°Г 
void search_by_value(unsigned long value);//ГЇГ®ГЁГ±ГЄ ГЁГ­Г¤ГҐГЄГ±Г  ГЇГ® Г§Г­Г Г·ГҐГ­ГЁГѕ
unsigned long sum_values_list();//Г±ГіГ¬Г¬Г  ГўГ±ГҐГµ ГЅГ«ГҐГ¬ГҐГ­ГІГ®Гў
unsigned long mid_value();//Г±Г°ГҐГ¤Г­ГҐГҐ Г§Г­Г Г·ГҐГ­ГЁГҐ ГўГ±ГҐГµ Г§Г­Г Г·ГҐГ­ГЁГ© ГЅГ«ГҐГ¬ГҐГ­ГІГ®Гў
unsigned long find_min_value();//ГЇГ®ГЁГ±ГЄ Г¬ГЁГ­ГЁГ¬Г Г«ГјГ­Г®ГЈГ® Г§Г­Г Г·ГҐГ­ГЁГї
unsigned long find_max_value();//ГЇГ®ГЁГ±ГЄ Г¬Г ГЄГ±ГЁГ¬Г Г«ГјГ­Г®ГЈГ® Г§Г­Г Г·ГҐГ­ГЁГї
unsigned long& operator[](const int index);//ГўГ»ГўГ®Г¤ Г§Г­Г Г·ГҐГ­ГЁГї ГЇГ® ГЁГ­Г¤ГҐГЄГ±Гі
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
Node *head;//ГЇГҐГ°ГўГ»Г© ГЅГ«ГҐГ¬ГҐГ­ГІ-ГЈГ®Г«Г®ГўГ 
Node *tail;//ГЇГ®Г±Г«ГҐГ¤Г­ГЁГ© ГЅГ«ГҐГ¬ГҐГ­ГІ-ГµГўГ®Г±ГІ
};

List::List()
{
    size = 0;
    head = nullptr;
}
List::~List()
{
}
<<<<<<< HEAD
//Методы добавления элементов
=======

//ГЊГҐГІГ®Г¤Г» Г¤Г®ГЎГ ГўГ«ГҐГ­ГЁГї ГЅГ«ГҐГ¬ГҐГ­ГІГ®Гў
>>>>>>> 6987792e882d5e5a2601525333e3b748a69756b2
void List::new_node(unsigned long field_data)
{
    if (head == nullptr)
    {
        head = new Node(field_data);
        Node *current = head;
        cout << "ГЃГ»Г« Г±Г®Г§Г¤Г Г­ ГЇГҐГ°ГўГ»Г© ГЅГ«ГҐГ¬ГҐГ­ГІ: " << "; pPrevious=" << current->pPrevious;
        cout << ";  ГЂГ¤Г°ГҐГ± ГІГҐГЄГіГ№ГҐГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ  =  = " << current;
        cout << "; Г€Г­ГґГ®Г°Г¬Г Г¶ГЁГї = " << field_data;
        cout << "; pNext = " << current->pNext << endl;
    }
    else
    {
        Node *current = this->head;//Г±Г®Г§Г¤Г ГҐГ¬ ГіГЄГ Г§Г ГІГҐГ«Гј, ГіГЄГ Г§Г»ГўГ ГѕГ№ГЁГ© Г­Г  ГЈГ®Г«Г®ГўГі-1Г»Г© ГЅГ«ГҐГ¬ГҐГ­ГІ
        if(size == 1 )
            {//Г…Г±Г«ГЁ ГЅГІГ® ГўГІГ®Г°Г®Г© ГЅГ«ГҐГ¬ГҐГ­ГІ
        Node *current_this;//ГіГЄГ Г§Г ГІГҐГ«Гј Г¤Г«Гї Г¤ГҐГ¬Г®Г­Г±ГІГ°Г Г¶ГЁГЁ ГІГҐГЄГіГ№ГҐГЈГ® Г Г¤Г°ГҐГ±Г  ГµГўГ®Г±ГІГ 
        current->pNext = new Node(field_data, current);//Г±Г®Г§Г¤Г ГҐГ¬ Г­Г®ГўГ»Г© ГµГўГ®Г±ГІ, ГЇГ°ГЁГ±ГўГ®ГЁГў pNext ГµГҐГ¤Г  Г­Г®ГўГ»Г© ГіГ§ГҐГ«
        tail = current->pNext;//ГЈГ®ГўГ®Г°ГЁГ¬ ГµГўГ®Г±ГІГі, Г·ГІГ® ГЅГІГ® Г±Г®Г§Г¤Г Г«ГЁ ГҐГЈГ®
        current_this = current->pNext;//Г ГЄГЄГіГ¬ГіГ«ГЁГ°ГіГҐГ¬ Г Г¤Г°ГҐГ± ГµГўГ®Г±ГІГ  Г¤Г«Гї ГўГ»ГўГ®Г¤Г 
        current = current->pNext;//Г±Г¬ГҐГ№Г ГҐГ¬ current Г­Г  ГµГўГ®Г±ГІ, Г¤Г«Гї ГўГ»ГўГ®Г¤Г  ГҐГЈГ® ГЇГ Г°Г Г¬ГҐГІГ°Г®Гў
        cout << "ГЃГ»Г« Г±Г®Г§Г¤Г Г­ ГЇГ®Г±Г«ГҐГ¤Г­ГЁГ© ГЅГ«ГҐГ¬ГҐГ­ГІ: " << " ГЂГ¤Г°ГҐГ± ГЇГ°ГҐГ¤Г»Г¤ГіГ№ГҐГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ  = " << current->pPrevious;
        cout << "; Г Г¤Г°ГҐГ± ГЅГ«ГҐГ¬ГҐГ­ГІГ  = " << current_this;
        cout << "; Г€Г­ГґГ®Г°Г¬Г Г¶ГЁГї = " << field_data;
        cout << "; Г Г¤Г°ГҐГ± Г±Г«ГҐГ¤ГіГѕГ№ГҐГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ :" << current->pNext << ";" << endl;
        }//Г…Г±Г«ГЁ ГЎГ®Г«ГҐГҐ, Г·ГҐГ¬ ГўГІГ®Г°Г®Г©
        else
        {
        Node *conteiner_for_uk;
        Node *current_this;//ГіГЄГ Г§Г ГІГҐГ«Гј Г­Г  Г±Г®Г§Г¤Г ГўГ ГҐГ¬Г»Г© ГЅГ«ГҐГ¬ГҐГ­ГІ
        conteiner_for_uk = current->pNext;//ГЇГ®Г¬ГҐГ№ГҐГ­ГЁГҐ Гў ГЄГ®Г­ГІГҐГ©Г­ГҐГ° ГіГЄГ Г§Г ГІГҐГ«Гї Г­Г  Г±Г«ГҐГ¤ГіГѕГ№ГЁГ© ГЅГ«ГҐГ¬ГҐГ­ГІ ГЈГ®Г«Г®ГўГ»
        current->pNext = new Node(field_data,head,conteiner_for_uk);//Г±Г®Г§Г¤Г Г­ГЁГҐ Г­Г®ГўГ®ГЈГ® ГіГ§Г«Г 
        current = current->pNext;//ГЇГҐГ°ГҐГЄГ«ГѕГ·ГҐГ­ГЁГҐ Г­Г  Г±Г«ГҐГ¤. ГіГ§ГҐГ«
        current_this = current;//Г ГЄГЄГіГ¬ГіГ«ГЁГ°Г®ГўГ Г­ГЁГҐ Г Г¤Г°ГҐГ±Г  ГЅГІГ®ГЈГ® ГіГ§Г«Г  Г¤Г«Гї ГўГ»ГўГ®Г¤Г  ГЁ ГЇГ°Г®ГўГҐГ°ГЄГЁ
        current = current->pNext;//ГЇГҐГ°ГҐГЄГ«ГѕГ·ГҐГ­ГЁГҐ Г­Г  ГіГ§ГҐГ«, ГЈГ¤ГҐ Г­ГіГ¦Г­Г® Г±Г¬ГҐГ­ГЁГІГј ГіГЄГ Г§Г ГІГҐГ«Гј Г­Г  ГЇГ°ГҐГ¤Г»Г¤ГіГ№ГЁГ©
        current->pPrevious = current_this;//ГЁГ§Г¬ГҐГ­ГҐГ­ГЁГҐ ГіГЄГ Г§Г ГІГҐГ«Гї Г­Г  ГЇГ°Г®ГёГ«Г»Г© ГЅГ«ГҐГ¬ГҐГ­ГІ(2Г®ГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ , Г¬ГҐГ¦Г¤Гі ГЄГ®ГІГ®Г°Г»Г¬ГЁ Г¬Г» ГўГ±ГІГ ГўГ«ГїГҐГ¬ ГіГ§ГҐГ« Г­Г®ГўГ»Г©) Г­Г  ГЇГ°Г ГўГЁГ«ГјГ­Г»Г© ГіГЄГ Г§Г ГІГҐГ«Гј Г­Г  ГўГ±ГІГ ГўГ«ГїГҐГ¬Г»Г© ГіГ§ГҐГ«
        cout << "ГЃГ»Г« Г±Г®Г§Г¤Г Г­ ГЅГ«ГҐГ¬ГҐГ­ГІ: " << " ГЂГ¤Г°ГҐГ± ГЇГ°ГҐГ¤Г»Г¤ГіГ№ГҐГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ  = " << head;
        cout << "; Г Г¤Г°ГҐГ± ГЅГІГ®ГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ  = " << current_this;
        cout << "; Г€Г­ГґГ®Г°Г¬Г Г¶ГЁГї = " << field_data;
        cout << "; Г Г¤Г°ГҐГ± Г±Г«ГҐГ¤ГіГѕГ№ГҐГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ :" << conteiner_for_uk << ";" << endl;
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
    conteiner_for_uk = current->pNext;//Г ГЄГЄГіГ¬ГіГ«ГЁГ°Г®ГўГ Г­ГЁГҐ ГіГЄГ Г§Г ГІГҐГ«Гї
    current->pNext = new Node(field_data, current, conteiner_for_uk);//Г±Г®Г§Г¤Г Г­ГЁГҐ ГіГ§Г«Г  ГЇГ®Г¤ ГўГ»ГЎГ°Г Г­Г­Г»Г¬ Г­Г®Г¬ГҐГ°Г®Г¬
    current = current->pNext;//ГЇГҐГ°ГҐГ¬ГҐГ№ГҐГ­ГЁГҐ ГіГ§Г«Г 
    conteiner_for_uk = current;//Г ГЄГЄГіГ¬ГіГ«ГЁГ°Г®ГўГ Г­ГЁГҐ ГҐГЈГ® Г Г¤Г°ГҐГ±Г 
    current = current->pNext;//ГЇГҐГ°ГҐГ¬ГҐГ№ГҐГ­ГЁГҐ Г­Г  ГЅГ«ГҐГ¬ГҐГ­ГІ, Г±ГІГ®ГїГ№ГЁГ© ГЇГ®Г±Г«ГҐ Г±Г®Г§Г¤Г Г­Г­Г®ГЈГ®
    current->pPrevious=conteiner_for_uk;//ГЁГ±ГЇГ°Г ГўГ«ГҐГ­ГЁГҐ ГіГЄГ Г§Г ГІГҐГ«Гї Г­Г  ГЇГ°ГҐГ¤Г»Г¤ГіГ№ГЁГ©
    };
    size++;
    cout << "ГќГ«ГҐГ¬ГҐГ­ГІ Г¤Г®ГЎГ ГўГ«ГҐГ­" << endl;
}
//ГЊГҐГІГ®Г¤Г» ГўГ»ГўГ®Г¤Г  Г±ГЇГЁГ±ГЄГ  Г­Г  ГЄГ®Г­Г±Г®Г«Гј
void List::print_list_ahead()
{
    Node *current = this->head;
    for(int i = 0; i < size; i++)
    {
        cout << "ГќГ«ГҐГ¬ГҐГ­ГІ " << i << ":" << " Г Г¤Г°ГҐГ± ГЇГ°ГҐГ¤Г»Г¤ГіГ№ГҐГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ  = " << current->pPrevious;
        cout << "; Г€Г­ГґГ®Г°Г¬Г Г¶ГЁГї = " << current->field_data;
        cout << "; ГЂГ¤Г°ГҐГ± Г±Г«ГҐГ¤ГіГѕГ№ГҐГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ  = " << current->pNext << ";" << endl;
        current = current->pNext;
    }
}

void List::print_list_back()
{
    Node *current = this->tail;
    for(int i = size - 1; i != -1; i--)
    {
        cout << "ГќГ«ГҐГ¬ГҐГ­ГІ " << i <<":" << " Г Г¤Г°ГҐГ± ГЇГ°ГҐГ¤Г»Г¤ГіГ№ГҐГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ  = " << current->pPrevious;
        cout << "; Г€Г­ГґГ®Г°Г¬Г Г¶ГЁГї = " << current->field_data;
        cout << "; ГЂГ¤Г°ГҐГ± Г±Г«ГҐГ¤ГіГѕГ№ГҐГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ  = " << current->pNext << ";" << endl;
        current = current->pPrevious;
    }
}

//Г“Г¤Г Г«ГїГѕГ№ГЁГҐ Г¬ГҐГІГ®Г¤Г»
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
    container_for_uk = current;//Г ГЄГЄГіГ¬ГіГ«ГЁГ°Г®ГўГ Г­ГЁГҐ Г Г¤Г°ГҐГ±Г  Г±Г«ГҐГ¤ГіГѕГ№ГҐГЈГ® ГЇГ®Г±Г«ГҐ ГіГ¤Г Г«ГҐГ­ГЁГї ГЅГ«ГҐГ¬ГҐГ­ГІГ 
    current = current->pPrevious;//ГЇГҐГ°ГҐГµГ®Г¤ Г­Г  ГіГ¤Г Г«ГїГҐГ¬Г»Г© ГЅГ«ГҐГ¬ГҐГ­ГІ
    uk_to_delete = current;//Г±Г®ГµГ°Г Г­ГҐГ­ГЁГҐ Г Г¤Г°ГҐГ±Г  ГіГ¤Г Г«ГїГҐГ¬Г®ГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ 
    current = current->pPrevious;//ГЇГҐГ°ГҐГµГ®Г¤ Г­Г  ГЅГ«ГҐГ¬ГҐГ­ГІ Г¤Г® ГіГ¤Г Г«ГїГҐГ¬Г®ГЈГ®
    current->pNext = container_for_uk;//ГЇГҐГ°ГҐГ­Г Г§Г­Г Г·ГҐГ­ГЁГҐ Г Г¤Г°ГҐГ± Г±Г«ГҐГ¤ГіГѕГ№ГҐГЈГ® Г­Г  Г Г¤Г°ГҐГ± ГЇГ®Г±Г«ГҐ Г±Г«ГҐГ¤ГіГѕГ№ГҐГЈГ®
    container_for_uk = current;//Г±Г®ГµГ°Г Г­ГҐГ­ГЁГҐ Г Г¤Г°ГҐГ±Г  ГІГҐГЄГіГ№ГҐГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ 
    current = current->pNext;//ГЇГҐГ°ГҐГµГ®Г¤ Г­Г  ГЅГ«ГҐГ¬ГҐГ­ГІ ГЇГ®Г±Г«ГҐ ГіГ¤Г Г«ГїГҐГ¬Г®ГЈГ® ГЇГ® Г®ГЎГ­Г®ГўГ«ГҐГ­Г­Г®Г¬Гі ГЇГіГІГЁ
    current->pPrevious = container_for_uk;//ГЇГҐГ°ГҐГ­Г Г§Г­Г Г·ГҐГ­ГЁГҐ ГіГЄГ Г§Г ГІГҐГ«Гї Г­Г  ГЇГ°ГҐГ¤Г»Г¤ГіГ№ГЁГ© Г± ГіГ¤Г Г«ГїГҐГ¬Г®ГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ 
    delete uk_to_delete;
    }
    else
        {
        current = tail;
        tail = tail->pPrevious;
        delete current;
    }
    size--;

    cout << "ГќГ«ГҐГ¬ГҐГ­ГІ ГіГ¤Г Г«ГҐГ­" << endl;
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

//ГЊГҐГІГ®Г¤Г» ГЇГ®ГЁГ±ГЄГ 
void List::search_by_value(unsigned long value)
{
    Node *current = this->head;
    int i = 0;
    if((current->field_data) == value)
        {
        cout << "Г€Г­Г¤ГҐГЄГ± ГЁГ±ГЄГ®Г¬Г®ГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ  " << i;
    }
    else
        {
    while(((current->field_data) != value) && (i != size -1))
    {
        current = current->pNext;
        i++;
    }
    if(i != 0)
    cout << "Г€Г­Г¤ГҐГЄГ± ГЁГ±ГЄГ®Г¬Г®ГЈГ® ГЅГ«ГҐГ¬ГҐГ­ГІГ  " << i <<endl;
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
