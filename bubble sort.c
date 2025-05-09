#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 5

int lista[TAM], aux;

int main() {
	setlocale(LC_ALL, "Portuguese");
	for(int i=0; i<TAM; i++) {
		printf("Digite o %d numero da lista: ",i+1);
		scanf("%d",&lista[i]);
	}
	
	system("cls");

	printf("\nLista atual:\n");
	for(int i=0; i<TAM; i++) {
		printf("%d, ",lista[i]);
	}
	
	//inverte a lista
	printf("\n\nLista invertida:\n");
	for(int i=4;i>=0;i--){
	    printf("%d, ",lista[i]);
	}
	
	//bubble sort crescente
	for(int contador=1;contador<TAM;contador++){
	 for(int i=0;i<TAM-1;i++){
	    if(lista[i]>lista[i+1]){
	        aux=lista[i];
	        lista[i]=lista[i+1];
	        lista[i+1]=aux;
	    }
	  }
	}
	
	printf("\n\nLista crescente:\n");
	for(int i=0; i<TAM; i++) {
		printf("%d, ",lista[i]);
	}
	
	//bubble sort decrescente
	for(int contador=1;contador<TAM;contador++){
	 for(int i=0;i<TAM-1;i++){
	    if(lista[i]<lista[i+1]){
	        aux=lista[i];
	        lista[i]=lista[i+1];
	        lista[i+1]=aux;
	    }
	  }
	}
	
	printf("\n\nLista decrescente:\n");
	for(int i=0; i<TAM; i++) {
		printf("%d, ",lista[i]);
	}
	
}