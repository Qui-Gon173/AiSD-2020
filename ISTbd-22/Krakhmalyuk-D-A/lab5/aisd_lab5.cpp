#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 64;

void fill(int* a)
{
	srand(time(NULL));
	for (int i = 0; i < ARRAY_SIZE; i++)
		a[i] = rand() % 228;
}

void print(int* a)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << a[i] << ' ';
}

void arrayIntoFile(int* a, int length, const char *filename)
{
	ofstream file(filename, ios::trunc);
	if (file.is_open())
	{
		for (int i = 0; i < length; i++)
			file << a[i] << " ";
		file.close();
	}
	else
		cout << "'" << filename << "' can not be opened." << endl;
}

void printFile(const char *filename)
{
	ifstream file(filename);
	if (file.is_open())
	{
		cout << file.rdbuf();
	}
	else
		cout << "'" << filename << "' can not be opened." << endl;
}

void mergeSort(const char *filename)
{
	int i, j,
		length = 1,
		counter = 0,
		tmp1, tmp2;

	fstream file, auxFile1, auxFile2;

	file.open(filename, ios::in);
	if (!file.is_open())
		cout << "'" << filename << "' can not be opened." << endl;

	else
	{
		while (!file.eof())
		{
			file >> tmp1;
			counter++;
		}
		file.close();
	}

	while (length < counter)
	{
		file.open(filename, ios::in);
		auxFile1.open("firstFile", ios::out);
		auxFile2.open("secondFile", ios::out);

		if (!file.eof())
			file >> tmp1;
		while (!file.eof())
		{
			for (i = 0; i < length && !file.eof(); i++)
			{
				auxFile1 << tmp1 << " ";
				file >> tmp1;
			}
			for (j = 0; j < length && !file.eof(); j++)
			{
				auxFile2 << tmp1 << " ";
				file >> tmp1;
			}
		}
		auxFile2.close();
		auxFile1.close();
		file.close();

		file.open(filename, ios::out);
		auxFile1.open("firstFile", ios::in);
		auxFile2.open("secondFile", ios::in);

		if (!auxFile1.eof())
			auxFile1 >> tmp1;
		if (!auxFile2.eof())
			auxFile2 >> tmp2;
		while (!auxFile1.eof() && !auxFile2.eof())
		{
			i = j = 0;
			while (i < length && j < length && !auxFile1.eof() && !auxFile2.eof())
			{
				if (tmp1 < tmp2)
				{
					file << tmp1 << " ";
					auxFile1 >> tmp1;
					i++;
				}
				else
				{
					file << tmp2 << " ";
					auxFile2 >> tmp2;
					j++;
				}
			}
			while (i < length && !auxFile1.eof())
			{
				file << tmp1 << " ";
				auxFile1 >> tmp1;
				i++;
			}
			while (j < length && !auxFile2.eof())
			{
				file << tmp2 << " ";
				auxFile2 >> tmp2;
				j++;
			}
		}
		while (!auxFile1.eof())
		{
			file << tmp1 << " ";
			auxFile1 >> tmp1;
		}
		while (!auxFile2.eof())
		{
			file << tmp2 << " ";
			auxFile2 >> tmp2;
		}

		auxFile2.close();
		auxFile1.close();
		file.close();
		length *= 2;
	}
	remove("firstFile");
	remove("secondFile");
}

int main()
{
	int array[ARRAY_SIZE];

	fill(array);

	cout << "Initial array: ";
	print(array);

	string temp;
	cout << "\nWhere to write the initial array: ";
	cin >> temp;
	const char *filename = temp.c_str();
	arrayIntoFile(array, ARRAY_SIZE, filename);

	mergeSort(filename);

	cout << "\nMerge-sorted array in '" << filename << "': ";
	printFile(filename);

	return EXIT_SUCCESS;
