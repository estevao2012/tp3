void M_inicializa(int qnt_pag){
	MEMORIA = (page**)malloc(sizeof(page**) * qnt_pag);
	int i;
	for(i=0;i<qnt_pag;i++){
		MEMORIA[i] = NULL;
	}
}

int M_busca(page* pagina,int qnt_paginas){
	int i = 0;
	while(i < qnt_paginas){
		if( MEMORIA[i] != NULL && getEndereco(MEMORIA[i]) == getEndereco(pagina) ) return i;
		i++;
	} 
	return -1;
}

int M_busca_antigo(int qnt_paginas){
	int tempo = TEMPO;
	int tmp = 0;
	int indice = 0;
	int i;
	for(i=0 ; i < qnt_paginas ; i++){
		tmp = getAcesso(MEMORIA[i]);
		if(tmp < tempo){
			tempo = tmp;
			indice = i;
		}
	}
	return indice;
}

void M_mostra(int qnt_paginas){
	int i;
	for(i=0;i< qnt_paginas ; i++){
		if(MEMORIA[i] != NULL)printf("%ld %d %c\n", getEndereco(MEMORIA[i]) , getAcesso(MEMORIA[i]) , getRw(MEMORIA[i]));
	}
}