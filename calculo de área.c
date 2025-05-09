//DESCUBRA A ÁREA

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int poligono, areaCalculada=0;
double base,altura,baseMenor,diagonal,diagonalMenor,area;
char forma[15];

int main(){
 printf("|                 |\n");
 Sleep(500);
 printf("| DESCUBRA A AREA |\n");
  Sleep(500);
  printf("|                 |\n");
  Sleep(500);
   printf("\nQual tipo de area voce quer calcular?");
   printf("\n1. Quadrado\n2. Triangulo\n3. Trapezio\n4. Losango\n5. Paralelogramo\n\nEscolha o numero correspondente: ");
      scanf("%i",&poligono);
      //Quadrado
      if(poligono==1){
          strcpy(forma,"quadrado");
          system("cls");
          printf("Valor da base: ");
              scanf("%lf",&base);
          printf("Valor da altura: ");
              scanf("%lf",&altura);
              area=base*altura;
               areaCalculada = 1;
      //Triângulo
      }else if(poligono==2){
          strcpy(forma,"triangulo");
          system("cls");
          printf("Valor da base: ");
              scanf("%lf",&base);
          printf("Valor da altura: ");
              scanf("%lf",&altura);
              area=(base*altura)/2;
               areaCalculada = 1;
      //Trapézio
      }else if(poligono==3){
          strcpy(forma,"trapézio");
          system("cls");
          printf("Valor da base maior: ");
              scanf("%lf",&base);
          printf("Valor da base menor: ");
              scanf("%lf",&baseMenor);
          printf("Valor da altura: ");
              scanf("%lf",&altura);
              area=(base+baseMenor)*altura/2;
               areaCalculada = 1;
      //Losango
      }else if(poligono==4){
          strcpy(forma,"losango");
          system("cls");
          printf("Valor da diagonal maior: ");
              scanf("%lf",&diagonal);
          printf("Valor da diagonal menor: ");
              scanf("%lf",&diagonalMenor);
              area=(diagonal*diagonalMenor)/2;
               areaCalculada = 1;
      //Paralelogramo
      }else if(poligono==5){
          strcpy(forma,"paralelogramo");
          system("cls");
          printf("Valor da base: ");
              scanf("%lf",&base);
          printf("Valor da altura: ");
              scanf("%lf",&altura);
              area=base*altura;
              areaCalculada = 1;
      }else{
          system("cls");
          printf("Poligono não encontrado!");
      }
       if (areaCalculada==1){
    printf ("A area deste %s e de %.1lfm²",forma,area);
       }
}