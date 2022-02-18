#ifndef _NUMERIC_H_
#define _NUMERIC_H_

#include <complex.h>


/* slozi_globalnu_M
   popunjava globalnu matricu zapisanu u stednom obliku (3 niza)
   sa dvijema matricama na elementu

   a_e1[][2]    M na el. 1              double
   a_e2[][2]    M na el. 2
   a_g1[]       gornja dijag.
   a_g2[]       dijagonala glob M
   a_g3[]       donja dijag.
   br_elem      br elemenata            unsigned long int
*/

void slozi_globalnu_M_(double_complex a_e1[][2], double_complex a_e2[][2], double_complex a_g1[], double_complex a_g2[], double_complex a_g3[], unsigned long int br_elem);


/* ini_V_alpha
   popunjava prvi i posljednji clan vektora alpha koeficijenata s
   rubnim uvjetima

   br_elem      broj KE                         unsigned long int
   val_1        rubni uvjet 1                   double
   val_2        rubni uvjet 2
   alpha[]      vektor alpha koeficijenata      ..._complex
*/

void ini_V_alpha(unsigned long int br_elem, double val_1, double val_2, double_complex alpha[]);


/*
*/

void ini_V_rjes(unsigned long int br_elem, double val_1, double val_2, double_complex a_e1[][2], double_complex a_e2[][2], double_complex rjes[]);

/*
*/

void M_2_gtrokM(double_complex a_g1[], double_complex a_g2[], double_complex a_g3[], double_complex rjes[], unsigned long int br_elem);

/*
*/

void gtrokM_mul_Valpha_eq_Vrjes(double_complex a_g1[], double_complex a_g2[], double_complex alpha[], double_complex rjes[], unsigned long int br_elem);


#endif

