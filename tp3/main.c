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
    int endereco ;

	tamanho_pagina = (int)argv[3];
	tamanho_memoria = (int)argv[4];

	FILE *f_log;
	f_log = fopen(argv[2], "r");

	printf("%i\n", tamanho_pagina );

	while (fscanf(f_log,"%x %c",&addr,&rw) != EOF) {
	 	//printf("%x %c\n",addr, rw );
		//printf("%x\n", determina_pagina(tamanho_pagina , addr) );
	}

}	