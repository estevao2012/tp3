#include <stdlib.h>
#include <stdio.h>

struct no{
	struct no* proximo;
	page *page;
	int indice;
};

typedef struct no node;

typedef struct{
	node* inicio;
	int tamanho;
}lista;

node* init_no();
void mostra_lista(lista *l);
void insere_no(lista* l, page* val);
void remove_no(lista *l , int indice_page);
lista* init_lista();

#include "lista.c"