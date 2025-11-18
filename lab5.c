#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

bool insere(Arvore* ap_arv, int x){
	Arvore aux = *ap_arv;
	while(aux){
		if(x < aux -> valor)
			ap_arv = &aux -> esq;
		else
			ap_arv = &aux -> dir;
		aux = *ap_arv;
	}
	*ap_arv = malloc(sizeof(No));
	if(*ap_arv == NULL)
		return false;

	(*ap_arv) -> valor = x;
	(*ap_arv) -> esq = NULL;
	(*ap_arv) -> dir = NULL;

	return true;	
}

int max(No *ap_arv){
        if(ap_arv -> dir == NULL)
                return ap_arv -> valor;
        return max(ap_arv -> dir);
}


bool remove_(Arvore* ap_arv, int x){
	if(*ap_arv == NULL){
		return false;
	}

	if(x < (*ap_arv) -> valor){
		return remove_(&(*ap_arv) -> esq, x);
	}
	if(x > (*ap_arv) -> valor){
		return remove_(&(*ap_arv) -> dir, x);
	}

	if((*ap_arv) -> esq == NULL){
		No * removido = (*ap_arv);
		(*ap_arv) = removido -> dir;
		free(removido);
		return true;
	}

	if((*ap_arv) -> dir == NULL){
		No *removido = (*ap_arv);
		(*ap_arv) = removido -> esq;
		free(removido);
		return true;
	}

	int maximo = max((*ap_arv) -> esq);
	(*ap_arv) -> valor = maximo;
	remove_(&(*ap_arv) -> esq, maximo);
	return true;
}

bool busca(Arvore arv, int x){
	if(arv == NULL)
		return false;
	if(arv -> valor == x)
		return true;
	if(x < arv -> valor)
		return busca(arv -> esq, x);
	return busca(arv -> dir, x);
}

void imprime(Arvore arv){
	if(arv == NULL){
		printf(".");
		return;
	}
	printf("[%d:", arv -> valor);
	printf("e=");
	imprime(arv -> esq);
	printf(" ,d=");
	imprime(arv -> dir);
	printf("]");

}
