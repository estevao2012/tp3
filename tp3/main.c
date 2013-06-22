
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
    lista *memoria = init_lista();
    FILE *f_log = fopen(argv[2], "r"); //Abre Pagina
    int mod_debug = 1;

    //Variaveis para estatistica
    int qnt_page_faults = 0;
    int paginas_sujas = 0;

    //Define Memoria Pagina e Qnt Paginas
    tamanho_pagina = atoi(argv[3]);
    tamanho_memoria = atoi(argv[4]);
    if(argv[5] != NULL) mod_debug = atoi(argv[5]);

    // qnt_paginas = tamanho_memoria / tamanho_pagina;
    qnt_paginas = 4;

    printf("Executando o simulador...\n");

	while (fscanf(f_log,"%x %c",&addr,&rw) != EOF) {
        TEMPO++;
        
        tmp_page = setAll(TEMPO , &rw , determina_pagina(tamanho_pagina,addr) , TEMPO);
        if(!strcmp(&rw,"W")) paginas_sujas++;

        qnt_page_faults = qnt_page_faults+aleatorio(memoria,tmp_page,qnt_paginas);
        
        if(mod_debug){ printf("inserir atual : %ld qnt fault:%d\n" , getEndereco(tmp_page),qnt_page_faults); mostra_lista(memoria);}
	}
    
    //Status FInal
    printf("Arquivo de entrada: %s\n", argv[2] );
    printf("Tamanho da memoria: %d\n", tamanho_memoria);
    printf("Tamanho das paginas: %d\n", tamanho_pagina);
    printf("Tecnica de reposicao: %s\n", argv[1] );
    printf("Paginas lidas:%d\n", qnt_page_faults );
    printf("Paginas escritas:%d\n", paginas_sujas );
}	
