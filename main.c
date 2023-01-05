#include "lrmp.h"
#include <string.h>
#include "MatrixVector.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "functions.h"

// Ergebnis struct, dass ale geforderten Daten zurückgibt
struct result
{
    double *x;
    double *fx;
    short flag;
    int n;
};

inline void aufdat(double **B, double *fx, double *d, int n)
{
    double c = dotproduct(d, d, n); // berechne d^T*d, gleich dem Skalarprodukt
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] += fx[i] * d[j] / c; // i,jter Eintrag von f(x^k+1)*(d^k)^T ist gleich fx[i] * d[j]
        }
    }
}

inline void updateReport(FILE *report, double prevDeltaNorm, double deltaNorm, double *fx, int i, int n)
{

    // schreibe Daten in Tabelle zur Analyse
    double konvOrdnung = log(deltaNorm) / log(prevDeltaNorm);
    if (konvOrdnung < 1)
    {
        konvOrdnung = NAN;
    }
    fprintf(report, "%02d | %02.14f | %02.14f | %f \n", i, length(fx, n), deltaNorm, konvOrdnung); // schreibe Iteration, norm von x^i,...
}

struct result calcZero(double *x, double **B, int maxit, double tol, int n, void f(double *, double *), const char *name)
{

    double deltaNorm = 1;
    double prevDeltaNorm = 0;

    double **LR = createMatrix(n, n);
    double *d = createVector(n);
    int *permutation = malloc(n * sizeof(int));
    if (permutation == NULL)
    {
        puts("Error allocatiing memmory");
        exit(1);
    }
    double *fx = createVector(n);

    // standard rückgabe, wenn die Schleife ohne Abbruch durchläuft war das Verfahren nicht erfolgreich
    struct result r;
    r.x = x;
    r.fx = fx;
    r.flag = -1;
    r.n = maxit;

    // öffne report Datei
    FILE *report = fopen("report.txt", "a");
    if(report == NULL){
        puts("Error opening report");
        exit(1);
    }

    fprintf(report, "%s \n", name);

    f(x, fx); // berechne f(x^0)
              // die schleife berechnet in jeder Iteration nur f(x^k+1), mit 0 beginned, weswegen wir f(x^0) vorgeben müssen
    for (int i = 1; i <= maxit; i++)
    {
        // kopiere -f(x^k) in d, da d durch Solve von der Lösung überschrieben wird und wir später beide Variablen benötigen
        for (int j = 0; j < n; j++)
        {
            d[j] = -fx[j];
        }

        cpyMatrix(LR, B, n, n);       // kopiere B in LR, da LR durch Solve von der LR Zerlegung von B überschrieben wird, und B noch benötigt wird
        Solve(n, LR, d, permutation); // Löse  B^k d^k = -f(x^k)
        addVector(x, d, n);           // x^k+1 = x^k+d^k
        f(x, fx);                     // berechne f(x^k+1), durch die Konstruktion der schleife muss diser Wert beim nächsten durchlaufen der Schleife nicht nochmal berechnet werden
        aufdat(B, fx, d, n);          // aufdatiere B

        // schreibe den Bericht stück für stück
        prevDeltaNorm = deltaNorm;
        deltaNorm = length(d, n); // Norm von d = x^k+1-x^k
        updateReport(report, prevDeltaNorm, deltaNorm, fx, i, n);

        // abruch Kriterium (Skript 5.6.2)
        if (deltaNorm < tol)
        {
            r.flag = 0; // Verfahren wurde erfolgreich durchgeführt
            r.n = i;
            break;
        }
    }
    // aufräumen
    fputs("\n", report);
    fclose(report);
    free(d);
    free(permutation);
    freeMatrix(LR, n);
    return r;
}

void apply(double *x, double **M, void f(double *, double *), char *name)
{
    int maxit = 50;            // setzte maximale Iterationen
    double tol = pow(10, -14); // setzte Toleranz
    struct result r = calcZero(x, M, maxit, tol, 2, f, name);
    // erfolgreicher durchlauf
    printf("%s \n", name);
    if (r.flag == 0)
    {
        puts("x");
        printVector(r.x, 2);
        puts("fx");
        printVector(r.fx, 2);
        printf("iterationen: \n%d \n", r.n);
    }
    else
    {
        puts("Its haben nicht ausgereicht.");
    }
    puts("");
    free(r.fx);
    // free(r.x); // wir benutzten x wieder, also wird der Speicher nicht frei gegeben
}

int main()
{
    double **M = createMatrix(2, 2);
    double *x = createVector(2);

    x[0] = -0.5;
    x[1] = 1.4;
    Df(x, M);
    apply(x, M, f, "f1");

    x[0] = -0.14;
    x[1] = -1.47;
    Df(x, M);
    apply(x, M, f, "f2");

    x[0] = 0;
    x[1] = 2;
    Dg(x, M);
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
    apply(x, M, g, "g3");

    free(x);
    freeMatrix(M, 2);
}