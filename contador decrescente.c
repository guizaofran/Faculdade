#include <stdio.h>

int main()
{
    int maior,menor,aux;
    printf("Digite o primeiro numero: ");
    scanf("%i",&maior);
    printf("\nDigite o segundo numero: ");
    scanf("%i",&menor);
    if(menor>maior){
        aux=menor;
        menor=maior;
        maior=aux;
    }
    while(maior>=menor){
        printf("%i, ",maior);
        maior--;
    }
}
