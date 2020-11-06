// size_t может принимать любые значения, поэтому буду его использовать

#include <iostream>

template<typename T>
class Vector { // Говорили (аналог vector C++) получили Vector
private:
    T* array;
    size_t length;
    size_t all_elements = 0;
public:
    // Размер массива
    Vector(size_t length = 64) : length(length) { 
        array = new T[length];
    }    

    // Деструктор
    ~Vector() {
        delete[] array;
    }

    // Поиск по индексу массива
    T operator[](size_t index) { 
        return array[index]; // Тупо возвращаем элемент(индекса)
    }

    // Поиск индекса по элементу (находит только первый из всех)
    size_t index(T element) {
        for (size_t i = 0; i < all_elements; i++) {
            if (array[i] == element) {
                return i; // Возвращаем индекс элемента который нашли способом выше (2 строчки линейного поиска)
            }
        }
        return -1; // Если элемента нет, то ты как бы тупой
    }
    
    // Увеличение размера массива
    void append() {
        size_t length = all_elements * sizeof(T);

        if (all_elements * sizeof(T) == length) { // Если кол-во элементов равно массиву, делаем ресайз 
            T* new_array = new T[all_elements * 2]; // Создаём новый массив с размером в 2 раза больше
            for (size_t i = 0; i < all_elements; i++) {
                new_array[i] = array[i];
            }
            delete[] array; // Высвобождаем память на старом массиве
            array = new_array; 
        }
    }

    // Добавление в конец массива
    void supplement(T element) {
        append();
        array[all_elements++] = element; // Добавляем элемент в массив
    }

    // Добавление элемента по позиции
    void insert(size_t position, T element) {
        append();

        if (position >= all_elements) { // Если указана позиция >= чем количество элементов в массиве, то новый элемент запишется в конец. 
            supplement(element);
            return;
        }

        for (size_t i = all_elements - 1; i >= position; i--) {  // Вычисление позиции
            array[i + 1] = array[i];
        }

        array[position] = element;  // Само добавление элемента по позиции
        all_elements++; // Чтобы не съедало последний элемент при добавлении в середину\начало массива
    }

    // Удаление элемента по позиции
    void delete_element(size_t position) {
        if (position >= all_elements) {
            return;
        }

        for (size_t i = position; i < all_elements - 1; i++) {  // тут как бы сдвиг и замена значения(i) на значение(i + 1)
            array[i] = array[i + 1];
        }
        all_elements--; // шоб небыло дублирования последнего элемента
    }

    // Обычный принт из C, ну... может немного получше...
    void print() {       
        for(size_t i = 0; i < all_elements; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};
