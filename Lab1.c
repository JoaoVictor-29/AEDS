#include <stdio.h>
#include "lista.h"
#include <stdlib.h>

/*inicializa a lista como lista vazia*/
void inicializa_lista(Lista * ap_lista){
        ap_lista ==NULL;
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

	at -> proximo = no_novo;
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
    No * no_novo = (*ap_lista);
	No *anterior = NULL;
    int valorRemovido;

        /*se a lista estiver vazia*/
    if(*ap_lista == NULL)
            return -1;

        /*se tiver apenas um no na lista*/
    if(no_novo -> proximo == NULL){
            valorRemovido =  no_novo -> valor;
            free(no_novo);
            (*ap_lista) = NULL;
            return valorRemovido;
    }

        /*percorre a lista até achar o ultimo no*/
    while(no_novo -> proximo != NULL){
            anterior = no_novo;
            no_novo = no_novo -> proximo;
    }

        /*coloca o valor na variavel pra retornar*/
     valorRemovido = no_novo -> valor;

     /*libera a memoria do no removido pra nao vazar memoria*/
    free(no_novo);

    /*desvincular o ultimo no da lista*/
	anterior -> proximo = NULL;
    return valorRemovido;
}

/*Remove valor do inicio da lista apontada por ap_lista e retorna este valor*/
int remove_inicio(Lista * ap_lista){
        No *no_novo;
        int valorRemovido;

        /*verificar se a lista ta vazia*/
        if(*ap_lista == NULL)
                return -1;

        //Armazena o nó que vai ser removido
        no_novo = (*ap_lista);
        //Salva o valor do nó
        valorRemovido = no_novo -> valor;
        //Atualiza o inicio da lista para o proximo nó
        (*ap_lista) = no_novo -> proximo;
        //libera memória
        free(no_novo);

        return valorRemovido;
}

/*Remove o i-ésimo da lista, caso ele exista. Retorna se o elemento
foi removido. As posições são contadas a partir de 1, sendo 1 a primeira posição*/
bool remove_i_esimo(Lista * ap_lista, int i){
    No *no_novo = *ap_lista;
	No *anterior == NULL;
    int cont = 1;
        //Verificar se a lista está vazia
    if(*ap_lista == NULL)
            return -1;

        //percorre a lista até encontrar a posição do elemento
        //anterior vai ficar i-1 e no_novo vai ficar na posição do elemento
    while(no_novo != NULL && cont < i){
            anterior = no_novo;
            no_novo = no_novo -> proximo;
            cont++;
    }

    if(no_novo == NULL)
        	return -1;

	if(i == 1){
		*ap_lista = no_novo -> proximo;//aqui atualiza o inicio/cabeça da lista
	}else{
		anterior -> proximo = no_novo -> proximo;//aqui remove o nó ligando o anterior ao próximo
	}
	free(no_novo);
	return 0;
}


/*Retorna o valor do i-ésimo elemento da lista, caso ele exista.
Retorna -1 caso contrário. As posições são contadas a partir  de 1, sendo 1 a primeira posição*/
int recupera_i_esimo(Lista lista, int i){
		No *no_novo = lista;
		int cont = 1;
		//verificar se a lista está vazia
		if(lista == NULL || i <= 0)
			return -1;

		//Percorre a lista até achar
		while(no_novo != NULL && cont < i){
			no_novo = no_novo -> proximo;
			cont++;
		}

	if(no_novo != NULL && cont == i){
		return no_novo -> valor;
	}
}

/* Retorna o tamanho da lista */
int tamanho(Lista lista){
	No *no_novo = lista;
	int cont = 0;

	if(lista == NULL)
		return 0;
	while(no_novo != NULL){
		cont++;
		no_novo = no_novo -> proximo;
	}
	return cont;
}

/* Remove todas as ocorrências de valor da lista apontada por ap_lista.
 * Retorna o número de ocorrências removidas */
int remove_ocorrencias(Lista *ap_lista, int valor){
        if(*ap_lista == NULL)
                return 0;

        No *no_atual = (*ap_lista);
        No *anterior = NULL;
        No *aux;
        int cont = 0;

        while(no_atual != NULL){
                if(no_atual -> valor == valor){
                        if(anterior == NULL){
                                *ap_lista = no_novo -> proximo;
                        }else{
                                anterior -> proximo = no_novo -> proximo;
                        }
                        cont++;
                        aux = no_novo;
                        no_novo = no_novo -> proximo;
                        free(aux);
                }else{
                        anterior = no_novo;
                        no_novo = no_novo -> proximo;
        }
        return cont;
}


/* Busca elemento valor na lista.
 * Retorna a posição na lista, começando de 1 = primeira posição.
 * Retorna -1 caso não encontrado. */
int busca(Lista lista, int valor){
        if(lista == NULL)
                return 0;

        No *no_novo = (lista);
        int cont = 1;

        while (no_novo != NULL){
                if(no_novo -> valor == valor){
                        return cont;
                }else{
                        no_novo = no_novo -> proximo;
                        cont++;
                }
        }
        return 0;
}


/* Imprime a lista na saída padrão, no formato:
 * (1,3,2,3,4,2,3,1,4)
 * em uma linha separada. */
void imprime(Lista lista){
	No *no_novo = (lista);
	printf("(");

	while(no_novo != NULL){
		printf("%d", no_novo -> valor);
		if(No_novo -> proximo = NULL){
			printf(",");
		}
		no_novo = no_novo -> proximo;
	}
	printf(")");	
}

/* Desaloca toda a memória alocada da lista. */
void desaloca_lista(lista * ap_lista){
	No *atual = (*ap_lista);
	No *desaloca = atual;
	
	While(atual != atual){
		desaloca = atual;
		atual = atual -> proximo;
		free(desaloca);
	}
	(*ap_lista) = NULL;
}

    
