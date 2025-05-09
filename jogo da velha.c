#include <stdio.h> //entrada e saída
#include <stdlib.h> //system clear etc
#include <windows.h> //puxa função sleep
#include <string.h> //manipular strings (carcteres)
#include <stdbool.h> //booleanos (verdadeiro ou falso) 
#include <locale.h> //permite utilizaz acentuação

char j[3][3]; // variavel definindo matriz que é o tabuleiro do jogo da velha 3x3
char player1[20], player2[20];// variáveis tipo de carcteres de no máximo 20 letras
char simb ='O'; //variável definindo o simbolo base
int nj=0, p1=0, p2=0, emp=0, op=0, lin=0, col=0; //varáveis inteiras para utilizar nos calculos, armazenar dados e no funcionamento do sistema
_Bool enc=false; //utilizaremos para verificar vitória lá na frente

void inicializar(){  //função que inicializa o game e a matriz que irá ficar dentro do tabuleiro
  for(int lin=0; lin<3; lin++){
    for(int col=0; col<3; col++){
      j[lin][col] = ' ';//definindo o caracter que vai ficar enquanto não tem simbolo
    }
  }
  nj=0; //zera o número de jogadas
  enc=false; //torna falso a condição de vitória    
}

char simbolo(){ //função que define o outro simbolo além do base
  if (simb == 'O'){
    simb = 'X';
  }else{
    simb ='O';
  }
  nj++;//incrementa o número de jogadas
  return simb;//retorna o simbolo base
}

void nomear(){//armazena o nome dos jogadores
  printf("Digite o nome do jogador 1: ");
  scanf("%s", player1);
  printf("Digite o nome do jogador 2: ");
  scanf("%s", player2);
}

void menu(){//imprime o menu principal
  system("cls");
  printf("*********\n");
  printf("*       GAME VELHA        *\n");
  printf("*********\n");
  printf("*                         *\n");
  printf("*   1 - INICIAR           *\n");
  printf("*   2 - ESTATÍSTICA       *\n");
  printf("*   3 - SAIR              *\n");
  printf("*                         *\n");
  printf("*********\n\n");
  printf("ESCOLHA A OPÇÃO DESEJADA: ");
}

void game(){//imprime o tabuleiro do game
  system("cls");
  printf("    0   1   2   \n");
  printf("  -------------\n");
  for (int i = 0; i < 3; i++) { //função para imprimir o tabuleiro na tela
    printf("%d | %c | %c | %c |\n", i, j[i][0], j[i][1], j[i][2]); //define as coordenadas para os simbolos
    printf("  -------------\n");
  }
}

void estatistica(){//imprime as estatisticas 
  printf("*********\n");
  printf("*       ESTATÍSTICA       *\n");
  printf("*********\n");
  printf("                           \n");
  printf("    %s = %d    \n", player1, p1);
  printf("    %s = %d    \n", player2, p2);
  printf("    Empate = %i        \n", emp);
  printf("                           \n");
  printf("*********\n");
  Sleep(5000);//espera 5 secundos
}

_Bool verificarjogada(int l, int c){ //verifica se a jogada escolhida está com a casa vazia
  return j[l][c] == ' ';
}

void verificarvitoria(){ //verifica se um dos jogadores ganhou o jogo
  for (int i = 0; i < 3; i++) {
    if ((j[i][0] == j[i][1] && j[i][1] == j[i][2] && j[i][0] != ' ') || //verifica se as linhas e colunas possuem o mesmo simbolo
       (j[0][i] == j[1][i] && j[1][i] == j[2][i] && j[0][i] != ' ')){
      enc = true;
    }    
  }
  if ((j[0][0] == j[1][1] && j[1][1] == j[2][2] && j[0][0] != ' ') || //verifica se as diagonais possuem o mesmo simbolo
      (j[0][2] == j[1][1] && j[1][1] == j[2][0] && j[0][2] != ' ')) {
    enc = true;
  }
  if (enc) {//se enc for verdadeiro, verifica quem ganhou a partida
    game();
    if (simb == 'X') { //se todos os simbolos forem igual a X, o jogador 1 ganha
      p1++;
      printf("Parabéns, %s, você ganhou!!\n", player1);
    } else { //se todos os simbolos forem igual a O, o jogador 2 ganha
      p2++;
      printf("Parabéns, %s, você ganhou!!\n", player2);
    }
    estatistica(); //chama estatistica
  } else if (nj == 9) { // declara empate caso ninguem ganhe
    emp++;
    printf("Deu velha!!!\n");
    estatistica();
  }
}

int main(){//função principal que irá chamar todas as outras
  setlocale(LC_ALL, "Portuguese"); //define o idioma portugues para poder utilizar os acentos
  nomear();
  do{ //operar o metodo menu/game/estatistica até que o usuário escolha o metodo sair
    menu();
    scanf("%d", &op); //escaneia a opção escolhida 
    switch(op){
      case 1:{
        inicializar(); //se escolher o jogo, chama a função inicializar para resetar tudo
        do{          
          game();
          do{//vai repetir a pergunta enquanto o jogador nao colocar o numero dentro da faixa permitida
            printf("Digite a linha entre 0-2: ");
            scanf("%i", &lin);
          }while(lin<0 || lin>2);

          do{
            printf("Digite a coluna entre 0-2: ");
            scanf("%i", &col);
          }while(col<0 || col>2);

          if (verificarjogada(lin, col)){//se na casa escolhida não houver simbolo, ele define o simbolo e continua o jogo
            j[lin][col] = simbolo();
            game();
            if(nj>4) verificarvitoria(); //a partir da 5ª jogada o programa passa a verificar vitoria
          }else{
            printf("Jogada não permitida!\n");
          }
        }while(enc == false && nj < 9);//irá repetir enquanto não houver vitorias e as jogadas forem menor que 9   
        break;
      }
      case 2:{//mostra a estatistica escolhendo a opcao 2
        estatistica();
        break;
      }
      default:{//define como invalido qualquer numero fora dos definidos no menu
        if(op > 3 || op < 1){
          printf("Opção inválida!\n");             
        }
        break;
      }
    }
  }while(op > 0 && op < 3);//irá repetir todo jogo até o usuario finalizar o programa
  printf("Sistema finalizado com sucesso!\n");
}