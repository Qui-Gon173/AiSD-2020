#include <iostream>
#include "print.h"
using namespace std;

int main() {
    cout << "============================== START ==============================" << endl;
    Stack<double> stack;
    double a[6] = { 22, 43, 1, 4, 94, 15 };
    stack.add_more_elements(a, sizeof(a) / sizeof(*a));
    cout << "[SOURCE]: ";
    stack.print();

    stack.add_element(322);
    cout << "[NOW]: ";
    stack.print();

    cout << "============================== DATA ===============================" << endl;
    cout << "[SUM]: " << stack.sum() << endl;
    cout << "[AVERAGE VALUE]: " << stack.average() << endl;
    cout << "[MIN]: " << stack.min() << endl;
    cout << "[MAX]: " << stack.max() << endl;

    cout << "===================================================================" << endl;

    double* arr = new double[2];
    arr = stack.extracting_elements(5);
    cout << "[SYSTEM]: extraction ... " << endl;
    cout << "[EXTRACTED]: ";
    for (int i = 0; i < 2; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "[LEFT STACK]: ";
    stack.print();

    Stack<double> stack2;
    stack2.add_element_from_new_stack(stack, 2);
    cout << "[NEW STACK]: ";
    stack2.print();

    cout << "[ORIGINAL STACK]: ";
    stack.print();


}