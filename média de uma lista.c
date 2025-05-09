#include <stdio.h>
#include <stdlib.h>

int lista[20],quantidade=0;

double media, soma=0;

void conta(){
    for(int i=0;i<20;i++){
        soma=soma+lista[i];
        media=soma/20;
    }
}

void maiores(){
    for(int i=0;i<20;i++){
    if(lista[i]>media){
    quantidade++;
    }
  }
}

int main(){
    for(int i=0;i<20;i++){
    printf("Escolha o %d numero para colocar na lista: ",i+1);
    scanf("%d",&lista[i]);
    system("cls");
    }
    conta();
    printf("A media da sua lista e %.2lf",media);
    maiores();
    printf("\nA quantidade de numeros maiores que a media e de %d",quantidade);
}



