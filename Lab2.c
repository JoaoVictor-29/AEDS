#include <stdio.h>
#include <stdlib.h>
#include "Polinomio.h"

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
        
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memoria
 * liberada*/
void zera(Polinomio pol){
        
}       

/*Computa a soma dos polinomio a e b colocando o resultado em res.
 * Libera a memoria anteriormente uilizada pelos nos descartados de res, e sobreescreve res.*/
void soma(Polinomio res, Polinomio a, Polinomio b){
       No *atualA, *atualB;
       atualA = a -> prox;
       atualB = b -> prox;
       
       while(atualA != a || atualB != b){
              Polinomi
              if(atualA -> grau == atualB -> grau){
                     no_novo -> coef = a -> coef + b -> coef;
                     a = a -> prox;
                     b = b -> prox;
              }

              if(a -> grau > b -> grau){
                     novo -> coef = a -> coef;
                     a = a -> coef;
              }else{
                     novo -> coef = b -> coef;
                     b = b -> coef;
              }

              if
}       

/* Computa a subtracao dos polinomios a e b colocando o resultado em res.
 * Libera a memoria anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b){
        
}       

/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau com valor - 2 e o de
 * grau 10 com valor 5.*/
void imprime(Polinomio pol){
        
}       

/*Desaloca toda a memoria alocada da lista*/
void desaloca_polinomio(Polinomio *ap_pol){
        
}   
