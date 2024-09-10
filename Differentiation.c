#include <stdio.h> 
#include <math.h> 
 
double f (double x) {  
    return 2 + 1.5 * log(2+x); //Differentiate this function
} 
 
double derivative(int x, double h) { 
    return (f(x + h) - f(x - h)) / (2 * h);  //Equation for central difference differentiation
} 
 
int main() { 
    int x = 2; // Point that needs to be differentiated
    double h = 0.001; // Step size 
 
    double result = derivative(x, h); 
    printf("The derivative of r_t0 at x = %.0d is %.3lf\n", x, result); 
 
    return 0; 
}