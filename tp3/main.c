#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "globais.h"
#include "page.h"
#include "tabela.h"
#include "memoria.h"
#include "funcoes.c"

int main(int argc , char **argv)
{
    //Variaveis

	int tamanho_pagina,tamanho_memoria,qnt_paginas;
	unsigned addr;
    char rw;
    page* tmp_page;
    FILE *f_log = fopen(argv[2], "r"); //Abre Pagina
    int mod_debug = 1;

    //Define Memoria Pagina e Qnt Paginas
    tamanho_pagina = atoi(argv[3]);
    tamanho_memoria = atoi(argv[4]);
    if(argv[5] != NULL) mod_debug = atoi(argv[5]);

    // qnt_paginas = tamanho_memoria / tamanho_pagina;
    qnt_paginas = 4;
    M_inicializa(qnt_paginas);
    T_inicializa(tamanho_pagina);

    printf("Executando o simulador...\n");

	while (fscanf(f_log,"%x %c",&addr,&rw) != EOF) {
        TEMPO++;
        tmp_page = setAll(TEMPO , &rw , determina_pagina(tamanho_pagina,addr) , TEMPO);
        if(!strcmp (argv[1] , "fifo"))
            page_faults = page_faults+fifo(tmp_page,qnt_paginas);
        
        else if(!strcmp (argv[1] , "lru"))
            page_faults = page_faults+lru(tmp_page,qnt_paginas);
        
        else if(!strcmp (argv[1] , "random"))
            page_faults = page_faults+aleatorio(tmp_page,qnt_paginas);

        if(mod_debug){ printf("inserir atual : %ld qnt fault:%d\n" , getEndereco(tmp_page),page_faults);M_mostra(qnt_paginas); }
	}
    
    
    //Status FInal
    printf("Arquivo de entrada: %s\n", argv[2] );
    printf("Tamanho da memoria: %d\n", tamanho_memoria);
    printf("Tamanho das paginas: %d\n", tamanho_pagina);
    printf("Tecnica de reposicao: %s\n", argv[1] );
    printf("Paginas lidas:%d\n", page_faults );
    printf("Paginas escritas:%d\n", paginas_sujas );
    
}	
