#include "Node.h"

using namespace std;


template <typename T>
class List {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    List() {};

    ~List() {
        this->clear();
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

    // удаление элемента с позиции
    void del(size_t index) {
        size_t length = this->length();
        if (length == 0 || index >= length) {
            return;
        }

        if (index == 0) {
            if (length == 1) {
                delete this->head;
                this->head = this->tail = nullptr;
            } else {
                Node<T>* second = this->head->get_next();
                delete this->head;
                this->head = second;
            }
        } else {
            Node<T>* previous = this->head;
            for (size_t i = 0; i < index - 1; i++) {
                previous = previous->get_next();
            }

            if (index == length - 1) {
                delete this->tail;
                this->tail = previous;
                this->tail->set_next(nullptr);
            } else {
                Node<T>* node_to_del = previous->get_next();
                previous->set_next(node_to_del->get_next());
                delete node_to_del;
            }
        }
    }

    size_t index(T value) {
        size_t i = 0;
        for (Node<T>* node = this->head; node != nullptr; node = node->get_next()) {
            if (node->get_value() == value) {
                return i;
            }
            i++;
        }

        return -1;
    }

    // Поочередный вывод в направлениях, свойственный типу контейнера
    void print() {
        for (Node<T>* node = this->head; node != nullptr; node = node->get_next()) {
            cout << node->get_value() << endl;
        }
    }

    // Полная очистка контейнера
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
        for (Node<T>* node = this->head; node != nullptr; node = node->get_next()) {
            counter++;
        }

        return counter;
    }

    // Сумму всех значений;
    T sum() {
        T counter = 0;
        for (Node<T>* node = this->head; node != nullptr; node = node->get_next()) {
            counter += node->get_value();
        }

        return counter;
    }

    // Среднее значение
    T average() {
        size_t length = this->length();
        if (!length) {
            throw domain_error("Can't div by 0");
        }

        return this->sum() / length;
    }

    // Значение минимального элемента
    T min() {
        size_t length = this->length();
        if (!length) {
            throw out_of_range("List is empty");
        }

        T min_value = this->head->get_value();
        for (Node<T>* node = this->head; node != nullptr; node = node->get_next()) {
            if (node->get_value() < min_value) {
                min_value = node->get_value();
            }
        }
        return min_value;
    }

    // Значение максимального элемента
    T max() {
        size_t length = this->length();
        if (!length) {
            throw out_of_range("List is empty");
        }

        T max_value = this->head->get_value();
        for (Node<T>* node = this->head; node != nullptr; node = node->get_next()) {
            if (node->get_value() > max_value) {
                max_value = node->get_value();
            }
        }
        return max_value;
    }
};
