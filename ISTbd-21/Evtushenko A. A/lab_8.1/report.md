# Lab 8.1

## Определение и особенности

Stack - это LIFO-коллекция, в которой доступен только последний добавленный элемент. Чтобы получить доступ к предыдущим, нужно извлечь последний. Аналогична стопке тарелок.

## Преимущества и недостатки

Многое зависит от реализации, но вообще от стека ожиджается быстрое добавление в конец и взятие из конца. Стэк решает свои задачи. Недостатки появляются, если использовать его не по назначению.

## Оценка сложности по добавлению, удалению и поиску элемента в коллекции

| Action | Worst Case |
| ------ | ---------- |
| add    | O(1)       |
| delete | O(1)       |
| find   | O(N)       |

## Для чего лучше всего подходит

Используется для обхода структур данных (дерево, граф и др.).