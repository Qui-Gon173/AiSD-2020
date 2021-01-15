#pragma once
#include <iterator>


template <typename T>
class ExpIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T a; // число
    T n; // степень
    T move; // шаг
    size_t it_count = 0;
    T* value; 

public:
    ExpIterator(T a, T n, T move, size_t it_count) : a(a), n(n), move(move), it_count(it_count) { // Конструктор
        value = new T;
    }

    // Деконструктор
    ~ExpIterator() {
        delete value;
    }

    // Бинарный оператор неравенства
    bool operator!=(ExpIterator const& other) const {
        return it_count != other.it_count;
    }

    // Бинарный оператор сравнения
    bool operator==(ExpIterator const& other) const {
        return it_count == other.it_count;
    }

    // Унарный оператор разыменования
    typename ExpIterator::reference operator*() const {
        *value = 1;
        for (size_t i = 0; i < n; i++) {
            *value *= a; // Возведение в степень
        }
        return *value; 
    }

    // Унарный оператор инкремент
    ExpIterator& operator++() {
        n = n + move; // чтобы степень увеличивалась на шаг(move)
        it_count++;
        return *this;
    }
};


template <typename T>
class ExpGenerator {
private:
    T a; // число
    T n; // степень
    T move; // шаг
    size_t all_moves; //все шаги (кол-во)

public:
    using iterator = ExpIterator<T>;
    using c_iter = ExpIterator<const T>;

    ExpGenerator(T a, T n, T move, size_t all_moves) : a(a), n(n), move(move), all_moves(all_moves) {} // Конструктор

    // Кол-во шагов
    size_t moves() {
        return all_moves;
    }

    // Вычисление начала для const
    c_iter begin() const {
        return iterator(a, n, move, 0);
    }

    // Вычисление конца для const
    c_iter end() const {
        return iterator(a, n, move, all_moves);
    }

    // Вычисление начала
    iterator begin() {
        return iterator(a, n, move, 0);
    }

    // Вычисление конца
    iterator end() {
        return iterator(a, n, move, all_moves);
    }
};
