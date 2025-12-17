#include "Arvore_AVL.h"
#include<stdio.h>
#include<stdlib.h>

No * novoNo(int x){
    No *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo -> valor = x;
        novo -> esq = NULL;
        novo -> dir = NULL;
        novo -> altura = 0;
    }
    else
        printf("\nERRO ao alocar nó em novoNo");
    return novo;
}

int alturaNo(No *no){
    if(no == NULL)
        return -1;
    else
        return no -> altura;
}

//calcula e retorna o fator de balanceamento de um nó
int fatorDeBalanceamento(No *no){
    if(no)
        return (alturaNo(no -> esq) - alturaNo(no -> dir));
    else 
        return 0;
}

int maior(int a, int b){
    return (a > b)? a : b;
}

No * rotacaoDireita(No *r){
    No *y, *f;

    //aqui eu posiciono os ponteiros
    y = r -> esq;
    f = y -> dir;

    //aqui eu faço a rotação
    y -> dir = r;
    r -> esq = f;

    //aqui atualiza a altura dos nós depois da rotação
    r -> altura = maior(alturaNo(r -> esq), alturaNo(r -> dir)) + 1;
    y -> altura = maior(alturaNo(y -> esq), alturaNo(y -> dir)) + 1;
    
    //retorna y porque é a nova raiz
    return y;
}

No * rotacaoEsquerda(No *r){
    No *y, *f;

    //aqui eu posiciono os ponteiros
    y = r -> dir;
    f = y -> esq;

    //aqui eu faço a rotação
    y -> esq = r;
    r -> dir = f;

    //aqui atualiza a altura dos nós depois da rotação
    r -> altura = maior(alturaNo(r -> esq), alturaNo(r -> dir)) + 1;
    y -> altura = maior(alturaNo(y -> esq), alturaNo(y -> dir)) + 1;

    //retorna y porque é a nova raiz
    return y;
}

No * rotacaoDireitaEsquerda(No *r){
    r -> dir = rotacaoDireita(r -> dir);
    return rotacaoEsquerda(r);
}

No * rotacaoEsquerdaDireita(No * r){
    r -> esq = rotacaoEsquerda(r -> esq);
    return rotacaoDireita(r);
}

No * balancear(No * r){
    short fb = fatorDeBalanceamento(r);

    if(fb < -1 && fatorDeBalanceamento(r->dir) <= 0)
        r = rotacaoEsquerda(r);

    else if(fb > 1 && fatorDeBalanceamento(r->esq) >= 0)
        r = rotacaoDireita(r);

    else if(fb > 1 && fatorDeBalanceamento(r->esq) < 0)
        r = rotacaoEsquerdaDireita(r);

    else if(fb < -1 && fatorDeBalanceamento(r->dir) > 0)
        r = rotacaoDireitaEsquerda(r);

    return r;
}

bool insere(Arvore * r, int x){
    if(*r == NULL){
      *r = novoNo(x);
      return(*r != NULL);
    }

    if(x < (*r)->valor){
        if(!insere(&((*r)->esq), x))
            return false;
    }
    else if(x > (*r)->valor){
        if(!insere(&((*r)->dir), x))
            return false;
    }
    else{
        return false;
    }

    (*r) -> altura = maior(alturaNo((*r)->esq), alturaNo((*r)->dir)) + 1;

    *r = balancear(*r);

    return true;
}

bool busca(Arvore arv, int x){
    if(arv == NULL)
        return false;
    if(arv -> valor == x)
        return true;
    if(arv -> valor < x)
        return busca(arv -> dir, x);
    return busca(arv -> esq, x);
}

void imprime_rec(Arvore arv) {
  if (arv == NULL) {
    printf(".");
    return;
  }
  printf("[%d:e=", arv->valor);
  imprime_rec(arv->esq);
  printf(",d=");
  imprime_rec(arv->dir);
  printf("]");
}

void imprime(Arvore arv) {
  imprime_rec(arv);
  printf("\n");
}
