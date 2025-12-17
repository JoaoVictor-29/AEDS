#include <stdio.h>

typedef struct{
	int num[100];
	int topo;
}pilhaNum;

typedef struct{
	char op[100];
	int topo;
}pilhaOp;

void adiciona_num(pilhaNum *p, int n){
        p -> num[++p -> topo] = n;
}

int remove_num(pilhaNum *p){
        return p -> num[p -> topo--];
}

void adiciona_op(pilhaOp *p, char op){
        p -> op[++p -> topo] = op;
}

char remove_op(pilhaOp *p){
        return p -> op[p -> topo--];
}


int precedencia(char op){
        if(op == '*' || op == '/'){
                return 2;//prioridade alta
        }
        if(op == '+' || op == '-'){
                return 1;//prioriadade baixa
        }
        return 0;//aqui se nao for um operador
}

void operacao_pilha(pilhaNum *p_num, pilhaOp *p_ops){
	char ope = remove_op(p_ops);

	int n2 = remove_num(p_num);
	int n1 = remove_num(p_num);
	
	int res;

	switch(ope){
		case '+':
			res = n1 + n2;
			break;
		case '-':
			res = n1 - n2;
			break;
		case '*':
			res = n1 * n2;
			break;
		case '/':
			res = n1 / n2;
			break;
	}
	adiciona_num(p_num, res);
}

int main(){
	
	pilhaNum p_num;
	//aqui eu inicializo a pilha de numeros como vazia
	p_num.topo = -1;

	pilhaOp p_op;
	//aqui eu inicializo a pilha de operadores como vazia
	p_op.topo = -1;

	int num;
	char op;

	printf("Digite a expressao: ");
	scanf("%d", &num);
	//chamo a funcao pra adicionar o primeiro numero na pilha de numeros
	adiciona_num(&p_num, num);

	while(scanf(" %c %d", &op, &num) == 2){
		while(p_op.topo != -1 && precedencia(p_op.op[p_op.topo]) >= precedencia(op)){
			operacao_pilha(&p_num, &p_op);
		}
	adiciona_num(&p_num, num);
	adiciona_op(&p_op, op);	
	}
	
	while(p_op.topo != -1){
		operacao_pilha(&p_num, &p_op);
	}

	printf("Resultado: %d\n",p_num.num[0]);

	return 0;
}
#include <stdio.h>

typedef struct{
	int num[100];
	int topo;
}pilhaNum;

typedef struct{
	char op[100];
	int topo;
}pilhaOp;

void adiciona_num(pilhaNum *p, int n){
        p -> num[++p -> topo] = n;
}

int remove_num(pilhaNum *p){
        return p -> num[p -> topo--];
}

void adiciona_op(pilhaOp *p, char op){
        p -> op[++p -> topo] = op;
}

char remove_op(pilhaOp *p){
        return p -> op[p -> topo--];
}


int precedencia(char op){
        if(op == '*' || op == '/'){
                return 2;//prioridade alta
        }
        if(op == '+' || op == '-'){
                return 1;//prioriadade baixa
        }
        return 0;//aqui se nao for um operador
}

void operacao_pilha(pilhaNum *p_num, pilhaOp *p_ops){
	char ope = remove_op(p_ops);

	int n2 = remove_num(p_num);
	int n1 = remove_num(p_num);
	
	int res;

	switch(ope){
		case '+':
			res = n1 + n2;
			break;
		case '-':
			res = n1 - n2;
			break;
		case '*':
			res = n1 * n2;
			break;
		case '/':
			res = n1 / n2;
			break;
	}
	adiciona_num(p_num, res);
}

int main(){
	
	pilhaNum p_num;
	//aqui eu inicializo a pilha de numeros como vazia
	p_num.topo = -1;

	pilhaOp p_op;
	//aqui eu inicializo a pilha de operadores como vazia
	p_op.topo = -1;

	int num;
	char op;

	printf("Digite a expressao: ");
	scanf("%d", &num);
	//chamo a funcao pra adicionar o primeiro numero na pilha de numeros
	adiciona_num(&p_num, num);

	while(scanf(" %c %d", &op, &num) == 2){
		while(p_op.topo != -1 && precedencia(p_op.op[p_op.topo]) >= precedencia(op)){
			operacao_pilha(&p_num, &p_op);
		}
	adiciona_num(&p_num, num);
	adiciona_op(&p_op, op);	
	}
	
	while(p_op.topo != -1){
		operacao_pilha(&p_num, &p_op);
	}

	printf("Resultado: %d\n",p_num.num[0]);

	return 0;
}
