#include <stdio.h>
#include <string.h>

int vetor[4];

double resultado=0;

char operacao;

int main(){
    for(int i=0;i<4;i++){
        printf("Escolha o %d elemento(s) dos vetor: ",i+1);
        scanf("%d",&vetor[i]);
    }

    printf("\nDefina uma das 4 operacoes matematicas: ");
    scanf(" %c",&operacao);
    
    switch(operacao){
        case '+':
        for(int i=0;i<4;i++){
        resultado=resultado+vetor[i];
        }
        printf("Essa e a soma de todos os elementos do vetor: %.2lf",resultado);
        break;
        case '-':
        resultado=vetor[0];
        for(int i=1;i<4;i++){
        resultado=resultado-vetor[i];
        }
        printf("Essa e a subtracao de todos os elementos do vetor em ordem: %.2lf",resultado);
        break;
        case '*':
        resultado=vetor[0];
        for(int i=1;i<4;i++){
        resultado=resultado*vetor[i];
        }
        printf("Essa e a multiplicacao de todos os elementos do vetor: %.2lf",resultado);
        break;
        case '/':
        resultado=vetor[0];
        for(int i=1;i<4;i++){
        resultado=resultado/vetor[i];
        }
        printf("Essa e a divisao de todos os elementos do vetor em ordem: %.2lf",resultado);
        break;
        default:
        printf("Opcao invalida\n");
        break;
     }
}