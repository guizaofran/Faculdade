#include <stdio.h>
#include <string.h>
#include <windows.h>

char entrada[100];  // Guarda o número digitado pelo usuário como string
int opcao;          // Guarda a opção do menu escolhida pelo usuário

// Função para inverter uma string (útil para imprimir números depois de montar ao contrário)
void inverteString(char str[]) {
    int tam = strlen(str);
    for (int i = 0; i < tam / 2; i++) {
        char temp = str[i];
        str[i] = str[tam - 1 - i];
        str[tam - 1 - i] = temp;
    }
}

// Converte número binário para octal diretamente, agrupando bits de 3 em 3
void binParaOct(char bin[]) {
    int tam = strlen(bin);
    int i = tam - 1;  // Começa do final da string (bit menos significativo)
    char octal[100];
    int idx = 0;

    // Percorre o binário de trás pra frente, pegando grupos de 3 bits para formar um dígito octal
    while (i >= 0) {
        int valor = 0;
        for (int j = 0; j < 3 && i >= 0; j++, i--) {
            if (bin[i] == '1') {
                valor += (1 << j);  // Soma 2^j para o dígito octal
            }
            else if (bin[i] != '0') {  // Validação de caractere inválido
                printf("Caractere invalido no binario!\n");
                return;
            }
        }
        octal[idx++] = valor + '0'; // Converte valor para caractere '0'..'7'
    }
    octal[idx] = '\0';
    inverteString(octal); // Inverte a string para ordem correta
    printf("Octal: %s\n", octal);
}

// Converte número binário para hexadecimal diretamente, agrupando bits de 4 em 4
void binParaHex(char bin[]) {
    int tam = strlen(bin);
    int i = tam - 1;
    char hexa[100];
    int idx = 0;

    // Percorre de trás pra frente, pegando grupos de 4 bits para formar dígitos hexadecimais
    while (i >= 0) {
        int valor = 0;
        for (int j = 0; j < 4 && i >= 0; j++, i--) {
            if (bin[i] == '1') {
                valor += (1 << j);
            }
            else if (bin[i] != '0') {
                printf("Caractere invalido no binario!\n");
                return;
            }
        }
        // Converte valor para '0'-'9' ou 'A'-'F'
        hexa[idx++] = valor < 10 ? valor + '0' : valor - 10 + 'A';
    }
    hexa[idx] = '\0';
    inverteString(hexa);
    printf("Hexadecimal: %s\n", hexa);
}

// Imprime o número binário como decimal, lendo os bits um a um e somando
void binParaDec(char bin[]) {
    int tam = strlen(bin);
    int valor = 0;
    for (int i = 0; i < tam; i++) {
        if (bin[i] == '1') {
            valor = valor * 2 + 1;  // Multiplica por 2 e soma 1
        } else if (bin[i] == '0') {
            valor *= 2;             // Multiplica por 2 e soma 0
        } else {
            printf("Caractere invalido no binario!\n");
            return;
        }
    }
    printf("Decimal: %d\n", valor);
}

// Converte número octal para binário direto, convertendo cada dígito octal em 3 bits binários
void octParaBin(char oct[]) {
    char bin[400] = "";  // String para construir o binário
    for (int i = 0; i < strlen(oct); i++) {
        if (oct[i] < '0' || oct[i] > '7') {
            printf("Caractere invalido no octal!\n");
            return;
        }
        int digito = oct[i] - '0';
        for (int j = 2; j >= 0; j--) {
            bin[strlen(bin)] = ((digito >> j) & 1) + '0'; // Extrai cada bit do dígito e concatena
        }
    }
    printf("Binario: %s\n", bin);
}

// Converte número octal para hexadecimal, usando octal para binário e depois binário para hexadecimal direto
void octParaHex(char oct[]) {
    char bin[400] = "";
    for (int i = 0; i < strlen(oct); i++) {
        if (oct[i] < '0' || oct[i] > '7') {
            printf("Caractere invalido no octal!\n");
            return;
        }
        int digito = oct[i] - '0';
        for (int j = 2; j >= 0; j--) {
            bin[strlen(bin)] = ((digito >> j) & 1) + '0';
        }
    }
    binParaHex(bin);  // Reutiliza função para converter binário para hexadecimal
}

// Imprime número octal como decimal, lendo dígitos um a um e somando multiplicando por 8 (sem uso de funções prontas)
void octParaDec(char oct[]) {
    int valor = 0;
    for (int i = 0; i < strlen(oct); i++) {
        if (oct[i] < '0' || oct[i] > '7') {
            printf("Caractere invalido no octal!\n");
            return;
        }
        valor = valor * 8 + (oct[i] - '0'); // Multiplica acumulador por 8 e soma o dígito atual
    }
    printf("Decimal: %d\n", valor);
}

// Converte número hexadecimal para binário direto, cada dígito vira 4 bits
void hexParaBin(char hex[]) {
    char bin[400] = "";
    for (int i = 0; i < strlen(hex); i++) {
        char c = hex[i];
        int valor;
        if (c >= '0' && c <= '9') valor = c - '0';
        else if (c >= 'A' && c <= 'F') valor = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f') valor = c - 'a' + 10;
        else {
            printf("Caractere invalido no hexadecimal!\n");
            return;
        }
        for (int j = 3; j >= 0; j--) {
            bin[strlen(bin)] = ((valor >> j) & 1) + '0';
        }
    }
    printf("Binario: %s\n", bin);
}

// Converte hexadecimal para octal, usando hex para binário e depois binário para octal
void hexParaOct(char hex[]) {
    char bin[400] = "";
    for (int i = 0; i < strlen(hex); i++) {
        char c = hex[i];
        int valor;
        if (c >= '0' && c <= '9') valor = c - '0';
        else if (c >= 'A' && c <= 'F') valor = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f') valor = c - 'a' + 10;
        else {
            printf("Caractere invalido no hexadecimal!\n");
            return;
        }
        for (int j = 3; j >= 0; j--) {
            bin[strlen(bin)] = ((valor >> j) & 1) + '0';
        }
    }
    binParaOct(bin);
}

// Imprime número hexadecimal como decimal (sem funções prontas), somando dígitos multiplicados por 16
void hexParaDec(char hex[]) {
    int valor = 0;
    for (int i = 0; i < strlen(hex); i++) {
        char c = hex[i];
        int v;
        if (c >= '0' && c <= '9') v = c - '0';
        else if (c >= 'A' && c <= 'F') v = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f') v = c - 'a' + 10;
        else {
            printf("Caractere invalido no hexadecimal!\n");
            return;
        }
        valor = valor * 16 + v;
    }
    printf("Decimal: %d\n", valor);
}

// Converte decimal para binário direto, usando divisão sucessiva e armazenando os restos
void decParaBin(int n) {
    char bin[100];
    int idx = 0;
    if (n == 0) bin[idx++] = '0'; // Caso especial para zero
    while (n > 0) {
        bin[idx++] = (n % 2) + '0';  // Resto da divisão por 2 vira bit
        n /= 2;
    }
    bin[idx] = '\0';
    inverteString(bin);  // Inverte para ordem correta
    printf("Binario: %s\n", bin);
}

// Converte decimal para octal direto, dividindo sucessivamente por 8 e pegando restos
void decParaOct(int n) {
    char oct[100];
    int idx = 0;
    if (n == 0) oct[idx++] = '0';  // Caso zero
    while (n > 0) {
        oct[idx++] = (n % 8) + '0';
        n /= 8;
    }
    oct[idx] = '\0';
    inverteString(oct);
    printf("Octal: %s\n", oct);
}

// Converte decimal para hexadecimal direto, dividindo sucessivamente por 16 e pegando restos
void decParaHex(int n) {
    char hex[100];
    int idx = 0;
    if (n == 0) hex[idx++] = '0';
    while (n > 0) {
        int resto = n % 16;
        hex[idx++] = resto < 10 ? resto + '0' : resto - 10 + 'A';
        n /= 16;
    }
    hex[idx] = '\0';
    inverteString(hex);
    printf("Hexadecimal: %s\n", hex);
}

// Menu principal do programa
void menu() {
    printf("CALCULADORA DE BASES NUMERICAS\n\n");
    printf("1 - BINARIO\n");
    printf("2 - DECIMAL\n");
    printf("3 - OCTAL\n");
    printf("4 - HEXADECIMAL\n");
    printf("5 - SAIR\n\n");
    printf("ESCOLHA UMA BASE PARA SER CONVERTIDA: ");
}

// Função principal
int main() {
    int numero;
    do {
        system("cls");
        menu();
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
        case 1:  // Se escolher binário, pede o número e mostra em decimal, octal e hexadecimal
            system("cls");
            printf("Digite o numero binario: ");
            scanf("%s", entrada);
            binParaDec(entrada);
            binParaOct(entrada);
            binParaHex(entrada);
            break;
        case 2:  // Se escolher decimal, pede número e converte para binário, octal e hexadecimal
            system("cls");
            printf("Digite o numero decimal: ");
            scanf("%d", &numero);
            decParaBin(numero);
            decParaOct(numero);
            decParaHex(numero);
            break;
        case 3:  // Se escolher octal, pede número e converte para decimal, binário e hexadecimal
            system("cls");
            printf("Digite o numero octal: ");
            scanf("%s", entrada);
            octParaDec(entrada);
            octParaBin(entrada);
            octParaHex(entrada);
            break;
        case 4:  // Se escolher hexadecimal, pede número e converte para decimal, binário e octal
            system("cls");
            printf("Digite o numero hexadecimal: ");
            scanf("%s", entrada);
            hexParaDec(entrada);
            hexParaBin(entrada);
            hexParaOct(entrada);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
        system("pause");
    } while (opcao != 5);
    return 0;
}