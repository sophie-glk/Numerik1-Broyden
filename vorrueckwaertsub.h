/**********************************************************************/
/***                                                                ***/
/***  vorrueckwaertsubs.h                                           ***/
/***                                                                ***/
/***  Vorwaerts und Rueckwaertssubstitution                         ***/
/***                                                                ***/
/**********************************************************************/

/*
 vwsubs                                                   
   Diese Funktion loest das Gleichungssystem Lz=b, 
   wobei L eine normierte untere Dreiecksmatrix ist mittels 
   Vorwaertssubstitution. Dabei wird die rechte Seite b mit 
   der Loesung z ueberschrieben.         
  input:  int           n        Dimension der Matrix 
          double**      L        Zeiger auf n*n Matrix. Algorithmus benoetigt nur
	  			 unteres Dreieck, 1er auf Diagonalen werden
				 nicht benoetigt			          
	  double*       b        Rechte Seite und Ergebnis z 
  output: void  
*/
void vwsubs(int n, double ** L, double * b);


/*
  rwsubs
    Diese Funktion loest das Gleichungssystem Rx=b, 
    wobei R eine regulaere obere Dreiecksmatrix ist mittels
    Rueckwaertssubstitution. Dabei wird die rechte Seite b 
    mit der Loesung ueberschrieben. 
   input:  int           n        Dimension der Matrix 
           double**      R        Zeiger auf n*n Matrix. Algorithmus benoetigt nur
	                          oberes Dreieck
           double*       b        Rechte Seite und Ergebnis x  
   output: void 
*/
void rwsubs(int n, double ** R, double * b);
