#include "Stack.h"
#include "Func.h"
#include "ArithmeticalGenerator.h"


int main() {
    ArithmeticalGenerator<double> gen(0, 2, 100);
    Stack<double> stack(gen);
    std::cout << "After adding: " << sum(stack) << std::endl;
    printStack(stack);
    std::cout << "Minimum number: " << min(stack)
        << ", Maximum number: " << max(stack)
        << ", Sum of numbers: " << sum(stack)
        << ", Average number: " << average(stack)
        << std::endl;
    std::cout << std::endl;

}