#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int N = 5000; // макс количество чисел

void mergeSort(const std::string&  fileName, int number)
{
	// вспомогательные числа для чтения и записи 
	int helpFirstNumber;
	int helpSecondNumber;

	int currentSize = 1; // длина текущей серии


	// вспомогательные файлы
	const std::string helpFirstFile = "helpFirstFile";
	const std::string helpSecondFile = "helpSecondFile";


	while (currentSize < number)
	{
		// открываем для чтения главный файл и для записи вспомогательные
		std::ifstream mainFile_r(fileName);
		std::ofstream helpFirstFile_w(helpFirstFile);
		std::ofstream helpSecondFile_w(helpSecondFile);

		// читаем первый элемент
		if (!mainFile_r.eof())
		{
			mainFile_r >> helpFirstNumber;
		}

		// распределяем серии по двум вспомогательным файлам
		while (!mainFile_r.eof())
		{
			// записываем серию в первый файл
			for (int i = 0; i < currentSize && !mainFile_r.eof(); i++)
			{
				helpFirstFile_w << helpFirstNumber << " " << " ";
				mainFile_r >> helpFirstNumber;
			}
			// записываем серию в второй файл
			for (int j = 0; j < currentSize && !mainFile_r.eof(); j++)
			{
				helpSecondFile_w << helpFirstNumber << " " << " ";
				mainFile_r >> helpFirstNumber;
			}
		}

		// закрываем файлы
		mainFile_r.close();
		helpFirstFile_w.close();
		helpSecondFile_w.close();

		// открываем для записи главный файл и для чтения вспомогательные
		std::ofstream mainFile_w(fileName);
		std::ifstream helpFirstFile_r(helpFirstFile);
		std::ifstream helpSecondFile_r(helpSecondFile);

		// читаем первые элементы из каждого файла
		if (!helpFirstFile_r.eof())
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
			while (i < currentSize && j < currentSize && !helpFirstFile_r.eof() && !helpSecondFile_r.eof())
			{
				// сравниваем значения из вспомогательных файлов и записываем наименьший в основной файл
				if (helpFirstNumber < helpSecondNumber)
				{
					mainFile_w << helpFirstNumber << " ";
					helpFirstFile_r >> helpFirstNumber;
					i++;
				}
				else
				{
					mainFile_w << helpSecondNumber << " ";
					helpSecondFile_r >> helpSecondNumber;
					j++;
				}
			}

			// дописываем оставшиеся отсортированные элементы
			while (i < currentSize && !helpFirstFile_r.eof())
			{
				mainFile_w << helpFirstNumber << " ";
				helpFirstFile_r >> helpFirstNumber;
				i++;
			}

			while (j < currentSize && !helpSecondFile_r.eof())
			{
				mainFile_w << helpSecondNumber << " ";
				helpSecondFile_r >> helpSecondNumber;
				j++;
			}
		}

		/// дописываем оставшиеся неотсортированные элементы
		while (!helpFirstFile_r.eof())
		{
			mainFile_w << helpFirstNumber << " ";
			helpFirstFile_r >> helpFirstNumber;
		}
		while (!helpSecondFile_r.eof())
		{
			mainFile_w << helpSecondNumber << " ";
			helpSecondFile_r >> helpSecondNumber;
		}

		/// закрываем файлы
		mainFile_w.close();
		helpFirstFile_r.close();
		helpSecondFile_r.close();

		/// увеличиваем серии в два раза 
		currentSize *= 2;
	}

	/// удаляем вспомогательные файлы
	remove(helpFirstFile.c_str());
	remove(helpSecondFile.c_str());

}

int main()
{
	setlocale(LC_ALL,"Russian");
	string filename = "sort.txt";
	
	mergeSort(filename, N);
	std::cout << "Успешно!"<<std::endl;
	return 0;
}