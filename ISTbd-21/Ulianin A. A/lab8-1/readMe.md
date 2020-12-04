# Отчет по лабораторной работе № 8.1

Варианты: по типу списка - 4 вариант, по типу данных списка - 1 вариант. Односвязный линейный список типа byte.

### Определение и особенности односвязного списка

Однонаправленный (односвязный) список – это структура данных, которая представляет из себя последовательность элементов, в каждом из которых хранится значение и указатель на следующий элемент списка. В последнем элементе указатель на следующий элемент равен NULL. 

### Преимущества и недостатки односвязного списка

Преимущества:

- удалить или добавить элемент возможно очень быстро и без проблем;
- существует возможность динамического удаления и прибавлеия компонентов.

Недостатки:

- список нельзя индексировать в качестве массива;
- узлы в списке не размещаются последовательно в памяти и программа работает немного медленнее.

### Оценка сложности по добавлению, удалению и поиску элемента в коллекции

Оценка сложности по добавлению, удалению и поиску: О(n).

### Для чего лучше всего подходит

Односвязный список лучше всего подходит для хранения данных, которые могут меняться.