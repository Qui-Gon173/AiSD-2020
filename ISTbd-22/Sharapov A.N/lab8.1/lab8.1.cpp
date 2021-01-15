#include <iostream>
#include <locale.h>



const size_t ALLOCATED_LENGTH = 32;
const size_t NOT_FOUND_INDEX = -1;
const int RESIZE_COEF = 2;


template<typename T>
class Vector {
    private:
    T* array;
    size_t length = 0;
    size_t allocated_length;
    public:
        Vector(size_t length = ALLOCATED_LENGTH) : allocated_length(length) {
            this->array = new T[length];
        }

        ~Vector() {
            delete[] array;
        }

        T operator[](size_t index) {
            return this->array[index];
        }

        size_t index(T element) {
            for (size_t i = 0; i < this->length; i++) {
                if (this->array[i] == element) {
                    return i;
                }
            }
            return NOT_FOUND_INDEX;
        }

        size_t len() const {
            return this->length;
        }

        void transform_size() {
            if (this->length < this->allocated_length) {
                return;
            }

            this->allocated_length *= RESIZE_COEF;
            T* new_array = new T[allocated_length];
            for (size_t i = 0; i < this->length; i++) {
                new_array[i] = this->array[i];
            }
            delete[] this->array;
            this->array = new_array;
        }

        void append(T element) {
            transform_size();
            this->array[length++] = element;
        }

        void insert(size_t position, T element) {
            transform_size();

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

        void delet(size_t position) {
            if (position >= this->length) {
                    return;
            }

            for (size_t i = position; i < this->length - 2; i++) {
                this->array[i] = this->array[i + 1];
            }
            this->length--;
        }

        void print() {
            std::cout << "[";
            size_t i = 0;
            for (; i < length - 1; i++) {
                std::cout << array[i] << ", ";
            }
            std::cout << array[i] << "]" << std::endl;
        }
};


int main() {

    setlocale(LC_ALL, "Russian");
    Vector<unsigned long>myVector;
    myVector.append(3);
    myVector.append(58);
    myVector.append(1);
    myVector.insert(3, 25);

    myVector.print();

    myVector.delet(3);


    myVector.print();

    std::cout << "Позиция элемента со значением 58: " << myVector.index(58);
    return 0;
}
