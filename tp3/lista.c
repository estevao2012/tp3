
node* init_no(){
	node* n;
	n = (node*)malloc(sizeof(node*));
	return n;
}
void mostra_lista(lista *l){
	node *tmp;
	tmp = l->inicio->proximo;
	while(tmp->proximo != NULL){
		printf("%d %ld %c\n", getAcesso(tmp->page) ,getEndereco(tmp->page) ,getRw(tmp->page));
		tmp = tmp->proximo;
	}
}
void insere_no(lista* l, page* val){
	node* tmp = init_no();
	tmp->page = val;
	tmp->proximo = l->inicio->proximo;
	l->inicio->proximo = tmp;
	l->tamanho++;
	
}
void remove_no(lista *l , long endereco){
	node *tmp,*aux;
	tmp = l->inicio;
	while(tmp->proximo != NULL){
		if(tmp->proximo->page->endereco == endereco){
			aux = tmp->proximo;
			tmp->proximo = aux->proximo;
			aux->proximo = NULL;
			aux = NULL;
			l->tamanho--;
			break;
		}
		tmp = tmp->proximo;
	}
}

void remove_ultimo(lista *l){
	node *tmp = l->inicio;
	while(tmp->proximo->proximo != NULL)
		tmp = tmp->proximo;
	tmp->proximo = NULL;
}
int busca_pagina(lista *l , page *p){

	node *tmp;
	tmp = l->inicio->proximo;

	// if(l->tamanho > 0){
	while(tmp->proximo != NULL){
		if( p->endereco == tmp->page->endereco) return 1;
		tmp = tmp->proximo;
	}
	// }
	return 0;
}

lista* init_lista(){
	lista* l;
	l = (lista*)malloc(sizeof(lista*));
	l->inicio = init_no();
	l->tamanho = -1;
	page* p = init_pag();
	insere_no(l,p); //Corrige o erro do primeiro insert nao ser valido
	return l;
}