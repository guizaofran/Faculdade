#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int x, numero, opcao;

void menu()
{
	printf("**************************************\n");
	printf("*       MENU PRINCIPAL: TABUADA      *\n");
	printf("*                                    *\n");
	printf("*   1 - ADICAO                       *\n");
	printf("*   2 - SUBTRACAO                    *\n");
	printf("*   3 - MULTIPLICACAO                *\n");
	printf("*   4 - DIVISAO                      *\n");
	printf("*   5 - SAIR                         *\n");
	printf("**************************************\n");
	printf("\nESCOLHA UMA OPCAO COM O VALOR CORRESPONDENTE: ");
}

//conta da adicao
void adicao(int numero, int x)
{
	for(x=0; x<10; x++) {
		printf("%i+%i= %i\n",numero,x,x+numero);
	}
}

//conta da substracao
void subtracao(int numero, int x)
{

	for(x=0; x<10; x++) {
		printf("%i-%i= %i\n",x+numero,numero,x);
	}
}

//conta da multiplicacao
void multiplicacao(int numero, int x)
{
	for(x=0; x<10; x++) {
		printf("%i.%i= %i\n",numero,x,x*numero);
	}

}

//conta da divisao
void divisao(int numero, int x)
{
	for(x=0; x<10; x++) {
		printf("%i/%i= %i\n",numero*x,numero,x);
	}
}

int main()
{

	do {
		system("cls");
		menu();
		scanf("%i",&opcao);
		system("cls");

		switch(opcao) {

		//escolha da adicao
		case 1: {
			printf("Digite o numero: ");
			scanf("%i",&numero);
			adicao(numero,x);
			break;
		}

		//escolha da subtracao
		case 2: {
			printf("Digite o numero: ");
			scanf("%i",&numero);
			subtracao(numero,x);
			break;
		}

		//escolha da multiplicacao
		case 3: {
			printf("Digite o numero: ");
			scanf("%i",&numero);
			multiplicacao(numero,x);
			break;
		}

		//escolha da divisao
		case 4: {
			printf("Digite o numero: ");
			scanf("%i",&numero);
			divisao(numero,x);
			break;
		}

		//sair do programa
		case 5: {
			printf("Programa finalizado com sucesso");
			break;

		}
		//escolha de numero invalido
		default: {
			printf("Opcao invalida\n");
		}
		}
		//se a opcao for diferente de 5, o programa vai esperar 3 segundos apos exibir o resultado
		if(opcao!=5) {
			for(int x=3; x>0; x--) {
				printf("\rVoltando ao menu em %i segundos...",x);
				fflush(stdout);
				Sleep(1000);
			}
		}
		//enquanto a opcao for diferente de 5, o programa ficara em looping
	} while(opcao!=5);
}



