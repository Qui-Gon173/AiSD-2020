#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

    cout << "Algoritm lineinogo poiska c barierom" << endl;
    cout << endl;

    cout << "Vvedite chislo elementov" << endl;
    int num;
    cin >> num;
    int m[num + 1];
    cout << "Vvedite granizi chisel" << endl;
    cout << "Levaia:" << endl;
    int a;
    cin>>a;
    cout << "Pravaia:" << endl;
    int b;
    cin>>b;
    for (int i = 0; i < num; i++)
    {
        m[i] = a + rand() % (b - a+1);
    }

    cout << "Nash massiv:" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << m[i] << endl;
    }
    cout << endl;

    cout << "Vvedite kluch" << endl;
    int key;
    cin >> key;
    m[num + 1] = key;
    int i = 0;
    while (m[i] != key)
    {
        i++;
    }
    if (i == num + 1)
    {
        cout << "v masive element ne naiden" << endl;
    }
    else
    {
        cout << "element c indexom " << i << " podhodit usloviu lineinogo poiska" << endl;
    }

    system("pause");
    return 0;
}