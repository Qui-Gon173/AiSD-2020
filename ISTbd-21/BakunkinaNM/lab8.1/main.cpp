#include <iostream>
#include "Stack.h"

using namespace std;


int main() {
    Stack<long> stack;
    stack.append(1);
    stack.append(2);
    stack.append(6);
    stack.print();

    long arr1[4] = { 10, 20, 30, 40 };
    stack.extend(arr1, 4);

    cout << "stack.top(): " << stack.top() << endl;
    cout << "stack.pop(): " << stack.pop() << endl;
    cout << "stack.top(): " << stack.top() << endl;
    stack.print();

    cout << "stack.pop_many(3): ";
    long* arr2 = stack.pop_many(3);
    cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << endl;
    delete[] arr2;

    stack.extend(arr1, 4);
    Stack<long> new_stack(stack, 5);
    stack.clear();
    cout << "new_stack:" << endl;
    new_stack.print();
    cout << "(should be empty) old:" << endl;
    stack.print();

    cout << "new_stack.length(): " << new_stack.length() << endl;
    cout << "new_stack.sum(): " << new_stack.sum() << endl;
    cout << "new_stack.average(): " << new_stack.average() << endl;
    cout << "new_stack.min(): " << new_stack.min() << endl;
    cout << "new_stack.max(): " << new_stack.max() << endl;

    try {
        cout << "stack.top(): " << stack.top() << endl;
    } catch (out_of_range e) {
        cout << e.what() << endl;
    }

    return 0;
}
