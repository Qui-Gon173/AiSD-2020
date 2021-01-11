#pragma once

#include <iterator>

template<typename T>
class ArifmIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T base;
    T step;
    size_t amount = 0;
    T* value;

public:
    ArifmIterator(T base, T step, size_t amount) : base(base), step(step), amount(amount) {
        value = new T(base);
    };

    ~ArifmIterator() {
        delete value;
    }
    bool operator!=(ArifmIterator const& other) const {
        return this->amount != other.amount;
    }
    typename ArifmIterator::reference operator*() const {
        return *this->value;
    }
    ArifmIterator& operator++() {
        *value += step;
        amount++;
        return *this;
    }
};




template<typename T>
class Gen : public std::iterator<std::input_iterator_tag, T> {
private:
    T base;
    T step;
    size_t maxStep;

public:
    using iterator = ArifmIterator<T>;
    using const_iterator = ArifmIterator<const T>;

    Gen(
        T base,
        T step,
        size_t maxStep
    ) : base(base), step(step), maxStep(maxStep) {};

    size_t len() {
        return this->maxStep;
    }

    const_iterator begin() const {
        return const_iterator(base, step, 0);
    };
    const_iterator end() const {
        return const_iterator(base, step, maxStep);
    };

    iterator begin() {
        return iterator(base, step, 0);
    };
    iterator end() {
        return iterator(base, step, maxStep);
    };

   
};