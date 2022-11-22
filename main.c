#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int id;
    char nome[25];
    char fornecedor[25];
    char marca[25];
    float precoDeCompra;
    float precoDeVenda;
    int quantidadeEmEstoque;
} Produto;

typedef struct
{
    char nome[25];
    char sobrenome[25];
    char endereco[100];
    char dataDeNascimento[10];
    char telefone[11];
    float renda;
    float salario;
    char login[20];
    char senha[20];
    int acesso;
} Usuario;
typedef struct
{
    char nome[25];
    char sobrenome[25];
    char endereco[100];
    char dataDeNascimento[10];
    char telefone[11];
    float renda;
} Cliente;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int quantidadeUser = 1;
    int quantidadeProdutos = 10;
    int quantidadeClientes = 0;
    int autenticado = 0;
    char login[25], senha[25];
    int id;
    Usuario usuarios[quantidadeUser];
    Produto produtos[quantidadeProdutos];
    Cliente clientes[quantidadeProdutos];
    int menuInicial, menuPrincipal, menuUser, menuProduto, menuVendas;

    do
    {
        printf("MENU INICIAL \n Digite 1 p/ login. \n Digite 2 p/ Sair do Sistema.\n");
        scanf("%d", &menuInicial);
        switch (menuInicial)
        {
        case 1:
            printf("Login:\n ");
            scanf("%s", login);
            printf("Senha:\n ");
            scanf("%s", senha);
            for (int i = 0; i < quantidadeUser; i++)
            {
                if (login == usuarios[i].login && senha == usuarios[i].senha)
                {
                    autenticado = 1;
                    id = i;
                }
            }

            if (autenticado == 1)
            {
                do
                {
                    printf("MENU PRINCIPAL\n");
                    printf("Digite 1 para seção de usuarios/clientes\n");
                    printf("Digite 2 para seção de produto\n");
                    printf("Digite 3 para seção de vendas/or�amentos\n");
                    printf("Digite 4 para Logout\n");
                    scanf("%d", &menuPrincipal);
                    switch (menuPrincipal)
                    {
                    case 1:
                        do
                        {
                            printf("MENU USUÁRIO\n");
                            printf("Digite 1 para Cadastrar novo cliente\n");
                            printf("Digite 2 para Cadastrar novo usuário\n");
                            printf("Digite 3 para Atualizar cadastro\n");
                            printf("Digite 4 para Remover usuario/cliente\n");
                            printf("Digite 5 para Retornar ao MENU PRINCIPAL\n");
                            scanf("%d", &menuUser);
                            switch (menuUser)
                            {
                            case 1:
                                printf("Informe o nome:\n");
                                scanf("%s", clientes[quantidadeClientes].nome);
                                printf("Informe o sobrenome:\n");
                                scanf("%s", clientes[quantidadeClientes].sobrenome);
                                printf("Informe o endereco:\n");
                                scanf("%s", clientes[quantidadeClientes].endereco);
                                printf("Informe o telefone:\n");
                                scanf("%s", clientes[quantidadeClientes].telefone);
                                printf("Informe o renda:\n");
                                scanf("%f", clientes[quantidadeClientes].renda);
                                quantidadeClientes++;
                                break;
                            case 2:
                                printf("Atualizar cadastro\n");
                                for(int i = 0; i < quantidadeClientes; i++){
                                    printf("nome: %s id: %d", clientes[i].nome , i);
                                }
                                printf("Digite a id do cliente: ");
                                scanf("%d", int &id);

                                break;
                            case 3:
                                printf("Remover usuario/cliente\n");
                                break;
                            case 4:
                                printf("Remover usuario/cliente\n");
                                break;
                            default:
                                break;
                            }
                        } while (menuUser != 5);
                        break;
                    case 2:
                        printf("MENU PRODUTO\n");
                        printf("Digite 1 para Cadastrar novo produto\n");
                        printf("Digite 2 para Atualizar produto\n");
                        printf("Digite 3 para Remover produto\n");
                        printf("Digite 4 para Retornar ao MENU PRINCIPAL\n");
                        do
                        {
                            scanf("%d", &menuProduto);
                            switch (menuProduto)
                            {
                            case 1:
                                printf("Cadastrar novo produto\n");
                                break;
                            case 2:
                                printf("Atualizar produto\n");
                                break;
                            case 3:
                                printf("Remover produto\n");
                                break;
                            default:
                                break;
                            }
                        } while (menuProduto != 4);
                        break;
                    case 3:
                        printf("MENU VENDAS/OR�AMENTOS\n");
                        printf("Digite 1 para fazer um orçamento!\n");
                        printf("Digite 2 para emitir um relatorio\n");
                        printf("Digite 4 para Retornar ao MENU PRINCIPAL\n");
                        do
                        {
                            scanf("%d", &menuVendas);
                            switch (menuVendas)
                            {
                            case 1:
                                printf("Realizar um or�amento!\n");
                                break;
                            case 2:
                                printf("Emitir um relatorio\n");
                                break;
                            case 3:
                                printf("Voltando para o menu principal\n");
                                break;
                            default:
                                break;
                            }
                        } while (menuVendas != 3);
                        break;
                    case 4:
                        printf("Logout");
                        break;
                    default:
                        break;
                    }
                } while (menuPrincipal != 4);
                break;
            }else{
                printf("Login e/ou senha informados estão incorretos\n");
                break;
            }

        case 2:
            printf("Encerrar o sistema\n");
            break;
        default:
            printf("Entre com um valor válido\n");
            break;
        }

    } while (menuInicial != 2);

    return 0;
}
