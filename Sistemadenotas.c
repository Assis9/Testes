#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registra_Nome_Nota(char nome[][30], float nota[][3], int qtdeAlunos);
float listagem_Médias(char nome[][30], float nota[][3], int qtdeAlunos);

int main() {
    system("cls || clear");
    
    int qtdeAlunos = 1;
    while(qtdeAlunos != 0){
        printf("Quantos alunos quer registrar?(0 para sair): ");
        scanf("%i", &qtdeAlunos);
        getchar();
        
        char nome[qtdeAlunos][30];
        float nota[qtdeAlunos][3];
    
        registra_Nome_Nota(nome, nota, qtdeAlunos);
        float mediaSala = listagem_Médias(nome, nota, qtdeAlunos);
        
        if(qtdeAlunos != 0)
            printf("Media da sala é: %.2f\n\n", (mediaSala/qtdeAlunos));
        
    }
    return 0;
}

void registra_Nome_Nota(char nome[][30], float nota[][3], int qtdeAlunos){
    for (int i = 0; i < qtdeAlunos; i++){
        printf("Digite o nome do aluno %d: ", i+1);
        fgets(nome[i], sizeof(nome[30]), stdin);        
        nome[i][strcspn(nome[i],"\n")] = '\0';
    
        for (int n = 0; n < 3; n++) {
            printf("%da nota do aluno %s: ", n+1, nome[i]);
            scanf("%f", &nota[i][n]);
            getchar();
        }
    }
}

float listagem_Médias(char nome[][30], float nota[][3], int qtdeAlunos){
    float somaNotasAluno = 0, mediaSala = 0.0; 
    if(qtdeAlunos != 0){
        printf("\nNomes e notas registrados: \n\n");
        for (int i = 0; i < qtdeAlunos; i++){
            somaNotasAluno = 0;
            printf("%s : ", nome[i]);
            for (int n = 0; n < 3; n++){
                printf("%.2f/ ", nota[i][n]);
                somaNotasAluno += nota[i][n];
            }
            float mediaAluno = (somaNotasAluno/3);
            printf("-média do aluno = %.2f", mediaAluno);
        
            mediaSala += mediaAluno;
            printf("\n");
        }
        return mediaSala;
    } else{
        printf("\nIntegrantes do grupo:\n");
        printf("Assis - RA: 260029699\n");
        printf("Joadina - RA: 260030642\n");
        printf("Caio Matheus - RA: 260030364\n");
        return 0;
    }
}