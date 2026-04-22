#include <stdio.h>

void escalonamento(int quant_processos) {

    int tempo_execucao[quant_processos];
    int tempo_chegada[quant_processos]; 

    for (int i = 0; i < quant_processos; i++) {
        printf("Tempo de chegada P%d: ", i+1);
        scanf("%d", &tempo_chegada[i]);
        printf("Tempo de execucao P%d: ", i+1);
        scanf("%d", &tempo_execucao[i]);
    }

    int tempo_atual = 0;

    for (int i = 0; i < quant_processos; i++) {
        if(tempo_atual < tempo_chegada[i]) {
            tempo_atual = tempo_chegada[i]; 
        }

        int inicio = tempo_atual;
        int fim = inicio + tempo_execucao[i];  

        printf("| P%d(%d - %d)", i+1, inicio, fim);

        tempo_atual = fim; 
    }

    printf("|\n");
    
    tempo_atual = 0;

    for(int i = 0; i < quant_processos; i++){
        if(tempo_atual < tempo_chegada[i]) {
        tempo_atual = tempo_chegada[i]; 
        }

        int inicio = tempo_atual;
        int fim = inicio + tempo_execucao[i]; 
        int turnaround = fim - tempo_chegada[i];
        printf("P%d: %d\n", i+1, turnaround);

        tempo_atual = fim;
    }

}

int main() {
    int quant_processos;
    printf("Digite a quantidade de processos: ");
    scanf("%d", &quant_processos);

    escalonamento(quant_processos);

    return 0;
}
