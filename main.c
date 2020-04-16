#include "lista.h"

void teste_no(){
	struct no *no1 = constroi_no(3);
	struct no *no2 = constroi_no(7); 
	
	if(no1 && no2){
		printf("\nOnde esta o no1: %p", no1);
		printf("\nValor armazenado la: %d", no1->info);
		printf("\nValor do campo proximo: %p", no1->prox);
		  
		printf("\nOnde esta o no2: %p", no2);
		printf("\nValor armazenado la: %d", no2->info);
		printf("\nValor do campo proximo: %p", no2->prox);
		
		//ligação 
		
		no1->prox = no2;
		no2->prox = no2;
			  
		printf("\nValor armazenado la: %d", no1->prox->info);
	} 
	else{
		printf("\nFalha na alocacao de memoria.\n");
	}
	/*
	trava:
	while(1){
		no2 = constroi_no(7);
	}*/	
}

//%p == ponteiro, pointer 

void teste_lista(){
	struct lista *l = constroi_lista();
	int n;
	if(l){
		printf("\nLista criada com sucesso.\n");
		insere_inicio(3, l);
		insere_inicio(5, l);
		insere_inicio(7, l);
		mostra_lista("lista depois das insercoes de inicio", l); 
		insere_fim(2, l);
		insere_fim(4, l);
		insere_fim(6, l);
		mostra_lista("lista depois das insercoes de fim", l); 
		if(remove_inicio(&n, l)==1){
			printf("\n%d foi removido do inicio", n);
			mostra_lista("lista depois da remocao de inicio", l);
		}
		if(remove_fim(&n, l)){
			printf("\n%d foi removido do fim", n);
			mostra_lista("lista depois da remocao de fim", l);
		}
	}
	else{
		printf("\nFalha na alocacao de memoria.\n");
	}
}

/*
int main(int argc, char *argv[]) {
    //teste_no();
	teste_lista();
	return 0;
}*/

#include <time.h>

/*int main(int argc, char *argv[]) {
	struct struct struct lista_dupla * l = cria_struct struct struct lista_dupla();
	int i;
	insere_inicio_dupla(2, l); 	
	insere_inicio_dupla(4, l);
	insere_inicio_dupla(6, l);
	mostra_struct struct struct lista_dupla("lista depois das insercoes de inicio", l);
	insere_fim_dupla(1, l); 	
	insere_fim_dupla(3, l);
	insere_fim_dupla(5, l);
	mostra_struct struct struct lista_dupla("lista depois das insercoes de fim", l);
	if(remove_inicio_dupla(&i, l)){
		printf("\n%d saiu do inicio", i);		
		mostra_struct struct struct lista_dupla("lista depois da remocao de inicio", l);		
	}
	else{
		printf("\nFalha na remocao\n");
	}
	if(remove_fim_dupla(&i, l)){
		printf("\n%d saiu do fim", i);
		mostra_struct struct struct lista_dupla("lista depois da remocao de fim", l);		
	}
	else{		
		printf("\nFalha na remocao\n");		
	}
	return 0;
}*/

//cadeiras
/*int main (){
	int i, j,k, batedor;
	struct no_duplo * aux;
	struct lista_dupla *l = cria_lista_dupla();
	srand(time(0));
	for(i=1; i<=12; i++){
		insere_fim_dupla(i, l);
	}
	mostra_lista_dupla ("cadeias: ", l);
	k = rand() % 20;//numero ate 19
	printf("\n k = %d\n", k);
	aux = l->prim;
	while(l->prim != l->prim->prox){
		for(i=1; i<=k; aux = aux->prox, i++);
		batedor = aux->prox;
		remove_por_ponteiro(aux, &j, l);
		printf("\n%d dancou", j);
		aux = batedor;
	}
	mostra_lista_dupla("\nQuem ganhou", l);
	return 0;
}
*/

int main (){
	struct lista *l = constroi_lista();
	int i;
	insere_fim(1,l);
	insere_fim(2,l);
	insere_fim(2,l);
	insere_fim(3,l);
	//insere_fim(1,l);
	insere_fim(2,l);
	//insere_fim(2,l);
	//insere_fim(2,l);
	//insere_fim(4,l);
	//insere_fim(2,l);
	insere_fim(3,l);
	//insere_fim(2,l);
	//insere_fim(2,l);
	mostra_lista("depois que inseriu", l);
	i = remove_todas_ocorrencias(2,l);
	printf("\nforam removidas %d ocorrencias\n", i);
	mostra_lista("depois que removeu", l);
	buscar_elemento(3, l);
	return 0;
}
	


