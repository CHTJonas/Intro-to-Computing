#include <iostream>
#include <cmath>
#define number_iterations 20 // the number of iterations to perform
using namespace std;

float f(float x);
float f_prime(float x);
float solve_root(float guess);

int main() {
	float input;
	cout << "Initial guess for equation root = ";
	cin >> input;
	cout << solve_root(input);
	// exit sucessfully
    return 0;
}

float f(float x) {
	return 16 * pow(x,4) + 7 * pow(x,3) - 15 * pow(x,2) ;
}

float f_prime(float x) {
	return 16 * 4 * pow(x,3) + 7 * 3 * pow(x,2) - 15 * 2 * pow(x,1) ;
}

float solve_root(float guess) {
	float result = guess;
	// iterate twenty times to find the root
	for (int i = 0; i < number_iterations; i++) {
		result = result - f(result) / f_prime(result);
	}
	return result;
}
