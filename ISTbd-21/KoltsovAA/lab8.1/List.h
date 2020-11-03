#include <iostream>
#include <cstring>

#include "Node.h"


template<typename T>
class List {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    Node<T>* get_head() {
        return head;
    }

    ~List() {
        remove_all();
    }

    size_t get_length() {
        size_t i = 0;
        for (Node<T>* node = head; node != nullptr; node = node->get_next(), i++) {}
        return i;
    }

    T get_average() {
        T sum = 0;
        size_t count = 0;
        for (Node<T>* node = head; node != nullptr; node = node->get_next()) {
            sum += *node->get_value();
            count++;
        }

        return sum / count;
    }

    void append(T* data) {
        Node<T>* node = new Node<T>(data);
        if (head == nullptr) {
            head = node;
            tail = head;
        } else {
            tail->set_next(node);
            tail = node;
        }
    }

    void insert_after(T* after, T* value) {
        for (Node<T>* node = head; node != nullptr; node = node->get_next()) {
            T* object = node->get_value();
            if (*object == *after) {
                if (node == tail) {
                    append(value);
                } else {
                    Node<T>* new_node = new Node<T>(value);
                    new_node->set_next(node->get_next());
                    node->set_next(new_node);
                }
            }
        }
    }

    void print_all() {
        size_t i = 1;
        for (Node<T>* node = head; node != nullptr; node = node->get_next(), i++) {
            T* object = node->get_value();
            std::cout << *object << std::endl;
        }
    }

    void remove_all() {
         while (head != nullptr) {
            Node<T>* current = head;
            head = head->get_next();
            delete current;
        }
    }
};
