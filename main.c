#include <stdio.h>
#include <stdlib.h>

int humor[10];

// declaração de funções - prototipo
void preencherHumor(int humor[]);
void mostrarHumor(int humor[]);
float calcularMedia(int humor[]);
int maiorHumor(int humor[]);
int menorHumor(int humor[]);
void categorias();
void relatorio(int humor[], float media, int maior, int menor);
void buscarHumor(int humor[]);
void alterarHumor(int humor[]);
void graficoHumor(int humor[]);
void alertaTurma(int humor[]);
void ranking(int humor[]);

int main() {
    system("cls || clear");

    int opcao = 1;

    do{
        printf("\n\n======== Escolha uma opção ========\n");
        printf("1- Inserir humores\n");
        printf("2- Mostrar humores\n");
        printf("3- Média da turma\n");
        printf("4- Melhor humor\n");
        printf("5- Pior humor\n");
        printf("6- Quantidade por categoria\n");
        printf("7- Relatório geral\n");
        printf("8- Buscar alunos pelo humor\n");
        printf("9- Alterar humor de aluno\n");
        printf("10- Mostrar humor grafico\n");
        printf("11- Detectar padrões perigosos\n");
        printf("12- Ranking de melhores humores\n");
        printf("0- Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);
    
        switch(opcao) {
            case 1:
                preencherHumor(humor);                
                break;
            case 2:
                mostrarHumor(humor);
                break;
            case 3:
                calcularMedia(humor);
                break;
            case 4:
                maiorHumor(humor);
                break;
            case 5:
                menorHumor(humor);
                break;
            case 6:
                categorias(humor);
                break;
            case 7:
                float media = calcularMedia(humor);
                int menor = menorHumor(humor);
                int maior = maiorHumor(humor);
                relatorio(humor, media, menor, maior);
                break;
            case 8:
                buscarHumor(humor);
                break;
            case 9:
                alterarHumor(humor);
                break;
            case 10:
                graficoHumor(humor);
                break;
            case 11:
                alertaTurma(humor);
                break;
            case 12:
                ranking(humor);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida\n\n");
        }

    } while (opcao != 0);

    return 0;
}

void preencherHumor(int humor[]){
    
    for(int i = 0; i < 10; i++){
        printf("Digite o humor do %ia aluno: ", i+1);
        scanf("%i", &humor[i]);
    }

}

void mostrarHumor(int humor[]) {
    
    for(int i = 0; i < 10; i++){
        printf("Aluno %i - humor:%i\n ", i+1, humor[i]);
    }

}


float calcularMedia(int humor[]) {
    if (humor <= 0) {
        printf("Você informou uma quantidade inválida!!");
        return 0;
    }

    int soma = 0;
    float media = 0;

    for (int i = 0; i < 10; i++) {
        soma += humor[i];
        
    }
    media = (soma / 10);
    printf("A média é: %.2f\n", media );
    
    return media;
}

int maiorHumor(int humor[]) {
    int maior = 0;

    for(int i = 0; i < 10; i++){
        if(humor[i] > maior)
            maior = humor[i];
    }

    printf("O Maior humor foi: %i\n", maior);
    return maior;
}

int menorHumor(int humor[]) {
    int menor = 10;

    for(int i = 0; i < 10; i++){
        if(humor[i] < menor)
            menor = humor[i];
    }

    printf("O Menor humor foi: %i\n", menor);
    return menor;
}

void categorias(int humor[]){
    int pessimo=0, ruin=0, normal=0, otimo=0;
    for(int i = 0; i < 10; i++){
        if(humor[i] <= 2){
            pessimo++;
        }else if(humor[i] >= 3 && humor[i] <= 5){
            ruin++;
        }else if(humor[i] >= 6 && humor[i] <= 7){
            normal++;
        }else if(humor[i] >= 8 && humor[i] <= 10){
            otimo++;
        }
    }
    printf("Situação péssima: %i Alunos\n", pessimo);
    printf("Situação ruin: %i Alunos\n", ruin);
    printf("Situação normal: %i Alunos\n", normal);
    printf("Situação ótima: %i Alunos\n", otimo);
}

void relatorio(int humor[], float media, int menor, int maior){
    int triste=0, feliz=0;
    for(int i = 0; i < 10; i++){
        if(humor[i] <= 2){
            triste++;
        }else if(humor[i] >= 8 && humor[i] <= 10){
            feliz++;
        }
    }
    
    printf("- Média da turma: %.2f\n", media);
    printf("- Quantidade de alunos felizes: %i\n", feliz);
    printf("- Quantidade de alunos tristes: %i\n", triste);
    printf("- Melhor humor: %i\n", maior);
    printf("- Pior humor: %i\n", menor);
    if(media <= 4){
        printf("- Situação da turma: Turma critica\n");
    }else if(media > 4 && media <= 7){
        printf("- Situação da turma: Turma estável\n");
    }else{
        printf("- Situação da turma: Turma motivada\n");
    }
}

void buscarHumor(int humor[]){
    int humorChamar = 0;
    
    printf("Digite qual humor quer que seja mostrado: ");
    scanf("%i", &humorChamar);
    
    for(int i = 0; i < 10; i++){
        if(humorChamar == humor[i]){
            printf("Aluno %i - humor: %i", i + 1, humor[i]);
        }
    }
}

void alterarHumor(int humor[]){
    int humorMudar = 0;
    
    printf("Digite qual humor quer que seja alterado: ");
    scanf("%i", &humorMudar);
    
    for(int i = 0; i < 10; i++){
        if(humorMudar == humor[i]){
            printf("Digite o novo humor: ");
            scanf("%i", &humor[i]);
        }
    }
}

void graficoHumor(int humor[]){
    for(int i = 0; i < 10; i++){
        printf("\nAluno %i: ", i+1);
        for(int n = 0; n < humor[i]; n++){
            printf("*");
        }
    }
    printf("\n");
}

void alertaTurma(int humor[]){
    int perigo = 0;
    for(int i = 0; i < 10; i++){
        if(humor[i] < 3){
            perigo++;
        }
    }
    printf("ALERTA: %i alunos estão com humor abaixo de 3", perigo);
}

void ranking(int humor[]){
    int humores[10];
    int alunos[10];

    for (int i = 0; i < 10; i++) {
        humores[i] = humor[i];
        alunos[i] = i + 1;
    }

    for (int i = 0; i < 10; i++) {
        for (int n = 0; n < 9 - i; n++) {
            if (humores[n] < humores[n + 1]){
                int tempHumor = humores[n];
                humores[n] = humores[n + 1];
                humores[n + 1] = tempHumor;

                int tempAluno = alunos[n];
                alunos[n] = alunos[n + 1];
                alunos[n + 1] = tempAluno;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%i° lugar - Aluno %i: humor %i\n", i + 1, alunos[i], humores[i]);
    }
}