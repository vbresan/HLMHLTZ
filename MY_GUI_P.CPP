#include <complex.h>
#include <allegro.h>
#include <conio.h>
#include <stdio.h>

#include "gui_defs.h"
#include "macs_gui.h"


int rectangle_proc(int msg, DIALOG *d, int c)
 {
   switch(msg)
     {
       case MSG_DRAW:
            rect(screen, 0, 0, SCREEN_W-1, SCREEN_H-1, d->fg);
            break;
       default:
            break;
     }

   return D_O_K;
 }


int slika_proc(int msg, DIALOG *d, int c)
 {
   switch(msg)
     {
       case MSG_DRAW:
            if(d->flags != D_HIDDEN)
              {
                if(d->d1)
                  { int i,
                        *boje;

                    if(d->d2 == RADIO1)
                      boje = (int *) d->dp;
                    else
                      boje = (int *) d->dp2;

                    for(i=0; i<=BR_PIX; i++)
                         hline(screen,220,101+i,420,boje[i]);
                  }

                // H1 i H2

                text_mode(-1);

                rectfill(screen, d->x+d->w/4, d->h/4+d->y-3, d->x+3*d->w/4, d->h/4+d->y,     gui_mg_color);
                rectfill(screen, d->x+d->w/4, 3*d->h/4+d->y, d->x+3*d->w/4, 3*d->h/4+d->y+3, gui_mg_color);
                textout(screen, font, "H1", d->x+3*d->w/4-10, d->h/4+d->y-15,  gui_mg_color);
                textout(screen, font, "H2", d->x+3*d->w/4-10, 3*d->h/4+d->y+9, gui_mg_color);

                // y os

                hline(screen, d->x, d->h/2+d->y, d->x+d->w, 32767);
                triangle(screen, d->x+d->w, d->h/2+d->y, d->x+d->w-5, d->h/2+d->y-2, d->x+d->w-5, d->h/2+d->y+2, 32767);
                textout(screen, font, "y", d->x+d->w+5, d->h/2+d->y+5, 32767);

                textout(screen, font, "µ1, e1, s1", d->x, d->h/2+d->y-15, 17890);
                textout(screen, font, "µ2, e2, s2", d->x, d->h/2+d->y+9,  17890);

                // x os

                vline(screen, d->x+d->w/2, d->y, d->y+d->h, 32767 /* bijela */);
                triangle(screen, d->x+d->w/2, d->y, d->x+d->w/2-2, d->y+5, d->x+d->w/2+2, d->y+5, 32767);
                textout(screen, font, "x", d->x+d->w/2+5, d->y+5, 32767);

                // h

                hline(screen, d->x+3*d->w/4+15, d->h/4+d->y,   d->x+3*d->w/4+21, gui_bg_color);
                hline(screen, d->x+3*d->w/4+15, 3*d->h/4+d->y, d->x+3*d->w/4+21, gui_bg_color);
                vline(screen, d->x+3*d->w/4+18, d->h/4+d->y,   3*d->h/4+d->y,    gui_bg_color);
                triangle(screen, d->x+3*d->w/4+18, d->h/4+d->y,   d->x+3*d->w/4+16, d->h/4+d->y+5,   d->x+3*d->w/4+20, d->h/4+d->y+5,   gui_bg_color);
                triangle(screen, d->x+3*d->w/4+18, 3*d->h/4+d->y, d->x+3*d->w/4+16, 3*d->h/4+d->y-5, d->x+3*d->w/4+20, 3*d->h/4+d->y-5, gui_bg_color);
                textout(screen, font, "h", d->x+3*d->w/4+25, 3*d->h/4+d->y-15, gui_bg_color);
              }
            else
                rectfill(screen,d->x-20,d->y-20,d->x+d->w+20,d->h+d->y+20, 0);

            break;
       default:
            break;
     }

   return D_O_K;
 }


/* */

int lista_proc(int msg, DIALOG *d, int c)
 { unsigned long int i,
                     od_mene_int,
                     do_mene_int;
   double_complex    *alpha;
   double            h, dx, x, tmp_d;
   char              *od_mene,
                     tmp[180];

   switch(msg)
     {
       case MSG_DRAW:
            if(d->flags != D_HIDDEN)
              {
                active_dialog[LISTA+1].flags =
                active_dialog[LISTA+2].flags =
                active_dialog[LISTA+3].flags =
                active_dialog[LISTA+4].flags =
                active_dialog[LISTA+5].flags =
                active_dialog[LISTA+6].flags =
                0;

                d_box_proc(MSG_DRAW,&active_dialog[LISTA+1],0);
                d_shadow_box_proc(MSG_DRAW,&active_dialog[LISTA+2],0);
                d_shadow_box_proc(MSG_DRAW,&active_dialog[LISTA+3],0);
                d_text_proc(MSG_DRAW,&active_dialog[LISTA+4],0);
                d_edit_proc(MSG_DRAW,&active_dialog[LISTA+5],0);
                d_button_proc(MSG_DRAW,&active_dialog[LISTA+6],0);

                ISPIS_LISTE;
              }
            else
              {
                active_dialog[LISTA+1].flags =
                active_dialog[LISTA+2].flags =
                active_dialog[LISTA+3].flags =
                active_dialog[LISTA+4].flags =
                active_dialog[LISTA+5].flags =
                active_dialog[LISTA+6].flags =
                D_HIDDEN;

                rectfill(screen,d->x-2,d->y-2,d->x+d->w+2,d->h+d->y+2, 0);
              }
            break;
       case MSG_USER:

            active_dialog[LISTA+6].flags = 0;
            d_button_proc(MSG_DRAW,&active_dialog[LISTA+6],0);

            d_shadow_box_proc(MSG_DRAW,&active_dialog[LISTA+2],0);

            ISPIS_LISTE;
            break;
       default:
            break;
     }

   active_dialog[LISTA+1].flags =
   active_dialog[LISTA+2].flags =
   active_dialog[LISTA+3].flags =
   active_dialog[LISTA+4].flags =
   D_HIDDEN;

   return D_O_K;
 }

int graf_proc(int msg, DIALOG *d, int c)
 {
   switch(msg)
     {
       case MSG_DRAW:
            if(d->flags != D_HIDDEN)
              { unsigned long int i,
                                  br_elem;
                double            abs_max_Re,
                                  abs_max_Im;
                double_complex    *alpha;
                char              tmp[80];
                int const         br_pix_h = 480,
                                  br_pix_v = 60;

                alpha = (double_complex *) d->dp;
                br_elem = *((unsigned long int *) d->dp2);

                if(!d->d1)
                    NACRTAJ_DVA_GRAFA;
                else
                    NACRTAJ_JEDAN_GRAF;
              }
            else
              { if(active_dialog[HANDLE].d1 == GRAF)
                    rectfill(screen,20,5,635,316,0);
              }
            break;
       default:
            break;
     }
   return D_O_K;
 }

int handle_var_proc(int msg, DIALOG *d, int c)
 {
   switch(msg)
     {
       case MSG_IDLE:
            if((active_dialog[VRIJ].flags & D_SELECTED))
              {
                if(d->d1 != VRIJ)
                  {
                    show_mouse(NULL);

                    if(d->d1 == TABL)
                      {
                        active_dialog[TABL].flags = 0;
                        d_button_proc(MSG_DRAW,&active_dialog[TABL],0);

                        active_dialog[LISTA].flags = D_HIDDEN;
                        lista_proc(MSG_DRAW,&active_dialog[LISTA],0);
                      }
                    else if(d->d1 == GRAF)
                      {
                        active_dialog[GRAF].flags = 0;
                        d_button_proc(MSG_DRAW,&active_dialog[GRAF],0);

                        active_dialog[GRAFOVI].flags = D_HIDDEN;
                        graf_proc(MSG_DRAW,&active_dialog[GRAFOVI],0);
                      }

                    ENABLE_ALL_TEXT;
                    REDRAW_ABLED;

                    active_dialog[RACUN].flags = D_EXIT;
                    d_button_proc(MSG_DRAW,&active_dialog[RACUN],0);

                    d->d1 = VRIJ;

                    show_mouse(screen);
                  }
                else
                  {
                    if((active_dialog[RADIO1].flags & D_SELECTED) &&
                       (d->d2 != RADIO1))
                      {
                        show_mouse(NULL);

                        d->d2 = RADIO1;
                        d_radio_proc(MSG_RADIO,&active_dialog[RADIO2],0);

                        active_dialog[SLIKA].d2 = RADIO1;
                        slika_proc(MSG_DRAW,&active_dialog[SLIKA],0);

                        show_mouse(screen);
                      }
                    else if((active_dialog[RADIO2].flags & D_SELECTED) &&
                            (d->d2 != RADIO2))
                      {
                        show_mouse(NULL);

                        d->d2 = RADIO2;
                        d_radio_proc(MSG_RADIO,&active_dialog[RADIO1],0);

                        active_dialog[SLIKA].d2 = RADIO2;
                        slika_proc(MSG_DRAW,&active_dialog[SLIKA],0);

                        show_mouse(screen);
                      }
                  }
              }
            if((active_dialog[TABL].flags & D_SELECTED))
              {
                if(d->d1 != TABL)
                  {
                    show_mouse(NULL);

                    if(d->d1 != GRAF)
                      {
                        DISABLE_ALL_TEXT;
                        REDRAW_ABLED;

                        active_dialog[RACUN].flags |= D_DISABLED;
                        d_button_proc(MSG_DRAW,&active_dialog[RACUN],0);
                      }
                    else
                      {
                        active_dialog[GRAFOVI].flags = D_HIDDEN;
                        graf_proc(MSG_DRAW,&active_dialog[GRAFOVI],0);
                      }

                    active_dialog[LISTA].flags = 0;
                    lista_proc(MSG_DRAW,&active_dialog[LISTA],0);

                    active_dialog[VRIJ].flags =
                    active_dialog[GRAF].flags = 0;
                    d_button_proc(MSG_DRAW,&active_dialog[VRIJ],0);
                    d_button_proc(MSG_DRAW,&active_dialog[GRAF],0);

                    d->d1 = TABL;

                    show_mouse(screen);
                  }
                else
                  {
                    if((active_dialog[LISTA+6].flags & D_SELECTED))
                      {
                        show_mouse(NULL);

                        lista_proc(MSG_USER,&active_dialog[LISTA],0);

                        show_mouse(screen);
                      }
                  }
              }
            if((active_dialog[GRAF].flags & D_SELECTED) && (d->d1 != GRAF))
              {
                show_mouse(NULL);

                active_dialog[GRAF].flags |= D_GOTFOCUS;
                d_button_proc(MSG_DRAW,&active_dialog[GRAF],0);

                if(d->d1 != TABL)
                  {
                    DISABLE_ALL_TEXT;
                    REDRAW_ABLED;

                    active_dialog[RACUN].flags |= D_DISABLED;
                    d_button_proc(MSG_DRAW,&active_dialog[RACUN],0);
                  }
                else
                  {
                    active_dialog[LISTA].flags = D_HIDDEN;
                    lista_proc(MSG_DRAW,&active_dialog[LISTA],0);
                  }

                active_dialog[GRAFOVI].flags = 0;
                graf_proc(MSG_DRAW,&active_dialog[GRAFOVI],0);

                active_dialog[VRIJ].flags =
                active_dialog[TABL].flags = 0;
                d_button_proc(MSG_DRAW,&active_dialog[VRIJ],0);
                d_button_proc(MSG_DRAW,&active_dialog[TABL],0);

                d->d1 = GRAF;

                show_mouse(screen);
              }
            if(!(active_dialog[GRAF].flags & D_SELECTED) &&
               !(active_dialog[TABL].flags & D_SELECTED) &&
               !(active_dialog[VRIJ].flags & D_SELECTED))
              {
                show_mouse(NULL);

                active_dialog[d->d1].flags |= D_SELECTED;
                d_button_proc(MSG_DRAW,&active_dialog[d->d1],0);

                show_mouse(screen);
              }
            if((gui_bg_color == getpixel(screen,400,20)) && (d->d1 != TABL))
              {
                show_mouse(NULL);
                rectfill(screen,395,10,495,30,0);
                graf_proc(MSG_DRAW,&active_dialog[GRAFOVI],0);
                show_mouse(screen);
              }
            break;
       default:
            break;
     }
   return D_O_K;
 }



