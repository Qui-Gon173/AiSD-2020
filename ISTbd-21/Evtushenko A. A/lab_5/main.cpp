#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

void generate_Random_Array(int array[], int nVar)
{
    srand((unsigned)time(0));
    for (int i = 0; i < nVar; i++)
        array[i] = rand() % 10;
}

void print_Array(int array[], int nVar)
{
    for (int i = 0; i < nVar; i++)
        cout << array[i] << " ";
    cout << endl;
}

void write_Array_To_File(int array[], int nVar, const char *filename)
{
    ofstream file (filename, ios::trunc);
    if (file.is_open())
    {
        for (int i = 0; i < nVar; i++) 
            file << array[i] << " ";
        file.close();
    }
    else
        cout << "'" << filename << "' couldn't be opened." << endl;
}

void print_File(const char *filename)
{
    ifstream file (filename);
    if (file.is_open())
    {
        cout << file.rdbuf();
    }
    else
        cout << "'" << filename << "' couldn't be opened." << endl;
}

void merge_Sort (const char *filename)
{
  int i, j, nVar, counter, tempValue1, tempValue2;
  FILE *file, *file1, *file2;
  nVar = 0;
  if ((file = fopen(filename, "r")) == NULL)
    cout << "'" << filename << "' couldn't be opened." << endl;
  else
  {
    while (!feof(file))
    {
      fscanf(file, "%d", &tempValue1);
      nVar++;
    }
    fclose(file);
  }
  counter = 1;
  while (counter < nVar)
  {
    file = fopen(filename, "r");
    file1 = fopen("mergeSort1", "w");
    file2 = fopen("mergeSort2", "w");
    if (!feof(file))
        fscanf(file, "%d", &tempValue1);
    while (!feof(file))
    {
      for (i = 0; i < counter && !feof(file); i++)
      {
        fprintf(file1, "%d ", tempValue1);
        fscanf(file, "%d", &tempValue1);
      }
      for (j = 0; j < counter && !feof(file); j++)
      {
        fprintf(file2, "%d ", tempValue1);
        fscanf(file, "%d", &tempValue1);
      }
    }
    fclose(file2);
    fclose(file1);
    fclose(file);
    file = fopen(filename, "w");
    file1 = fopen("mergeSort1", "r");
    file2 = fopen("mergeSort2", "r");
    if (!feof(file1))
        fscanf(file1, "%d", &tempValue1);
    if (!feof(file2))
        fscanf(file2, "%d", &tempValue2);
    while (!feof(file1) && !feof(file2))
    {
      i = 0;
      j = 0;
      while (i < counter && j < counter && !feof(file1) && !feof(file2))
      {
        if (tempValue1 < tempValue2)
        {
          fprintf(file, "%d ", tempValue1);
          fscanf(file1, "%d", &tempValue1);
          i++;
        }
        else
        {
          fprintf(file, "%d ", tempValue2);
          fscanf(file2, "%d", &tempValue2);
          j++;
        }
      }
      while (i < counter && !feof(file1))
      {
        fprintf(file, "%d ", tempValue1);
        fscanf(file1, "%d", &tempValue1);
        i++;
      }
      while (j < counter && !feof(file2))
      {
        fprintf(file, "%d ", tempValue2);
        fscanf(file2, "%d", &tempValue2);
        j++;
      }
    }
    while (!feof(file1))
    {
      fprintf(file, "%d ", tempValue1);
      fscanf(file1, "%d", &tempValue1);
    }
    while (!feof(file2))
    {
      fprintf(file, "%d ", tempValue2);
      fscanf(file2, "%d", &tempValue2);
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
    int nVar;
    cout << "Enter the number of array elements: ";
    cin >> nVar;
    int* array = new int[nVar];
    cout << "Generating initial random array..." << endl;
    generate_Random_Array(array, nVar);
    cout << "Initial random array: ";
    print_Array(array, nVar);
    string temp;
    cout << "Enter a filename to write initial random array to: ";
    cin >> temp;
    const char *filename = temp.c_str();
    cout << "Writing initial random array to '" << filename << "'..." << endl;
    write_Array_To_File(array, nVar, filename);
    cout << "Merge sorting initial random array in '" << filename << "'..." << endl;
    merge_Sort(filename);
    cout << "Merge sorted array in '" << filename << "': ";
    print_File(filename);
    return 0;
}