#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int N = 1000; // макс количество чисел

void mergeSort(const std::string&  fileName, int number)
{
	// вспомогательные числа для чтения и записи 
	int helpFirstNumber;
	int helpSecondNumber;

	int currentLengthSeries = 1; // длина текущей серии


	// вспомогательные файлы
	const std::string helpFirstFile = "helpFirstFile";
	const std::string helpSecondFile = "helpSecondFile";
	

	while (currentLengthSeries < number)
	{
		// открываем для чтения главный файл и для записи вспомогательные
		std::ifstream file_r(fileName);
		std::ofstream helpFirstFile_w(helpFirstFile);
		std::ofstream helpSecondFile_w(helpSecondFile);

		// читаем первый элемент
		if (!file_r.eof())
		{
			file_r >> helpFirstNumber ;
		}

		// распределяем серии по двум вспомогательным файлам
		while (!file_r.eof())
		{
			// записываем серию в первый файл
			for (int i = 0; i < currentLengthSeries && !file_r.eof(); i++)
			{
				helpFirstFile_w << helpFirstNumber << " " << " ";
				file_r >> helpFirstNumber;
			}
			// записываем серию в второй файл
			for (int j = 0; j < currentLengthSeries && !file_r.eof(); j++)
			{
				helpSecondFile_w << helpFirstNumber << " " << " ";
				file_r >> helpFirstNumber;
			}
		}

		// закрываем файлы
		file_r.close();
		helpFirstFile_w.close();
		helpSecondFile_w.close();

		// открываем для записи главный файл и для чтения вспомогательные
		std::ofstream file_w(fileName);
		std::ifstream helpFirstFile_r(helpFirstFile);
		std::ifstream helpSecondFile_r(helpSecondFile);

		// читаем первые элементы из каждого файла
		if (!helpFirstFile_r.eof() )
		{
			helpFirstFile_r >> helpFirstNumber;
		}
		if (!helpSecondFile_r.eof())
		{
			helpSecondFile_r >> helpSecondNumber;
		}

		// пока не достигли конца одного из файлов
		while (!helpFirstFile_r.eof() && !helpSecondFile_r.eof())
		{
			// обнуляем счётчики элементов серий 
			int i = 0;
			int j = 0;

			// записываем первые n чисел, сортируя их
			while (i < currentLengthSeries && j < currentLengthSeries && !helpFirstFile_r.eof() && !helpSecondFile_r.eof())
			{
				// сравниваем значения из вспомогательных файлов и записываем наименьший в основной файл
				if (helpFirstNumber < helpSecondNumber)
				{
					file_w << helpFirstNumber << " ";
					helpFirstFile_r >> helpFirstNumber;
					i++;
				}
				else
				{
					file_w << helpSecondNumber << " ";
					helpSecondFile_r >> helpSecondNumber;
					j++;
				}
			}

			// дописываем оставшиеся отсортированные элементы
			while (i < currentLengthSeries && !helpFirstFile_r.eof())
			{
				file_w << helpFirstNumber << " ";
				helpFirstFile_r >> helpFirstNumber;
				i++;
			}

			while (j < currentLengthSeries && !helpSecondFile_r.eof())
			{
				file_w << helpSecondNumber << " ";
				helpSecondFile_r >> helpSecondNumber;
				j++;
			}
		}

		// дописываем оставшиеся неотсортированные элементы
		while (!helpFirstFile_r.eof())
		{
			file_w << helpFirstNumber << " ";
			helpFirstFile_r >> helpFirstNumber;
		}
		while (!helpSecondFile_r.eof())
		{
			file_w << helpSecondNumber << " ";
			helpSecondFile_r >> helpSecondNumber;
		}

		// закрываем файлы
		file_w.close();
		helpFirstFile_r.close();
		helpSecondFile_r.close();

		// увеличиваем серии в два раза 
		currentLengthSeries *= 2;
	}

	// удаляем вспомогательные файлы
	remove(helpFirstFile.c_str());
	remove(helpSecondFile.c_str());
	
}

int main()
{
	string filename = "chisla.txt";
	mergeSort(filename, N);
	return 0;
}