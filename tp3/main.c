#include <stdlib.h>
#include <stdio.h>
#include "page.h"
#include "tabela.h"
#include "lista.h"
#include "funcoes.c"


int main(int argc , char **argv)
{
    //Variaveis
    int TEMPO = 0;
	int tamanho_pagina,tamanho_memoria,qnt_paginas,endereco;
	unsigned addr;
    char rw;
    page* tmp_page;
    lista *l = init_lista();
    FILE *f_log = fopen(argv[2], "r"); //Abre Pagina

    //Define Memoria Pagina e Qnt Paginas
    tamanho_pagina = atoi(argv[3]);
    tamanho_memoria = atoi(argv[4]);
    qnt_paginas = tamanho_memoria / tamanho_pagina;
    printf("%d\n", qnt_paginas );
    //Le do arquivo
	while (fscanf(f_log,"%x %c",&addr,&rw) != EOF) {
        TEMPO++;
        tmp_page = init_pag();
		setEndereco(tmp_page,determina_pagina(tamanho_pagina,addr));
        setRw(tmp_page,&rw);
        setAcesso(tmp_page,TEMPO);
        insere_no(l,tmp_page);
	}

    mostra_lista(l);
}	
