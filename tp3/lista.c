node* init_no(){
	node* n;
	n = (node*)malloc(sizeof(node*));
	return n;
}
lista* init_lista(){
	lista* l;
	l = (lista*)malloc(sizeof(lista*));
	l->inicio = init_no();
	l->inicio->proximo = NULL;
	return l;
}
void mostra_lista(lista *l){
	node *tmp;
	tmp = l->inicio->proximo;
	while(tmp->proximo != NULL){
		printf("%d\n", tmp->page->indice);
		tmp = tmp->proximo;
	}

}
void insere_no(lista* l, int val){
	node* tmp = init_no();
	page* p = init_pag();

	setIndice(p,val);
	tmp->page = p;

	if(l->inicio->proximo == NULL){
		tmp->proximo = NULL;
		l->inicio->proximo = tmp;
	}else{
		tmp->proximo = l->inicio->proximo;
		l->inicio->proximo = tmp;
		
	}
	
	printf("valor:%d\n", getIndice(tmp->page) );
}
void remove_no(lista *l , int indice_page){

	node *tmp,*aux;
	tmp = l->inicio;
	while(tmp->proximo != NULL){
		if(tmp->proximo->page->indice == indice_page){
			aux = tmp->proximo;
			tmp->proximo = aux->proximo;
			aux->proximo = NULL;
			aux = NULL;
			break;
		}
		tmp = tmp->proximo;
	}

}