#include <iostream>
#include <limits>


const size_t DEFAULT_ALLOCATED_LENGTH = 32;
const size_t NOT_FOUND_INDEX = -1;
const int RESIZE_COEFFICIENT = 2;


template<typename T>
class Vector {
private:
    T* array;
    size_t length = 0;
    size_t allocated_length;

    void manage_size() {
        // alloc memory for new elements

        if (this->length < this->allocated_length) {
            return;
        }

        this->allocated_length *= RESIZE_COEFFICIENT;
        T* new_array = new T[allocated_length];
        for (size_t i = 0; i < this->length; i++) {
            new_array[i] = this->array[i];
        }
        delete[] this->array;
        this->array = new_array;
    }
public:
    Vector(size_t length = DEFAULT_ALLOCATED_LENGTH) : allocated_length(length) {
        this->array = new T[length];
    }

    ~Vector() {
        delete[] array;
    }

    T operator[](size_t index) {
        return this->array[index];
    }

    size_t len() const {
        return this->length;
    }

    size_t index(T element) {
        for (size_t i = 0; i < this->length; i++) {
            if (this->array[i] == element) {
                return i;
            }
        }
        return NOT_FOUND_INDEX;
    }

    void append(T element) {
        this->manage_size();
        this->array[length++] = element;
    }

    void insert(size_t position, T element) {
        this->manage_size();

        if (position >= this->length) {
            this->append(element);
            return;
        }

        for (size_t i = length - 1; i >= position; i--) {
            this->array[i + 1] = this->array[i];
        }

        this->array[position] = element;
        this->length++;
    }

    void del(size_t position) {
        if (position >= this->length) {
            return;
        }

        for (size_t i = position; i < this->length - 1; i++) {
            this->array[i] = this->array[i + 1];
        }
        this->length--;
    }

    void repr() {
        // python-like repr for Vector

        std::cout << "[";
        size_t i = 0;
        for (; i < length - 1; i++) {
            std::cout << array[i] << ", ";
        }
        std::cout << array[i] << "]" << std::endl;
    }

    void clear() {
        // awesome O(1) clear...
        this->length = 0;
    }

    T get_sum() {
        T counter = 0;
        for (size_t i = 0; i < this->length; i++) {
            counter += this->array[i];
        }
        return counter;
    }

    T get_average() {
        // C++ != JS
        return this->length ? this->get_sum() / this->length : 0;
    }

    T get_min() {
        T min_value = std::numeric_limits<T>::max();
        for (size_t i = 0; i < this->length; i++) {
            if (array[i] < min_value) {
                min_value = array[i];
            }
        }
        return min_value;
    }

    T get_max() {
        T max_value = std::numeric_limits<T>::lowest();
        for (size_t i = 0; i < this->length; i++) {
            if (array[i] > max_value) {
                max_value = array[i];
            }
        }
        return max_value;
    }
};
