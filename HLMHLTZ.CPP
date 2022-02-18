#include <complex.h>


#define M0 4*PI*0.0000001
#define E0 8.85418782*0.000000000001

//#include "hlmhltz.h"


/*
*/

void slozi_M_na_elementu(double dx,
                         double w,
                         double m, double e,
                         double s,
                         double_complex a_e[][2])
 {
   if(w == 299792458)
     {
       a_e[0][0] = a_e[1][1] = double_complex(1/dx-m*e*dx/3, w*m*M0*s*dx/3);
       a_e[0][1] = a_e[1][0] = double_complex(-1/dx-m*e*dx/6,w*m*M0*s*dx/6);
     }
   else
     {
       a_e[0][0] = a_e[1][1] = double_complex(1/dx-w*w*m*M0*e*E0*dx/3,
                                              w*m*M0*s*dx/3);
       a_e[0][1] = a_e[1][0] = double_complex(-1/dx-w*w*m*M0*e*E0*dx/6,
                                              w*m*M0*s*dx/6);
     }
 }


void izracunaj_analiticka(double w,
                          double m, double e,
                          double H,
                          double h,
                          double rjesenje[],
                          unsigned long int br_elem)
 { unsigned long int i;
   double            k, x, dx;

   if(w == 299792458)
     k = sqrt(m * e);
   else
     k = sqrt(w*w * m*M0 * e*E0);

   x = h/2;
   dx = h / br_elem;
   for(i=0; i<br_elem+1; i++)
      {
        rjesenje[i] = H * cos(k*x) / cos(k*h/2);
        x -= dx;
      }
 }

double analiticko(double w,
                  double m, double e,
                  double H,
                  double h,
                  double x)
 { double k;

   if(w == 299792458)
     k = sqrt(m * e);
   else
     k = sqrt(w*w * m*M0 * e*E0);

   return (H * cos(k*x) / cos(k*h/2));
 }

/*
*/

