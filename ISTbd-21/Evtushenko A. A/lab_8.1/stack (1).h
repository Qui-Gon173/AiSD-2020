#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
    T* pStack;                      // указатель на стек
    const int num_elements;                   // максимальное количество элементов в стеке
    int index;                          // номер текущего элемента стека
    void increased_length();
public:
    Stack(int = 64);                  // по умолчанию размер стека равен 10 элементам
    ~Stack();                         // деструктор

    T delete_element();                   // удалить элемент из вершины стека
    const T& search_n_element(int = 1) const; // n-й элемент от вершины стека
    T* getPtr() const;         // получить указатель на стек

    T* extracting_elements(int);
    T sum();
    T max();
    T min();
    T average();

    void add_element(const T&);     // поместить элемент в вершину стека
    void print();         // вывод стека на экран
    int getStackLength() const;  // получить размер стека
    int getNumElement() const;        // получить номер текущего элемента в стеке
    void add_more_elements(T*, int);         //Вставка несколькиз значений
    void print_top_stack() const;            // Вывод вершины
    void add_element_from_new_stack(Stack<T>&, int); // Функция вставки в новый экземпляр значений из другого стека
    void cls();
};
// реализация методов шаблона класса Stack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
    num_elements(maxSize) // инициализация константы
{
    pStack = new T[num_elements]; // выделить память под стек
    index = 0; // инициализируем текущий элемент нулем;
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
    delete[] pStack; // удаляем стек
}

// ===============================================================

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
// =========================================================

template <typename T>
void Stack<T>::cls() {
    this->index = 0;
}

// функция добавления элемента в стек
template <typename T>
void Stack<T>::add_element(const T& value)
{
    // проверяем размер стека
    if (index == num_elements) {
        increased_length();
    }
    pStack[index++] = value; // помещаем элемент в стек
}

//Вставка несколькиз значений
template <typename T>
void Stack<T>::add_more_elements(T* array, int length) {
    for (int i = 0; i < length; i++) {
        add_element(array[i]);
    }
}

// Увеличение размера стека
template <typename T>
void Stack<T>::increased_length() {
    T* buffer = new T[this->getStackLength() * 2];
    index = this->getNumElement();

    for (int i = 0; i < index; i++)
        pStack[i] = this->getPtr()[i];
    delete[] pStack;
    pStack = buffer;
}

// функция извлечения n элементов
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

// Функция вставки в новый экземпляр значений из другого стека
template <typename T>
void Stack<T>::add_element_from_new_stack(Stack<T>& otherStack, int n)
{
    int otherTop = otherStack.getNumElement();
    assert(n < otherTop);

    for (int i = 0; i < n; i++) {
        this->add_element(otherStack.delete_element());
    }
}

// функция возвращает n-й элемент от вершины стека
template <class T>
const T& Stack<T>::search_n_element(int num) const
{
    // Проверка
    assert(num <= index);

    return pStack[index - num]; // вернуть n-й элемент стека
}

// вернуть размер стека
template <typename T>
int Stack<T>::getStackLength() const
{
    return num_elements;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
T* Stack<T>::getPtr() const
{
    return pStack;
}

// вернуть размер стека
template <typename T>
int Stack<T>::getNumElement() const
{
    return index;
}

// функция удаления элемента из стека
template <typename T>
T Stack<T>::delete_element()
{
    // проверяем размер стека
    assert(index > 0); // номер текущего элемента должен быть больше 0

    return pStack[--index]; // удаляем элемент из стека
}