#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

#define MAX 100
#define MAX_DISCIPLINAS 6
#define TAM_NOME 50

// Structs
struct Disciplina {
    int codDisc;
    char nomeDisc[TAM_NOME];
};

struct Turma {
    int codTurma;
    char nomeTurma[TAM_NOME];
};

struct Curso {
    int codCurso;
    char nomeCurso[TAM_NOME];
};

struct Professor {
    long long matricula;
    char nome[TAM_NOME];
    char escolaridade[TAM_NOME];
    char especialista[TAM_NOME];
    int qtdCursos;
    int qtdTurmas;
    int qtdDisciplinas;
    struct Curso curso[MAX_DISCIPLINAS];
    struct Turma turma[MAX_DISCIPLINAS];
    struct Disciplina disciplinas[MAX_DISCIPLINAS];    
};

struct Horario {
    int codCurso;
    int codTurma;  
    int codDisc;
    long long matProf;
    char dia[TAM_NOME];
    char hora[15];
};

// Globais
struct Professor professores[MAX];
int totalProfessores = 0;

// Funções auxiliares
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int buscarProfessorPorMatricula(long long matricula) {
    for (int i = 0; i < totalProfessores; i++) {
        if (professores[i].matricula == matricula) return i;
    }
    return -1;
}

void imprimirProfessor(int idx) {
    printf("Matricula: %lld\n", professores[idx].matricula);
    printf("Nome: %s\n", professores[idx].nome);
    printf("Escolaridade: %s\n", professores[idx].escolaridade);
    printf("Especialista: %s\n", professores[idx].especialista);
    printf("Quantidade de Disciplinas: %d\n", professores[idx].qtdDisciplinas);
    for (int i = 0; i < professores[idx].qtdDisciplinas; i++) {
        printf("- %d: %s\n", i + 1, professores[idx].disciplinas[i].nomeDisc);
    }
}

void cadastrarProfessor() {
    if (totalProfessores >= MAX) {
        printf("Limite de professores atingido.\n");
        return;
    }

    long long mat;
    printf("Digite a matricula do professor: ");
    scanf("%lld", &mat);
    limparBuffer();

    int idx = buscarProfessorPorMatricula(mat);
    if (idx != -1) {
        printf("Professor ja cadastrado.\n");
        imprimirProfessor(idx);
        return;
    }

    struct Professor novo;
    novo.matricula = mat;

    printf("Digite o nome: ");
    fgets(novo.nome, TAM_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Digite a escolaridade: ");
    fgets(novo.escolaridade, TAM_NOME, stdin);
    novo.escolaridade[strcspn(novo.escolaridade, "\n")] = '\0';

    printf("Digite a especialidade: ");
    fgets(novo.especialista, TAM_NOME, stdin);
    novo.especialista[strcspn(novo.especialista, "\n")] = '\0';

    printf("Quantidade de disciplinas: ");
    scanf("%d", &novo.qtdDisciplinas);
    limparBuffer();

    for (int i = 0; i < novo.qtdDisciplinas; i++) {
        printf("- Nome da %da disciplina: ", i + 1);
        fgets(novo.disciplinas[i].nomeDisc, TAM_NOME, stdin);
        novo.disciplinas[i].nomeDisc[strcspn(novo.disciplinas[i].nomeDisc, "\n")] = '\0';
    }

    professores[totalProfessores++] = novo;
    printf("Professor cadastrado com sucesso!\n");
    Sleep(2000);
}

void menuOperacao(const char *titulo) {
    system("cls");
    printf("***********\n");
    printf("*         %s         *\n", titulo);
    printf("***********\n");
    printf("*   1 - CURSO               *\n");
    printf("*   2 - TURMA               *\n");
    printf("*   3 - DISCIPLINA          *\n");
    printf("*   4 - PROFESSOR           *\n");
    printf("*   5 - HORARIO             *\n");
    printf("*   6 - VOLTAR              *\n");
    printf("***********\n");
    printf("ESCOLHA A OPCAO DESEJADA: ");
}

void consultarProfessor() {
    long long mat;
    printf("Digite a matricula do professor: ");
    scanf("%lld", &mat);

    int idx = buscarProfessorPorMatricula(mat);
    if (idx == -1) {
        printf("Professor nao encontrado.\n");
    } else {
        imprimirProfessor(idx);
    }
    Sleep(3000);
}

void menuPrincipal() {
    int opcao;
    do {
        system("cls");
        printf("***********\n");
        printf("*       MENU PRINCIPAL      *\n");
        printf("***********\n");
        printf("*   1 - CADASTRAR           *\n");
        printf("*   2 - CONSULTAR           *\n");
        printf("*   3 - SAIR                *\n");
        printf("***********\n");
        printf("ESCOLHA A OPCAO: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                menuOperacao("CADASTRAR");
                int opCad;
                scanf("%d", &opCad);
                if (opCad == 4) cadastrarProfessor();
                break;
            case 2:
                menuOperacao("CONSULTAR");
                int opCons;
                scanf("%d", &opCons);
                if (opCons == 4) consultarProfessor();
                break;
            case 3:
                printf("Saindo...\n");
                Sleep(2000);
                break;
            default:
                printf("Opcao invalida!\n");
                Sleep(2000);
        }

    } while (opcao != 3);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    menuPrincipal();
    return 0;
}