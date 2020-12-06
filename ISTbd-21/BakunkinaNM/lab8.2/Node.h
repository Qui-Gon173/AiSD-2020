#pragma once


template <typename T>
class Node {
private:
    T value;
    Node<T>* next = nullptr;
public:
    Node(T value) {
        this->set_value(value);
    }

    T get_value() {
        return value;
    }

    void set_value(T value) {
        this->value = value;
    }

    Node<T>* get_next() {
        return next;
    }

    void set_next(Node<T>* next) {
        this->next = next;
    }
};
