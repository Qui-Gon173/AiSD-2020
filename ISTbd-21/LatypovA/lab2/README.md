# Lab2 Report

## Алгоритм метода пузырька

Простой алгоритм сортировки. Для понимания и реализации этот алгоритм — простейший, но эффективен он лишь для небольших массивов. Сложность алгоритма: O(N^2).  

#### +

- Простой

#### -

- Низкая эффективность

### Сортировка перемешиванием

Границы рабочей части массива (то есть части массива, где происходит движение) устанавливаются в месте последнего обмена на каждой итерации. Массив просматривается поочередно справа налево и слева направо.

#### +

- Быстрее пузырька

#### -

- Не так прост, как пузырек

### Сортировка выбором

Поиск минимального и перемещение его на i-ю позицию.

#### +

- Значительно быстрее пузырька, т.к. нет "всплывания"

#### -

- O(N^2)

### Алгоритм метода вставок

На каждом шаге алгоритма выбирается один из элементов входных данных и помещается на нужную позицию в уже отсортированной последовательности до тех пор, пока набор входных данных не будет исчерпан.

#### +

- Хорошо работает для почти отсортированных множеств

#### -

- Вставка не так уж эффективна
