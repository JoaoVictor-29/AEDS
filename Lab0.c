#include <stdio.h>

void divisorProprio(int num);
void numerosAmigos(int n1, int n2);

int main(){

	int num1, num2;
	
	printf("Digite um numero: ");
	scanf("%d", &num1);
	printf("Digite outro numero: ");
	scanf("%d", &num2);
	
	numerosAmigos(num1, num2);	

return 0;
}

int divisorProprio(int num){
	int soma;
	for(int i = 0; i < num; i++){
		if(num % i == 0)
			soma += i;			
	}
return soma;
}

void numerosAmigos(int n1, int n2){
 	int somaNum1, somaNum2;
	somaNum1 = divisorProprio(n1);
	somaNum2 = divisorProprio(n2);
	if(somaNum1 == somaNum2){
		printf("sao amigos");
	}else{
		printf("nao amigos");
	}

}
