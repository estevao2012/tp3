#include <stdlib.h>
#include <stdio.h>

struct no{
	struct no* proximo;
	page *p;
	int indice;
};

typedef struct no node;

typedef struct{
	node* inicio;
}lista;

#include "lista.c"