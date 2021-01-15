#include <iterator>
#include <cstdlib>

typedef unsigned char byte_t;


class GeneratorInterator : public std::iterator<std::input_iterator_tag, byte_t> {
private:
    size_t iter_count;
    byte_t n;

public:
    GeneratorInterator(
        size_t iter_count
    ) : iter_count(iter_count) {
    }

    bool operator!=(GeneratorInterator const& other) const {
        return this->iter_count != other.iter_count;
    }

    bool operator==(GeneratorInterator const& other) const {
        return this->iter_count == other.iter_count;
    }
    typename GeneratorInterator::reference operator*() const {
        static byte_t value = 3;
        static size_t a = value;
        for (int i = 0; i < 10; i++) {
            value *= a;
            byte_t* pvalue = &value;
            return *pvalue;
        }
    }

    GeneratorInterator& operator++() {
        this->iter_count++;
        return *this;
    }
};


class ExponentialFunctionGenerator {
private:
    size_t n;
public:
    using iterator = GeneratorInterator;
    using const_iterator = GeneratorInterator;

    ExponentialFunctionGenerator(size_t n) : n(n) {}

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