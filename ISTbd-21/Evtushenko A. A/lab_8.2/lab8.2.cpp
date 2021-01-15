#include <iostream>
#include "mycode.h"
using namespace std;

int main() {
    Generator<double> gen(0, 2, 100);
    Stack<double> stack(gen);
    std::cout << "[STACK]: " << sum(stack) << std::endl;
    print(stack);

    cout << endl;
    cout << "[MIN]: " << min(stack) << endl;
    cout << "[MAX]: " << max(stack) << endl;
    cout << "[SUM]: " << sum(stack) << endl;
    cout << "[AVERAGE]: " << average(stack) << endl;
    cout << endl;

    return 0;
}