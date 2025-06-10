#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int opcao, i = 0, numero;
char continuar;

#define MAXIMO 100

struct Produtos
{
    int codigo;
    char nome[50];
    int quantidade;
};

struct Produtos produtos[MAXIMO];

void imprimir(int x)
{
    printf("Nome: %s\n", produtos[x].nome);
    printf("Quantidade: %d\n", produtos[x].quantidade);
    if (produtos[x].quantidade < 10)
    {
        printf("\nEstoque baixo");
    }
}
void consultar()
{
    int achou = 0;
    printf("Informe o codigo do produto: ");
    scanf("%d", &numero);
    for (int x = 0; x < i; x++)
    {
        if (numero == produtos[x].codigo)
        {
            imprimir(x);
            achou = 1;
            break;
        }
    }
    if (!achou)
    {
        printf("\nProduto nao encontrado");
    }
}

void cadastrar()
{
    do
    {
        system("cls");

        printf("Insira o codigo do produto %d: ", i + 1);
        scanf("%d", &produtos[i].codigo);

        getchar();
        printf("Informe o nome do produto %d: ", i + 1);
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        printf("Quantidade deste produto: ");
        scanf("%d", &produtos[i].quantidade);

        i++;

        printf("Deseja continuar?(S/N): ");
        scanf(" %c", &continuar);
        getchar();

    } while (i < MAXIMO && (continuar == 'S' || continuar == 's'));
}

int main()
{
    system("cls");
    cadastrar();
    system("cls");
    do
    {
        printf("\nConsultar algum produto ou finalizar? (1/2):  ");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            system("cls");
            consultar();
            Sleep(3000);
        }
    } while (opcao == 1);
    system("cls");
    printf("Registro de produtos finalizado");
}