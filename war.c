#include <stdio.h>

#define OPCAO_CADASTRAR_TERRITORIOS 1
#define OPCAO_LISTAR_TERRITORIOS 2
#define OPCAO_SAIR 0

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

int main()
{
    int opcaoSelecionada;

    do
    {
        selecionarOpcao(&opcaoSelecionada);

        switch (opcaoSelecionada)
        {
        case OPCAO_CADASTRAR_TERRITORIOS:
            break;
        case OPCAO_LISTAR_TERRITORIOS:
            break;
        default:
            break;
        }
    } while (opcaoSelecionada != OPCAO_SAIR);

    return 0;
}