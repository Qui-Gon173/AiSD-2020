#pragma once

#include <iterator>

template<typename T>
class AIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T current;
    T increase;
    int iter_count = 0;
    T* value;

public:
    AIterator(
        T current,
        T increase,
        int iter_count
    ) : current(current), increase(increase), iter_count(iter_count) {
        value = new T(current);
    };

    ~AIterator() {
        delete value;
    }
    bool operator!=(AIterator const& other) const {
        return this->iter_count != other.iter_count;
    }
    typename AIterator::reference operator*() const {
        return *this->value;
    }
    AIterator& operator++() {
        *value += increase;
        iter_count++;
        return *this;
    }
};

template<typename T>
class Generator : public std::iterator<std::input_iterator_tag, T> {
private:
    T current;
    T increase;
    int step_counter;

public:
    using iterator = AIterator<T>;
    using const_iterator = AIterator<const T>;

    Generator(
        T current,
        T increase,
        int step_counter
    ) : current(current), increase(increase), step_counter(step_counter) {};

    int len() {
        return this->step_counter;
    }

    iterator begin() {
        return iterator(current, increase, 0);
    };
    iterator end() {
        return iterator(current, increase, step_counter);
    };

    const_iterator begin() const {
        return const_iterator(current, increase, 0);
    };
    const_iterator end() const {
        return const_iterator(current, increase, step_counter);
    };
};