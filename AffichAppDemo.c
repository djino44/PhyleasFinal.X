
/**
 * \file affichage.c
 * \brief Phyleas Dev.
 * \author Radjy.R
 * \version 0.1
 * \date 8 novembre 2013
 *
 * Fonction permettant l'affichage sur l'ecran lcd de l'explorer 16 pour la démonstration Mersen.
 *
 */


#include "LCD.h"






void affichage(int index,bool bp1,bool bp2)
{
   static unsigned char value;
   char s[8];

   value = index;
   clrLCD();
   //sprintf(s, "%2d%%", value);
   putsLCD(s);
   putLCD( '%');

   drawProgressBar(value, 100, HLCD-3); //edition graphique de la progress-bar

   drawBpState(bp1,bp2); //edition graphique des BP
}