#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

#define MAX 100
#define MAX_DISCIPLINAS 6
#define TAM_NOME 50

int i_prof = 0, i_curso = 0, i_turma = 0, i_disc = 0, i_horario = 0;
int opcao;
long long mat;

char titulo[20];

struct Disciplina
{
    int codDisc;
    char nomeDisc[TAM_NOME];
};

struct Turma
{
    int codTurma;
    char nomeTurma[TAM_NOME];
};

struct Curso
{
    int codCurso;
    char nomeCurso[TAM_NOME];
};

struct Professor
{
    long long matricula;
    char nome[TAM_NOME];
    char escolaridade[TAM_NOME];
    char especialista[TAM_NOME];
    int qtdCursos;
    int qtdturmas;
    int qtdDisciplinas;
    struct Curso curso[MAX_DISCIPLINAS];
    struct Turma turma[MAX_DISCIPLINAS];
    struct Disciplina disciplinas[MAX_DISCIPLINAS];
};

struct Horario
{
    int codCurso;
    int codTurma;
    int codDisc;
    long long matProf;
    char dia[TAM_NOME];
    char hora[15];
};

struct Professor professor[MAX];
struct Curso cursos[MAX];
struct Turma turmas[MAX];
struct Disciplina disciplinas[MAX_DISCIPLINAS];
struct Horario horarios[MAX];

void imprimirProfessor(int y)
{
    printf("Matricula: %lld\n", professor[y].matricula);
    printf("Nome: %s\n", professor[y].nome);
    printf("Escolaridade: %s\n", professor[y].escolaridade);
    printf("Especialista: %s\n", professor[y].especialista);
    printf("Quantidade de Disciplinas: %d\n", professor[y].qtdDisciplinas);
    printf("Disciplinas:\n");
    for (int x = 0; x < professor[y].qtdDisciplinas; x++)
    {
        printf("- %d: %s\n", x + 1, professor[y].disciplinas[x].nomeDisc);
    }
    printf("\n");
}

bool existeProfessor(long long mat, int *pos)
{
    for (int x = 0; x < i_prof; x++)
    {
        if (professor[x].matricula == mat)
        {
            if (pos)
                *pos = x;
            return true;
        }
    }
    return false;
}

void cadastrarProfessor()
{
    long long matTemp;
    int pos;

    printf("Digite a matricula do professor: ");
    scanf("%lld", &matTemp);

    if (existeProfessor(matTemp, &pos))
    {
        printf("Professor já cadastrado:\n");
        imprimirProfessor(pos);
        printf("Nao será cadastrado novamente.\n");
        Sleep(3000);
        return;
    }

    professor[i_prof].matricula = matTemp;
    getchar();

    printf("Digite o nome do professor: ");
    fgets(professor[i_prof].nome, sizeof(professor[i_prof].nome), stdin);
    professor[i_prof].nome[strcspn(professor[i_prof].nome, "\n")] = '\0';

    printf("Digite a escolaridade do professor: ");
    fgets(professor[i_prof].escolaridade, sizeof(professor[i_prof].escolaridade), stdin);
    professor[i_prof].escolaridade[strcspn(professor[i_prof].escolaridade, "\n")] = '\0';

    printf("Digite a especialidade do professor: ");
    fgets(professor[i_prof].especialista, sizeof(professor[i_prof].especialista), stdin);
    professor[i_prof].especialista[strcspn(professor[i_prof].especialista, "\n")] = '\0';

    printf("Digite a Quantidade de Disciplinas do professor: ");
    scanf("%d", &professor[i_prof].qtdDisciplinas);

    getchar();
    for (int x = 0; x < professor[i_prof].qtdDisciplinas; x++)
    {
        printf("- Nome da %d disciplina: ", x + 1);
        fgets(professor[i_prof].disciplinas[x].nomeDisc, TAM_NOME, stdin);
        professor[i_prof].disciplinas[x].nomeDisc[strcspn(professor[i_prof].disciplinas[x].nomeDisc, "\n")] = '\0';
    }

    i_prof++;
    printf("Professor cadastrado com sucesso!\n");
    Sleep(3000);
}

void consultarProfessor()
{
    long long matTemp;
    int pos;

    printf("Digite a matricula do professor: ");
    scanf("%lld", &matTemp);

    if (existeProfessor(matTemp, &pos))
    {
        imprimirProfessor(pos);
    }
    else
    {
        printf("Professor nao cadastrado.\n");
    }
    Sleep(3000);
}

void alterarProfessor()
{
    long long matTemp;
    int pos;

    printf("Digite a matricula do professor: ");
    scanf("%lld", &matTemp);

    if (!existeProfessor(matTemp, &pos))
    {
        printf("Professor nao cadastrado.\n");
        Sleep(3000);
        return;
    }

    printf("Alterar dados do professor:\n");
    printf("1 - Nome\n2 - Escolaridade\n3 - Especialidade\n4 - Quantidade Disciplinas\n5 - Disciplinas\n");
    printf("Escolha a opcao: ");
    int op;
    scanf("%d", &op);
    getchar();

    switch (op)
    {
    case 1:
        printf("Novo nome: ");
        fgets(professor[pos].nome, sizeof(professor[pos].nome), stdin);
        professor[pos].nome[strcspn(professor[pos].nome, "\n")] = '\0';
        break;
    case 2:
        printf("Nova escolaridade: ");
        fgets(professor[pos].escolaridade, sizeof(professor[pos].escolaridade), stdin);
        professor[pos].escolaridade[strcspn(professor[pos].escolaridade, "\n")] = '\0';
        break;
    case 3:
        printf("Nova especialidade: ");
        fgets(professor[pos].especialista, sizeof(professor[pos].especialista), stdin);
        professor[pos].especialista[strcspn(professor[pos].especialista, "\n")] = '\0';
        break;
    case 4:
        printf("Nova quantidade de disciplinas: ");
        scanf("%d", &professor[pos].qtdDisciplinas);
        break;
    case 5:
        for (int d = 0; d < professor[pos].qtdDisciplinas; d++)
        {
            printf("- %d: %s\n", d + 1, professor[pos].disciplinas[d].nomeDisc);
        }
        printf("Qual disciplina deseja alterar? (1-%d): ", professor[pos].qtdDisciplinas);
        int discOpc;
        scanf("%d", &discOpc);
        getchar();
        if (discOpc >= 1 && discOpc <= professor[pos].qtdDisciplinas)
        {
            printf("Novo nome da disciplina: ");
            fgets(professor[pos].disciplinas[discOpc - 1].nomeDisc, TAM_NOME, stdin);
            professor[pos].disciplinas[discOpc - 1].nomeDisc[strcspn(professor[pos].disciplinas[discOpc - 1].nomeDisc, "\n")] = '\0';
        }
        else
        {
            printf("Disciplina invalida!\n");
        }
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }

    printf("Dados alterados com sucesso!\n");
    Sleep(3000);
}

void excluirProfessor()
{
    long long matTemp;
    int pos;

    printf("Digite a matricula do professor: ");
    scanf("%lld", &matTemp);

    if (!existeProfessor(matTemp, &pos))
    {
        printf("Professor nao cadastrado.\n");
        Sleep(3000);
        return;
    }

    for (int x = pos; x < i_prof - 1; x++)
    {
        professor[x] = professor[x + 1];
    }
    i_prof--;
    printf("Professor excluido com sucesso!\n");
    Sleep(3000);
}

void cadastrarCurso()
{
    if (i_curso >= MAX)
    {
        printf("Limite de cursos atingido.\n");
        Sleep(3000);
        return;
    }
    printf("Digite o codigo do curso: ");
    scanf("%d", &cursos[i_curso].codCurso);
    getchar();
    printf("Digite o nome do curso: ");
    fgets(cursos[i_curso].nomeCurso, TAM_NOME, stdin);
    cursos[i_curso].nomeCurso[strcspn(cursos[i_curso].nomeCurso, "\n")] = '\0';
    i_curso++;
    printf("Curso cadastrado com sucesso!\n");
    Sleep(3000);
}

void consultarCurso()
{
    if (i_curso == 0)
    {
        printf("Nenhum curso cadastrado.\n");
        Sleep(3000);
        return;
    }
    printf("Lista de cursos cadastrados:\n");
    for (int i = 0; i < i_curso; i++)
    {
        printf("Codigo: %d - Nome: %s\n", cursos[i].codCurso, cursos[i].nomeCurso);
    }
    Sleep(3000);
}

void cadastrarTurma()
{
    if (i_turma >= MAX)
    {
        printf("Limite de turmas atingido.\n");
        Sleep(3000);
        return;
    }
    printf("Digite o codigo da turma: ");
    scanf("%d", &turmas[i_turma].codTurma);
    getchar();
    printf("Digite o nome da turma: ");
    fgets(turmas[i_turma].nomeTurma, TAM_NOME, stdin);
    turmas[i_turma].nomeTurma[strcspn(turmas[i_turma].nomeTurma, "\n")] = '\0';
    i_turma++;
    printf("Turma cadastrada com sucesso!\n");
    Sleep(3000);
}

void consultarTurma()
{
    if (i_turma == 0)
    {
        printf("Nenhuma turma cadastrada.\n");
        Sleep(3000);
        return;
    }
    printf("Lista de turmas cadastradas:\n");
    for (int i = 0; i < i_turma; i++)
    {
        printf("Codigo: %d - Nome: %s\n", turmas[i].codTurma, turmas[i].nomeTurma);
    }
    Sleep(3000);
}

void cadastrarDisciplina()
{
    if (i_disc >= MAX_DISCIPLINAS)
    {
        printf("Limite de disciplinas atingido.\n");
        Sleep(3000);
        return;
    }
    printf("Digite o codigo da disciplina: ");
    scanf("%d", &disciplinas[i_disc].codDisc);
    getchar();
    printf("Digite o nome da disciplina: ");
    fgets(disciplinas[i_disc].nomeDisc, TAM_NOME, stdin);
    disciplinas[i_disc].nomeDisc[strcspn(disciplinas[i_disc].nomeDisc, "\n")] = '\0';
    i_disc++;
    printf("Disciplina cadastrada com sucesso!\n");
    Sleep(3000);
}

void consultarDisciplina()
{
    if (i_disc == 0)
    {
        printf("Nenhuma disciplina cadastrada.\n");
        Sleep(3000);
        return;
    }
    printf("Lista de disciplinas cadastradas:\n");
    for (int i = 0; i < i_disc; i++)
    {
        printf("Codigo: %d - Nome: %s\n", disciplinas[i].codDisc, disciplinas[i].nomeDisc);
    }
    Sleep(3000);
}

void cadastrarHorario()
{
    if (i_horario >= MAX)
    {
        printf("Limite de horarios atingido.\n");
        Sleep(3000);
        return;
    }
    printf("Digite o codigo do curso: ");
    scanf("%d", &horarios[i_horario].codCurso);
    printf("Digite o codigo da turma: ");
    scanf("%d", &horarios[i_horario].codTurma);
    printf("Digite o codigo da disciplina: ");
    scanf("%d", &horarios[i_horario].codDisc);
    printf("Digite a matricula do professor: ");
    scanf("%lld", &horarios[i_horario].matProf);
    getchar();
    printf("Digite o dia da aula: ");
    fgets(horarios[i_horario].dia, TAM_NOME, stdin);
    horarios[i_horario].dia[strcspn(horarios[i_horario].dia, "\n")] = '\0';
    printf("Digite o horario da aula: ");
    fgets(horarios[i_horario].hora, 15, stdin);
    horarios[i_horario].hora[strcspn(horarios[i_horario].hora, "\n")] = '\0';

    i_horario++;
    printf("Horario cadastrado com sucesso!\n");
    Sleep(3000);
}

void consultarHorario()
{
    if (i_horario == 0)
    {
        printf("Nenhum horario cadastrado.\n");
        Sleep(3000);
        return;
    }
    printf("Lista de horarios cadastrados:\n");
    for (int i = 0; i < i_horario; i++)
    {
        printf("Curso: %d, Turma: %d, Disciplina: %d, Professor: %lld, Dia: %s, Hora: %s\n",
               horarios[i].codCurso, horarios[i].codTurma, horarios[i].codDisc,
               horarios[i].matProf, horarios[i].dia, horarios[i].hora);
    }
    Sleep(3000);
}

void submenu(char *entidade)
{
    while (1)
    {
        system("cls");
        printf("*****************************\n");
        printf("*        %s       *\n", entidade);
        printf("*****************************\n");
        printf("*   1 - CADASTRAR           *\n");
        printf("*   2 - CONSULTAR           *\n");
        printf("*   3 - ALTERAR             *\n");
        printf("*   4 - EXCLUIR             *\n");
        printf("*   0 - VOLTAR              *\n");
        printf("*****************************\n");
        printf("ESCOLHA A OPCAO DESEJADA: ");
        scanf("%d", &opcao);
        getchar();

        if (strcmp(entidade, "Professor") == 0)
        {
            switch (opcao)
            {
            case 1:
                cadastrarProfessor();
                break;
            case 2:
                consultarProfessor();
                break;
            case 3:
                alterarProfessor();
                break;
            case 4:
                excluirProfessor();
                break;
            case 0:
                return;
            default:
                printf("Opcao invalida!\n");
                Sleep(3000);
            }
        }
        else if (strcmp(entidade, "Curso") == 0)
        {
            switch (opcao)
            {
            case 1:
                cadastrarCurso();
                break;
            case 2:
                consultarCurso();
                break;
            case 0:
                return;
            default:
                printf("Opcao invalida!\n");
                Sleep(3000);
            }
        }
        else if (strcmp(entidade, "Turma") == 0)
        {
            switch (opcao)
            {
            case 1:
                cadastrarTurma();
                break;
            case 2:
                consultarTurma();
                break;
            case 0:
                return;
            default:
                printf("Opcao invalida!\n");
                Sleep(3000);
            }
        }
        else if (strcmp(entidade, "Disciplina") == 0)
        {
            switch (opcao)
            {
            case 1:
                cadastrarDisciplina();
                break;
            case 2:
                consultarDisciplina();
                break;
            case 0:
                return;
            default:
                printf("Opcao invalida!\n");
                Sleep(3000);
            }
        }
        else if (strcmp(entidade, "Horario") == 0)
        {
            switch (opcao)
            {
            case 1:
                cadastrarHorario();
                break;
            case 2:
                consultarHorario();
                break;
            case 0:
                return;
            default:
                printf("Opcao invalida!\n");
                Sleep(3000);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    while (1)
    {
        system("cls");
        printf("*****************************\n");
        printf("*        MENU PRINCIPAL     *\n");
        printf("*****************************\n");
        printf("*   1 - PROFESSOR           *\n");
        printf("*   2 - CURSO               *\n");
        printf("*   3 - TURMA               *\n");
        printf("*   4 - DISCIPLINA          *\n");
        printf("*   5 - HORARIO             *\n");
        printf("*   0 - SAIR                *\n");
        printf("*****************************\n");
        printf("ESCOLHA A OPCAO DESEJADA: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            submenu("Professor");
            break;
        case 2:
            submenu("Curso");
            break;
        case 3:
            submenu("Turma");
            break;
        case 4:
            submenu("Disciplina");
            break;
        case 5:
            submenu("Horario");
            break;
        case 0:
            printf("Saindo...\n");
            Sleep(3000);
            exit(0);
        default:
            printf("Opcao invalida!\n");
            Sleep(3000);
        }
    }
    return 0;
}