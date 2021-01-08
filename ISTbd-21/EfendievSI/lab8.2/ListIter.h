#pragma once

#include <iterator>
#include "Node.h"

class ListIterator : public std::iterator<std::input_iterator_tag, unsigned int> {
private:
    int index;
    Node* node;

public:
    ListIterator(const ListIterator& it) : index(it.index), node(it.node) {}
    ListIterator(int index, Node* node) : node(node), index(index) {}

    bool operator!=(ListIterator const& other) const {
        return this->index != other.index;
    }

    bool operator==(ListIterator const& other) const {
        return this->index == other.index;
    }

    typename ListIterator::reference operator*() const {
        unsigned int* pval = &this->node->data;
        return *pval;
    }

    ListIterator& operator++() {
        this->node = this->node->pNext;
        this->index++;
        return *this;
    }
};