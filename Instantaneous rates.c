#include <stdio.h>
#include <math.h>
/*This is for data where the zero rate curve (r_t0) (modelled on r_t0 = a + b * ln(c * t)
    a, b and c are variables that are preset at the start of the code.
        a is the starting level of r_t0 at t = 0
        b is the how much the ln has an effect on the r_t0 value. A lower b means a flatter r_t0
        c is a maturity scale that makes sure the ln affects the r_t0 more appropriately to the data
This formula will then work to work out the instantaneous rate (r) of an investment
at a time, t, that the user will input.
It will do this using the following formula: r = r_t0 + t * (dr_t0 / dt)*/

int main() {
    double t;
    float a = 2;
    float b = 1.5;
    double c = 2;

    /*printf("How much would you like to invest?")
    scanf("")*/
    printf("How may years do you want to invest for?");
    scanf("%lf", &t); //Time input
    float r_t0 = a + b * log(c + t); //Formula for zero rate curve
    
    printf("\nThe zero rate curve percentage is: %.3lf\n", r_t0);

    double f(double x) {
        return a + b * log(c + x); //Formula r_t0 to be differentiated
    }

    double der(double x, double h) {
        return (f(x + h) - f(x - h)) / (2 * h); //Function for differentiantion
    }

    double h = 0.0001; //Step
    double res = der(t, h); //Applying differential at t

    printf("The differential of the zero rate curve at %.1lf years is %.3lf\n", t, res);

    double isr = r_t0 + t * res;
    printf("The instantaneous rate after %.1lf years is %.3lf\n", t, isr);

    return 0;
}    