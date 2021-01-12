#include "Node.h"
#include "ListIterator.h"
#include "ArithmeticalGenerator.h"

using namespace std;


template <typename T>
class List {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    using iterator = ListIterator<T>;
    using const_iterator = ListIterator<const T>;

    List() {};

    List(ArithmeticalGenerator<T>& gen) {
        for (auto& number : gen) {
            this->insert(gen.limit(), number);
        }
    }

    ~List() {
        this->clear();
    }

    iterator begin() {
        return iterator(this->head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator begin() const {
        return iterator(this->head);
    }

    const_iterator end() const {
        return iterator(nullptr);
    }

    // Добавление элемента на позицию
    void insert(size_t index, T object) {
        size_t length = this->length();
        Node<T>* new_node = new Node<T>(object);

        if (length == 0) {
            this->head = this->tail = new_node;
        } else if (index == 0) {
            new_node->set_next(this->head);
            this->head = new_node;
        } else if (index >= length) {
            this->tail->set_next(new_node);
            this->tail = new_node;
        } else {
            Node<T>* previous = this->head;
            for (size_t i = 0; i < index - 1; i++) {
                previous = previous->get_next();
            }

            new_node->set_next(previous->get_next());
            previous->set_next(new_node);
        }
    }

    void clear() {
        while (this->head != nullptr) {
            Node<T>* current = this->head;
            this->head = this->head->get_next();
            delete current;
        }

        this->tail = this->head;
    }

    // Количество элементов в контейнере;
    size_t length() {
        size_t counter = 0;
        List::iterator it = this->begin();
        while (it != this->end()) {
            counter++;
            ++it;
        }

        return counter;
    }
};
