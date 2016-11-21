#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>

#define NUMBER_OF_ITERATIONS 10
#define INTEGRATION_LIMIT_LOWER 1.0
#define INTEGRATION_LIMIT_UPPER 2.0

using namespace std;

float f(float x) {
	return 1/x;
}

int main(int argc, char* argv[]) {

	int N = NUMBER_OF_ITERATIONS;
	if(argc>1) {
		// put the first command-line argument in N
		sscanf( argv[1], "%d", &N );
	}

	// define the constants we will be using
	float result = 0, scaleFactor = (INTEGRATION_LIMIT_UPPER - INTEGRATION_LIMIT_LOWER) / N;

	// boundary conditions
	result += scaleFactor * f(INTEGRATION_LIMIT_LOWER) / 2;
	result += scaleFactor * f(INTEGRATION_LIMIT_UPPER) / 2;

	// perform the iteration
	for (int k = 1; k<=N-1; k++) {
		// calculate the new result
		result = result + scaleFactor * f(INTEGRATION_LIMIT_LOWER + k * (INTEGRATION_LIMIT_UPPER - INTEGRATION_LIMIT_LOWER) / N);
		// print it
		cout << "Iteration No. " << k << "\t\t" << result << endl;
	}

	cout << endl << endl;
	cout << "Final result is:" << "\t" << "ln(2) = " << result << endl;

	// the real result should be: ln(2) = 0.693147181

    // exit successfully
    return 0;
}
