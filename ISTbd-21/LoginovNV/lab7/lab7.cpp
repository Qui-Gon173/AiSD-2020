#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

void hanoj(int N, char fromTower, char toTower, char freeTower)
{
    if (N!=0)
    {
        //чтобы перенести N колец с одного стержня на другой
        //надо n-1 перенести с него на свободный 
        //т.е. с fromTower на freeTower с помощью toTower
        hanoj(N - 1, fromTower, freeTower, toTower);
        //перенести последнее N-ое кольцо на нужный стержень 
        //это и делаем:
        std::cout << "с " << fromTower << " на " << toTower << std::endl;
        //после нужно перенести N-1 кольцо со свободного на нужное
        //т.е. с freeTower на toTower с помощью fromTower
        hanoj(N - 1, freeTower, toTower, fromTower);
    }
}

int main() 
{
    setlocale(LC_ALL, "Rus");

    int countRings;
    std::cout << "Ханойские башни" << std::endl;
    std::cout << "3 башни - A, B, C" << std::endl;
    std::cout << "Перекладываем с левой A на центральную B с помощью правой C" << std::endl;
    std::cout << "Введите количество колец:";
    std::cin >> countRings;
    std::cout << std::endl << "Перемещаем:" << std::endl;
    hanoj(countRings, 'A', 'B', 'C');
    std::cout << "\nЦенок" << std::endl;
    system("pause");
    return 0;
}



