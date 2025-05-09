#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
  double media,teste,prova;
  
  do{
      system("cls");
      printf("Digite sua nota do teste: ");
      scanf("%lf",&teste);
      if(teste<0 || teste>10){
          printf("Nota Invalida\n");
          Sleep(5000);
      }
  }while(teste<0 || teste>10);
  Sleep(5000);
  
  do{
      system("cls");
      printf("Digite sua nota da prova: ");
      scanf("%lf",&prova);
      if(prova<0 || prova>10){
          printf("Nota Invalida\n");
          Sleep(5000);
      }
  }while(prova<0 || prova>10);
  
  system("cls");
  media=(teste+prova)/2;
  if(media>=6){
      printf("Sua nota foi %1.lf, voce esta aprovado!",media);
  }else{
      printf("Sua nota foi %1.lf, voce esta reprovado!",media);
  }
}
