#include <stdio.h>
#include "list.h"


void swap(unsigned short *a, unsigned short *b) {
	unsigned short tmp=*a;
	*a=*b;
	*b=tmp;
}

List allocate_cell(unsigned short *table){
	List new;
	if(NULL == (new=(List)malloc(sizeof(Cell)))){
		perror("malloc allocate_cell");
		exit(EXIT_FAILURE);
	}
	new->rank=malloc(sizeof(short)*SIZE);
	new->rank=table;
	new->next=NULL;
	
	return new;	
}

List insert_list(List *list, unsigned short *tab){
	Cell *new;
	if((new=allocate_cell(tab)) == NULL){
		perror("malloc insert_list");
		exit(EXIT_FAILURE);
	}
	if((*list) != NULL){
		new->next=*list;
	}

	return new;	
}

void free_list(List *list){
	Cell *tmp;
	while((*list) != NULL) {
		tmp = *list;
		(*list) = (*list)->next;
		free(tmp->rank);
		free(tmp);
	}
	tmp = NULL;
}

void display_list(List list){
	int i;
	List copy=list;

	while( copy != NULL ){
		printf("[ ");
		for(i=0 ; i < SIZE ; i++){
			printf("%d ",copy->rank[i] );
		}
		printf("] ");
		copy=copy->next;
	}
	printf("\n");
}