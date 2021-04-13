// Raphson-NewtonOpdrachtAA.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <math.h>
using namespace std;

int j;
double f_1(double x)
{
    return 3 * pow(x, 2) - exp(x); //de functie f_1(x) = 3x^2 - e^x
}
double fd_1(double x)
{
    return 6*x - exp(x); //de afgeleide van f_1(x)
}

double f_2(double x)
{
    return exp(x) - pow(x, 2) + 3 * x - 2; //de functie f_2(x) = e^x - x^2 + 3x - 2;
}

double fd_2(double x)
{
    return exp(x) - 2 * x + 3; //de afgeleide van f_2(x)
}

void lesDrie(double x)
{
    std::cout << "x_0: " << x << endl;
    for (int i = 1; i < 30; i++) {
        j = i;
        x = x - (f_1(x) / fd_1(x)); //de Newton Raphson formule
        std::cout << "x_" << j << ": " << x << endl;
    }
    return;
}

void lesVierA(double a, double b, double magn)
{
    double m = (a + b) / 2;
    cout    << "iteratie: 0" << endl
            << "a: " << a << endl
            << "b: " << b << endl
            << "m: " << m << endl
            << "f(m): " << f_2(m) << endl << endl;
    for(int i=1; abs(f_2(m)) >= pow(10.0, magn);i++)
    {
        if((f_2(m) < 0))
        {
            a = m;
        }
        else
        {
            b = m;
        }
        m = (a + b) / 2;
        cout    << "iteratie: " << i << endl  
                << "a: " << a << endl
                << "b: " << b << endl
                << "m: " << m << endl
                << "f(m): " << f_2(m) << endl << endl;
    }
    return;

}
void lesVierB(float b, float a, float n) 
{
    float h = (b - a) / n;
    float benadering = 0;

    for (float x = a; b >= x ; x = x + h) 
    {
        benadering = (exp(x) / x) + benadering;
    }
    benadering = h * benadering;
    cout << "benadering integraal: " << b << ";" << a << " = " << benadering << endl;

    return;
}

int main()
{
    // lesDrie(1);
    // lesDrie(2);
    // lesDrie(3);
    // lesDrie(4);
    // lesDrie(5);
    // lesDrie(6);
    // lesVierA(0, 1, -3); //(b, a, magnitude accuratie)
    // lesVierB(5, 1, 1); // (b, a, n)
    // lesVierB(5, 1, 4);
    // lesVierB(5, 1, 10);
}
