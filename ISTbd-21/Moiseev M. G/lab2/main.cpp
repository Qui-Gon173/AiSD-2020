#include <iostream>
#include <algorithm>

typedef int element_t;

int main(){
    const element_t length = 10;
    int array[length];

    std::cout << "Enter " << length << " numbers:" << std::endl;

    for (size_t i = 0; i < length; i++){
        std::cin >> array[i];
    }

    for(size_t i = 1; i < length; i++){
        for(size_t j = i; j>0 && array[j-1] > array[j]; j--)
			std::swap(array[j-1], array[j]);
    } 

    std::cout << "Sorted list: ";

    for (size_t i = 0; i < length; i++){
        std::cout << array[i] << " ";
    }
    std::cout<<std::endl;
}
