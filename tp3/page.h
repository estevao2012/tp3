#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char rw[1];
	long endereco; 
	int acesso;
	int indice;
}page;


page* init_pag();

void setIndice(page* p ,int i);
void setRw(page* p ,char* c);
void setEndereco(page* p ,long i);
void setAcesso(page* p ,int i);
page* setAll(int indice , char *rw, long endereco , int acesso);
int getIndice(page* p);
char getRw(page* p);
long getEndereco(page* p);
int getAcesso(page* p);

#include "page.c"