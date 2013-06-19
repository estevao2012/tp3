unsigned determina_pagina(unsigned page_size, unsigned addr){
	unsigned s, tmp ,page;

	/* Derivar o valor de s: */
	tmp = page_size;
	s = 0;
	while (tmp>1) {
		tmp = tmp>>1;
		s++;
	}
	page = addr >> s;
	printf("%d\n", page_size );
	printf("%d %d %x\n", page,s,addr );
	return page;
}