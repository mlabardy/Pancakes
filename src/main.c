
/*Sujet : Jeu des pancakes

Tuteur : Stéphane Vialette - vialette@univ-mlv.fr
	 Bureau Copernic 4B066

Le jeu des pancakes consiste, partant d'une permutation p quelconque,
à renverser le prefixe de taille p[1] jusqu'à ce que p[1]= 1 (le 1
apparaît en première position). Par exemple nous obtenons la séquence
à partir de la permutation 4 5 1 6 2 3:

4 5 1 6 2 3
6 1 5 4 2 3
3 2 4 5 1 6
4 2 3 5 1 6
5 3 2 4 1 6
1 4 2 3 5 6

Le but de ce stage est de construire par programme les instances les
plus difficiles, c'est-à-dire d'identifier pour un n donné les
permutations de taille n qui nécessitent le plus grand nombre de
renversements pour placer 1 en première position.*/
#define _BSD_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <float.h>
#include "rank.h"

void copy_permutation(unsigned short *src, unsigned short *dest, int size){
	int i;

	for(i=0 ; i<SIZE ; i++)
		dest[i]=src[i];
}

int main(int argc, char *argv[]) {
	List list=NULL;
	int count;
	long int rank=0;
	int max_permutation=0;
	unsigned short origin[SIZE];
	unsigned short copy[SIZE];

	fact=factorial(SIZE,1);
	
	while(rank < fact){
		id_permutation(origin,SIZE);
		unrank(SIZE,rank,origin);
		copy_permutation(origin,copy,SIZE);

		for(count=0 ; copy[0]!=0 ; count++){
			switch_permutation(copy,SIZE);
		}
		if(count == max_permutation){
			insert_list(&list,origin);
		}
		if(count > max_permutation){
			max_permutation=count;
			free_list(&list);
			insert_list(&list,origin);
			printf("Changement! %d\n",max_permutation);
			display_tab(origin,SIZE);
		}
		rank++;
	}
	return 0;
}
