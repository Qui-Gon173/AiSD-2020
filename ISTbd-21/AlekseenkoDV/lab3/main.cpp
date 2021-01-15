#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

void QuickSort(int array[], int low, int high)
{
    int i = low;
    int j = high;
    int tmp;
    int middle = array[(i + j)/2];
    do {
        while(array[i] < middle){
            i++;
        }
        while(array[j] > middle){
            j--;
        }
        if (i <= j){
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    } while(i <= j);

    if (low < j ){
        QuickSort(array, low, j);
    }
    if (i < high){
        QuickSort(array, i, high);
    }
}

int main()
{
    int size;
    int array[1000];
    cout << "Enter size array (max = 1000) = ";
    cin >> size;
    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    int low = 0;
    int high = size - 1;
    QuickSort(array, low, high);
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    return 0;

}
