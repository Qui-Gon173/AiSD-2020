#include <iostream>
#include <fstream>

using namespace std;
// функци¤ сортировки простым сли¤нием
void MergingSort(char* filename) {
	int a1, a2, k, i, j, tmp;
	int count = -1;
	fstream f, f1, f2;
	f.open(filename, fstream::in);
	// провер¤ем файл на пустоту
	if (!f)
	{
		cout << "File read error" << endl;
	}
	else {
		while (f) {
			f >> a1;
			count++;
		}
		f.close();
	}
	k = 1;
	//разбиваем исходный файл на два вспомогательных, сортиру¤ пары элементов
	//повтор¤ем до тех пор, пока не будет упор¤дочен весь файл
	while (k < count) {
		f.open(filename, fstream::in);
		f1.open("sortfile1.txt", fstream::out);
		f2.open("sortfile2.txt", fstream::out);
		if (f) f >> a1;
		while (f) {

			for (i = 0; i < k && f; i++) {
				f1 << a1 << endl;
				f >> a1;
			}
			for (j = 0; j < k && f; j++) {

				f2 << a1 << endl;
				f >> a1;
			}
		}
		f1.close();
		f.close();
		f2.close();


		f.open(filename, fstream::out);
		f1.open("sortfile1.txt", fstream::in);
		f2.open("sortfile2.txt", fstream::in);

		if (f1) f1 >> a1;
		if (f2) f2 >> a2;
		while (f1 && f2) {
			i = 0;
			j = 0;
			while (i < k && j < k && f1 && f2)
			{
				if (a1 < a2) {
					f << a1 << endl;
					f1 >> a1;
					i++;
				}
				else {
					f << a2 << endl;
					f2 >> a2;
					j++;
				}
			}
			while (i < k && f1) {
				f << a1 << endl;
				f1 >> a1;
				i++;
			}
			while (j < k && f2) {
				f << a2 << endl;
				f2 >> a2;
				j++;
			}
		}


		while (f1)
		{
			f << a1 << endl;
			f1 >> a1;

		}
		while (f2)
		{
			f << a2 << endl;
			f2 >> a2;
		}
		f2.close();
		f1.close();
		f.close();
		k *= 2;
	}
	remove("sortfile1.txt");
	remove("sortfile2.txt");
}
int main()
{
	char filename[] = "file.txt";
	MergingSort(filename);
	return 0;
}