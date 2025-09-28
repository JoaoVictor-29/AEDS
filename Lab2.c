#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

Polinomio insereFim(Polinomio pol, int grau, int coef);

//inicializa um polinomio vazio
void inicializa_polinomio(Polinomio * ap_pol){
        *ap_pol = (No*)malloc(sizeof(No));

        if(*ap_pol == NULL)return;

        (*ap_pol) -> prox = *ap_pol;
        (*ap_pol) -> antec = *ap_pol;
}      

/* Define que o coeficiente de grau do pol eh igual a pol. Deve manter os
 * coeficientes ordenados por grau*/
void define_coeficiente(Polinomio pol, int grau, int coef){
    No *novo, *insere;
    insere = (No*)malloc(sizeof(No));
    novo = pol->prox;

    if(coef == 0) return;

    /*essa para pegar o indice para adicionar ordenado
     anterior vai pegar o indice para eu ordenar e quando 
     for adicionado vai ser anteriot mais 1*/
    while (novo != pol && novo->valor.grau < grau)
    {
        novo = novo->prox;
    }
    
    /*mesmo grau ou coeficiente == 0*/
    if(novo != pol && novo->valor.grau == grau){
        novo->valor.coef = coef;
        free(insere);
    }else{
        /*adicona os valores do polinomio*/
        insere->valor.grau = grau;
        insere->valor.coef = coef;

        /*Insere Apos*/
        insere->prox = novo;
        insere->antec = novo->antec;
        novo->antec->prox = insere;
        novo->antec = insere;
    }	        
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memoria
 * liberada*/
void zera(Polinomio pol){
	//criei uma variavel pra apontar para o primeiro nó da lista
        No *novoAp = pol;
	No *prox;
	
	/*percorrer a lista um nó de cada vez
	 * guardar o endereço do proximo no em uma variavel temporaria
	 * liberar a memoria de novoAp
	 * avançar o nó usando o ponteiro temporario. */
	while(novoAp != NULL){
		prox = novoAp -> prox;
		free(novoAp);
		novoAp = prox;
	}
	pol = NULL;
}       

/*Computa a soma dos polinomio a e b colocando o resultado em res.
 * Libera a memoria anteriormente uilizada pelos nos descartados de res, e sobreescreve res.*/
void soma(Polinomio res, Polinomio a, Polinomio b){
       No *atualA, *atualB;
       zera(res);

       atualA = a -> prox;
       atualB = b -> prox;
       int resSoma = 0;

       while(atualA != a || atualB != b){
	       if(atualA != a && atualB != b && atualA ->valor.grau == atualB -> valor.grau){
		       resSoma = atualA -> valor.coef + atualB -> valor.coef;
		       if(resSoma != 0){
			      insereFim(res, atualA -> valor.grau, resSoma);
		       }
		       atualA = atualA -> prox;
		       atualB = atualB -> prox;
	       }else if(atualB == b ||(atualA != a && atualB != b && atualA -> valor.grau > atualB -> valor.grau)){
		       insereFim(res, atualA -> valor.grau, atualA -> valor.coef);
		       atualA = atualA -> prox;
	       }else{
		       insereFim(res, atualB -> valor.grau, atualB -> valor.coef);
		       atualB = atualB -> prox;
	       }
       }
}      		 

/* Computa a subtracao dos polinomios a e b colocando o resultado em res.
 * Libera a memoria anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b){
        No *atualA, *atualB;
	zera(res);

	atualA = a -> prox;
	atualB = b -> prox;
	int subRes = 0;

	while(atualA != a || atualB != b){
		if(atualA != a && atualB != b && atualA -> valor.grau == atualB -> valor.grau){
			subRes = atualA -> valor.coef + atualB -> valor.coef;
			if(subRes != 0){
				insereFim(res, atualA -> valor.grau, subRes);
			}
			atualA = atualA -> prox;
			atualB = atualB -> prox;
		}
		else if(atualB == b ||(atualA != a && atualB != b && atualA -> valor.grau > atualB -> valor.grau)){
			insereFim(res, atualA -> valor.grau, atualA -> valor.coef);
			atualA = atualA -> prox;
		}else{
			insereFim(res, atualB -> valor.grau, atualB -> valor.coef);
			atualB = atualB -> prox;
		}
	}
}       

/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau com valor - 2 e o de
 * grau 10 com valor 5.*/
void imprime(Polinomio pol){
        No *novoPol = pol -> prox;	

	printf("[");

	while(novoPol != NULL){
		printf("(%d, %d)", novoPol -> valor.grau, novoPol -> valor.coef);
		if(novoPol -> prox != NULL)
			printf(",");
		novoPol = novoPol -> prox;
	}
	printf("]\n");
}       

/*Desaloca toda a memoria alocada da lista*/
void desaloca_polinomio(Polinomio *ap_pol){
        No *atual = (*ap_pol);
	No *desaloca;

	while(atual != *ap_pol){
		desaloca = atual -> prox;
		free(atual);
		atual = desaloca;
	}
	(*ap_pol) = NULL;
}

Polinomio insereFim(Polinomio pol, int grau, int coef){
	No *no_novo = malloc(sizeof(No));

	no_novo -> valor.grau = grau;
	no_novo -> valor.coef = coef;

	no_novo -> prox = pol;
	no_novo -> antec = pol -> antec;
	pol -> antec -> prox = no_novo;
	pol -> antec = no_novo;

	return pol;
}





