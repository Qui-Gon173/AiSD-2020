#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
    T* pStack;                    
    const int num_elements;                   
    int index;                         
    void increased_length();
public:
    Stack(int = 64);                 
    ~Stack();                   

    T delete_element();                   
    const T& search_n_element(int = 1) const; 
    T* getPtr() const;       

    T* extracting_elements(int);
    T sum();
    T max();
    T min();
    T average();

    void add_element(const T&);    
    void print();       
    int getStackLength() const; 
    int getNumElement() const;       
    void add_more_elements(T*, int);        
    void print_top_stack() const;           
    void add_element_from_new_stack(Stack<T>&, int);
    void cls();
};


template <typename T>
Stack<T>::Stack(int maxSize) :
    num_elements(maxSize) 
{
    pStack = new T[num_elements]; 
    index = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] pStack; 
}

template <typename T>
T Stack<T>::sum() {
    T result = 0;
    for (int i = 0; i < this->getNumElement(); i++) {
        result += pStack[i];
    }
    return result;
}

template <typename T>
T Stack<T>::average() {
    return this->getNumElement() ? this->sum() / this->getNumElement() : 0;
}

template <typename T>
T Stack<T>::min() {
    assert(index > 0);
    T min_element = pStack[0];
    for (int i = 0; i < this->getNumElement(); i++) {
        if (min_element > pStack[i]) min_element = pStack[i];
    }
    return min_element;
}

template <typename T>
T Stack<T>::max() {
    assert(index > 0);
    T max_element = pStack[0];
    for (int i = 0; i < this->getNumElement(); i++) {
        if (max_element < pStack[i]) {
            max_element = pStack[i];
        }
    }
    return max_element;
}

template <typename T>
void Stack<T>::cls() {
    this->index = 0;
}

template <typename T>
void Stack<T>::add_element(const T& value)
{
    // проверяем размер стека
    if (index == num_elements) {
        increased_length();
    }
    pStack[index++] = value; 
}

template <typename T>
void Stack<T>::add_more_elements(T* array, int length) {
    for (int i = 0; i < length; i++) {
        add_element(array[i]);
    }
}

template <typename T>
void Stack<T>::increased_length() {
    T* buffer = new T[this->getStackLength() * 2];
    index = this->getNumElement();

    for (int i = 0; i < index; i++)
        pStack[i] = this->getPtr()[i];
    delete[] pStack;
    pStack = buffer;
}

template <typename T>
T* Stack<T>::extracting_elements(int n)
{
    assert(index > n);
    T* array = new T[n - 1];

    for (int i = 0; i < n - 1; i++) {
        array[i] = this->delete_element();
    }
    return array;
}

template <typename T>
void Stack<T>::add_element_from_new_stack(Stack<T>& otherStack, int n)
{
    int otherTop = otherStack.getNumElement();
    assert(n < otherTop);

    for (int i = 0; i < n; i++) {
        this->add_element(otherStack.delete_element());
    }
}

template <class T>
const T& Stack<T>::search_n_element(int num) const
{
    assert(num <= index);

    return pStack[index - num];
}


template <typename T>
int Stack<T>::getStackLength() const
{
    return num_elements;
}

template <typename T>
T* Stack<T>::getPtr() const
{
    return pStack;
}

template <typename T>
int Stack<T>::getNumElement() const
{
    return index;
}

template <typename T>
T Stack<T>::delete_element()
{
    assert(index > 0); 
    return pStack[--index]; 
}