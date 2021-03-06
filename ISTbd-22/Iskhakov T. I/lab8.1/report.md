# Отчет по лабораторной работе №8.1 #

### Определение и особенности ###
Очередь – это структура данных, представляющая собой последовательность элементов, образованная в порядке их поступления. Каждый новый элемент размещается в конце очереди; элемент, стоящий в начале очереди, выбирается из нее первым. В очереди используется принцип доступа к элементам FIFO ( First Input – First Output, "первый пришёл – первый вышел") ( рис. 30.2). В очереди доступны два элемента (две позиции): начало очереди и конец очереди. Поместить элемент можно только в конец очереди, а взять элемент только из ее начала.

### Преимущества и недостатки ###

#### Плюсы: ####

- каждая операция выполняется за время O(1).

#### Минусы: ####

- память фрагментируется гораздо сильнее и последовательная итерация по такой очереди может быть ощутимо медленнее, нежели итерация по очереди реализованной на массиве.

### Оценка сложности по добавлению, удалению и поиску элемента в коллекции ###

Операция удаления и дабавления n в коллекцию занимает О(1). Поиск элемента в коллекции выполняется с помощью извлечения 
каждого элемента, пока не будет найден нужный, поэтому в худшем варианте понадобится извлечь все элементы очереди.
То есть в худшем случае поиск элемента в коллекции будет иметь сложность О(N).

### Для чего лучше всего подходит ### 
Очереди часто используются в программах для реализации буфера, в который можно положить элемент для последующей обработки, сохраняя порядок поступления. Например, если база данных поддерживает только одно соединение, можно использовать очередь потоков, которые будут ждать своей очереди на доступ к БД.