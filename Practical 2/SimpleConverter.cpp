// SimpleConverter.cpp
// Converts an energy in electronvolts to joules

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    const float scale = 1.602176565 * pow(10, -19) ;
    float eV, joules;
    cout << "Input the energy in electronvolts: " << endl;
    cin >> eV;
    joules = eV * scale;
    cout << "The energy in joules is: " << joules << endl;
    return 0;
}

