long determina_pagina(unsigned page_size, unsigned addr){
	unsigned s, tmp ,page;
	tmp = page_size*1024;
	s = 0;
	while (tmp>1) {
		tmp = tmp>>1;
		s++;
	}
	page = addr >> s; 
	return page;
}

int fifo(page *p,int qnt_paginas){
	// int i = M_busca(p,qnt_paginas);
	int i = TABELA_PAGINA[getEndereco(p)];
	page *tmp;
	if(i == -1){
		i = 0;
		while(MEMORIA[i] != NULL && i < qnt_paginas)i++;
		if(i == qnt_paginas){
			i = M_busca_antigo(qnt_paginas);
			if(!strcmp(MEMORIA[i]->rw ,"W"))paginas_sujas++;
		}

		if(MEMORIA[i] != NULL){
			tmp = MEMORIA[i];
			TABELA_PAGINA[getEndereco(tmp)] = -1;
		}
		TABELA_PAGINA[getEndereco(p)] = i;
		MEMORIA[i] = p;
		return 1;
	}

	return 0;
}

int lru(page *p , int qnt_paginas){
	
	int i = TABELA_PAGINA[getEndereco(p)];
	page *tmp;
	if(i == -1){
		i = 0;
		while(MEMORIA[i] != NULL && i < qnt_paginas)i++;
		if(i == qnt_paginas){
			i = M_busca_antigo(qnt_paginas);
			if(!strcmp(MEMORIA[i]->rw ,"W"))paginas_sujas++;
		}
		if(MEMORIA[i] != NULL){
			tmp = MEMORIA[i];
			TABELA_PAGINA[getEndereco(tmp)] = -1;
		}
		TABELA_PAGINA[getEndereco(p)] = i;
		MEMORIA[i] = p;
		return 1;
	}else setAcesso(MEMORIA[i],getAcesso(p));
	
	return 0;
}

int aleatorio(page *p , int qnt_paginas){
	// int i = M_busca(p,qnt_paginas);
	int i = TABELA_PAGINA[getEndereco(p)];
	page *tmp;
	if(i == -1){
		i = 0;
		while(MEMORIA[i] != NULL && i < qnt_paginas)i++;
		if(i == qnt_paginas){
			i = random() % qnt_paginas;
			if(!strcmp(MEMORIA[i]->rw ,"W"))paginas_sujas++;
		}

		if(MEMORIA[i] != NULL){
			tmp = MEMORIA[i];
			TABELA_PAGINA[getEndereco(tmp)] = -1;
		}
		TABELA_PAGINA[getEndereco(p)] = i;
		MEMORIA[i] = p;
		return 1;
	}

	return 0;

}