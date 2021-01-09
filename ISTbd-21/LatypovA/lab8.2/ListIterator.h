#include <iterator>
#include "Node.h"

template <typename T>
class ListIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    Node<T>* node;
public:
    ListIterator(const ListIterator& it) : node(it.node) {}
    ListIterator(Node<T>* node) : node(node) {}

    bool operator!=(ListIterator const& other) const {
        return this->node != other.node;
    }

    bool operator==(ListIterator const& other) const {
        return this->node == other.node;
    }

    typename ListIterator::reference operator*() const {
        T value = this->node->get_value();
        T* pvalue = &value;
        return *pvalue;
    }

    ListIterator& operator++() {
        this->node = this->node->get_next();
        return *this;
    }
};
