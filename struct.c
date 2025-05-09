#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>
#define MAX 100


int i = 0, opcao;
char n[50];

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

struct Aluno aluno[MAX];

void imprimir(int y) {
    printf("Nome: %s\n", aluno[y].nome);
    printf("Idade: %d\n", aluno[y].idade);
    printf("Nota: %.2f\n\n", aluno[y].nota);
}

void cadastrar() {
    char continuar;

    do {
        getchar(); // limpa o buffer
        printf("Digite o nome do aluno: ");
        fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
        aluno[i].nome[strcspn(aluno[i].nome, "\n")] = '\0';

        printf("Digite a idade do aluno: ");
        scanf("%d", &aluno[i].idade);

        printf("Digite a nota do aluno: ");
        scanf("%f", &aluno[i].nota);

        i++;

        getchar(); // limpa o buffer
        printf("Deseja cadastrar outro aluno? (S/N): ");
        scanf("%c", &continuar);
        system("cls");
    } while ((continuar == 'S' || continuar == 's') && i < MAX);
}

void alterar(int x) {
    char op;
    getchar(); // limpar buffer
    printf("O que você deseja alterar?\n1 - Nome\n2 - Idade\n3 - Nota\n\n");
    scanf("%c", &op);

    switch (op) {
        case '1':
            getchar();
            printf("Digite o novo nome: ");
            fgets(aluno[x].nome, sizeof(aluno[x].nome), stdin);
            aluno[x].nome[strcspn(aluno[x].nome, "\n")] = '\0';
            break;
        case '2':
            printf("Digite a nova idade: ");
            scanf("%d", &aluno[x].idade);
            break;
        case '3':
            printf("Digite a nova nota: ");
            scanf("%f", &aluno[x].nota);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

void excluir(int x){    
    for(int x=z;x<i;x++){
        aluno[x]=aluno[x+1];
    }
    i--;
}

bool consultar(char nom[50]) {
    bool enc = false;
    int x = 0;

    while (x < i && enc == false) {
        if (strcmp(aluno[x].nome, nom) == 0) {
            if (opcao == 2) {
                imprimir(x);                
            } else if (opcao == 3) {
                alterar(x);
                printf("Registro alterado com sucesso!");
            } else if (opcao == 4){
                excluir(x);
                printf("Registro excluido com sucesso!");
            }    
            Sleep(3000); // pausa de 3 segundos (em milissegundos)        
            enc = true;
            return true;
        }        
        x++;
    }
    return false;
}

void menu() {
    system("cls");
    printf("*****************************\n");
    printf("*       MENU PRINCIPAL      *\n");
    printf("*****************************\n");
    printf("*   1 - CADASTRAR           *\n");
    printf("*   2 - CONSULTAR           *\n");
    printf("*   3 - ALTERAR             *\n");
    printf("*   4 - EXCLUIR             *\n"); //não implementado
    printf("*   5 - IMPRIMIR            *\n");
    printf("*   6 - SAIR                *\n");
    printf("*****************************\n");
    printf("ESCOLHA A OPCAO DESEJADA: ");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    do {
        menu();
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
            case 3:
            case 4:
                if (i > 0) {
                    getchar();
                    printf("Digite o nome do aluno: ");
                    fgets(n, sizeof(n), stdin);
                    n[strcspn(n, "\n")] = '\0';

                    if (!consultar(n)) {
                        printf("Aluno nao cadastrado.\n");
                        Sleep(3000); // pausa de 3 segundos (em milissegundos)
                    }
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                    Sleep(3000); // pausa de 3 segundos (em milissegundos)
                }
                break;
            case 5:
                if (i > 0) {
                    printf("\n--- Dados dos Alunos ---\n");
                    for (int x = 0; x < i; x++) {
                        imprimir(x);
                    }
                    Sleep(3000); // pausa de 3 segundos (em milissegundos)
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                    Sleep(3000); // pausa de 3 segundos (em milissegundos)
                }
                break;
            case 6:
                printf("... saindo...\n");
                Sleep(3000); // pausa de 3 segundos (em milissegundos)
                break;
            default:
                printf("Opção invalida!\n");
                Sleep(3000); // pausa de 3 segundos (em milissegundos)
                break;
        }        
    } while (opcao != 6);

    printf("Sistema finalizado com sucesso!\n");
}
