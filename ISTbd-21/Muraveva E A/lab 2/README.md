# Отчет по 2 лабораторной работе 

## Алгоритм метода пузырька

Этот алгоритм сравнивает с начала массива попарно элементы, и меняет их местами в случае неверного порядка. Алгоритм проходит по массиву, пока он весь не отсортируется.

## Достоинства и недостатки метода пузырька

- достоинстава - лёгок в реализации
- недостатки - квадратичная сложность т. е. для сортировки массива в Н элементов операций надо сделать Н * Н


## Алгоритм шейкер-сортировки

Алгоритм работает как пузырьковая сортировка, но меняет направление сортировки, что позволит элементам попасть на свои места, если они далеко от сортированных.

## Достоинства и недостатки шейкер-сортировки

- достоинства — простая реализация.
- недостатки — медленная работа алгоритма.

## Алгоритм метода перебора

Сначала находит минимальное(максимальное) значение, сравнивает с первым элементов, меняем местами, если он не минимальный. Остальную часть массива сортируется так же, не беря уже отсортированную часть.

## Достоинства и недостатки метода перебора

- достоинства - простая реализация
- недостатки - в большистве случаев уступает в эффективности

## Алгоритм метода вставок

 Алгоритм, в котором элементы массива просматриваются по одному, и каждый последующий элемент размещается в подходящее место среди ранее отсортированных элементов.

## Достоинства и недостатки метода вставок

- достоинства - работает с последовательно поступающими данными, эффективный при работе с небольшими массивами
- недостатки - высокая алгоритмическая сложность