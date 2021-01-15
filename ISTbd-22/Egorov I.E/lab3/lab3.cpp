#include <iostream>
#include <cstdlib>

using namespace std;

int Ipt(int *mass, int num)
{
    int lever;
    cout << "Vibirite tip zapolneniya:" << endl;
    cout << "1-vruchnuyu" << endl;
    cout << "2-random" << endl;
    cin >> lever;
    if (lever == 1)
    {
        for (int i = 0; i < num; i++)
        {
            cout << "Vvedite " << i + 1 << " element" << endl;
            cin >> mass[i];
        }
        cout << "Massiv zapolnen" << endl;
    }
    else
    {
        if (lever == 2)
        {
            cout << "Vvedite levuyu granicu" << endl; 
           int a;
           cin>>a;
           cout << "Vvedite pravuyu granicu" << endl;
           int b;
           cin>>b;

            for (int i = 0; i < num; i++)
        {

            mass[i]=rand()%(b-a+1) + a;
        }
        cout << "Massiv zapolnen" << endl;
        }
        else
        {
            cout << "Vi vveli neverniy parametr" << endl;
            Ipt(mass,num);
        }

    }
    return(mass,num);
}

void Opt(int *mass, int num){
    cout<<"Massiv:"<<endl;
    for (int i = 0; i < num; i++){
        cout<<"id "<<i<<" , value "<<mass[i]<<endl;
    }
}

int Hoar(int *mass,int num){
    
    int i = 0;
    int j = num - 1;

    
    int mid = mass[num / 2];

    
    do {
        while(mass[i] < mid) {
            i++;
        }
        while(mass[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = mass[i];
            mass[i] = mass[j];
            mass[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    if(j > 0) {
        Hoar(mass, j + 1);
    }
    if (i < num) {
        Hoar(&mass[i], num - i);
    }

}

    int main()
    {
        cout << "Vvedite chislo elementov" << endl;
        int num;
        cin >> num;
        int mass[num];
        Ipt(mass, num);
        Opt(mass,num);
        Hoar(mass,num);
        cout << "Massiv otsortirovan" << endl; 
        Opt(mass,num);
        system("pause");
    }