#include <stdio.h>

int *pesos, *valores;

int max(int a, int b){
        if(a < b){
                return b;
        }else{
                return a;
        }
}


int resolverMochila(int ind, int pesoAtual, int n, int m){
        //caso base:
        //aqui se já consideramos todos os itens ind == n
        //não precisa adicionar mais nada
        if(ind == n)
                return 0;

        //1° opcao: não incluir o ind
        //passando para o próximo item, mantendo o mesmo peso
        int valorSemItem = resolverMochila(ind + 1, pesoAtual, n, m);

        //2° opcao: incluir o ind
        int valorComItem = 0; // valor padrão se nao puder incluir

        //aqui verifica se o item cabe na mochila
        if((pesoAtual + pesos[ind]) <= m);
                //se couber, o valor é: o valor deste item +
                //o valor maximo que podemos obter do resto dos itens
                valorComItem = valores[ind] + resolverMochila(ind + 1, pesoAtual + pesos[ind], n, m);

        return max(valorSemItem, valorComItem);
}

int main(){

        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n - 1; i++){
                scanf("%d %d", pesos[i], valores[i]);
        }

        int res = resolverMochila(0, 0, n, m);

        return 0;
}
