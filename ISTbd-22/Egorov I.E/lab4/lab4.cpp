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

void Pyramid_lwst(int *mass, int father , int lowest){
int higher;
bool finish = false;

while((father*2<=lowest)&&(finish==false)){
    if(father*2==lowest){
        higher=father*2;
    }else if(mass[father*2] > mass[father*2+1]){
        higher=father*2;
    }else{
        higher=father*2+1;
    }

    if(mass[father]<mass[higher]){
         int oper = mass[father];
         mass[father]=mass[higher];
         mass[higher]=oper;
         father=higher;
    }else{
        finish=true;
    }

}

}

int Pyramid_Sort(int *mass, int num){
for(int i=(num/2)-1; i>=0 ; i--){
    Pyramid_lwst(mass,i,num-1);
}
for(int i=num-1 ;i>=1;i--){
    int oper = mass[0];
    mass[0]=mass[i];
    mass[i]=oper;
    Pyramid_lwst(mass,0,i-1);
}
}

    int main()
    {
        cout << "Vvedite chislo elementov" << endl;
        int num;
        cin >> num;
        int mass[num];

        Ipt(mass,num);
        cout << "Massiv neotsortirovan" << endl;
        Opt(mass,num);
        
        Pyramid_Sort(mass,num);
        
        cout << "Massiv otsortirovan" << endl; 
        Opt(mass,num);
        system("pause");
    }