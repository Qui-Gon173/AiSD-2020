#include <iostream>
#include <algorithm>

#include "Generator.h"
#include "VectorIter.h"
#include "Vector.h"
#include "Math.h"
#include "Print.h"
using namespace std;


int main()
{
    Generator<double> generator(0, 2, 100);
    Vector<double> vector(generator);

    const auto max = std::max_element(vector.begin(), vector.end());
    const auto min = std::min_element(vector.begin(), vector.end());
    cout << "============================== VALUES ==============================" << endl;
    print(vector);
    cout << endl;
    cout << "[INDEX][MIN]: " << std::distance(vector.begin(), min) << std::endl;
    cout << "[INDEX][MAX]: " << std::distance(vector.begin(), max) << std::endl;
    cout << "[SUM VALUES]: " << sum(vector) << std::endl;
    cout  << "[AVERAGE VALUE]: " << average(vector) << std::endl;
    cout << std::endl;
    return 0;
}
