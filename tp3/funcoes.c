void atualiza_acesso(lista *l, page* p){
	remove_no(l,p->endereco);
	insere_no(l,p);
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

int fifo(lista *l,page *p,int qnt_paginas){
	int page_fault = 0;
	if(busca_pagina(l,p) == 0){
		if(qnt_paginas <= l->tamanho){
			remove_ultimo(l);
			insere_no(l,p);
		}else{
			insere_no(l,p);
		}
		page_fault++;
	}
	return page_fault;
		
}

int lru(lista *l , page *p , int qnt_paginas){
	
	if(busca_pagina(l,p) == 0) return fifo(l,p,qnt_paginas);
	atualiza_acesso(l,p);
	return 0;
}

int aleatorio(lista *l , page *p , int qnt_paginas){
	int page_fault=0;
	int indice;
	node *tmp;
	if(busca_pagina(l,p) == 0){

		if(qnt_paginas <= l->tamanho){
			indice = (random() % qnt_paginas);
			tmp = l->inicio;
			do{
				tmp = tmp->proximo;
				indice--;
			}while(indice >= 0);
			remove_no(l,getEndereco(tmp->page));
			insere_no(l,p);
		}else insere_no(l,p);
		

		page_fault++;

	}else{
		atualiza_acesso(l,p);
	}
	return page_fault;

}