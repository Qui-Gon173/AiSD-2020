
#include <iostream>


using namespace std;

int barrier_search(int* mArray, int _size, int find_el) {
    int position = 0;
    if (mArray[_size - 1] != find_el) {
        mArray[_size - 1] = find_el;
        for (; mArray[position] != find_el; position++);
        position++;
    }

    else return _size;

    return position < _size ? position : 0;
}


int main() {

    int ar[] = { 1, 4 , 4, 5, 6, 3, 2, 7 };
    cout << barrier_search(ar, 8, 7) << endl;
    system("pause");
    return 0;
}
