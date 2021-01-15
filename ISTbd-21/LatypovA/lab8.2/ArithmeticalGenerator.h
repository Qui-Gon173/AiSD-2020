#pragma once

#include <iterator>


template<typename T>
class ArithmeticalIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T base;
    T increment;
    size_t iter_count = 0;
    T* value;

public:
    ArithmeticalIterator(
        T base,
        T increment,
        size_t iter_count
    ) : base(base), increment(increment), iter_count(iter_count) {
        value = new T(base);
    };

    ~ArithmeticalIterator() {
        delete value;
    }
    bool operator!=(ArithmeticalIterator const& other) const {
        return this->iter_count != other.iter_count;
    }
    typename ArithmeticalIterator::reference operator*() const {
        return *this->value;
    }
    ArithmeticalIterator& operator++() {
        *value += increment;
        iter_count++;
        return *this;
    }
};


template<typename T>
class ArithmeticalGenerator : public std::iterator<std::input_iterator_tag, T> {
private:
    T base;
    T increment;
    size_t max_step_count;

public:
    using iterator = ArithmeticalIterator<T>;
    using const_iterator = ArithmeticalIterator<const T>;

    ArithmeticalGenerator(
        T base,
        T increment,
        size_t max_step_count
    ) : base(base), increment(increment), max_step_count(max_step_count) {
    };

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

    size_t limit() {
        return this->max_step_count;
    }
};
