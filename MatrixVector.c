#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Helferfunktionen zum Arbeiten mit Vektoren und Matritzen,
nicht alle werden benutzt
*/

// allocated den Speicher für ein Matrix
double **createMatrix(int m, int n)
{
    double **M = malloc(m * sizeof(double *));
    if (M == NULL)
    {
        puts("Konnte keinen Speicher allocaten");
        exit(1);
    }
    for (int i = 0; i < m; i++)
    {
        M[i] = malloc(n * sizeof(double));
        if (M[i] == NULL)
        {
            puts("Konnte keinen Speicher allocaten");
            exit(1);
        }
    }
    return M;
}

// gibt den Speicher einer Matrix frei
void freeMatrix(double **A, int m)
{
    for (int i = 0; i < m; i++)
    {
        free(A[i]);
    }
    free(A);
}

//kopiert eine Matrix in eine andere
void cpyMatrix(double **dest, double **source, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        memcpy(dest[i], source[i], m * sizeof(double));
    }
}

//addiert zwei Matritzen
void addMatrices(double **A, double **B, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = A[i][j] + B[i][j];
        }
    }
}

// allocated den Speicher für einen Vektor
double *createVector(int n)
{
    double *b = malloc(n * sizeof(double));
    if (b == NULL)
    {
        puts("Konnte keinen Speicher allocaten");
        exit(1);
    }
    return b;
}

//mulitpliziere Vektor mit Skalar
void multVector(double a, double *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = a * v[i];
    }
}

//dividiere Vektor durch Skalar
void divideVector(double *v, double a, int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = v[i] / a;
    }
}

//addiere zwei Vektoren
void addVector(double *v, double *w, int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] += w[i];
    }
}

// gibt die Einträge einer Matrix aufs Terminal aus
void printMatrix(double **A, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.15f ", A[i][j]);
        }
        puts("");
    }
}

// gibt die Einträge eines Vektors aufs Terminal aus
void printVector(double *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.15f \n", b[i]);
    }
}

//berechnet das Skalaprodukt zweier Vektoren
double dotproduct(double *b, double *w, int n)
{
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        result += b[i] * w[i];
    }
    return result;
}

// berechnet die Euklidische Länge eines Vektors
double length(double *v, int n)
{
    return sqrt(dotproduct(v, v, n));
}
