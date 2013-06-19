#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int indice;
	int permissao;
}page;

void setIndice(page* p ,int i);
void setPermissao(page* p ,int i);
int getIndice(page* p);
int getPermissao(page* p);
page* init_pag();

#include "page.c"