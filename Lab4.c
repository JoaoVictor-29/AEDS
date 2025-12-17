#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tamanho;
    int mascara_elementos;
} Subconjunto;

#define MAX_ELEMENTOS 15
#define MAX_SUBCONJUNTOS 17

void buscar_por_mascara_de_bits(int num_subconjuntos, Subconjunto *colecao, int n_elementos_universo);

int main()
{
    int n, qtd_subconjuntos, tamanho_subconjunto_atual, valor_elemento;
    int i = 0, j = 0;
    Subconjunto *colecao_W;

    scanf("%d", &n);
    scanf("%d", &qtd_subconjuntos);
    
    colecao_W = (Subconjunto*)malloc(sizeof(Subconjunto) * qtd_subconjuntos);
    
    for(i = 0; i < qtd_subconjuntos; i++){
        colecao_W[i].mascara_elementos = 0;
    }

    for(i = 0; i < qtd_subconjuntos; i++){
        scanf("%d", &tamanho_subconjunto_atual);
        colecao_W[i].tamanho = tamanho_subconjunto_atual;
        
        for(j = 0; j < tamanho_subconjunto_atual; j++){
            scanf("%d", &valor_elemento);
            colecao_W[i].mascara_elementos |= (1 << valor_elemento);
        }
    }

    buscar_por_mascara_de_bits(qtd_subconjuntos, colecao_W, n);

    free(colecao_W);

    return 0;
}

void buscar_por_mascara_de_bits(int num_subconjuntos, Subconjunto *colecao, int n_elementos_universo)
{
    int i, j, k;
    int mascara_objetivo = (1 << n_elementos_universo) - 1;
    
    int contador_solucao = 0;
    int mascara_uniao = 0;
    int solucao_encontrada = 0;
    int eh_cobertura_exata = 1;

    for (i = 0; i < (1 << num_subconjuntos); i++)
    {
        mascara_uniao = 0;
        contador_solucao = 0;
        eh_cobertura_exata = 1;
        int frequencia_elementos[MAX_ELEMENTOS] = {0};
        
        for (j = 0; j < num_subconjuntos; j++)
        {
            if(i & (1 << j)){
                mascara_uniao |= colecao[j].mascara_elementos;
                contador_solucao++;

                for(k = 0; k < n_elementos_universo; k++){
                    if(colecao[j].mascara_elementos & (1 << k)){
                        frequencia_elementos[k]++;
                        if(frequencia_elementos[k] > 1){
                            eh_cobertura_exata = 0;
                            break;
                        }
                    }
                }
                
                if(!eh_cobertura_exata) break;
            }
        }

        if(mascara_uniao == mascara_objetivo && eh_cobertura_exata){
            solucao_encontrada = 1;
            printf("%d\n", contador_solucao);

            for(j = 0; j < num_subconjuntos; j++){
                if(i & (1 << j))
                {
                    printf("%d", colecao[j].tamanho);
                    for(k = 0; k < n_elementos_universo; k++){
                        if(colecao[j].mascara_elementos & (1 << k))
                            printf(" %d", k);
                    }
                    printf("\n");
                }
            }
            break;
        }
    }
    
    if(!solucao_encontrada){
        printf("Insoluvel\n");
    }
}
