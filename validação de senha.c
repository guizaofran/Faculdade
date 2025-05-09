#include <stdio.h>
#include <stdlib.h>

int main()
{
    
   const int senhaCorreta=15;
   int senha, contador=1;
   
   while(contador<=3){
       system("cls");
       printf("Digite a senha: ");
       scanf("%i",&senha);
       if(senha==senhaCorreta){
           printf("Acesso permitido");
           contador=4;
        }else{
            contador++;
        }
   } 
    if(senha!=15){
        printf("Acesso negado");
   }
}
