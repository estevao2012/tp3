void setIndice(page* p ,int i){
	p->indice = i; 
}
void setPermissao(page* p ,int i){
	p->permissao = i; 
}
int getIndice(page* p){
	return p->indice;
}
int getPermissao(page* p){
	return p->permissao;
}

page* init_pag(){
	page* p;
	p = (page*)malloc(sizeof(page*));
	return p;
}