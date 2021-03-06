# Отчет по 7 лабораторной работе

## Что такое Ханойская башня?

Это задача, в которой нужно перенести кольца, расположенные на одном из 3 стержнея по возрастанию, на другой стержень, используя промежуточный стержень. Правила: можно за ход перенести только одно кольцо, при этом нельзя ставить кольца по убыванию.

## Рекурсивное решение 

1. Сначала надо перенести башню из n-1 дисков с первого стержня на вспомогательный.
2. Оставшийся диск перенести на конечный стержень.
3. Перенесем башню из n-1 дисков на конечный.

Потом с помощью этого алгоритма сделать то же самое, только перемещаем m-2 дисков.

## «Треугольное» решение

Нужно поставить колышки на вершинах треугольника.
Начиная с маленького, перекладываем его на любой колышек(потом переносим его в том же направлении). Перенесем другие кольца, потом снова самое маленькое.

## Циклическое решение 

1. Действие ,когда мы перекладываем кольцо с 1->2 или со 2->1(где он меньше), обозначаем как 1-2.
2. Решая говоломку с четным кол-вом дисков, надо повторять действия: 1-2, 1-3, 2-3. С нечетным - 1-3, 1-2, 2-3.

## Применение кода Грея

1. Код Грея (длина=кол-во дисков) сначала стостоит из нулей, надо пройти по всем 0.
2. Каждому биту сопоставим диск. (маленький диск-маленький бит). Изменение бита = перемещение диска.
3. Для нечетной последовательности: начальный->финальный->промежуточный->начальный->финальный->промежуточный...
Для четной: начальный->дополнительный->финальный->начальный->дополнительный->финальный.
