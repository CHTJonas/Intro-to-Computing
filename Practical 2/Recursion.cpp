// Recursion.cpp
// Calculates the sequence 1, 1+1/1, 1+1/(1+1/1) ...

#include <iostream>

using namespace std;

float fract(float prevResult) {
     return 1.0 + 1.0 / prevResult;
}

int main()
{
    float result = 1.0;
    for (int i=0; i<20; i++) {
        cout << result << endl;
        result = fract(result);
    }
    return 0;
}
