#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 19

long *tab_factorial;

typedef struct cell{
	unsigned short *rank;
	struct cell *next;	
}Cell;
typedef Cell * List;

/* Variable globale correspondant à SIZE!*/
long int fact; 


void swap(unsigned short *a, unsigned short *b);

/* Fonction d'allocation d'une cellule */
List allocate_cell(unsigned short *rank);

/* Fonction d'insertion en début de liste */

List insert_list(List *list, unsigned short *tab);

/* Fonction de libération de la liste */
void free_list(List *list);

/* Fonction d'affichage de la liste */
void display_list(List list);

/*unsigned short extract_list(List *list, unsigned char element);*/

#endif
