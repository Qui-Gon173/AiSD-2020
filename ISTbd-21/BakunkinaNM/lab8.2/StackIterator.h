#include <iterator>
#include "Node.h"

template <typename T>
class StackIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    Node<T>* node;
public:
    StackIterator(const StackIterator& it) : node(it.node) {}
    StackIterator(Node<T>* node) : node(node) {}

    bool operator!=(StackIterator const& other) const {
        return this->node != other.node;
    }

    bool operator==(StackIterator const& other) const {
        return this->node == other.node;
    }

    typename StackIterator::reference operator*() const {
        T value = this->node->get_value();
        T* pvalue = &value;
        return *pvalue;
    }

    StackIterator& operator++() {
        this->node = this->node->get_next();
        return *this;
    }
};
