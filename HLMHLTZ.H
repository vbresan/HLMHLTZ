#ifndef _HLMHLTZ_H_
#define _HLMHLTZ_H_

#include <complex.h>


#define M0 4*PI*0.0000001
#define E0 8.85418782*0.000000000001


/* slozi_M_na_elementu
   popunjava odgovarajucim vrijednostima matricu na KE

   dx           delta_x         double
   w            omega
   m            mi_r
   e            epsilon_r
   s            sigma
   a_e[][2]     matrica na KE   ..._complex
*/

void slozi_M_na_elementu(double dx, double w, double m, double e, double s, double_complex a_e[][2]);

void izracunaj_analiticka(double w, double m, double e, double H, double h, double rjesenje[],unsigned long int br_elem);

double analiticko(double w, double m, double e, double H, double h, double x);

#endif

