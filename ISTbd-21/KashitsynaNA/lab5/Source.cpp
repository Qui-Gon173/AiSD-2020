#include <iostream>
#include <fstream>
using namespace std;

//Сортировка методом простого слияния
void sliyanieSort(char* nazvanie);

int main()
{
	setlocale(LC_ALL, "rus");
	char nazvanie[] = "Array.txt";
	sliyanieSort(nazvanie);
	cout << "Сортировка успешно завершена";
	return 0;
}


void sliyanieSort(char* nazvanie)
{
	int first, second; //Вспомогательные числа
	int k = 1, i, j, size = -1;
	fstream fs;
	fstream fs_first, fs_second; //Вспомогательные файлы
	fs.open(nazvanie, fstream::in);

	while (fs) 
	{
		fs >> first;
		size++; //Количество чисел
	}
	fs.close();

	while (k < size)
	{
		fs.open(nazvanie, fstream::in); //Читаю поток ввода
		fs_first.open("first.txt", fstream::out);
		fs_second.open("second.txt", fstream::out); //Открываю потоки вывода

		if (fs) 
		{  
			fs >> first; //Читаю первое число
		}

		while (fs) //Делю на пары
		{
			for (i = 0; i < k && fs; i++) {
				fs_first << first << " ";
				fs >> first;
			}
			for (j = 0; j < k && fs; j++) {
				fs_second << first << " ";
				fs >> first;
			}
		}
		fs.close();
		fs_first.close();
		fs_second.close(); //Закрываю потоки

		fs.open(nazvanie, fstream::out);
		fs_first.open("first.txt", fstream::in);
		fs_second.open("second.txt", fstream::in);
		if (fs_first) {
			fs_first >> first; //Читаю числа
		}
		if (fs_second) {
			fs_second >> second;
		}

		while (fs_first && fs_second) {
			i = 0;
			j = 0;

			while ((i < k) && (j < k) && (fs_first && fs_second)) { //Обмен элементов
				if (first < second) {
					fs << first << " ";
					fs_first >> first;
					i++;
				}
				else {
					fs << second << " ";
					fs_second >> second;
					j++;
				}
			}

			while (i < k && fs_first) { //Добавляю оставшиеся сортируемые элменты
				fs << first << " ";
				fs_first >> first;
				i++;
			}
			while (j < k && fs_second) {
				fs << second << " ";
				fs_second >> second;
				j++;
			}
		}

		while (fs_first) { //Добавляю оставшиеся неотсортированные элементы
			fs << first << " ";
			fs_first >> first;

		}
		while (fs_second) {
			fs << second << " ";
			fs_second >> second;
		}
		fs_second.close();
		fs_first.close();
		fs.close();
		k *= 2;
	}
}
