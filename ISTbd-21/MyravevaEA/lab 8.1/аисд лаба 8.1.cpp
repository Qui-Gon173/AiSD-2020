#include "steck.h"

using namespace std;

int main() {

    Steck<double> steck;
    double steckk[5];
    double x;

    cout << "Vvedite 5 elementov" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> steckk[i];
    }

    steck.pushEnum(steckk, sizeof(steckk) / sizeof(*steckk));
    cout << "Kakoi element dobavit' = ";
    cin >> x;
    steck.push(x);

    cout << "Update steck = ";
    steck.printSteck();
    cout << endl;
    
    cout << "Summa: " << steck.summa() << endl; 
    cout << "Srednee: " << steck.avg() << endl;
    cout << "Max elem: " << steck.MaxElement() << endl;
    cout << "Min elem: " << steck.MinElement() << endl;
    
    
    double* steck2 = new double[2];
    steck2 = steck.popEnum(3);
    cout << "New steck" << endl;
    for (size_t i = 0; i < 2; i++) {
        cout << steck2[i] << " ";
    }
    cout << endl;
    
    cout << "Old:" << endl;
    steck.printSteck();

    Steck<double> steckNew;
    steckNew.pushFromDifStack(steck, 2);
    cout << endl;
    
    cout << "V drugoi stack" << endl;
    steckNew.printSteck();
    cout << endl;
}