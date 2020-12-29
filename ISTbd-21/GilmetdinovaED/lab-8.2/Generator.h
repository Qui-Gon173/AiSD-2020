#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED
#include <iterator>


template <typename T>
class ExpIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T a; // число
    T n; // степень
    T step; // шаг
    int it_count = 0;
    T* value; //значение

public:
    ExpIterator(T a, T n, T step, int it_count) : a(a), n(n), step(step), it_count(it_count) {
        value = new T;
    }


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
        for (int i = 0; i < n; i++) {
            *value *= a;
        }
        return *value;
    }

    // Унарный оператор инкремент
    ExpIterator& operator++() {
        n = n + step;
        it_count++;
        return *this;
    }
};


template <typename T>
class Generator {
private:
    T a; // число
    T n; // степень
    T step; // шаг
    int all_steps; //количесвто шагов

public:
    typedef ExpIterator<T> iterator;
   typedef ExpIterator<const T> const_iter;

    Generator(T a, T n, T step, int all_steps) : a(a), n(n), step(step), all_steps(all_steps) {}


    int steps() {
        return all_steps;
    }

    const_iter begin() const {
        return iterator(a, n, step, 0);
    }

    const_iter end() const {
        return iterator(a, n, step, all_steps);
    }

    iterator begin() {
        return iterator(a, n, step, 0);
    }

    iterator end() {
        return iterator(a, n, step, all_steps);
    }
};

#endif // GENERATOR_H_INCLUDED
