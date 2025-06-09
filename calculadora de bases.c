#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int numeroBin[100], numeroOctal[100], opcao;
char numeroHexa[100];

int potencia(int base, int expoente)
{
    int resultado = 1;
    for (int i = 0; i < expoente; i++)
    {
        resultado *= base;
    }
    return resultado;
}

int binarioParaDecimal(char bin[])
{
    int tam = strlen(bin);
    int decimal = 0;
    for (int i = 0; i < tam; i++)
    {
        if (bin[i] == '1')
        {
            decimal += potencia(2, tam - i - 1);
        }
        else if (bin[i] != '0')
        {
            printf("Caractere invalido no binario!\n");
            return -1;
        }
    }
    return decimal;
}

int octalParaDecimal(char oct[])
{
    int tam = strlen(oct);
    int decimal = 0;
    for (int i = 0; i < tam; i++)
    {
        if (oct[i] >= '0' && oct[i] <= '7')
        {
            decimal += (oct[i] - '0') * potencia(8, tam - i - 1);
        }
        else
        {
            printf("Caractere invalido no octal!\n");
            return -1;
        }
    }
    return decimal;
}

int hexaParaDecimal(char hex[])
{
    int tam = strlen(hex);
    int decimal = 0;
    for (int i = 0; i < tam; i++)
    {
        char ch = hex[i];
        int valor;
        if (ch >= '0' && ch <= '9')
            valor = ch - '0';
        else if (ch >= 'A' && ch <= 'F')
            valor = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'f')
            valor = ch - 'a' + 10;
        else
        {
            printf("Caractere invalido no hexadecimal!\n");
            return -1;
        }
        decimal += valor * potencia(16, tam - i - 1);
    }
    return decimal;
}

void converterDeDecimal(int numero)
{
    // binário
    int i = 0, aux = numero;
    while (aux > 0)
    {
        numeroBin[i++] = aux % 2;
        aux /= 2;
    }
    printf("Binario: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", numeroBin[j]);
    }
    if (i == 0)
    {
        printf("0");
    }

    // octal
    i = 0;
    aux = numero;
    while (aux > 0)
    {
        numeroOctal[i++] = aux % 8;
        aux /= 8;
    }
    printf("\nOctal: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", numeroOctal[j]);
    }
    if (i == 0)
    {
        printf("0");
    }

    // hexadecimal
    i = 0;
    aux = numero;
    while (aux > 0)
    {
        int resto = aux % 16;
        if (resto < 10)
        {
            numeroHexa[i++] = resto + '0';
        }
        else
        {
            numeroHexa[i++] = resto - 10 + 'A';
        }
        aux /= 16;
    }
    printf("\nHexa: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", numeroHexa[j]);
    }
    if (i == 0)
    {
        printf("0");
    }

    printf("\n");
}

void binarioConversor(char bin[])
{
    int decimal = binarioParaDecimal(bin);
    if (decimal >= 0)
    {
        printf("Decimal: %d\n", decimal);
        converterDeDecimal(decimal);
    }
}

void decimalConversor(int numero)
{
    printf("Decimal: %d\n", numero);
    converterDeDecimal(numero);
}

void octalConversor(char oct[])
{
    int decimal = octalParaDecimal(oct);
    if (decimal >= 0)
    {
        printf("Decimal: %d\n", decimal);
        converterDeDecimal(decimal);
    }
}

void hexadecimalConversor(char hex[])
{
    int decimal = hexaParaDecimal(hex);
    if (decimal >= 0)
    {
        printf("Decimal: %d\n", decimal);
        converterDeDecimal(decimal);
    }
}

void menu()
{
    printf("CALCULADORA DE BASES NUMERICAS\n\n");
    printf("1 - BINARIO\n");
    printf("2 - DECIMAL\n");
    printf("3 - OCTAL\n");
    printf("4 - HEXADECIMAL\n");
    printf("5 - SAIR\n\n");
    printf("ESCOLHA UMA BASE PARA SER CONVERTIDA: ");
}

int main()
{
    int numero;
    char entrada[100];

    do
    {
        system("cls");
        menu();
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("Digite o numero binario: ");
            scanf("%s", entrada);
            binarioConversor(entrada);
            Sleep(3500);
            break;
        case 2:
            system("cls");
            printf("Digite o numero decimal: ");
            scanf("%d", &numero);
            decimalConversor(numero);
            Sleep(3500);
            break;
        case 3:
            system("cls");
            printf("Digite o numero octal: ");
            scanf("%s", entrada);
            octalConversor(entrada);
            Sleep(3500);
            break;
        case 4:
            system("cls");
            printf("Digite o numero hexadecimal (sem 0x): ");
            scanf("%s", entrada);
            hexadecimalConversor(entrada);
            Sleep(3500);
            break;
        }
    } while (opcao != 5);

    system("cls");
    printf("Programa finalizado!\n");
    return 0;
}
