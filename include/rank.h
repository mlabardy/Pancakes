#ifndef RANK_H
#define RANK_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"


void display_tab(unsigned short *tab, int size);

void switch_permutation(unsigned short *tab, int size);

/*-------------------------------Nouvelles fonctions-------------------*/

void id_permutation(unsigned short *dest, int size);
void random_permutation(unsigned short *tab, int size);
void inverse_permutation(unsigned short *src, unsigned short *dest, int size);
long rank(int n, unsigned short *tab, unsigned short *tab_inv);
void unrank(int n, int r, unsigned short *tab);

/*---------------------------------------------------------------------*/

long factorial(unsigned short num, long result);

#endif
