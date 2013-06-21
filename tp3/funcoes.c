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

void fifo();

void lru();