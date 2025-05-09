#include <stdio.h>
#include <string.h>

int main()
{
    int anoDeNascimento, idade;
    const int anoAtual=2024;
    char nome[10], res[200];
    
    printf("Digite o seu nome: ");
    scanf("%s",nome);
    printf("Digite seu ano de nascimento: ");
    scanf("%i",&anoDeNascimento);
    idade=anoAtual-anoDeNascimento;
    if(idade<=10){
        strcpy(res,"Criança");
    }else if(idade>=11 && idade<=13){
        strcpy(res,"Pre-Adolescente");
    }else if(idade>=14 && idade<=17){
        strcpy(res,"Adolescente!");
    }else if(idade>=18 && idade<=39){
        strcpy(res,"Adulto!");
    }else if(idade>=40 && idade<=59){
        strcpy(res,"Coroa!");
    }else{
        strcpy(res,"Idoso");
    }
    printf("%s, voce tem %i ano(s), logo voce e %s",nome,idade,res);
}