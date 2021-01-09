#pragma once

#include <iterator>

template<typename T>
class AIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T base;
    T increment;
    size_t iter_count = 0;
    T* value;

public:
    AIterator(
        T base,
        T increment,
        size_t iter_count
    ) : base(base), increment(increment), iter_count(iter_count) {
        value = new T(base);
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
        *value += increment;
        iter_count++;
        return *this;
    }
};

template<typename T>
class Generator : public std::iterator<std::input_iterator_tag, T> {
private:
    T base;
    T increment;
    size_t step_counter;

public:
    using iterator = AIterator<T>;
    using const_iterator = AIterator<const T>;

    Generator(
        T base,
        T increment,
        size_t step_counter
    ) : base(base), increment(increment), step_counter(step_counter) {};

    size_t len() {
        return this->step_counter;
    }

    iterator begin() {
        return iterator(base, increment, 0);
    };
    iterator end() {
        return iterator(base, increment, step_counter);
    };

    const_iterator begin() const {
        return const_iterator(base, increment, 0);
    };
    const_iterator end() const {
        return const_iterator(base, increment, step_counter);
    };
};