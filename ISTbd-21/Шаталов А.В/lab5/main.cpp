#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


void mergeSort(const std::string& filename, size_t non) {
    const std::string firstHelpFilename = "firstHFile"; //Первый вспомогательный файл
    const std::string secondHelpFilename = "secondHFile"; //Второй вспомогательный файл

    int helpNumber1;
    int helpNumber2;
    //Вспомогательные числа для чтения и записи элементов

    size_t k = 1;
    while (k < non) {
        std::ifstream givenFileRead(filename);
        std::ofstream helpFile1Write(firstHelpFilename);
        std::ofstream helpFile2Write(secondHelpFilename);
        //Создание потоков ввода из данного нам файла и потоков вывода в вспомогательные файлов

        if (!givenFileRead.eof()) { //Если не конец файла чтение 1 элемента
            givenFileRead >> helpNumber1;
        }
        while (!givenFileRead.eof()) { // Чтение k*2 элементов из оригинального файла и запись в вспомогательные файлы
            for (int i = 0; i < k && !givenFileRead.eof(); i++) {
                helpFile1Write << helpNumber1 << " " << " ";
                givenFileRead >> helpNumber1;
            }
            for (int j = 0; j < k && !givenFileRead.eof(); j++) {
                helpFile2Write << helpNumber1 << " " << " ";
                givenFileRead >> helpNumber1;
            }
        }
        givenFileRead.close();
        helpFile1Write.close();
        helpFile2Write.close();
        //Закрытие потоков

        std::ofstream givenFileWrite(filename); //Открытие потоков наоборот данный файл в потоке записи
        std::ifstream helpFile1Read(firstHelpFilename); //Вспомогательные файлы в потоке чтения
        std::ifstream helpFile2Read(secondHelpFilename);

        if (!helpFile1Read.eof()) { // если файлы не пустые читаем 1 числа из вспомогательных файлов
            helpFile1Read >> helpNumber1;
        }
        if (!helpFile2Read.eof()) {
            helpFile2Read >> helpNumber2;
        }

        while (!helpFile1Read.eof() && !helpFile2Read.eof()) {
            int i = 0;
            int j = 0;
            while (i < k && j < k && !helpFile1Read.eof() && !helpFile2Read.eof())
            {
                if (helpNumber1 < helpNumber2) //Процесс сортровки: сравнение значений из 2 вспомогательных файлов
                {
                    givenFileWrite << helpNumber1 << " "; //Запись меньшего в основной файл
                    helpFile1Read >> helpNumber1; //Чтение следуещего элемента
                    i++;
                }
                else
                {
                    givenFileWrite << helpNumber2 << " "; //Анологично описаному выше
                    helpFile2Read >> helpNumber2;
                    j++;
                }
            }
            while (i < k && !helpFile1Read.eof()) //Добавляем оставшиеся сортируемые элменты
            {
                givenFileWrite << helpNumber1 << " ";
                helpFile1Read >> helpNumber1;
                i++;
            }
            while (j < k && !helpFile2Read.eof())
            {
                givenFileWrite << helpNumber2 << " ";
                helpFile2Read >> helpNumber2;
                j++;
            }
        }
        while (!helpFile1Read.eof()) //добавляем оставшиеся неотсортированные элементы
        {
            givenFileWrite << helpNumber1 << " ";
            helpFile1Read >> helpNumber1;
        }
        while (!helpFile2Read.eof())
        {
            givenFileWrite << helpNumber2 << " ";
            helpFile2Read >> helpNumber2;
        }
        givenFileWrite.close();
        helpFile1Read.close();
        helpFile2Read.close();
        k *= 2; //Смещаем границу отсортированных элементов
    }
    std::remove(firstHelpFilename.c_str());
    std::remove(secondHelpFilename.c_str());
    //Удаляем вспомогательные файлы
}

int main()
{
    std::string filename;
    size_t numberOfNumbers;

    std::cout << "Введите имя фаила: ";
    std::getline(std::cin, filename);
    std::cout << "Введите число элементов: ";
    std::cin >> numberOfNumbers;
    mergeSort(filename, numberOfNumbers);
    std::cout << "Готово" << std::endl;
}