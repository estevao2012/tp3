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
void mostra_lista(lista *memoria);
void insere_no(lista*memoria, page* val);
void remove_no(lista *memoria , long endereco_page);
lista* init_lista();

#include "lista.c"