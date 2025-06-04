#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>

int jogo[4][4];
int opcao, casa, movimentos = 0, recorde, vitorias;
_Bool enc = false;

// verifica se o recorde atual ainda é menor que a quantidade de movimentos da última partida
void recordeAtual()
{
	if (recorde < movimentos)
	{
		recorde = recorde;
	}
	else
	{
		recorde = movimentos;
	}
}

// mostra o recorde atual de movimentos
void pontuacao()
{
	system("cls");
	printf("*********JOGO DOS 15*********\n\n");
	printf("Movimentos da última jogada: %d movimentos\n\n", movimentos);
	printf("Recorde atual: %d movimentos\n", recorde);
	Sleep(3000);
}

// verifica se o jogador ganhou
void verificarVitoria()
{
	if (jogo[0][0] == 1 && jogo[0][1] == 2 && jogo[0][2] == 3 && jogo[0][3] == 4 &&
		jogo[1][0] == 5 && jogo[1][1] == 6 && jogo[1][2] == 7 && jogo[1][3] == 8 &&
		jogo[2][0] == 9 && jogo[2][1] == 10 && jogo[2][2] == 11 && jogo[2][3] == 12 &&
		jogo[3][0] == 13 && jogo[3][1] == 14 && jogo[3][2] == 15)
	{
		system("cls");
		printf("Parabéns! Você finalizou o tabuleiro em %d movimentos\n", movimentos);
		Sleep(3000);
		enc = true;
		vitorias++;
	}
}

// Verifica se o tabuleiro é resolvível
_Bool ehResolvivel(int numeros[16])
{
	int inversoes = 0;
	for (int i = 0; i < 16; i++)
	{
		if (numeros[i] == 0)
			continue;
		for (int j = i + 1; j < 16; j++)
		{
			if (numeros[j] != 0 && numeros[i] > numeros[j])
			{
				inversoes++;
			}
		}
	}

	int linhaZero;
	for (int i = 0; i < 16; i++)
	{
		if (numeros[i] == 0)
		{
			linhaZero = 4 - (i / 4); // conta de baixo para cima
			break;
		}
	}

	return ((inversoes + linhaZero) % 2 == 1);
}

// embaralha o tabuleiro ate chegar numa configuracao resolvivel
void embaralharTabuleiro()
{
	int numeros[16], usado[16] = {0}, index = 0;
	srand(time(NULL)); // inicializa aleatoriedade

	// Gera configuração resolvível
	do
	{
		for (int i = 0; i < 16; i++)
		{
			usado[i] = 0;
		}

		index = 0;
		while (index < 16)
		{
			int r = rand() % 16;
			if (!usado[r])
			{
				numeros[index++] = r;
				usado[r] = 1;
			}
		}
	} while (!ehResolvivel(numeros));

	index = 0;
	for (int l = 0; l < 4; l++)
	{
		for (int c = 0; c < 4; c++)
		{
			jogo[l][c] = numeros[index++];
		}
	}

	// Exibe o tabuleiro
	system("cls");
	for (int l = 0; l < 4; l++)
	{
		for (int c = 0; c < 4; c++)
		{
			printf(" %2d |", jogo[l][c]);
		}
		printf("\n");
	}
}

// verifica se a jogada é válida e troca a posição dos números
void mudarPosicao(int casa)
{
	for (int l = 0; l < 4; l++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (jogo[l][c] == 0)
			{

				if (l < 3 && jogo[l + 1][c] == casa)
				{
					jogo[l + 1][c] = 0;
					jogo[l][c] = casa;
					movimentos++;
					return;
				}
				else if (l > 0 && jogo[l - 1][c] == casa)
				{
					jogo[l - 1][c] = 0;
					jogo[l][c] = casa;
					movimentos++;
					return;
				}
				else if (c < 3 && jogo[l][c + 1] == casa)
				{
					jogo[l][c + 1] = 0;
					jogo[l][c] = casa;
					movimentos++;
					return;
				}
				else if (c > 0 && jogo[l][c - 1] == casa)
				{
					jogo[l][c - 1] = 0;
					jogo[l][c] = casa;
					movimentos++;
					return;
				}
			}
		}
	}
}

void mostrarTabuleiro()
{
	system("cls");
	for (int l = 0; l < 4; l++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (jogo[l][c] == 0)
				printf("    |");
			else
				printf(" %2d |", jogo[l][c]);
		}
		printf("\n");
	}
	printf("\nMovimentos: %d\n", movimentos);
}

// menu principal
void menu()
{
	printf("*********JOGO DOS 15*********\n\n");
	printf("1-Iniciar jogo\n");
	printf("2-Pontuação\n");
	printf("3-Sair\n\n");
	printf("Escolha a opção: ");
	scanf("%d", &opcao);
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	do
	{
		system("cls");
		menu();

		switch (opcao)
		{

		case 1:
			movimentos = 0;
			enc = false;
			embaralharTabuleiro();
			do
			{
				mostrarTabuleiro();
				printf("\nEscolha a casa para mover: ");
				scanf("%d", &casa);
				mudarPosicao(casa);
				verificarVitoria();
			} while (enc == false);
			break;

		case 2:
			if (vitorias > 1)
			{
				recordeAtual();
			}
			else
			{
				recorde = movimentos;
			}
			pontuacao();
			break;

		default:
			if (opcao < 1 || opcao > 3)
			{
				printf("\nOpção invalida\n");
				Sleep(2000);
			}
			break;
		}
	} while (opcao != 3);
	system("cls");
	printf("Jogo finalizado!");

	return 0;
}