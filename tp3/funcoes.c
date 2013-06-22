void atualiza_acesso(lista *memoria, page* p){
	remove_no(memoria,p->endereco);
	insere_no(memoria,p);
}

long determina_pagina(unsigned page_size, unsigned addr){
	unsigned s, tmp ,page;
	tmp = page_size;
	s = 0;
	while (tmp>1) {
		tmp = tmp>>1;
		s++;
	}
	page = addr >> s; 
	return page;
}

int fifo(lista *memoria,page *p,int qnt_paginas){
	int page_fault = 0;
	if(busca_pagina(memoria,p) == 0){
		if(qnt_paginas <= memoria->tamanho){
			remove_ultimo(memoria);
			insere_no(memoria,p);
		}else{
			insere_no(memoria,p);
		}
		page_fault++;
	}
	return page_fault;
		
}

int lru(lista *memoria , page *p , int qnt_paginas){
	
	if(busca_pagina(memoria,p) == 0) return fifo(memoria,p,qnt_paginas);
	atualiza_acesso(memoria,p);
	return 0;
}

int aleatorio(lista *memoria , page *p , int qnt_paginas){
	int page_fault=0;
	int indice;
	
	if(busca_pagina(memoria,p) == 0){

		if(qnt_paginas <= memoria->tamanho){
			node *tmp = memoria->inicio;
			indice = (random() % qnt_paginas);
			do{
				tmp = tmp->proximo;
				indice--;
			}while(indice >= 0);
			remove_no(memoria,getEndereco(tmp->page));
			insere_no(memoria,p);
		}else insere_no(memoria,p);
		

		page_fault++;

	}else{
		atualiza_acesso(memoria,p);
	}
	return page_fault;

}