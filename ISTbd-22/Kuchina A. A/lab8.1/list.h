#include <iostream>

using namespace std;

class List
{
public:
List();
~List();
void new_node(unsigned long field_data);
void creation_node_in_target_place(int place, unsigned long field_data);//ìåòîä âñòàâëÿþùèé óçåë íà óêàçàííóþ ïîçèöèþ
void print_list_ahead();//ìåòîä, âûâîäÿùèé âñå ýëåìåíòû îò íà÷àëà äî êîíöà
void print_list_back();//ìåòîä, âûâîäÿùèé âñå ýëåìåíòû ñ êîíöà äî íà÷àëà
int getsize() {
    return size;};
void delete_target_element(int target);
void pop_front();//óäàëåíèå ïåðâîãî ýëåìåíòà
void clear();//÷èñòêà êîíòåéíåðà
//int search(const int ind);//Ïîèñê ïî èíäåêñó
void search_by_value(unsigned long value);//ïîèñê èíäåêñà ïî çíà÷åíèþ
unsigned long sum_values_list();//ñóììà âñåõ ýëåìåíòîâ
unsigned long mid_value();//ñðåäíåå çíà÷åíèå âñåõ çíà÷åíèé ýëåìåíòîâ
unsigned long find_min_value();//ïîèñê ìèíèìàëüíîãî çíà÷åíèÿ
unsigned long find_max_value();//ïîèñê ìàêñèìàëüíîãî çíà÷åíèÿ
unsigned long& operator[](const int index);//âûâîä çíà÷åíèÿ ïî èíäåêñó
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
Node *head;//ïåðâûé ýëåìåíò-ãîëîâà
Node *tail;//ïîñëåäíèé ýëåìåíò-õâîñò
};

List::List()
{
    size = 0;
    head = nullptr;
}
List::~List()
{
}

//Ìåòîäû äîáàâëåíèÿ ýëåìåíòîâ
void List::new_node(unsigned long field_data)
{
    if (head == nullptr)
    {
        head = new Node(field_data);
        Node *current = head;
        cout << "Áûë ñîçäàí ïåðâûé ýëåìåíò: " << "; pPrevious=" << current->pPrevious;
        cout << ";  Àäðåñ òåêóùåãî ýëåìåíòà =  = " << current;
        cout << "; Èíôîðìàöèÿ = " << field_data;
        cout << "; pNext = " << current->pNext << endl;
    }
    else
    {
        Node *current = this->head;//ñîçäàåì óêàçàòåëü, óêàçûâàþùèé íà ãîëîâó-1ûé ýëåìåíò
        if(size == 1 )
            {//Åñëè ýòî âòîðîé ýëåìåíò
        Node *current_this;//óêàçàòåëü äëÿ äåìîíñòðàöèè òåêóùåãî àäðåñà õâîñòà
        current->pNext = new Node(field_data, current);//ñîçäàåì íîâûé õâîñò, ïðèñâîèâ pNext õåäà íîâûé óçåë
        tail = current->pNext;//ãîâîðèì õâîñòó, ÷òî ýòî ñîçäàëè åãî
        current_this = current->pNext;//àêêóìóëèðóåì àäðåñ õâîñòà äëÿ âûâîäà
        current = current->pNext;//ñìåùàåì current íà õâîñò, äëÿ âûâîäà åãî ïàðàìåòðîâ
        cout << "Áûë ñîçäàí ïîñëåäíèé ýëåìåíò: " << " Àäðåñ ïðåäûäóùåãî ýëåìåíòà = " << current->pPrevious;
        cout << "; àäðåñ ýëåìåíòà = " << current_this;
        cout << "; Èíôîðìàöèÿ = " << field_data;
        cout << "; àäðåñ ñëåäóþùåãî ýëåìåíòà:" << current->pNext << ";" << endl;
        }//Åñëè áîëåå, ÷åì âòîðîé
        else
        {
        Node *conteiner_for_uk;
        Node *current_this;//óêàçàòåëü íà ñîçäàâàåìûé ýëåìåíò
        conteiner_for_uk = current->pNext;//ïîìåùåíèå â êîíòåéíåð óêàçàòåëÿ íà ñëåäóþùèé ýëåìåíò ãîëîâû
        current->pNext = new Node(field_data,head,conteiner_for_uk);//ñîçäàíèå íîâîãî óçëà
        current = current->pNext;//ïåðåêëþ÷åíèå íà ñëåä. óçåë
        current_this = current;//àêêóìóëèðîâàíèå àäðåñà ýòîãî óçëà äëÿ âûâîäà è ïðîâåðêè
        current = current->pNext;//ïåðåêëþ÷åíèå íà óçåë, ãäå íóæíî ñìåíèòü óêàçàòåëü íà ïðåäûäóùèé
        current->pPrevious = current_this;//èçìåíåíèå óêàçàòåëÿ íà ïðîøëûé ýëåìåíò(2îãî ýëåìåíòà, ìåæäó êîòîðûìè ìû âñòàâëÿåì óçåë íîâûé) íà ïðàâèëüíûé óêàçàòåëü íà âñòàâëÿåìûé óçåë
        cout << "Áûë ñîçäàí ýëåìåíò: " << " Àäðåñ ïðåäûäóùåãî ýëåìåíòà = " << head;
        cout << "; àäðåñ ýòîãî ýëåìåíòà = " << current_this;
        cout << "; Èíôîðìàöèÿ = " << field_data;
        cout << "; àäðåñ ñëåäóþùåãî ýëåìåíòà:" << conteiner_for_uk << ";" << endl;
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
    conteiner_for_uk = current->pNext;//àêêóìóëèðîâàíèå óêàçàòåëÿ
    current->pNext = new Node(field_data, current, conteiner_for_uk);//ñîçäàíèå óçëà ïîä âûáðàííûì íîìåðîì
    current = current->pNext;//ïåðåìåùåíèå óçëà
    conteiner_for_uk = current;//àêêóìóëèðîâàíèå åãî àäðåñà
    current = current->pNext;//ïåðåìåùåíèå íà ýëåìåíò, ñòîÿùèé ïîñëå ñîçäàííîãî
    current->pPrevious=conteiner_for_uk;//èñïðàâëåíèå óêàçàòåëÿ íà ïðåäûäóùèé
    };
    size++;
    cout << "Ýëåìåíò äîáàâëåí" << endl;
}
//Ìåòîäû âûâîäà ñïèñêà íà êîíñîëü
void List::print_list_ahead()
{
    Node *current = this->head;
    for(int i = 0; i < size; i++)
    {
        cout << "Ýëåìåíò " << i << ":" << " àäðåñ ïðåäûäóùåãî ýëåìåíòà = " << current->pPrevious;
        cout << "; Èíôîðìàöèÿ = " << current->field_data;
        cout << "; Àäðåñ ñëåäóþùåãî ýëåìåíòà = " << current->pNext << ";" << endl;
        current = current->pNext;
    }
}

void List::print_list_back()
{
    Node *current = this->tail;
    for(int i = size - 1; i != -1; i--)
    {
        cout << "Ýëåìåíò " << i <<":" << " àäðåñ ïðåäûäóùåãî ýëåìåíòà = " << current->pPrevious;
        cout << "; Èíôîðìàöèÿ = " << current->field_data;
        cout << "; Àäðåñ ñëåäóþùåãî ýëåìåíòà = " << current->pNext << ";" << endl;
        current = current->pPrevious;
    }
}

//Óäàëÿþùèå ìåòîäû
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
    container_for_uk = current;//àêêóìóëèðîâàíèå àäðåñà ñëåäóþùåãî ïîñëå óäàëåíèÿ ýëåìåíòà
    current = current->pPrevious;//ïåðåõîä íà óäàëÿåìûé ýëåìåíò
    uk_to_delete = current;//ñîõðàíåíèå àäðåñà óäàëÿåìîãî ýëåìåíòà
    current = current->pPrevious;//ïåðåõîä íà ýëåìåíò äî óäàëÿåìîãî
    current->pNext = container_for_uk;//ïåðåíàçíà÷åíèå àäðåñ ñëåäóþùåãî íà àäðåñ ïîñëå ñëåäóþùåãî
    container_for_uk = current;//ñîõðàíåíèå àäðåñà òåêóùåãî ýëåìåíòà
    current = current->pNext;//ïåðåõîä íà ýëåìåíò ïîñëå óäàëÿåìîãî ïî îáíîâëåííîìó ïóòè
    current->pPrevious = container_for_uk;//ïåðåíàçíà÷åíèå óêàçàòåëÿ íà ïðåäûäóùèé ñ óäàëÿåìîãî ýëåìåíòà
    delete uk_to_delete;
    }
    else
        {
        current = tail;
        tail = tail->pPrevious;
        delete current;
    }
    size--;

    cout << "Ýëåìåíò óäàëåí" << endl;
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

//Ìåòîäû ïîèñêà
void List::search_by_value(unsigned long value)
{
    Node *current = this->head;
    int i = 0;
    if((current->field_data) == value)
        {
        cout << "Èíäåêñ èñêîìîãî ýëåìåíòà " << i;
    }
    else
        {
    while(((current->field_data) != value) && (i != size -1))
    {
        current = current->pNext;
        i++;
    }
    if(i != 0)
    cout << "Èíäåêñ èñêîìîãî ýëåìåíòà " << i <<endl;
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
