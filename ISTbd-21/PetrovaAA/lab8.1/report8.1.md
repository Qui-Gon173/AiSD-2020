# Отчет по лабораторной работе №8.1
**Определение и особенности**  
Двусвязный список — это список, который основан на односвязном, только адресных полей в нём два. Каждый узел двунаправленного (двусвязного) линейного списка (ДЛС) содержит два поля указателей — на следующий и на предыдущий узлы. Указатель на предыдущий узел корня списка содержит нулевое значение. Указатель на следующий узел последнего узла также содержит нулевое значение.

**Преимущества**   
+ *Перемещение по списку возможно в обоих направлениях.* Это упрощает работу со списком, в частности, вставку и удаление. 
+ *Пользователь может просматривать список в любом направлении.* Еще одно преимущество имеет значение только при некоторых сбоях. Поскольку весь список можно пройти не только по прямым, но и по обратным ссылкам, то в случае, если какая-то из ссылок станет неверной, целостность списка можно восстановить по другой ссылке.

**Недостатки**   
+ *Использование бОльших объемов памяти.* (два поля указателей) 
+ *Более трудоёмкие манипуляции с объектами в списке.* (бОльшие объемы памяти подлежат изменению)

**Оценка сложности по добавлению, удалению и поиску элемента в коллекции**

Сложность добавления и удаления - O(1).  
Сложность поиска в худшем случае (при переборе всех элементов) - O(N).

**Для чего лучше всего подходит**
+ для записи и хранения часто изменяемых данных
+ для данных заранее неизвестного объема

