/*int prnt_max_el_proc(int msg, DIALOG *d, int c)
 {

  long int max_br_elem;

   switch(msg)
     {
       case MSG_DRAW:

            malloc(max_br_elem = (4*sizeof(double_complex));

            textprintf(screen,font,d->x,d->y,d->fg,"(%s%li) ",(char *)d->dp,
                       max_br_elem);

            break;
       case MSG_IDLE:

            if((active_dialog[RADIO1].flags & D_SELECTED) && d->d1 != RADIO1)
              {
                d->d1 = RADIO1;
                d->d2 = 1;

                d_radio_proc(MSG_RADIO,&active_dialog[RADIO2],0);
                d_radio_proc(MSG_RADIO,&active_dialog[RADIO3],0);
              }
            else if((active_dialog[RADIO2].flags & D_SELECTED) &&
                    d->d1 != RADIO2)
              {
                d->d1 = RADIO2;
                d->d2 = 1;

                d_radio_proc(MSG_RADIO,&active_dialog[RADIO1],0);
                d_radio_proc(MSG_RADIO,&active_dialog[RADIO3],0);
              }
            else if((active_dialog[RADIO3].flags & D_SELECTED) &&
                    d->d1 != RADIO3)
              {
                d->d1 = RADIO3;
                d->d2 = 1;

                d_radio_proc(MSG_RADIO,&active_dialog[RADIO1],0);
                d_radio_proc(MSG_RADIO,&active_dialog[RADIO2],0);
              }

            if(d->d2)
              {
                memory_left = (_go32_dpmi_remaining_physical_memory()+
                               _go32_dpmi_remaining_virtual_memory())/
                              (2*bajta_po_clanu);

                scare_mouse();
                textprintf(screen,font,d->x,d->y,d->fg,"(%s%li) ",
                           (char *)d->dp,memory_left);
                unscare_mouse();

                d->d2 = 0;
              }

            break;
       default:
            break;
     }

   return D_O_K;
 }*/

/*   int flags_unos, flags_graf, flags_tablica, flags_o_prg, flags_kraj;
   void pokreni_gui_unos(void);

   ret_alert = 0;
   do
     {
       ret_dialog = do_dialog(the_dialog,UNOS);

       switch(ret_dialog)
         {
           case UNOS: */

                /* snimi flagse ostalih botuna, diseblaj ih i
                   ponovo nacrtaj na ekran */

            /*    flags_graf = the_dialog[GRAF].flags;
                flags_tablica = the_dialog[TABLICA].flags;
                flags_o_prg = the_dialog[O_PRG].flags;
                flags_kraj = the_dialog[KRAJ].flags;

                the_dialog[GRAF].flags =
                the_dialog[TABLICA].flags =
                the_dialog[O_PRG].flags =
                the_dialog[KRAJ].flags = D_DISABLED;

                d_button_proc(MSG_DRAW,&the_dialog[GRAF],0);
                d_button_proc(MSG_DRAW,&the_dialog[TABLICA],0);
                d_button_proc(MSG_DRAW,&the_dialog[O_PRG],0);
                d_button_proc(MSG_DRAW,&the_dialog[KRAJ],0);

                pokreni_gui_unos();           */

                /* vrati flagse ostalim botunima */

              /*  the_dialog[GRAF].flags = flags_graf & !D_SELECTED;
                the_dialog[TABLICA].flags = flags_tablica & !D_SELECTED;
                the_dialog[O_PRG].flags = flags_o_prg;
                the_dialog[KRAJ].flags = flags_kraj;

                the_dialog[GRAF].flags = 0;
                the_dialog[TABLICA].flags = 0;

                break;
           case O_PRG:*/

                /* snimi flagse ostalih botuna, diseblaj ih i
                   ponovo nacrtaj na ekran */

              /*  flags_unos = the_dialog[UNOS].flags;
                flags_graf = the_dialog[GRAF].flags;
                flags_tablica = the_dialog[TABLICA].flags;
                flags_kraj = the_dialog[KRAJ].flags;

                the_dialog[UNOS].flags =
                the_dialog[GRAF].flags =
                the_dialog[TABLICA].flags =
                the_dialog[KRAJ].flags = D_DISABLED;

                d_button_proc(MSG_DRAW,&the_dialog[UNOS],0);
                d_button_proc(MSG_DRAW,&the_dialog[GRAF],0);
                d_button_proc(MSG_DRAW,&the_dialog[TABLICA],0);
                d_button_proc(MSG_DRAW,&the_dialog[KRAJ],0);

                alert("Rjesavanje Helmholtzove jednadzbe metodom KE",
                    "","Viktor Bresan, lipanj '99.", "&Povratak",NULL, 'p',0);*/

                /* vrati flagse ostalim botunima */

/*                the_dialog[UNOS].flags = flags_unos;
                the_dialog[GRAF].flags = flags_graf & !D_SELECTED;
                the_dialog[TABLICA].flags = flags_tablica & !D_SELECTED;
                the_dialog[KRAJ].flags = flags_kraj;

                break;
           case KRAJ: */

                /* snimi flagse ostalih botuna, diseblaj ih i
                   ponovo nacrtaj na ekran */

            /*    flags_unos = the_dialog[UNOS].flags;
                flags_graf = the_dialog[GRAF].flags;
                flags_tablica = the_dialog[TABLICA].flags;
                flags_o_prg = the_dialog[O_PRG].flags;

                the_dialog[UNOS].flags =
                the_dialog[GRAF].flags =
                the_dialog[TABLICA].flags =
                the_dialog[O_PRG].flags = D_DISABLED;

                d_button_proc(MSG_DRAW,&the_dialog[UNOS],0);
                d_button_proc(MSG_DRAW,&the_dialog[GRAF],0);
                d_button_proc(MSG_DRAW,&the_dialog[TABLICA],0);
                d_button_proc(MSG_DRAW,&the_dialog[O_PRG],0);

                ret_alert =
                    alert("Da li zelite nastaviti s","izlaskom iz programa:",
                          NULL, "&Da","&Ne", 'd','n');*/

                /* vrati flagse ostalim botunima */

             /*   the_dialog[UNOS].flags = flags_unos ;
                the_dialog[GRAF].flags = flags_graf & !D_SELECTED;
                the_dialog[TABLICA].flags = flags_tablica & !D_SELECTED;
                the_dialog[O_PRG].flags = flags_o_prg;

                break;
           default:
                break;
         }
     }
   */
