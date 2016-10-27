// SquareRoots.cpp
// Calculates the sequence root(1), root(1 + root(1)), root(1 + root(1 + root(1))) ...

#include <iostream>
#include <math.h>

using namespace std;

float root(float prevResult) {
     return pow(1.0 + prevResult, 0.5);
}

int main()
{
    float result = 1.0; // square root of 1 = 1
    for (int i=0; i<20; i++) {
        cout << result << endl;
        result = root(result);
    }
    return 0;
}
