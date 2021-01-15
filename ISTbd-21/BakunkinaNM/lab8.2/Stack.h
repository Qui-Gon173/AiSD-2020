#include "Node.h"
#include "StackIterator.h"
#include "FibGenerator.h"

using namespace std;


template <typename T>
class Stack {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    using iterator = StackIterator<T>;
    using const_iterator = StackIterator<const T>;

    Stack() {};

    // перенос n элементов в новый экземпляр
    Stack(Stack<T>& other, size_t count) {
        T* arr = other.pop_many(count);
        this->extend(arr, count);
        delete[] arr;
    }

    // Стэк из генератора
    Stack(FibGenerator<T>& gen) {
        for (auto& item : gen) {
            this->append(item);
        }
    }

    ~Stack() {
        this->clear();
    }

    iterator begin() {
        return iterator(this->tail);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator begin() const {
        return iterator(this->tail);
    }

    const_iterator end() const {
        return iterator(nullptr);
    }

    // добавить один элемент в вершину
    void append(T value) {
        Node<T>* node = new Node<T>(value);
        if (this->head == nullptr) {
            this->head = this->tail = node;
        } else {
            node->set_next(this->tail);
            this->tail = node;
        }
    }

    // добавить несколько элементов в вершину
    void extend(T values[], size_t count) {
        for (size_t i = 0; i < count; i++) {
            this->append(values[i]);
        }
    }

    // просмотреть верхний элемент
    T top() {
        if (this->tail == nullptr) {
            throw out_of_range("Stack is empty");
        }

        return this->tail->get_value();
    }

    // извлечь один верхний элемент
    T pop() {
        if (this->tail == nullptr) {
            throw out_of_range("Stack is empty");
        }

        T value = this->tail->get_value();
        Node<T>* next = this->tail->get_next();
        delete this->tail;

        if (next == nullptr) {
            this->tail = this->head = nullptr;
        } else {
            this->tail = next;
        }

        return value;
    }

    // извлечь несколько верхних элементов
    T* pop_many(size_t count) {
        T* arr = new T[count];
        for (size_t i = 0; i < count; i++) {
            arr[i] = this->pop();
        }

        return arr;
    }


    // Полная очистка контейнера
    void clear() {
        while (this->tail != nullptr) {
            Node<T>* current = this->tail;
            this->tail = this->tail->get_next();
            delete current;
        }

        this->head = this->tail;
    }

    // Количество элементов в контейнере;
    size_t length() {
        size_t counter = 0;
        for (Node<T>* node = this->tail; node != nullptr; node = node->get_next()) {
            counter++;
        }

        return counter;
    }
};
