#include <stdio.h>
#include <stdlib.h>

typedef enum{false, true} bool;

typedef struct no_arvore{
	bool ehValor;
	int valor;
	char op;
	struct no_arvore *dir;
	struct no_arvore *esq;
}arvore;

typedef struct no_pilhano{
	arvore *arv;
	struct no_pilhano *prox;
}pilhaNo;

typedef struct no_pilhaop{
	char op;
	struct no_pilhaop *prox;
}pilhaOp;

typedef arvore Arvore;
typedef pilhaNo pilhaNoArv;
typedef pilhaOp pilhaOpe;

Arvore * novoNo_num(int x){
	Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
	novo -> ehValor = true;
	novo -> valor = x;
	novo -> dir = NULL;
	novo -> esq = NULL;
	
	return novo;
}

Arvore * novoNo_op(char op){
	Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
	novo -> ehValor = false;
	novo -> op = op;
	novo -> dir = NULL;
	novo -> esq = NULL;

	return novo;
}

void empilharNo(pilhaNoArv **topo, Arvore *no){
	pilhaNoArv *novo = (pilhaNoArv*)malloc(sizeof(pilhaNoArv));
	novo -> no = arv;
	novo -> prox = *topo;
	*topo = novo;
}

Arvore * desempilharNo(pilhaNoArv **topo){
	if(*topo == NULL)return NULL;

	pilhaNoArv *remover = *topo;
	Arvore *dado = remover -> no;
	*topo = remover -> prox;
	free(remover);
	return dado;
}

void empilharOp(pilhaOpe **topo, char op){
	pilhaOpe *novo = (pilhaOpe*)malloc(sizeof(pilhaOpe));
	novo -> op = arv;
	novo -> prox = *topo;
	*topo = novo;
}

char desempilharOp(pilhaOpe **topo){
	if(*topo == NULL)return NULL;

	pilhaOpe *remover = *topo;
	char dado = remover -> op;
	*topo = remover -> prox;
	free(remover);	
	return dado;
}

int precedencia(char op){
	if(op == '*' || op == '/')
		return 3;//prioridade alta
	if(op == '+' || op == '-')
		return 2;//prioridade média
	return 1;//prioridade baixa
}

void criarSubArvore(pilhaNoArv **pilhano, pilhaNoOp **pilhaop){
	//tira o operador
	char op = desempilharOp(pilhaop);
	
	//desempilha os nós em ordem inversa
	pilhaNoArv *noDir = desempilharNo(pilhano);
	pilhaNoArv *noEsq = desempilharNo(pilhano);
	
	//cria no pai para o operador
	Arvore *novo = novoNo_op(op);

	novo -> dir = noDir;
	novo -> esq = noEsq;

	//devolver para a pilha de nós
	empilharNo = (pilhano, novo);
}

int calculo(Arvore *apArv){
	if(apArv == NULL)
		return 0;

	if(apArv -> ehValor == true)
		return apArv -> valor;

	int resEsq = calculo(apArv -> esq);
	int resDir = calculo(apArv -> dir);

	switch(apArv -> op){
		case '+':
			return resEsq + resDir;
		case '-':
			return resEsq - resDir;
		case '*':
			return resEsq * resDir;
		case '/':
			return resEsq / resDir;
		case '%':
			return resEsq % resDir;
	}
}

void impressaoPosFixa(Arvore *a){
	if(a != NULL){
		impressaoPosFixa(a -> esq);
		impressaoPosFixa(a -> dir);

		if(a -> ehValor == true){
			printf("%d ", a -> valor);
		}else{
			printf("%c ", a -> op);
		}
}

void impressaoPreFixa(Arvore *b){
	if(b != NULL){
		if(b -> ehValor == true){
			printf("%d ", b -> valor);
		}else{
			printf("%c ", b -> op);
		}

		impressaoPreFixa(b -> esq);
		impressaoPreFixa(b -> dir);
}

int main(){
	
	//inicializando as pilhas como NULL
	pilhaNoArv *pilhano = NULL;
	pilhaNoOp *pilhaop = NULL;

	int num;
	char c;

	while(1){


	return 0;
}
