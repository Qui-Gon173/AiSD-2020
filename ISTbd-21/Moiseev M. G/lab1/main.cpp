#include <iostream>

typedef int element_t;

int searchWithBarier(element_t *arr, element_t key, const size_t arrayLength){
    arr = reinterpret_cast<element_t *>(realloc(arr, (arrayLength + 1) * sizeof(element_t)));
    arr[arrayLength] = key;
    size_t i = 0;
    while (arr[i] != key) {
        i++;
    }
    return i < arrayLength ? i : -1;
}

int main(){
    const size_t arrayLength = 10;
    element_t * array = reinterpret_cast<element_t *>(malloc(sizeof(element_t)*arrayLength));
    std::cout << "Input numbers:" << std::endl;
    for (size_t i = 0; i < arrayLength; i++){
        std::cin >> array[i];
    }
    element_t key;
    std::cout << "Input Key: ";
    std::cin >> key;
    std::cout << searchWithBarier(array, key, arrayLength) << std::endl;
}
