#include "num.h"
#include "macs_num.h"


// jos malo reduciranja velicine EXEa

char **__crt0_glob_function(char *arg) { return 0; }
void   __crt0_load_environment_file(char *progname) { }


/* */

void boje_rjesenja(unsigned long int br_elem,
                   double_complex    alpha[],
                   int               boje_Re[],
                   int               boje_Im[])
 { unsigned long int i, index;
   double            poz_max_Re, neg_min_Re, max_max_Re,
                     poz_max_Im, neg_min_Im, max_max_Im,
                     tmp;
   int               j;

   tmp = ((double) (br_elem+1))/((double) BR_PIX);

   poz_max_Re = neg_min_Re = poz_max_Im = neg_min_Im = 0;
   for(i=0; i<br_elem+1; i++)
      {
        if(alpha[i].real() > poz_max_Re)
          poz_max_Re = alpha[i].real();
        else if(alpha[i].real() < neg_min_Re)
          neg_min_Re = alpha[i].real();

        if(alpha[i].imag() > poz_max_Im)
          poz_max_Im = alpha[i].imag();
        else if(alpha[i].imag() < neg_min_Im)
          neg_min_Im = alpha[i].imag();
      }

   if(poz_max_Re > -neg_min_Re)
     max_max_Re = poz_max_Re;
   else
     max_max_Re = -neg_min_Re;

   if(poz_max_Im > -neg_min_Im)
     max_max_Im = poz_max_Im;
   else
     max_max_Im = -neg_min_Im;

   for(j=0; j<=BR_PIX; j++)
      {
        index = (unsigned long int) (((double) j)*tmp);

        if(alpha[index].real() > 0)
            boje_Re[j] = makecol15((int) (255*alpha[index].real()/max_max_Re),0,0);
        else
            boje_Re[j] = makecol15(0,0,(int) (-255*alpha[index].real()/max_max_Re));

        if(alpha[index].imag() > 0)
            boje_Im[j] = makecol15((int) (255*alpha[index].imag()/max_max_Im),0,0);
        else
            boje_Im[j] = makecol15(0,0,(int) (-255*alpha[index].imag()/max_max_Im));
      }
 }


/* */

void analiticka_za_graf(double w,
                        double m,
                        double e,
                        double H,
                        double h,
                        double rjesenje[])
 { double analiticko(double w, double m, double e, double H, double h, double x);
   double x, dx;
   int    i;

   x = h / 2;
   dx = h / BR_PIX_H;
   for(i=0; i<BR_PIX_H; i++)
      {
        rjesenje[i] = analiticko(w,m,e,H,h,x);
        x -= dx;
      }
 }


/* */

void pokreni_gui()
 { char cp_h1[20] = "120", cp_h2[20] = "120",
        cp_w[20] = "299792458",
        cp_m1[20] = "1", cp_m2[20] = "1",
        cp_e1[20] = "1", cp_e2[20] = "1",
        cp_s1[20] = "0", cp_s2[20] = "0",
        cp_h[20] = "2" ,
        cp_ke[20] = "2",
        cp_x[20] = "";
   unsigned long int br_elem;
   double_complex a_e1[2][2],
                  a_e2[2][2],
                  *a_g1,
                  *a_g2,
                  *a_g3,
                  *alpha,
                  *rjes;
   double dx, H1,H2, w, m1,m2, e1,e2, s1,s2;
   double h,
          *analiticki;
   int ret_dialog,
       ret_alert,
       racunato,
       analno,
       selected,
       MY_DIALOG_PROCS;

   selected = VRIJ;
   alpha = NULL;
   analiticki = NULL;

   DIALOG the_dialog[] = MY_DIALOG;

   br_elem = 0;
   racunato = analno = MY_FALSE;
   ret_alert = NE;
   do
     {
       ret_dialog = do_dialog(the_dialog,RACUN);

       if(ret_dialog == KRAJ)
         {
           ret_alert =
                    alert("Zelite li nastaviti s","izlaskom iz programa?",
                          NULL, "&Da","&Ne", 'd','n');
         }
       else if(ret_dialog == RACUN)
         { int  boje_Re[BR_PIX+1],
                boje_Im[BR_PIX+1];
           void boje_rjesenja(unsigned long int, double_complex alpha[],
                              int boje_Re[], int boje_Im[]);

           if(racunato)
             {
               free(alpha);     // oslobodi mem zauzetu vektorom alpha koef
               racunato = MY_FALSE;

               if(analno)
                 {
                   free(analiticki);
                   analno = MY_FALSE;
                 }
             }

           br_elem = atol(cp_ke);
           if((br_elem % 2) || !br_elem)
             {
               alert("Pogreska pri unosu broja elemenata!",NULL,
                     "Unesite paran broj razlicit od nule.",
                     "&OK",NULL, 'o',0);
             }
           else
             {
               UCITAJ_PODATKE;

               a_g1 = (double_complex *) malloc((br_elem-2)*(sizeof(double_complex)));
               a_g2 = (double_complex *) malloc((br_elem-1)*(sizeof(double_complex)));
               a_g3 = (double_complex *) malloc((br_elem+1)*(sizeof(double_complex)));
                      /*   br_elem-2 ali umjesto g3 dolazi alpha */

               if((a_g1 == NULL) || (a_g2 == NULL) || (a_g3 == NULL))
                 {
                   if(a_g2 == NULL)
                     free(a_g1);
                   else if(a_g3 == NULL)
                     {
                       free(a_g1);
                       free(a_g2);
                     }

                   alert("Pogreska pri unosu broja elemenata!",NULL,
                         "Unesite manji broj.",
                         "&OK",NULL, 'o',0);
                 }
               else
                 {
                   rjes = (double_complex *) malloc((br_elem-1)*(sizeof(double_complex)));
                   if(rjes == NULL)
                     {
                       free(a_g1);
                       free(a_g2);
                       free(a_g3);

                       alert("Pogreska pri unosu broja elemenata!",NULL,
                         "Unesite manji broj.",
                         "&OK",NULL, 'o',0);
                     }
                   else
                     { void slozi_M_na_elementu(double dx, double w, double m, double e, double s, double_complex a_e[][2]),
                            slozi_globalnu_M_(double_complex a_e1[][2], double_complex a_e2[][2], double_complex a_g1[], double_complex a_g2[], double_complex a_g3[], unsigned long int br_elem),
                            ini_V_rjes(unsigned long int br_elem, double val_1, double val_2, double_complex a_e1[][2], double_complex a_e2[][2], double_complex rjes[]),
                            M_2_gtrokM(double_complex a_g1[], double_complex a_g2[], double_complex a_g3[], double_complex rjes[], unsigned long int br_elem);
                       DIALOG small_dialog[] = SMALL_DIALOG;

/**/                   small_dialog[0].flags =
/**/                   small_dialog[1].flags = 0;
/**/                   small_dialog[1].dp = " Slazem matricu na elementu. ";
/**/                   d_box_proc(MSG_DRAW,&small_dialog[0],0);
/**/                   d_textbox_proc(MSG_DRAW,&small_dialog[1],0);

                       slozi_M_na_elementu(dx,w,m1,e1,s1,a_e1);
                       slozi_M_na_elementu(dx,w,m2,e2,s2,a_e2);

/**/                   small_dialog[1].dp = " Slazem globalnu matricu. ";
/**/                   d_textbox_proc(MSG_DRAW,&small_dialog[1],0);

                       slozi_globalnu_M_(a_e1,a_e2,a_g1,a_g2,a_g3,br_elem);

/**/                   small_dialog[1].dp = " Inicijaliziram vektor rjesenja. ";
/**/                   d_textbox_proc(MSG_DRAW,&small_dialog[1],0);

                       ini_V_rjes(br_elem,H1,H2,a_e1,a_e2,rjes);

/**/                   small_dialog[1].dp = " Transformiram globalnu matricu u gornju trokutastu. ";
/**/                   d_textbox_proc(MSG_DRAW,&small_dialog[1],0);

                       M_2_gtrokM(a_g1,a_g2,a_g3,rjes,br_elem);
                       free(a_g3);

                       alpha = (double_complex *) malloc((br_elem+1)*(sizeof(double_complex)));
                       if(alpha == NULL)
                         {
                           free(a_g1);
                           free(a_g2);
                           free(rjes);

/**/                       small_dialog[0].flags =
/**/                       small_dialog[1].flags = D_HIDDEN;

                           alert("Pogreska pristupa memoriji - vanjski uzrok!",
                                 "Ovo se meni doma nikad nije dogodilo, pa neznam sto da kazem.",
                                 "Mozda bi bilo najbolje da izadjete iz programa.",
                                 "&OK",NULL, 'o',0);
                         }
                       else
                         { void ini_V_alpha(unsigned long int br_elem, double val_1, double val_2, double_complex alpha[]),
                                gtrokM_mul_Valpha_eq_Vrjes(double_complex a_g1[], double_complex a_g2[], double_complex alpha[], double_complex rjes[], unsigned long int br_elem);

                           racunato = MY_TRUE;

/**/                       small_dialog[1].dp = " Inicijaliziram vektor alpha koef. ";
/**/                       d_textbox_proc(MSG_DRAW,&small_dialog[1],0);

                           ini_V_alpha(br_elem,H1,H2,alpha);

/**/                       small_dialog[1].dp = " Rjesavam sustav. ";
/**/                       d_textbox_proc(MSG_DRAW,&small_dialog[1],0);

                           gtrokM_mul_Valpha_eq_Vrjes(a_g1,a_g2,alpha,rjes,br_elem);

                           free(a_g1);  // oslobodi mem zauzetu glob M
                           free(a_g2);  //
                           free(rjes);  // oslobodi mem zauzetu vektorom rjesenja

/**/                       small_dialog[0].flags =
/**/                       small_dialog[1].flags = D_HIDDEN;

                           boje_rjesenja(br_elem,alpha,boje_Re,boje_Im);

                           SET_ALL_FLAGS;

                           if((H1 == H2) && (m1 == m2) && (e1 == e2)
                              && !s1 && !s2)
                             {
                               analiticki = (double *) malloc((br_elem+1)*(sizeof(double)));
                               if(analiticki == NULL)
                                 {
                                   free(a_g1);
                                   free(a_g2);
                                   free(rjes);
                                   free(alpha);

                                   alert("Pogreska pristupa memoriji - vanjski uzrok!",
                                         "Ovo se meni doma nikad nije dogodilo, pa neznam sto da kazem.",
                                         "Mozda bi bilo najbolje da izadjete iz programa.",
                                         "&OK",NULL, 'o',0);
                                 }
                               else
                                 { void   izracunaj_analiticka(double w, double m, double e, double H, double h, double rjesenje[],unsigned long int br_elem),
                                          analiticka_za_graf(double w, double m, double e, double H, double h, double rjesenje[]);
                                   double za_graf[BR_PIX_H+1];

                                   izracunaj_analiticka(w,m1,e1,H1,h,analiticki,br_elem);
                                   analiticka_za_graf(w,m1,e1,H1,h,za_graf);
                                   analno = MY_TRUE;

                                   the_dialog[LISTA].d1 =
                                   the_dialog[GRAFOVI].d1 = MY_TRUE;

                                   the_dialog[GRAFOVI].dp3 = za_graf;
                                   the_dialog[HANDLE].dp = analiticki;
                                 }
                             }
                         } // alpha OK
                     }     // rjes OK
                 }         // globalna OK
             }             // br_elem OK
         } // ret_dialog == RACUN
     }
   while(!(ret_dialog==KRAJ && ret_alert==DA));

   if(racunato)
     free(alpha);               // oslobodi mem zauzetu vektorom alpha koef
   if(analno)
     free(analiticki);
 }


// main

int main(/*int argc, char *argv[]*/)
 { PALETTE pal;
   void pokreni_gui();

   allegro_init();
   install_keyboard(); 
   if(install_mouse() == -1)
     {
       puts("Nije ucitan int33 driver - funkcije s misom ne rade!\n\n<pritisni tipku>\n");
       readkey();
       return 1;
     }
   install_timer();

   set_color_depth(15);
   if(set_gfx_mode(GFX_VESA1, 640, 480, 0, 0) != 0)
    {
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
      puts("Ne moze se prikazati 640x480 15 bit ekranski mod!\n\n<pritisni tipku>\n");
      readkey();
      return 1;
    }
// generate_332_palette(pal);
   set_palette(pal);

   gui_bg_color = 26425;
   gui_fg_color = 22;
   gui_mg_color = 16912;

   pokreni_gui();

   allegro_exit();
   puts("               lipanj '99.\n");

   return 0;
 }
