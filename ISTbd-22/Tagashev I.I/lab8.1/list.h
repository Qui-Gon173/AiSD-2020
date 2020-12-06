#pragma once
class List
{
public:
    List();
    ~List();
    void adding_element(unsigned long data);
    void adding_element(int place, unsigned long data);
    void print_from_head();
    void print_from_end();
    int getsize() { return count_elements; };
    void delete_target_element(int target);
    void search_index();
    void cls();
    void search_index(unsigned long value);
    unsigned long sum();
    unsigned long mid_value();
    unsigned long min_value();
    unsigned long max_value();
    unsigned long& operator[](const int index);
private:

    class Node
    {
    public:
        Node* pNext;
        Node* pPrev;
        unsigned long data;
        Node(unsigned long data = 123, Node* pPrev = nullptr, Node* pNext = nullptr)
        {
            this->data = data;
            this->pPrev = pPrev;
            this->pNext = pNext;
        }
    };
    int count_elements;
    Node* head;
    Node* tail;
};

List::List()
{
    count_elements = 0;
    head = nullptr;
}
// Деструктор
List::~List()
{
}
unsigned long& List::operator[](const int index)
{
    int counter = 0;
    Node* current = this->head;
    while (current != nullptr)
    {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }

}

void List::adding_element(unsigned long data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        Node* current = head;
        std::cout << "[HEAD]" << " || " << "[pPrev]: " << current->pPrev << " || " << "[ADDRESS]: " << current << " || " << "[DATA]: " << data << " || " << "[pNext]:" << current->pNext << std::endl;
    }
    else
    {
        Node* current = this->head;
        if (count_elements == 1) {
            Node* current_this;
            current->pNext = new Node(data, current);
            tail = current->pNext;
            current_this = current->pNext;
            current = current->pNext;
            std::cout << "[TAIL]" << " || " << "[pPrev]: " << current->pPrev << " || " << "[ADDRESS]: " << current_this << " || " << "[DATA]: " << data << " || " << "[pNext]:" << current->pNext << std::endl;
        }
        else
        {
            Node* conteiner_for_uk;
            Node* current_this;
            Node* current_prev;
            conteiner_for_uk = current->pNext;
            current->pNext = new Node(data, head, conteiner_for_uk);
            current = current->pNext;
            current_this = current;
            current = current->pNext;
            current->pPrev = current_this;
            std::cout << "[NODE]" << " || " << "[pPrev]: " << head << " || " << "[ADDRESS]: " << current_this << " || " << "[DATA]: " << data << " || " << "[pNext]:" << conteiner_for_uk << std::endl;
        }
    }
    count_elements++;
}

void List::adding_element(int place, unsigned long data)
{
    Node* current = this->head;
    int i = 0;
    if (place == 0) {
        current->pPrev = new Node(data, nullptr, current);
        head = current->pPrev;
    }
    else {
        while (place - i != 1) {
            current = current->pNext;
            i++;
        };
        Node* conteiner_for_uk;
        conteiner_for_uk = current->pNext;
        current->pNext = new Node(data, current, conteiner_for_uk);
        current = current->pNext;
        conteiner_for_uk = current;
        current = current->pNext;
        current->pPrev = conteiner_for_uk;
    };
    count_elements++;
}

void List::print_from_head()
{
    Node* current = this->head;
    for (int i = 0; i < count_elements; i++)
    {
        std::cout << "[" << "ELEMENT " << i << "]" << " || " << "[pPrev]:" << current->pPrev << " || " << "[DATA]:" << current->data << " || " << "[pNext]:" << current->pNext;
        std::cout << std::endl;
        current = current->pNext;
    }
}

void List::print_from_end()
{
    Node* current = this->tail;
    for (int i = count_elements - 1; i != -1; i--)
    {
        std::cout << "[" << "ELEMENT " << i << "]" << " || " << "[pPrev]:" << current->pPrev << " || " << " [DATA]:" << current->data << " || " << "[pNext]:" << current->pNext;
        std::cout << std::endl;
        current = current->pPrev;
    }
}

void List::delete_target_element(int target)
{
    Node* current = this->head;
    int i = 0;
    if (target == 0) {
        current = head;
        head = head->pNext;
        delete current;
    }
    if (target > 0 && target < (count_elements - 1)) {
        while (i - target != 1) {
            current = current->pNext;
            i++;
        };
        Node* conteiner_for_uk; Node* uk_to_delete;
        conteiner_for_uk = current;
        current = current->pPrev;
        uk_to_delete = current;
        current = current->pPrev;
        current->pNext = conteiner_for_uk;
        conteiner_for_uk = current;
        current = current->pNext;
        current->pPrev = conteiner_for_uk;
        delete uk_to_delete;
    };
    if (target == (count_elements - 1)) {
        current = tail;
        tail = tail->pPrev;
        delete current;
    }
    count_elements--;
}

void List::search_index()
{
    Node* temp = head;
    if (head->pNext != nullptr) {
        head = head->pNext;
        head->pPrev = nullptr;
        delete temp;
        count_elements--;
    }
    else
    {
        delete head; count_elements--;
    }

}

void List::cls()
{
    while (count_elements)
    {
        search_index();
    }
}

void List::search_index(unsigned long value)
{
    Node* current = this->head;
    int i = 0;
    if ((current->data) == value) {
        std::cout << "[SEARCH INDEX]: " << i;
    }
    else {
        while (((current->data) != value) && (i != count_elements - 1))
        {
            current = current->pNext;
            i++;
        }
        if (i != 0)
            std::cout << "[SEARCH INDEX]: " << i << std::endl;
    };
}

unsigned long List::sum()
{
    unsigned long sum = 0;
    Node* current = this->head;
    while (current->pNext != nullptr)
    {
        sum += current->data;
        current = current->pNext;
    }
    return sum;
}

unsigned long List::mid_value()
{
    unsigned long mid;
    mid = sum() / count_elements;
    return mid;
}

unsigned long List::min_value()
{
    Node* current = this->head;
    unsigned long min = current->data;
    while ((current->pNext) != nullptr)
    {
        if (current->data < min)
            min = current->data;
        current = current->pNext;
    }
    return min;
}

unsigned long List::max_value()
{
    Node* current = this->head;
    unsigned long max = current->data;
    while ((current->pNext) != nullptr)
    {
        current = current->pNext;
        if (current->data > max)
            max = current->data;

    }
    return max;
}