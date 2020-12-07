#pragma once
#include <iterator>

template <typename T>
class VectorIter : public std::iterator<std::input_iterator_tag, T> {
private:
    T* ptr;
public:
    VectorIter(const VectorIter& it) : ptr(it.ptr) {} // Конструктор const
    VectorIter(T* ptr) : ptr(ptr) {} // Конструктор

// Перегрузка операторов

    // Бинарный оператор сравнения
    bool operator==(VectorIter const& other) const {
        return ptr == other.ptr;
    }

    // Бинарный оператор неравенства
    bool operator!=(VectorIter const& other) const {
        return ptr != other.ptr;
    }

    // Унарный оператор разыменования
    typename VectorIter::reference operator*() const {
        return *ptr;
    }

    // Унарный оператор инкремент
    VectorIter& operator++() {
        ++ptr;
        return *this;
    }
};