#include <stdio.h>
#include <string.h>

#define OPCAO_CADASTRAR_TERRITORIOS 1
#define OPCAO_LISTAR_TERRITORIOS 2
#define OPCAO_SAIR 0

#define MAX_TERRITORIOS 5

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

struct Territorio
{
    char nome[50];
    char corExercito[6];
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
                for (int i = 0; i <= MAX_TERRITORIOS; i++)
                {
                    printf("--- Cadastrando Territorio %d ---\n", i + 1);
                    // CADASTRO DO TERRITORIO...
                    totalTerritorios++;
                }
            }
            else
            {
                printf("Limite de territorios excedido.\n");
            }
            break;
        case OPCAO_LISTAR_TERRITORIOS:
            break;
        default:
            break;
        }
    } while (opcaoSelecionada != OPCAO_SAIR);

    return 0;
}