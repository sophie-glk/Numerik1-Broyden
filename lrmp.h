#ifndef _LRMP_H_
#define _LRMP_H_ 1

#include "vorrueckwaertsub.h"
#include <math.h>

int LRmP (int n, double ** A, int * p);
  /* LR-Zerlegung mit Spaltenpivotisierung */
  /* Eingabe: */
  /*   n : Groesse der Matrix, */
  /*   A : Matrix, */
  /*   p : Permutationsvektor. */
  /* Rueckgabe: */
  /*   A : LR-zerlegte Matrix, */
  /*       unterhalb der Diagonale ist L gespeichert, */
  /*       in der Diagonale und oberhalb R, */
  /*   p : Permutationen nach Pivotsuche. */
  /* Rueckgabewert: */
  /*   bei Fehler */
  /*    (Matrix 'fast' singulaer, d.h. */
  /*     Pivotelement kleiner als eps = 1.0e-8) */
  /*   wird 1 zurueckgegeben, */
  /*   sonst 0. */

int Solve (int n, double ** A, double * b, int * p);
  /* Berechnet Loesung von Ax=b mittels : */
  /*            Routine LRmP(n,A,p) fuer LR-Zerlegung, */
  /*            dann Substitutionen mit 'vorrueckwaertsub'. */
  /* Eingabe: */
  /*   n : Groesse des Systems, */
  /*   A : Matrix, */
  /*   b : rechte Seite des LGS, */
  /*   p : Vektor, um die Permutationen zu speichern. */
  /* Rueckgabe: */
  /*   b : Loesung, */
  /*   p : Permutationen von LRmP, */
  /*   A : LR-zerlegte Matrix. */
  /* Rueckgabewert: */
  /*   falls die LR-Zerlegung nicht funktioniert 1, */
  /*   sonst 0. */  

  
#endif
