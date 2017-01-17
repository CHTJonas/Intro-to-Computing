// magic numbers

// include directives
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void print() {
	cout << "\n";
}

void print(string message, bool lineBreak = true) {
	if (lineBreak == true) {
		cout << message << endl;
	} else {
		cout << message;
	}
}

void print(double message) {
	cout << message << endl;
}

// read text from the command line
string read() {
	string temp;
	cin >> temp;
	return temp;
}

struct particle {

	double x; // position
	double p; // momentum
	double im; // inverse mass
	double v; // velocity
	double T; // K.E.
	double a; // radius of particle

	void updateMomentum() {
	if (im > 0.0) {
		// particle is a particle
		p =  v / im;
	} else {
		// particle is a wall
		p = 0.0;
	}
	// update the energy too
	T = 0.5 * v * p; 
	}
};

void ellasticCollision(particle& a, particle& b) {
	double relativeVelocity =  a.v - b.v;
	double af = a.im / (a.im + b.im); 
	double bf = b.im / (a.im + b.im); 
	a.v = a.v - 2.0 * af * relativeVelocity;
	b.v = b.v + 2.0 * bf * relativeVelocity;
	a.updateMomentum();
	b.updateMomentum();
}

int main()
{
	particle a;
	particle b;
	print("Enter 1st particle's mass: ", false);
	a.im = 1 / atof(read().c_str());
	print("Enter 1st particle's velocity: ", false);
	a.v = atof(read().c_str());
	print("Enter 2nd particle's mass: ", false);
	b.im = 1 / atof(read().c_str());
	print("Enter 2nd particle's velocity: ", false);
	b.v = atof(read().c_str());
	a.updateMomentum();
	b.updateMomentum();
	print("We are now crashing the particles together...");
	ellasticCollision(a, b);
	print("The first particle now has velocity: ", false);
	print(a.v);
	print("The second particle now has velocity: ", false);
	print(b.v);
	return 0;
}
