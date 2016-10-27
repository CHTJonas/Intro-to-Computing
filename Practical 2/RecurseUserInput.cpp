// RecurseUserInput.cpp
// Calculates the sequence x, x+1/x, x+1/(x+1/x) ...

#include <iostream>

using namespace std;

float x;

float fract(float prevResult) {
     return x + 1.0 / prevResult;
}

int main()
{
    cout << "Enter a value for x: " << endl;
    // if x=2 I believe the series converges to the square root of 2?
    cin >> x;
    float result = x;
    for (int i=0; i<20; i++) {
        cout << result << endl;
        result = fract(result);
    }
    return 0;
}
