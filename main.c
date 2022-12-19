#include "lrmp.h"
#include <string.h>
#include "MatrixVector.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "functions.h"

struct result
{
    double *x;
    double *fx;
    short flag;
    int n;
};


inline void aufdat(double **B, double *x, double *d, int dim)
{
    double c = innerproduct(d, d, dim); // berechne d^T*d
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            B[i][j] += x[i] * d[j] / c;
        }
    }
}

inline void updateReport(FILE *report, double prevErrorNorm, double errorNorm, double *fx, int i, int n){

   
        double konvOrdnung = log(errorNorm) / log(prevErrorNorm);
        if (konvOrdnung < 1)
        {
            konvOrdnung = NAN;
        }
        fprintf(report, "%02d | %02.14f | %02.14f | %f \n", i, length(fx, n), errorNorm, konvOrdnung);
}

struct result calcZero(double *x, double **B, int maxit, double tol, int n, void f(double *, double *), const char *name)
{
    double errorNorm = 1;
    double prevErrorNorm = 0;

    double **LR = createMatrix(n, n); // Matrix um die LR Zerlegung für die Funktion Solve zu speichern
    double *d = createVector(n); 
    int *permutation = malloc(n * sizeof(int));
    double *fx = createVector(n);

    struct result r;
    r.x = x;
    r.fx = fx;
    r.flag = -1;
    r.n = maxit;

    FILE *report = fopen("report.txt", "a");
    fprintf(report, "%s \n", name);
    f(x, fx); // berechne f(x^0)
    for (int i = 1; i <= maxit; i++)
    {
        //kopiere -f(x^k) in d, da d durch Solve von der Lösung überschrieben wird
        for (int j = 0; j < n; j++)
        {
            d[j] = -fx[j];
        }
        
        cpyMatrix(LR, B, n, n);  //kopiere B in LR, da LR durch Solve von der LR Zerlegung von B überschrieben wird
        Solve(n, LR, d, permutation);
        addVector(x, d, n); // x^k+1 = x^k+d
        f(x, fx);  //berechne f(x^k+1)
        aufdat(B, fx, d, n); //audfatiere B

        // write report
        //
        prevErrorNorm = errorNorm;
        errorNorm = length(d, n);
        updateReport(report, prevErrorNorm, errorNorm, fx, i, n);

        if (errorNorm < tol)
        {
            r.flag = 0;
            r.n = i;
            break;
        }
    }
    fputs("\n", report);
    fclose(report);
    free(d);
    free(permutation);
    freeMatrix(LR, n);
    return r;
}

void apply(double *x, double **M, void f(double *, double *), char *name)
{
    int maxit = 50;
    double tol = pow(10, -14);
    struct result r = calcZero(x, M, maxit, tol, 2, f, name);
    if (r.flag == 0)
    {
        puts("x");
        printVector(r.x, 2);
        puts("f(x)");
        printVector(r.fx, 2);
        printf("iterationen: \n%d \n", r.n);
    }
    else
    {
        puts("Its haben nicht ausgereicht.");
    }
    free(r.fx);
    // free(r.x);
}

int main()
{
    double *x = createVector(2);
    x[0] = -0.5;
    x[1] = 1.4;
    double **M = Df(x);
    apply(x, M, f, "f1");
    freeMatrix(M, 2);

    x[0] = -0.14;
    x[1] = -1.47;
    M = Df(x);
    apply(x, M, f, "f2");
    freeMatrix(M, 2);

    x[0] = 0;
    x[1] = 2;
    M = Dg(x);
    printMatrix(M, 2, 2);
    apply(x, M, g, "g1");

    x[0] = 0;
    x[1] = 2;

    M[0][0] = 1;
    M[0][1] = 0;
    M[1][0] = 0;
    M[1][1] = 1;
    apply(x, M, g, "g2");

    x[0] = 0;
    x[1] = 2;
    double h = pow(10, -5);
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 2 * x[0] + h;
    M[1][1] = 2 * x[1] + h;
    printMatrix(M, 2, 2);
    apply(x, M, g, "g3");

    free(x);
    freeMatrix(M, 2);
}