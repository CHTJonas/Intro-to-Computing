#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

float f(float x) {
	return 1/x;
}

int main(int argc, char* argv[]) {

	int N=10;
	// limits of integration
	float a = 1.0, b = 2.0;
	
	if(argc>1) {
		// put the first command-line argument in N
		sscanf( argv[1], "%d", &N );
	}

	// define the constants we will be using
	float result = 0, scaleFactor = (b - a) / N;

	// boundary conditions
	result += scaleFactor * f(a) / 2;
	result += scaleFactor * f(b) / 2;

	// perform the iteration
	for (int k = 1; k<=N-1; k++) {
		// calculate the new result
		result = result + scaleFactor * f(a + k * (b - a) / N);
		// print it
		cout << "Iteration No. " << k << "\t\t" << result << endl;
	}

	cout << endl << endl;
	cout << "Final result is:" << "\t" << "ln(2) = " << result << endl;

	// the real result should be: ln(2) = 0.693147181

    // exit successfully
    return 0;
}