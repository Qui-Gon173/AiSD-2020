#include <iostream>
using namespace std;

int linsearch(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5, -33, 3, 10, -2};
    cout << linsearch(arr, 5, 3) << endl;
    cout << linsearch(arr, 5, 133) << endl;
}
