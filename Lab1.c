#include <stdio.h>
#include "lista.h"

/*inicializa a lista como lista vazia*/
void inicializa_lista(Lista * ap_lista){
	ap_lista -> valor = 0;
}

/*Insere valor no fim da lista por ap_lista. ap_lista aponta para o inicio da lista*/
void insere_fim(Lista * ap_lista, int valor){
	No * no_novo = (No*) malloc (sizeof(No));
	no_novo -> valor = valor;
	no_novo -> proximo = NULL;
	if(*ap_lista == NULL){
		(*ap_lista) = no_novo;
		return;
	}
	No * at = *ap_lista;
	while(at -> proximo != NULL){
		at = at -> proximo;
	}
	at -> proximo = no;
}

/*Insere valor no inicio da lista apontada por ap_lista*/
void insere_inicio(Lista * ap_lista, int valor){
	No * no_novo = (No *)malloc(sizeof(No));
	no_novo -> valor = valor;
	no_novo -> proximo = (*ap_lista);
	(*ap_lista) = no_novo;
}

/*Remove valor do fim da lista apontada por ap_lista e retorna esse valor*/
int remove_fim(Lista * ap_lista){
	No * no_novo, *anterior;

}

int remove_inicio(Lista * ap_lista){

}

bool remove_i_esimo(Lista * ap_lista, int i){

}

int recupera_i_esimo(Lista lista, int i){

}

int tamanho(Lista lista){

}

int remove_ocorrencias(Lista *ap_lista, int valor){

}

int busca(Lista lista, int valor){

}

void imprime(Lista lista){

}

void desaloca_lista(lista * ap_lista){

}
