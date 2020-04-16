# include "no.h"

struct no * constroi_no (int i){
	struct no * aux = (struct no *) malloc (sizeof(struct no)); 
	if (aux) {
		aux -> info = i;
		aux -> prox = NULL;
	}
	return aux;
}

