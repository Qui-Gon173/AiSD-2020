#include "Stack.h"


int main() {
    Stack<double> stack;
    double a[6] = { 10, 20, 30, 80, 23, 29 };
    stack.pushSev(a, sizeof(a) / sizeof(*a));
    stack.push(20);
    std::cout << "After adding: " << std::endl;
    stack.printStack();
    std::cout << "Sum: " << stack.sum() << " Average: " << stack.average() << " Min: " << stack.min() << " Max: " << stack.max() << std::endl;
    double* arr = new double[2];
    arr = stack.popSev(3);
    std::cout << "After extraction:" << std::endl;
    std::cout << "Extracted:" << std::endl;
    for (size_t i = 0; i < 2; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Left in stack:" << std::endl;
    stack.printStack();
    Stack<double> stack2;
    stack2.pushFromDifStack(stack, 2);
    std::cout << "After moving from stack to stack 2 elements(2 stack):" << std::endl;
    stack2.printStack();
    std::cout << "Initial stack:" << std::endl;
    stack.printStack();


}