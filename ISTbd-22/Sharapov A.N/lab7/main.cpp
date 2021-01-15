#include <iostream>

void hanoiSolution(int amount, char from, char destination, char buffer)
{
    if (amount != 0)
    {
        hanoiSolution(amount - 1, from, buffer, destination);
        std::cout << from << " -> " << destination << std::endl;
        hanoiSolution(amount - 1, buffer, destination, from);
    }
}

int main()
{
    int amount;
    std::cin >> amount;
    hanoiSolution(amount, '1', '2', '3');

    return 0;
    system("pause");
}