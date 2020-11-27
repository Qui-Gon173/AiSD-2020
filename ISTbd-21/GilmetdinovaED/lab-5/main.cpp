#include <iostream>
#include <fstream>
using namespace std;

void MergingSort(char* name) {
    int a1, a2;//записываем в переменные значения элемента
    int i, j;//номера рассматриваемых элементов
    int k = 1;//длина серии
    fstream f,f1,f2; // основной файл и вспомогательные

 f.open(name, fstream::in);
 int kol = 0; //количество элементов в файле
    if (!f)
    {
 cout << " not reading"<<endl;
    }
    else {
        while (f) { //считаем количество элементов в файле
          f >> a1;
          kol++;
        }
      f.close();
    }

   //РАСПРЕДЕЛЕНИЕ
    while (k < kol) {
     f.open(name, fstream::in); //читаем основной файл
     f1.open("smsort_1", fstream::out);//открываем вспомогательные для записи
     f2.open("smsort_2", fstream::out);
        if (f) f >>a1;
        while (f) { //разбиваем на пары
            for (i = 0; i < k && f; i++) {
             f1 << a1 << endl;
                f >> a1;
            }
            for (j = 0; j < k && f; j++) {

                f2 << a1 << endl;
                f >> a1;
            }
        }
        //закрываем файлы
        f1.close();
        f.close();
        f2.close();

       //СЛИЯНИЕ
        f.open(name, fstream::out);//открываем для записи
        f1.open("smsort_1", fstream::in);//открываем для чтения
        f2.open("smsort_2", fstream::in);

        if (f1) f1 >> a1;//читаем элементы
        if (f2) f2 >> a2;
        while (f1 && f2) {
            i = 0;
            j = 0;
            while (i < k && j < k && f1 && f2) {
                if (a1 < a2) { //меняем элементы
                    f << a1 <<endl;
                   f1 >> a1;
                    i++;
                }
                else {
                    f << a2 <<endl;
                    f2 >> a2;
                    j++;
                }
            }
            //дописываем оставшиеся сортируемые элементы
            while (i < k && f1) {
                f << a1 <<endl;
                f1>>a1;
                i++;
            }
            while (j < k && f2) {
                f << a2 <<endl;
               f2 >>a2;
                j++;
            }
        }

       // дописываем оставшиеся неотсортированные элементы
        while (f1) {
            f << a1 <<endl;
            f1 >> a1;

        }
        while (f2) {
            f << a2 <<endl;
            f2 >> a2;
        }
        //закрываем файлы
        f2.close();
        f1.close();
        f.close();
        k *= 2;// увеличение длины серии
}
//удаление вспомогательных файлов
  remove("smsort_1");
  remove("smsort_2");
}
int main()
{
    char name[]="File.txt";
    MergingSort(name);
    cout<<"Array is sort. Check .txt file"<<endl;

    return 0;
}
