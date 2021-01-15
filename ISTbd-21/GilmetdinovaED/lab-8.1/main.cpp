#include <iostream>
#include <vector>

using namespace std;
template<typename T>
    class Vector
    {
 private:
    T* arr;
    int length;
    int elements = 0;
    public:
        Vector();
         ~Vector();

    int GetIndex(T data);//получение индекса элемента по значению
    unsigned long GetElement(int index);//получение значение по индексу
	void DeleteElement(int index);//удаление элемента в списке по указанному индексу
	void MoreSize();//Увеличение размера массива
	void insert(T data, int index);//добавление элемента в список по указанному индексу
	void push_back(T data);//добавление элемента в конец списка
	void print();// вывод элементов
    void Clear();// очистить список
	int Size(); //количество элементов
	unsigned long summ();//сумма всех элементов
	unsigned long medium();//среднее значение
	unsigned long Min();//минимальный элемент
	unsigned long Max();//максимальный элемент
};

template<typename T>
Vector<T>::Vector()
{
	length = 0;

}

template<typename T>
Vector<T>::~Vector()
{
     delete[] arr;
}

template<typename T>
int Vector<T>::GetIndex(T data)
{
     for (int i = 0; i < elements; i++) {
            if (arr[i] == data) {
                return i;
            }
        }
        return -1;
}

template<typename T>
unsigned long Vector<T>::GetElement(int index)
{
    return arr[index];
}

 template<typename T>
void Vector<T>::DeleteElement(int index)
{
     if (index >= elements) {
            return;
        }

        for (int i = index; i < elements - 1; i++) {
            arr[i] = arr[i + 1];
        }
        elements--;
}

template<typename T>
void Vector<T>:: MoreSize() {
        int length = elements * sizeof(T);

        if (elements * sizeof(T) == length) {
            T* new_arr = new T[elements * 2];
            for (int i = 0; i < elements; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
    }

template<typename T>
void Vector<T>::push_back(T data)
{
    MoreSize();
   arr[elements++] = data;
}

 template<typename T>
void Vector<T>::insert(T data, int index)
{
     MoreSize();
     if (index >= elements) {
            push_back(data);
            return;
        }

        for (int i = elements - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }

        arr[index] = data;
        elements++;
}

template<typename T>
void Vector<T>::print()
{
    for(int i = 0; i < elements; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
}

template<typename T>
void Vector<T>:: Clear()
{
     elements = 0;
}

template<typename T>
int Vector<T>:: Size()
{
    return elements;
}
template<typename T>
unsigned long Vector<T>::summ() {
        T  all = 0;
        for (int i = 0; i < elements; i++) {
            all += arr[i];
        }
        return all;
    }

template<typename T>
unsigned long Vector<T>:: medium() {
        return  summ()/elements;
    }

template<typename T>
unsigned long Vector<T>:: Min() {
        T min_value = 4294967295;
        for (int i = 0; i <elements; i++) {
            if (arr[i] < min_value) {
                min_value = arr[i];
            }
        }
        return min_value;
    }

template<typename T>
unsigned long Vector<T>:: Max() {
         T max_value = 0;
        for (int i = 0; i <=elements; i++) {
            if (arr[i] > max_value) {
                max_value = arr[i];
            }
        }
        return max_value;
    }
int main()
{

   Vector<unsigned long>myVector;
   myVector.push_back(55);
    myVector.push_back(1977);
     myVector.push_back(7);
    myVector.print();

     cout<<"Index of element 7: "<< myVector.GetIndex(7)<<endl;
     cout<<"Element of index 1: "<< myVector.GetElement(1)<<endl;

	myVector.insert(99999, 4);//добавление по индексу

    myVector.DeleteElement(1);//удаление по индексу
    myVector.print();//метод для распечатки

	cout << endl;
	cout <<"Sum: "<< myVector.summ() << endl;
	cout << endl;
	cout << "Medium: " << myVector.medium() << endl;
	cout << endl;
	cout << "Min: " << myVector.Min() << endl;
	cout << endl;
	cout << "Max: " << myVector.Max() << endl;
    cout << endl;

   cout << "Size of array: " << myVector.Size();//размер вектора
   myVector.Clear();

return 0;
}
