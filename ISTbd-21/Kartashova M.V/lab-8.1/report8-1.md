# Отчет по лабораторной работе №8.1
### Определение и особенности односвязного списка
Двусвязный список - это структура данных, которая состоит из узлов, которые хранят полезные данные, указатели на предыдущий узел и следующий узел.

Особенность двусвязного списка, что каждый элемент имеет две ссылки: на следующий и на предыдущий элемент, позволяет двигаться как в его конец, так и в начало.
### Преимущества и недостатки
(+) Операции добавления и удаления здесь наиболее эффективны, чем в односвязном списке, поскольку всегда известны адреса тех элементов списка, указатели которых направлены на изменяемый элемент.

Возможность двигаться как вперед, так и назад полезна для выполнения некоторых операций.

(-) Добавление и удаление элемента в двусвязном списке, требует изменения большого количества ссылок, чем этого потребовал бы односвязный список.

Дополнительные указатели требуют задействования большего количества памяти, чем таковой необходимо в односвязном списке.
### Оценка сложности по добавлению, удалению и поиску элемента в коллекции
При добавление и удалении двусвязный список имеет сложность O(1).

Поиск эл-а осуществляется путём извлечения всех эл-ов, которые предшествуют нужному. В худшем случае нам нужно извлечь все эл-ты. Операция извлечения занимает О(1), всего эл-ов N, поэтому операция поиска в худшем случае имеет сложность О(N).

### Для чего лучше всего подходит
Двусвязный список лучше всего применять для хранения данных, которые будут часто изменяться. Также из-за динамической природы его можно применять, когда заранее неизвестно количество данных. Списки не привязаны к определенному фрагменту памяти так жестко, как к примеру массивы.