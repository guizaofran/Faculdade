#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

int op, n;

void menu(){
    printf("**************************************\n");
    printf("*           MENU PRINCIPAL           *\n");
    printf("*                                    *\n");
    printf("*   1 - IDENTIFICADOR DE PRIMO       *\n");
    printf("*   2 - NUMEROS PARES                *\n");
    printf("*   3 - NUMEROS IMPARES              *\n");
    printf("*   4 - SAIR                         *\n");
    printf("**************************************\n");
    printf("ESCOLHA UMA OPCAO: ");
}

_Bool idPrimo(int num){
    int x=2;
    _Bool enc=false;
    while(enc==false && x<num){
        if (num%x==0){
            enc=true;
        }else{
            x++;    
        }
    }
    return enc;
}

void nPares(int num){
    for(int x=1;x<=num;x++){
        if(x%2==0){
            printf("%i\n",x);
        }
    }
}

void nImpares(int num){
    for(int x=1;x<=num;x++){
        if(x%2==1){
            printf("%i\n",x);
        }
    }
}

int main()
{
    do{
        system("cls");
        menu();
        scanf("%i",&op);
        system("cls");
        switch(op){
            case 1:{
                printf("Digite um numero: ");
                scanf("%i",&n);
                if (idPrimo(n)==true){
                    printf("Esse numero nao e primo\n");
                }else{
                    printf("Esse numero e primo\n");
                }
                break;
            }
            case 2:{
                printf("Digite um numero: ");
                scanf("%i",&n);
                nPares(n);
                break;
            }
            case 3:{
                printf("Digite um numero: ");
                scanf("%i",&n);
                nImpares(n);
                break;
            }
            default:{
                if (op<1 || op>4){
                    printf("Opcao invalida\n");
                }
            }
        }
        if(op!=4) Sleep(3000);
    }while(op!=4);
    printf("Sistema finalizado com sucesso!");
    
}
