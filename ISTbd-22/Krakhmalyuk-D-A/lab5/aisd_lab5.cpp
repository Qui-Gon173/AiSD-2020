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
	int i, j, length = 0, counter, tmp1, tmp2;
	FILE *file, *file1, *file2;
	if ((file = fopen(filename, "r")) == NULL)
		cout << "'" << filename << "' can not be opened." << endl;
	else
	{
		while (!feof(file))
		{
			fscanf(file, "%d", &tmp1);
			length++;
		}
		fclose(file);
	}
	counter = 1;
	while (counter < length)
	{
		file = fopen(filename, "r");
		file1 = fopen("mergeSort1", "w");
		file2 = fopen("mergeSort2", "w");
		if (!feof(file))
			fscanf(file, "%d", &tmp1);
		while (!feof(file))
		{
			for (i = 0; i < counter && !feof(file); i++)
			{
				fprintf(file1, "%d ", tmp1);
				fscanf(file, "%d", &tmp1);
			}
			for (j = 0; j < counter && !feof(file); j++)
			{
				fprintf(file2, "%d ", tmp1);
				fscanf(file, "%d", &tmp1);
			}
		}
		fclose(file2);
		fclose(file1);
		fclose(file);
		file = fopen(filename, "w");
		file1 = fopen("mergeSort1", "r");
		file2 = fopen("mergeSort2", "r");
		if (!feof(file1))
			fscanf(file1, "%d", &tmp1);
		if (!feof(file2))
			fscanf(file2, "%d", &tmp2);
		while (!feof(file1) && !feof(file2))
		{
			i = 0;
			j = 0;
			while (i < counter && j < counter && !feof(file1) && !feof(file2))
			{
				if (tmp1 < tmp2)
				{
					fprintf(file, "%d ", tmp1);
					fscanf(file1, "%d", &tmp1);
					i++;
				}
				else
				{
					fprintf(file, "%d ", tmp2);
					fscanf(file2, "%d", &tmp2);
					j++;
				}
			}
			while (i < counter && !feof(file1))
			{
				fprintf(file, "%d ", tmp1);
				fscanf(file1, "%d", &tmp1);
				i++;
			}
			while (j < counter && !feof(file2))
			{
				fprintf(file, "%d ", tmp2);
				fscanf(file2, "%d", &tmp2);
				j++;
			}
		}
		while (!feof(file1))
		{
			fprintf(file, "%d ", tmp1);
			fscanf(file1, "%d", &tmp1);
		}
		while (!feof(file2))
		{
			fprintf(file, "%d ", tmp2);
			fscanf(file2, "%d", &tmp2);
		}
		fclose(file2);
		fclose(file1);
		fclose(file);
		counter *= 2;
	}
	remove("mergeSort1");
	remove("mergeSort2");
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
}


