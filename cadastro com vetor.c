#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

int arm[10];
int op=0, n=0;
void cadastrar(){
    for(int i=0; i<10;i++){
        system("cls");
        printf("Digite o %d numero:  ", i+1);
        scanf("%d", &arm[i]);
    }
}

_Bool consultar(int num){
    _Bool enc=false;
    int i=0;
    while(i<10 && enc==false){
        if (arm[i]==num){ 
        enc=true;
     }
     i++;
    }
    return enc;
}
void imprimir(){
    for(int i=0; i<10; i++){
        printf("%d \n", arm[i]);
    }
    Sleep(10000);
}

void menu(){
    system("cls");
    printf("1-Cadastrar\n2-imprimir\n3-consultar\n4-sair\n");
    printf("Escolha uma das opcoes 1-4: ");
    scanf("%i", &op);
}

int main(){
    do{
    menu();
    if (op>4 || op<1){
        printf("Opcao invalida!!!\n");
        Sleep(2000);
        system("cls");
    }else{
    switch (op){
    case 1:
        cadastrar();
        break;
    case 2:
        imprimir();
        break;
    case 3:
        printf("Digite o numero a ser consultado: ");
        scanf("%d", &n);
       if (consultar(n)){
        printf("Numero consta na lista!!\n");
       }else{
        printf("Numero não consta na lista!!\n");
       }
       Sleep(2000);
       break;
        }
    }
  }while (op!=4);
  printf("Sistema encerrado!!!");
}