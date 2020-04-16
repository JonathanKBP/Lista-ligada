#include "lista.h"

int conta_nos(struct lista *l){
	struct no *aux;
	int cont=0;
	if(lista_vazia(l))
		return 0;
	aux = l->prim;
	while(aux != NULL){//vai ate o final da lista 
		cont ++;
		aux = aux->prox;
	}	
	return cont;
}

int media_nos(struct lista *l){
	struct no *aux;
	int cont = 0, soma = 0;
	if(lista_vazia(l))
		return -1;
	aux = l->prim;
	while(aux != NULL){//vai ate o final da lista 
		cont ++;
		soma+=aux->info;
		aux = aux->prox;
	}	
	return (float) soma/cont;
}

struct lista * constroi_lista(){
	struct lista * l = (struct lista *) malloc (sizeof(struct lista));
	if(l){
		l->prim = NULL;
	}
	return l;
}

int lista_vazia(struct lista *l){
	/*if(l->prim == NULL)
		return 1;
	return;*/
	return !l->prim;
}

int insere_inicio(int i, struct lista *l){
	struct no *novo = constroi_no(i);	
	if(novo){
		if(!lista_vazia(l)){
			novo-> prox = l->prim;
		}
		l->prim = novo;
		return 1;
	}
	return 0;
}

void mostra_lista(char *msg, struct lista *l){
	struct no *aux;
	printf("\n%s \n", msg);
	if(lista_vazia(l))
		printf("\nLista vazia.");
	else{
		aux = l->prim;
		while(aux != NULL){//vai ate o final da lista 
			printf("%d ", aux->info);
			aux = aux->prox;
		}
	}
	printf("\n");
}
 
int insere_fim(int i, struct lista *l){
	struct no *novo = constroi_no(i);
	struct no *aux;
	if(novo){
		if (lista_vazia(l)){
			l->prim = novo;
		}
		else{
			aux = l->prim;
			while(aux->prox != NULL){//VAI ATE O ULTIMO DA LISTA 
				aux = aux->prox;
			}
			aux->prox = novo;
		}
		return 1;
	}
	return 0;
}

int remove_inicio(int *i, struct lista *l){
	struct no *aux;
	if(lista_vazia(l))
		return 0;
	aux = l->prim;//endereço do primeiro elemento da lista
	*i=aux->info;
	l->prim = l->prim->prox;
	free(aux);
	return 1;
}


int remove_fim(int *i, struct lista *l){
	struct no *aux;
	if(lista_vazia(l)){
		return 0;
	}
	if(l->prim->prox == NULL){// só tem um
		return remove_inicio(i, l);
	}
	aux = l->prim;
	while(aux->prox->prox != NULL){ // vai até o penúltimo
		aux = aux -> prox;
	}
	*i = aux->prox->info;
	free(aux->prox);
	aux->prox = NULL;
	return 1;
}

int remove_todas_ocorrencias (int n, struct lista *l){
	int cont = 0;
	struct no * atual, * anterior;
	while(!lista_vazia(l) && l->prim->info == n){
		cont ++;
		remove_inicio(&n, l);
	}
	if(lista_vazia(l)){
		return cont;
	}
	atual = l->prim->prox;
	anterior = l->prim;
	while(atual != NULL){
		if(atual->info == n){
			cont++;
			anterior->prox = atual->prox;
			free(atual);
			atual = anterior->prox;
		}
		else{
			anterior = atual;
			atual = atual->prox;
		}
	}
	return cont;	
}


