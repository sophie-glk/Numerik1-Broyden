#include <math.h>
#include "MatrixVector.h"

//Definition der funktionen f und g, und deren Ableitungen / Jacobi Matritzen
void f(double *x, double *result)
{
    result[0] = (x[0] + 3) * (x[1] * x[1] * x[1] - 7) + 18;
    result[1] = sin(x[1] * exp(x[0]) - 1);
}

void g(double *x, double *result)
{
    result[0] = x[0] + x[1] - 3;
    result[1] = x[0] * x[0] + x[1] * x[1] - 9;
}

void Df(double *x, double **M)
{
    M[0][0] = x[1] * x[1] * x[1] - 7;
    M[0][1] = 3 * x[1] * x[1] * (x[0] + 3);
    M[1][0] = cos(x[1] * exp(x[0]) - 1) * x[1] * exp(x[0]);
    M[1][1] = cos(x[1] * exp(x[0]) - 1) * exp(x[0]);
}

void Dg(double *x, double **M)
{
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 2 * x[0];
    M[1][1] = 2 * x[1];
}