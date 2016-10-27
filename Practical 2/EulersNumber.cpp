// EulersNumber.cpp
// Calculates e the base of the natural logarithm using the sum of the infinite series (1/n!)

#include <iostream>
#include <math.h>

using namespace std;

int factorial(int a) {
    if (a == 0) return 1; // we choose 0 instead of 1 as the base case here so that (0! = 1) will still work
    else return a * factorial(a - 1);
}

int main()
{
    float sum;
    int n;
    cout << "Enter a value for n: " << endl;
    cin >> n;
    for (int i=0; i<n+1; i++) {
        sum = sum + 1.0/factorial(i);
    }
    cout << "The calculated value for e is " << sum << endl;
    return 0;
}