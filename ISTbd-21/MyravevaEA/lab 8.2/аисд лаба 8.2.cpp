#include "Steck.h"
#include "math.h"
#include "Gen.h"

using namespace std;

int main() {
    int x, y, z;
    cout << "Vvedite nachalo progressii = ";
    cin >> x;
    cout << "Vvedite shag progressii = ";
    cin >> y;
    cout << "Vvedite col-vo elementov = ";
    cin >> z;

    Gen<double> gen(x, y, z);
    
    Steck<double> stack(gen);
    
    printSteck(stack);
    
    cout << "Max: " << max(stack) << endl;
    cout << "Min " << min(stack) << endl;
    cout << "Sum " << sum(stack) << endl;
    cout << "Srednee: " << average(stack) << endl;
    cout << endl;
}