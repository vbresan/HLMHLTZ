#ifndef _NUM_H_
#define _NUM_H_

// skrati vrijeme kompajliranja

#define alleg_joystick_unused
#define alleg_flic_unused
#define alleg_sound_unused
#define alleg_file_unused
#define alleg_datafile_unused
#define alleg_math_unused


// inkludovi

#include <stdio.h>
#include <complex.h>
#include <allegro.h>
#include "gui_defs.h"
//#include "numeric.h"
//#include "hlmhltz.h"
//#include "my_gui_p.h"


// izbaci od allegra sta ne treba

BEGIN_COLOR_DEPTH_LIST
      COLOR_DEPTH_15
END_COLOR_DEPTH_LIST

BEGIN_GFX_DRIVER_LIST
   /* GFX_DRIVER_VBEAF
      GFX_DRIVER_VESA3
      GFX_DRIVER_VESA2L
      GFX_DRIVER_VESA2B */
      GFX_DRIVER_VESA1
END_GFX_DRIVER_LIST


// defineovi

#define DA      1
#define NE      2

#define MY_TRUE    1
#define MY_FALSE   0

#define BR_PIX          115
#define BR_PIX_H        480


#define MY_DIALOG_PROCS \
        rectangle_proc(int msg, DIALOG *d, int c),              \
        slika_proc(int msg, DIALOG *d, int c),                  \
        handle_var_proc(int msg, DIALOG *d, int c),             \
        lista_proc(int msg, DIALOG *d, int c),                  \
        graf_proc(int msg, DIALOG *d, int c)


#define MY_DIALOG       \
        {               \
          /* (dialog proc)     (x)   (y)   (w)   (h)   (fg)          (bg)          (key) (flags)     (d1)  (d2)  (dp)            */             \
          { d_clear_proc,      0,    0,    0,    0,    0,            0,            0,    0,          0,    0,    NULL },                        \
          { rectangle_proc,    0,    0,    0,    0,    gui_fg_color, 0,            0,    0,          0,    0,    NULL },                        \
          { d_box_proc,        5,    325,  629,  101,  gui_fg_color, gui_mg_color, 0,    0,          0,    0,    0 },                           \
                                                                                                                                                \
          { d_shadow_box_proc, 15,   330,  275,  38,   gui_fg_color, gui_bg_color, 0,    0,          0,     0,    0 },                          \
          { d_text_proc,       25,   340,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,     0,    "&Broj KE: " },               \
          { d_text_proc,       222,  340,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,     0,    "(paran)" },                  \
          { d_edit_proc,       97,   340,  60,   12,   gui_fg_color, gui_bg_color, 'b',  0,          19,    0,    cp_ke },                      \
/*          { prnt_max_el_proc,  25,   353,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          RADIO1,0,    "Max:    " }, */            \
                                                                                                                                                \
          { d_shadow_box_proc, 15,   373,  275,  48,   gui_fg_color, gui_bg_color, 0,    0,          0,    0,    0 },                           \
          { d_text_proc,       25,   379,    0,   0,   gui_fg_color, gui_bg_color, 0,    D_DISABLED, 0,    0,    "Prikazi:" },                  \
          { d_radio_proc,      55,   392,    8,   8,   gui_fg_color, gui_bg_color, 'e',  D_DISABLED, 0,    0,    "r&ealni dio rjesenja" },      \
          { d_radio_proc,      55,   405,    8,   8,   gui_fg_color, gui_bg_color, 'i',  D_DISABLED, 0,    0,    "&imaginarni dio rjesenja" },  \
                                                                                                                                                \
          { d_shadow_box_proc, 295,  330,  334,  91,   gui_fg_color, gui_bg_color, 0,    0,          0,    0,    0 },                           \
          { d_text_proc,       305,  340,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "&H1 = " },                    \
          { d_edit_proc,       345,  340,  60,   12,   gui_fg_color, gui_bg_color, 'h',  0,          19,   0,    cp_h1 },                       \
          { d_text_proc,       430,  340,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "H2 = " },                     \
          { d_edit_proc,       470,  340,  60,   12,   gui_fg_color, gui_bg_color, 0,    0,          19,   0,    cp_h2 },                       \
          { d_text_proc,       555,  340,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "(A/m)" },                     \
          { d_text_proc,       305,  353,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "w  = " },                     \
          { d_edit_proc,       345,  353,  80,   12,   gui_fg_color, gui_bg_color, 0,    0,          19,   0,    cp_w },                        \
          { d_text_proc,       555,  353,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "(Hz)" },                      \
          { d_text_proc,       305,  366,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "µ1 = " },                     \
          { d_edit_proc,       345,  366,  60,   12,   gui_fg_color, gui_bg_color, 0,    0,          19,   0,    cp_m1 },                       \
          { d_text_proc,       430,  366,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "µ2 = " },                     \
          { d_edit_proc,       470,  366,  60,   12,   gui_fg_color, gui_bg_color, 0,    0,          19,   0,    cp_m2 },                       \
          { d_text_proc,       305,  379,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "e1 = " },                     \
          { d_edit_proc,       345,  379,  60,   12,   gui_fg_color, gui_bg_color, 0,    0,          19,   0,    cp_e1 },                       \
          { d_text_proc,       430,  379,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "e2 = " },                     \
          { d_edit_proc,       470,  379,  60,   12,   gui_fg_color, gui_bg_color, 0,    0,          19,   0,    cp_e2 },                       \
          { d_text_proc,       305,  392,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "s1 = " },                     \
          { d_edit_proc,       345,  392,  60,   12,   gui_fg_color, gui_bg_color, 0,    0,          19,   0,    cp_s1 },                       \
          { d_text_proc,       430,  392,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "s2 = " },                     \
          { d_edit_proc,       470,  392,  60,   12,   gui_fg_color, gui_bg_color, 0,    0,          19,   0,    cp_s2 },                       \
          { d_text_proc,       305,  405,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "h  = " },                     \
          { d_edit_proc,       345,  405,  60,   12,   gui_fg_color, gui_bg_color, 0,    0,          19,   0,    cp_h },                        \
          { d_text_proc,       555,  405,  0,    0,    gui_fg_color, gui_bg_color, 0,    0,          0,    0,    "(m)" },                       \
                                                                                                                                                \
          { d_box_proc,        5,    431,  629,  43,   gui_fg_color, gui_mg_color, 0,    0,          0,    0,    0 },                           \
          { d_button_proc,     15,   438,  120,  30,   gui_fg_color, gui_bg_color, 'r',  D_EXIT,     0,    0,    "&Racunanje" },                \
          { d_button_proc,     187,  438,  120,  30,   gui_fg_color, gui_bg_color, 'v',  D_SELECTED, 0,    0,    "&Vrijednosti" },              \
          { d_button_proc,     312,  438,  100,  30,   gui_fg_color, gui_bg_color, 't',  D_DISABLED, 0,    0,    "&Tablica" },                  \
          { d_button_proc,     417,  438,  80,   30,   gui_fg_color, gui_bg_color, 'g',  D_DISABLED, 0,    0,    "&Graf" },                     \
          { d_button_proc,     549,  438,  80,   30,   gui_fg_color, gui_bg_color, 'k',  D_EXIT,     0,    0,    "&Kraj" },                     \
                                                                                                                                                \
          { slika_proc,        120,  44,   400,  230,  0,            0,            0,    0,          0,    0,    NULL, NULL },                  \
                                                                                                                                                \
          { lista_proc,        5,    5,    630,  315,  gui_fg_color, gui_bg_color, 0,    D_HIDDEN,   0,    0,    NULL, NULL, NULL },            \
          { d_box_proc,        5,    5,    630,  315,  gui_fg_color, gui_mg_color, 0,    D_HIDDEN,   0,    0,    NULL },                        \
          { d_shadow_box_proc, 10,   35,   620,  280,  gui_fg_color, gui_bg_color, 0,    D_HIDDEN,   0,    0,    NULL },                        \
          { d_shadow_box_proc, 10,   10,   380,  20,   gui_fg_color, gui_bg_color, 0,    D_HIDDEN,   0,    0,    NULL },                        \
          { d_text_proc,       15,   15,   0,    0,    gui_fg_color, gui_bg_color, 0,    D_HIDDEN,   0,    0,    "Prikazi od vrijednosti x = "},\
          { d_edit_proc,       235,  15,   60,   12,   gui_fg_color, gui_bg_color, 0,    D_HIDDEN,   19,   0,    cp_x },                        \
          { d_button_proc,     395,  10,   100,  20,   gui_fg_color, gui_bg_color, 'p',  D_HIDDEN,   0,    0,    "&Prikazi!" },                 \
                                                                                                                                                \
          { graf_proc,         0,    0,    0,    0,    gui_fg_color, gui_bg_color, 0,    D_HIDDEN,   0,    0,    NULL, NULL, NULL },            \
                                                                                                                                                \
          { handle_var_proc,   0,    0,    0,    0,    0,            0,            0,    0,          selected,   RADIO1,    NULL },             \
                                                                                                                                                \
          { NULL,              0,    0,    0,    0,    0,            0,            0,    0,          0,    0,    NULL } };

#define SMALL_DIALOG       \
        {               \
          /* (dialog proc)     (x)   (y)   (w)   (h)   (fg)          (bg)          (key) (flags)     (d1)  (d2)  (dp)            */             \
          { d_box_proc,        5,    295,  629,  25,   gui_fg_color, gui_mg_color, 0,    D_HIDDEN,   0,    0,    NULL },                        \
          { d_textbox_proc,    15,   300,  614,  15,   gui_fg_color, gui_bg_color, 0,    D_HIDDEN,   0,    0,    NULL },                        \
          { NULL,              0,    0,    0,    0,    0,            0,            0,    0,          0,    0,    NULL } };




#endif
