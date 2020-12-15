#include "Node.h"

using namespace std;


template <typename T>
class Stack {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    Stack() {};

    // перенос n элементов в новый экземпляр
    Stack(Stack<T>& other, size_t count) {
        T* arr = other.pop_many(count);
        this->extend(arr, count);
        delete[] arr;
    }

    ~Stack() {
        this->clear();
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

    // Поочередный вывод в направлениях, свойственный типу контейнера
    void print() {
        for (Node<T>* node = this->tail; node != nullptr; node = node->get_next()) {
            cout << node->get_value() << endl;
        }
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

    // Сумму всех значений;
    T sum() {
        T counter = 0;
        for (Node<T>* node = this->tail; node != nullptr; node = node->get_next()) {
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
            throw out_of_range("Stack is empty");
        }

        T min_value = this->top();
        for (Node<T>* node = this->tail; node != nullptr; node = node->get_next()) {
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
            throw out_of_range("Stack is empty");
        }

        T max_value = this->top();
        for (Node<T>* node = this->tail; node != nullptr; node = node->get_next()) {
            if (node->get_value() > max_value) {
                max_value = node->get_value();
            }
        }
        return max_value;
    }
};
