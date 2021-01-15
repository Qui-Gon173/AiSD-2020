#include <iterator>
#include <cstdlib>

typedef unsigned char byte_t;


class RandomIterator : public std::iterator<std::input_iterator_tag, byte_t> {
private:
    size_t iter_count;

public:
    RandomIterator(
        size_t iter_count
    ) : iter_count(iter_count) {    
}

    bool operator!=(RandomIterator const& other) const {
        return this->iter_count != other.iter_count;
    }

    bool operator==(RandomIterator const& other) const {
        return this->iter_count == other.iter_count;
    }

    typename RandomIterator::reference operator*() const {
        byte_t value = rand() % 0x100;
        byte_t* pvalue = &value;
        return *pvalue;
    }

    RandomIterator& operator++() {
        this->iter_count++;
        return *this;
    }
};


class RandomGenerator {
private:
    size_t n;
public:
    using iterator = RandomIterator;
    using const_iterator = RandomIterator;

    RandomGenerator(size_t n) : n(n) {}

    iterator begin() {
        return iterator(0);
    }

    iterator end() {
        return iterator(n);
    }

    const_iterator cbegin() const {
        return iterator(0);
    }

    const_iterator cend() const {
        return iterator(n);
    }
};
