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
    size_t max_step_count;

public:
    using iterator = AIterator<T>;
    using const_iterator = AIterator<const T>;

    Generator(
        T base,
        T increment,
        size_t max_step_count
    ) : base(base), increment(increment), max_step_count(max_step_count) {};

    size_t len() {
        return this->max_step_count;
    }

    iterator begin() {
        return iterator(base, increment, 0);
    };
    iterator end() {
        return iterator(base, increment, max_step_count);
    };

    const_iterator begin() const {
        return const_iterator(base, increment, 0);
    };
    const_iterator end() const {
        return const_iterator(base, increment, max_step_count);
    };
};