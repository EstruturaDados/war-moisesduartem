#include <stdio.h>
#include <string.h>

#define OPCAO_CADASTRAR_TERRITORIOS 1
#define OPCAO_LISTAR_TERRITORIOS 2
#define OPCAO_SAIR 0

// #define MAX_TERRITORIOS 5
#define MAX_TERRITORIOS 1

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void selecionarOpcao(int *opcaoSelecionada)
{
    printf("\n--- WAR ---\n\n");
    printf("%d - Cadastrar Territorios\n", OPCAO_CADASTRAR_TERRITORIOS);
    printf("%d - Listar Territorios\n", OPCAO_LISTAR_TERRITORIOS);
    printf("%d - Sair\n\n", OPCAO_SAIR);

    printf("\n");
    scanf("%d", opcaoSelecionada);
    limparBufferEntrada();
}

#define TAM_NOME_TERRITORIO 50
#define TAM_COR_EXERCITO 6

struct Territorio
{
    char nome[TAM_NOME_TERRITORIO];
    char corExercito[TAM_COR_EXERCITO];
    int numeroTropas;
};

int main()
{
    int opcaoSelecionada, totalTerritorios = 0;
    struct Territorio territorios[MAX_TERRITORIOS];

    do
    {
        selecionarOpcao(&opcaoSelecionada);

        switch (opcaoSelecionada)
        {
        case OPCAO_CADASTRAR_TERRITORIOS:
            if (totalTerritorios < MAX_TERRITORIOS)
            {
                for (int i = 0; i < MAX_TERRITORIOS; i++)
                {
                    printf("--- Cadastrando Territorio %d ---\n", i + 1);

                    printf("Nome do territorio: ");
                    fgets(territorios[i].nome, TAM_NOME_TERRITORIO, stdin);
                    printf("Cor do exercito (ex: Azul, Verde): ");
                    fgets(territorios[i].corExercito, TAM_COR_EXERCITO, stdin);

                    territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';
                    territorios[i].corExercito[strcspn(territorios[i].corExercito, "\n")] = '\0';

                    printf("Numero de Tropas: ");
                    scanf("%d", &territorios[i].numeroTropas);
                    limparBufferEntrada();

                    totalTerritorios++;

                    printf("Cadastro realizado com sucesso.\n");
                }
            }
            else
            {
                printf("Limite de territorios excedido.\n");
            }
            break;
        case OPCAO_LISTAR_TERRITORIOS:
            if (totalTerritorios > 0)
            {
                for (int i = 0; i < totalTerritorios; i++)
                {
                    printf("TERRITORIO %d\n", i + 1);
                    printf("- Nome: %s\n", territorios[i].nome);
                    printf("- Dominado por: Exercito %s\n", territorios[i].corExercito);
                    printf("- Tropas: %d\n\n", territorios[i].numeroTropas);
                }
            }
            else
            {
                printf("Nenhum territorio encontrado.\n");
            }
            break;
        default:
            break;
        }
    } while (opcaoSelecionada != OPCAO_SAIR);

    return 0;
}