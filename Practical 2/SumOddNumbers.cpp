// SumOddNumbers.cpp
// Summs the first N odd numbers

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int N;
    int sum = 0;
    cout << "Input the number of N: " << endl;
    cin >> N;
    for (int i=1; i<N+1; i++) {
        sum = sum + 2*i - 1;
    }
    if (sum != pow(N,2)) {
        cout << "ERROR!"<< endl;
        return -1;
    }
    else {
        cout << "The sum of the first N odd numbers is: " << sum << endl;
        return 0;
    }
}
