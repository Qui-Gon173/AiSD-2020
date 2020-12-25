# Отчет по лабораторной работе №4 #

## Бинарное сортирующее дерево ##
Сортирующее дерево — такое двоичное дерево, для которого выполнены три условия:

- Значение в любой вершине не меньше, чем значения её потомков.
- Глубина всех листьев (расстояние до корня) отличается не более чем на 1 слой.
- Последний слой заполняется слева направо без «дырок».
  
## Пирамидальный алгоритм сортировки ##

Метод пирамидальной сортировки, изобретенный Д. Уилльямсом, является улучшением традиционных сортировок с помощью дерева. 
Общая идея пирамидальной сортировки заключается в том, что сначала строится пирамида из элементов исходного массива, а затем осуществляется сортировка элементов.

Выполнение алгоритма разбивается на два этапа.

### Построение пирамиды. ###
Определяем правую часть дерева, начиная с n/2-1 (нижний уровень дерева). Берем элемент левее этой части массива и просеиваем его сквозь пирамиду по пути, где находятся меньшие его элементы, которые одновременно поднимаются вверх; из двух возможных путей выбираете путь через меньший элемент.

### Сортировка на построенной пирамиде. ### 
Берем последний элемент массива в качестве текущего. Меняем верхний (наименьший) элемент массива и текущий местами. Текущий элемент (он теперь верхний) просеиваем сквозь n-1 элементную пирамиду. Затем берем предпоследний элемент и т.д. Продолжаем процесс. В итоге массив будет отсортирован по убыванию.

### В чем разница устойчивой и неустойчивой сортировки? ###
При неустойчивой сортировке теряется порядок элементов, имеющих одинаковые ключи, этим страдают сортировки пирамидой и методом Хоара. При устойчивой сортировке относительный порядок элементов с одинаковыми ключами сохраняется.

Достоинства
- Пирамидальная сортировка не использует дополнительной памяти
- Является одной из самых эффективных

Недостатки
- Сложен в реализации
- На почти отсортированных данных работает столь же долго, как и на хаотических данных.
- Метод не является устойчивым