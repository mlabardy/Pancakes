#include <stdio.h>
#include "rank.h"


void display_tab(unsigned short *tab, int size){
	int i;

	for(i=0 ; i < size ; i++)
		printf("%d ",tab[i]+1);
	printf("\n");
}

/*--------------------------------Switch--------------------------------------*/

void switch_permutation(unsigned short *tab, int size){
	int n=tab[0]+1;
	int i;

	for( i=0 ; i < n/2 ; i++){
		swap(&tab[i],&tab[n-i-1]);
	}
}

/*--------------------Nouvelles fonctions-------------------------------------*/
void id_permutation(unsigned short *dest, int size) {
	int i;
	for(i=0 ; i<size ; i++) {
		dest[i]=i;
	}
}

void random_permutation(unsigned short *tab, int size) {
	int i;
	unsigned char random;
	int tmp;
	
	id_permutation(tab, size);
	srand(time(NULL));
	for(i=0 ; size!=0 ; i++){
		random=rand()%(size);
		tmp=tab[random];
		tab[random]=tab[size-1];
		tab[size-1]=tmp;
		size--;
	}
}

void inverse_permutation(unsigned short *src, unsigned short *dest, int size) {
	int i;
	for(i=0 ; i<size ; i++) {
		dest[src[i]]=i;
	}
}

long rank(int n, unsigned short *tab, unsigned short *tab_inv) {
	long s;
	if(n==1)	return 1;
	else {
		s=tab[n-1];
		swap(&tab[n-1], &tab[tab_inv[n-1]]);
		swap(&tab_inv[s], &tab_inv[n-1]);
	}
	return (s+n*rank(n-1, tab, tab_inv));
}

void unrank(int n, int r, unsigned short *tab) {
	if (n>0) {
		swap(&tab[n-1], &tab[r%n]);
		unrank(n-1, r/n, tab);
	}
}

/*------------------------------------------------------------------------------*/


long factorial(unsigned short num, long result){
	if(num<=1){
		return result;
	}
	return factorial(num-1, result*num);
}