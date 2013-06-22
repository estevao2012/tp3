
node* init_no(){
	node* n;
	n = (node*)malloc(sizeof(node*));
	return n;
}
void mostra_lista(lista *memoria){
	node *tmp;
	tmp = memoria->inicio->proximo;
	while(tmp->proximo != NULL){
		printf("%d %ld %c\n", getAcesso(tmp->page) ,getEndereco(tmp->page) ,getRw(tmp->page));
		tmp = tmp->proximo;
	}
}
void insere_no(lista *memoria, page* val){
	node* tmp = init_no();
	tmp->page = val;
	tmp->proximo = memoria->inicio->proximo;
	memoria->inicio->proximo = tmp;
	memoria->tamanho++;
	
}
void remove_no(lista *memoria , long endereco){
	node *tmp,*aux;
	tmp = memoria->inicio;
	while(tmp->proximo != NULL){
		if(tmp->proximo->page->endereco == endereco){
			aux = tmp->proximo;
			tmp->proximo = aux->proximo;
			aux->proximo = NULL;
			aux = NULL;
			memoria->tamanho--;
			break;
		}
		tmp = tmp->proximo;
	}
}

void remove_ultimo(lista *memoria){
	node *tmp = memoria->inicio;
	while(tmp->proximo->proximo != NULL)
		tmp = tmp->proximo;
	tmp->proximo = NULL;
}
int busca_pagina(lista *memoria , page *p){

	node *tmp;
	tmp = memoria->inicio->proximo;

	// if(memoria->tamanho > 0){
	while(tmp->proximo != NULL){
		if( p->endereco == tmp->page->endereco) return 1;
		tmp = tmp->proximo;
	}
	// }
	return 0;
}

lista* init_lista(){
	lista *memoria;
	memoria = (lista*)malloc(sizeof(lista*));
	memoria->inicio = init_no();
	memoria->tamanho = -1;
	page* p = init_pag();
	insere_no(memoria,p); //Corrige o erro do primeiro insert nao ser valido
	return memoria;
}