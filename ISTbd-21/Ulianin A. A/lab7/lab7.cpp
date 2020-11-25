#include <iostream>
#include <clocale>

using namespace std;

/// рекурсивная функция hanoy
/// numberDisks - число дисков, которое нужно переместить
/// from - колышек, на котором находятся диски
/// to - колышек, на который нужно переместить
/// through - колышек временного размещения

void hanoy(int numberDisks, int from, int to, int through)
{
    if (numberDisks == 0) return;

    /// перенос numberDisks - 1 элементов на временный колышек
    hanoy(numberDisks - 1, from, through, to); 

    /// перемещение диска на нужный колышек
    cout << from << " => " << to << endl;

    /// перенос с временного колышека 
    hanoy(numberDisks - 1, through, to, from);
}

int main()
{
    setlocale(LC_ALL, "ru");
    int countRings; // кол - во дисков
    
    cout << "Введите количество дисков: ";
    cin >> countRings;
    cout << endl;

    /// необходимо переместить countRings дисков с 1 на 2 колышек, используя 3
    hanoy(countRings, 1, 2, 3);

    return 0;
}