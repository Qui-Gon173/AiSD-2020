# Лабораторная №7

### Что такое Ханойская башня?

Ханойская башня - это головолмка, условия которой такие:
- даны три (возможно и больше) башни
- одна из них заполнена дисками разного диаметра от большего к меньшему
- задача - переложить все диски с одноого стержня на другой за минимальное количество действий
- перекладывать можно только по одному диску
- причём можно класть только меньший диск на больший

### Рекурсивное решение

Рекурсивное решение состоит в следующем:
чтобы перенести N башен на нужный стержень, нужно сначала рекурсивно(то есть повторяя два следующих шага и этот) перенести N-1 диск на свободный стержень, потом перенести самый большой - последний диск на нужный стержень, после чего перенести рекурсивно(то есть повторяя два прошлых шага и этот) N-1 диск на нужный стержень

### «Треугольное» решение

Нужно расположить стержни в виде треугольника. Затем перемещаем самый маленький диск на какой-либо штырь. Запоминаем направление перемещения и всегда перемещаем данный диск в этом же направлении. Перекладываем следющее кольцо, запоминаем направление, и повторяем эти действия над всеми дисками, пока пирамида не будет собрана.

### Циклическое решение

Циклическое решение зависит от количество дисков.

Если количество дисков чётное повторяем следущие действия:
1. перенести с 1 на 3 (если на 1 диск меньше, чем на 3) либо с 3 на 1 (если на 3 диск меньше, чем на 1) - это условие относится ко всем перемещениям
2. с 1 на 2 или с 2 на 1
3. с 2 на 3 или с 3 на 2

Если нечётное:

1. с 1 на 2 или с 2 на 1
2. с 1 на 3 или с 3 на 1
3. с 2 на 3 или с 3 на 2

### Применение кода Грея для решения
Пронумеруем каждый диск с помощью кода Грея, начиная с самого маленького, давая ему код, состоящий из всех нулей. Последущие диски (идём от меньшего к большему) нумеруем, прибавляя к коду 1 бит. Получается, что каждому диску соответствует уникальный i-ый бит. Перемещение i-го диска равняется изменению i-го бита. Заметим, что все диски, кроме наименьшего, совершают одинаковый ход - перекладываются на свободый стержень на каждом шаге. Задачу можно решить, выбрав верную стратегию ходов для наименьшего диска. 

Если количество дисков чётное, то перемещаем в следущей последовательности:
 1 -> 2 -> 3 -> 1 -> 2 -> 3 -> 1 -> 2 -> 3 и т.д.,
 
 где 1 - начальный стержень, 2 - финальный (на котором должна оказаться пирамида в конце), 3 - свободный

если нечётное то в такой:
 1 -> 3 -> 2 -> 1 -> 3 -> 2 -> 1 -> 3 -> 2 и т.д.