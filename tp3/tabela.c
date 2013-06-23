int Log2(int n){
	int total = 2;
	int i=1;
	for(i=1; total < n ;i++)
		total=total*2;

	return i;
}
int expo(int base, int expo){
	int i;
	int tmp = base;
	for(i=1;i<expo;i++) {
		tmp = tmp*base;
	}
	return tmp;
}

void T_inicializa(int tam_pagina){

	long int tam_p_bytes = tam_pagina*1024;
	int num_bits = Log2( tam_p_bytes);
	int num_bits_tabela = 32-num_bits;
	int i;
	long int tamanho_tabela;
	tamanho_tabela = expo(2 , num_bits_tabela);
	printf("%ld\n",  tamanho_tabela);

	TABELA_PAGINA = (int*)malloc(sizeof(int) * tamanho_tabela);

	for(i=0;i<tamanho_tabela;i++)
		TABELA_PAGINA[i] = -1;

}
