Since I had already I calculated the natural logarithm of 2 using the Monte Carlo method, I set myself the following additional task (devised by me):

I decided to calculate ln(2) using numeric integration from x=1 to x=2 of (dx/x). See: https://en.wikipedia.org/wiki/Numerical_integration#Quadrature_rules_based_on_interpolating_functions

To do this I used the trapezoidal rule to sum iteratively and perform the numeric integration.

My solution contains only one file:
*  ln2.cpp = calculates an approximation of ln(2) using the number of iterations specified by the user at the terminal or a default of 10 otherwise.