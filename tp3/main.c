#include <stdlib.h>
#include <stdio.h>
#include "page.h"
#include "tabela.h"
#include "lista.h"
#include "funcoes.c"

int main(int argc , char **argv)
{
	int tamanho_pagina;
	int tamanho_memoria;
	unsigned addr;
    char rw;
    int endereco;
    lista *l;
    l = init_lista(); 
    insere_no(l,-1);
    // insere_no(l,2);
    // insere_no(l,3);
    mostra_lista(l);
    printf("removendo no\n");
    remove_no(l,1);
    printf("no removido\n");
    mostra_lista(l);

	tamanho_pagina = atoi(argv[3]);
	tamanho_memoria = atoi(argv[4]);

	FILE *f_log;
	f_log = fopen(argv[2], "r");

	while (fscanf(f_log,"%x %c",&addr,&rw) != EOF) {
		printf("%x %x\n", tamanho_pagina, determina_pagina(tamanho_pagina , addr) );
	}
}	