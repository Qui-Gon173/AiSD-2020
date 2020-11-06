#include <iostream>
#include <cstdlib>

using namespace std;

int input(int nm, int *arr)
{

    for (int i = 0; i < nm; i++)
    {
        cout << "Vvedite " << i + 1 << " element massiva" << endl;
        cin >> arr[i];
    }
    return(nm,*arr);
}

int sort(int ind, int *arr)
{
    
    for (int i = 1; i < ind; i++)
    {
        for(int j=i;j>0 && arr[j-1]>arr[j];j--){
            int mem=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=mem;
        }
    }
    return(ind,*arr);
}

void output(int nm, int *arr)
{
    cout << "Masssiv" << endl;
    for (int i = 0; i < nm; i++)
    {
        cout << arr[i] << endl;
    }
    
}

int main()
{
    cout << "Vvedite chislo elementov" << endl;
    int num;
    cin >> num;
    int mass[num];
    input(num, mass);
    output(num, mass);
    system("pause");
    sort(num, mass);
    output(num, mass);
    system("pause");
}