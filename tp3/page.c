void setIndice(page* p ,int i){	p->indice = i; }
void setRw(page* p ,char* c){p->rw[0] = c[0]; }
void setEndereco(page* p ,long i){	p->endereco = i; }
void setAcesso(page* p ,int i){	p->acesso = i; }

page* setAll(int indice , char *rw, long endereco , int acesso){
	page* p;
	p = init_pag();
	setIndice(p,indice);
	setRw(p,rw);
	setEndereco(p,endereco);
	setAcesso(p,acesso);
	return p;
}

int getIndice(page* p){	return p->indice;}
char getRw(page* p){ return p->rw[0];}
long int getEndereco(page* p){ return p->endereco;}
int getAcesso(page* p){ return p->acesso;}

page* init_pag(){
	page* p;
	p = malloc(sizeof(page*)*sizeof(page*));
	return p;
}