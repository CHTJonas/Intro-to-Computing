// magic numbers
#define BIG_G 5
#define MASS_SUN 100
#define MASS_EARTH 1
#define TIME_TO_SIMULATE 20.0
#define STEPS_TO_MAKE 100
#define EARTH_INITIAL_POSITION_X 5.0
#define EARTH_INITIAL_POSITION_Y 0.0
#define EARTH_INITIAL_VELOCITY_X 0.0
#define EARTH_INITIAL_VELOCITY_Y 10.0

// include directives
#include <iostream>
#include <cmath>

using namespace std;

struct twoVector {

  double x;
  double y;
  twoVector() : x(), y() {}
  twoVector(double xx, double yy) : x(xx), y(yy) {}
  double magnitude() const {
    return sqrt(x*x + y*y);
  }
  twoVector unit() {
    return twoVector(x/magnitude(), y/magnitude());
  }
};

class inverseSquareForce {

private:

  const double forceConstant;

public:

  inverseSquareForce(double f0) : forceConstant(f0) {}

  twoVector getForce(twoVector& s) {
    // assume object creating force is at origin
    const double distance = s.magnitude();
    const double forceMagnitude = forceConstant * MASS_SUN * MASS_EARTH / (distance * distance);
    twoVector force;
    force.x = s.unit().x * -forceMagnitude;
    force.y = s.unit().y * -forceMagnitude;
    return force;
  }
};

class massiveBody {

private:

  const double m; // mass
  twoVector s; // position
  twoVector v; // velocity
  twoVector a; // acceleration
  double t; // time
  inverseSquareForce gravity;

  void s_step(const double dt) {
    s.x = s.x + v.x * dt;
    s.y = s.y + v.y * dt;
  }

  void v_step(const double dt) {
    refreshAcceleration();
    v.x = v.x + a.x * dt;
    v.y = v.y + a.y * dt;
  }

  void t_step(const double dt) {
    t = t + dt;
  }

  void refreshAcceleration() {
    a.x = gravity.getForce(s).x / m;
    a.y = gravity.getForce(s).y / m;
  }

  void printout() {
    cout << s.x << "," << s.y << endl;
  }

public:

  massiveBody(double m0, twoVector s0, twoVector v0) : m(m0), s(s0), v(v0), a(), t(0), gravity(BIG_G) {}

  void eulerStep(const double dt) {
    s_step(dt);
    v_step(dt);
    t_step(dt);
    printout();
  }
  
  void leapfrogStep(const double dt) {
    s_step(0.5 * dt);
    v_step(dt);
    s_step(0.5 * dt);
    t_step(dt);
    printout();
  }
};

void simulate(massiveBody& p, double t, int n) {
  // the total duration is t
  // the number of steps to make is n
  const double dt = t / n;
  for (int i = 0; i < n; i++) {
    // arbitrarily call either leapfrog or Euler here
    p.leapfrogStep(dt);
    //p.eulerStep(dt);
  }
}

int main() {
  // we assume the sun is stationary at the origin
  const twoVector earthPosition(EARTH_INITIAL_POSITION_X, EARTH_INITIAL_POSITION_Y);
  const twoVector earthVelocity(EARTH_INITIAL_VELOCITY_X, EARTH_INITIAL_VELOCITY_Y);
  massiveBody earth(MASS_EARTH, earthPosition, earthVelocity);
  simulate(earth, TIME_TO_SIMULATE, STEPS_TO_MAKE);
  return 0; 
}