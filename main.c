#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>

typedef struct
{
    int id;
    char nome[25];
    char fornecedor[25];
    char marca[25];
    float precoDeCompra;
    float precoDeVenda;
    int quantidadeEmEstoque;
}Produto;

typedef struct
{
    char nome[25];
    char sobrenome[25];
    char endereco[100];
    char dataDeNascimento[10];
    char telefone[11];
    float salario;
    char login[20];
    char senha[20];
    int acesso;

}Usuario;
typedef struct
{
    char nome[25];
    char sobrenome[25];
    char endereco[100];
    char dataDeNascimento[10];
    char telefone[11];
    float renda;
}Cliente;
void limpar_tela(){
  #ifdef _WIN32
    system("cls");
  # else
    system("clear");
  #endif
}
int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    //Registro do numero de clientes, usuarios e produtos cadastrados.
    int quantidadeUser = 3, quantidadeProdutos = 0, quantidadeClientes = 0;
    //variaveis auxiliares de dados recebidos pelo usuario
    char loginRecebido[25], senhaRecebida[25], nomeClienteRecebido[25], nomeUsarioRecebido[25],nomeProdutoRecebido[25];
    //variaveis para controle de menus e autenticaÃ§Ã£o de usuario
    int menuInicial, menuPrincipal, menuUser, menuProduto, menuVendas, autenticado = 0, acesso = 0;
    //array de armazenamento de usuarios, clientes e produtos
    Usuario usuarios[quantidadeUser];
    Produto produtos[quantidadeProdutos];
    Cliente clientes[quantidadeClientes];
    //defininindo um 1Â° user admin
    strcpy(usuarios[0].login,"admin");
    strcpy(usuarios[0].senha,"12345");
    usuarios[0].acesso = 1;
    //definindo um user funcionario
    strcpy(usuarios[1].login,"funcionario");
    strcpy(usuarios[1].senha,"12345");
    usuarios[1].acesso = 0;

    do
    {
        printf("MENU INICIAL \n Digite 1 p/ login. \n Digite 2 p/ Sair do Sistema.\n");
        scanf("%d", &menuInicial);
        switch (menuInicial)
        {
        case 1:
            //recebendo login e senha
            printf("Login:\n ");
            scanf("%s",loginRecebido);
            printf("Senha:\n ");
            scanf("%s",senhaRecebida);
            //verificando se existe um user c/ este login e senha alterando autenticado = 1;
            for (int i = 0; i < quantidadeUser; i++)
            {
                if (!strcmp(loginRecebido ,usuarios[i].login) && !strcmp(senhaRecebida,usuarios[i].senha))
                {
                    autenticado = 1;
                    limpar_tela();
                }
            }

            if (autenticado == 1)
            {
                do
                {
                    printf("MENU PRINCIPAL\n");
                    printf("Digite 1 para seção de usuários/clientes\n");
                    printf("Digite 2 para seção de produto\n");
                    printf("Digite 3 para seção de vendas/orçamentos\n");
                    printf("Digite 4 para Logout\n");
                    scanf("%d", &menuPrincipal);
                    switch (menuPrincipal)
                    {
                    case 1:
                        do
                        {
                            limpar_tela();
                            printf("MENU USUÁRIO\n");
                            printf("Digite 1 para Cadastrar novo cliente\n");
                            printf("Digite 2 para Atualizar cadastro de cliente\n");
                            printf("Digite 3 para Cadastrar novo usuário\n");
                            printf("Digite 4 para Atualizar cadastro de usuários\n");
                            printf("Digite 5 para Retornar ao MENU PRINCIPAL\n");
                            scanf("%d", &menuUser);
                            switch (menuUser)
                            {
                            case 1:
                                printf("Informe o nome:\n");
                                scanf("%s", clientes[quantidadeClientes].nome);
                                fflush(stdin);
                                printf("Informe o sobrenome:\n");
                                scanf("%s", clientes[quantidadeClientes].sobrenome);
                                fflush(stdin);
                                printf("Informe o endereco:\n");
                                scanf("%s", clientes[quantidadeClientes].endereco);
                                fflush(stdin);
                                printf("Informe o telefone:\n");
                                scanf("%s", clientes[quantidadeClientes].telefone);
                                fflush(stdin);
                                printf("Informe o renda:\n");
                                scanf("%f", &clientes[quantidadeClientes].renda);
                                quantidadeClientes++;
                                break;
                            case 2:
                                printf("Digite o nome do cliente: ");
                                scanf("%s", nomeClienteRecebido);
                                for(int i = 0; i < quantidadeClientes; i++){
                                    if(!strcmp(nomeClienteRecebido ,clientes[i].nome)){

                                        int escolhaAttCliente;
                                        do{
                                            limpar_tela();
                                            printf("Informe o que deseja altera");
                                            printf("Nome: digite 1");
                                            printf("Sobrenome: digite 2");
                                            printf("Endereço: digite 3");
                                            printf("Data de Nascimento: digite 4");
                                            printf("Telefone: digite 5");
                                            printf("Renda: digite 6");
                                            printf("Voltar: digite 7");
                                            scanf("%d", &escolhaAttCliente);
                                            switch(escolhaAttCliente){
                                            case 1:
                                                printf("Informe o nome:\n");
                                                scanf("%s", clientes[i].nome);
                                                printf("Nome atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 2:
                                                printf("Informe o Sobrenome:\n");
                                                scanf("%s", clientes[i].sobrenome);
                                                printf("Sobrenome atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 3:
                                                printf("Informe o endereço:\n");
                                                scanf("%s", clientes[i].endereco);
                                                printf("Endereço atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 4:
                                                printf("Informe a data de nascimento:\n");
                                                scanf("%s", clientes[i].dataDeNascimento);
                                                printf("Data de nascimento atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 5:
                                                printf("Informe o telefone:\n");
                                                scanf("%s", clientes[i].telefone);
                                                printf("Telefone atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 6:
                                                printf("Informe a renda do cliente:\n");
                                                scanf("%f", &clientes[i].renda);
                                                printf("Renda atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 7:
                                                printf("Retornando ao menu de usuario!\n");
                                                Sleep(1000);
                                                break;
                                            default:
                                                printf("\n --- Entre com um valor válido! ---\n");
                                                Sleep(1000);
                                                break;
                                            }

                                        }while(escolhaAttCliente != 7);

                                    }
                                }
                                break;
                            case 3:
                                printf("Informe o login:\n");
                                scanf("%s", usuarios[quantidadeUser].login);
                                fflush(stdin);
                                printf("Informe a senha:\n");
                                scanf("%s", usuarios[quantidadeUser].senha);
                                fflush(stdin);
                                printf("Informe o tipo de acesso: \n 0 - funcionario \n 1 - administrador :\n");
                                scanf("%d", &usuarios[quantidadeUser].acesso);
                                fflush(stdin);
                                printf("Informe o nome:\n");
                                scanf("%s", usuarios[quantidadeUser].nome);
                                fflush(stdin);
                                printf("Informe o sobrenome:\n");
                                scanf("%s", usuarios[quantidadeUser].sobrenome);
                                fflush(stdin);
                                printf("Informe o endereco:\n");
                                scanf("%s", usuarios[quantidadeUser].endereco);
                                fflush(stdin);
                                printf("Informe a data de nascimento:\n");
                                scanf("%s", usuarios[quantidadeUser].dataDeNascimento);
                                fflush(stdin);
                                printf("Informe o telefone:\n");
                                scanf("%s", usuarios[quantidadeUser].telefone);
                                fflush(stdin);
                                printf("Informe o salario:\n");
                                scanf("%f", &usuarios[quantidadeUser].salario);
                                quantidadeUser++;
                                break;
                            case 4:
                                printf("Digite o nome do usuario: ");
                                scanf("%s", nomeUsarioRecebido);
                                for(int i = 0; i < quantidadeUser; i++){
                                    if(!strcmp(nomeUsarioRecebido ,usuarios[i].nome)){

                                        int escolhaAttUsuario;
                                        do{
                                            limpar_tela();
                                            printf("Informe o que deseja altera");
                                            printf("Login: digite 1");
                                            printf("Senha: digite 2");
                                            printf("Acesso: digite 3");
                                            printf("Nome: digite 4");
                                            printf("Sobrenome: digite 5");
                                            printf("Endereço: digite 6");
                                            printf("Data de Nascimento: digite 7");
                                            printf("Telefone: digite 8");
                                            printf("Salario: digite 9");
                                            printf("Voltar: digite 10");
                                            scanf("%d", &escolhaAttUsuario);
                                            switch(escolhaAttUsuario){
                                            case 1:
                                                printf("Informe o login:\n");
                                                scanf("%s", usuarios[i].login);
                                                printf("Login atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 2:
                                                printf("Informe o senha:\n");
                                                scanf("%s", usuarios[i].senha);
                                                printf("Senha atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 3:
                                                printf("Informe o acesso:\n");
                                                scanf("%d", &usuarios[i].acesso);
                                                printf("Acesso atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 4:
                                                printf("Informe o nome:\n");
                                                scanf("%s", usuarios[i].nome);
                                                printf("Nome atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 5:
                                                printf("Informe o Sobrenome:\n");
                                                scanf("%s", usuarios[i].sobrenome);
                                                printf("Sobrenome atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 6:
                                                printf("Informe o endereço:\n");
                                                scanf("%s", usuarios[i].endereco);
                                                printf("Endereço atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 7:
                                                printf("Informe a data de nascimento:\n");
                                                scanf("%s", usuarios[i].dataDeNascimento);
                                                printf("Data de nascimento atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 8:
                                                printf("Informe o telefone:\n");
                                                scanf("%s", usuarios[i].telefone);
                                                printf("Telefone atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 9:
                                                printf("Informe a renda do cliente:\n");
                                                scanf("%f", &usuarios[i].salario);
                                                printf("Renda atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 10:
                                                printf("Retornando ao menu de usuario!\n");
                                                Sleep(1000);
                                                break;
                                            default:
                                                printf("\n --- Entre com um valor válido! ---\n");
                                                Sleep(1000);
                                                break;
                                            }

                                        }while(escolhaAttUsuario != 10);

                                    }
                                }
                                break;
                            default:
                                break;
                            }
                        } while (menuUser != 5);
                        break;
                    case 2:
                        limpar_tela();
                        printf("MENU PRODUTO\n");
                        printf("Digite 1 para Cadastrar novo produto\n");
                        printf("Digite 2 para Atualizar produto em estoque\n");
                        printf("Digite 3 para Retornar ao MENU PRINCIPAL\n");
                        do
                        {
                            scanf("%d", &menuProduto);
                            switch (menuProduto)
                            {
                            case 1:
                                printf("Informe o nome do produto:\n");
                                scanf("%s", produtos[quantidadeProdutos].nome);
                                fflush(stdin);
                                printf("Informe o fornecedor:\n");
                                scanf("%s", produtos[quantidadeProdutos].fornecedor);
                                fflush(stdin);
                                printf("Informe a marca do produto:\n");
                                scanf("%s", produtos[quantidadeProdutos].marca);
                                fflush(stdin);
                                printf("Informe o preço de compra:\n");
                                scanf("%f", &produtos[quantidadeProdutos].precoDeCompra);
                                fflush(stdin);
                                printf("Informe o preço de venda:\n");
                                scanf("%f", &produtos[quantidadeProdutos].precoDeVenda);
                                fflush(stdin);
                                printf("Informe o quantidade comprada:\n");
                                scanf("%d", &produtos[quantidadeProdutos].quantidadeEmEstoque);
                                fflush(stdin);
                                produtos[quantidadeProdutos].id = quantidadeProdutos;
                                quantidadeProdutos++;
                                break;
                            case 2:
                                printf("Digite o nome do produto: ");
                                scanf("%s", nomeProdutoRecebido);
                                for(int i = 0; i < quantidadeProdutos; i++){
                                    if(!strcmp(nomeProdutoRecebido ,produtos[i].nome)){

                                        int escolhaAttProduto;
                                        do{
                                            limpar_tela();
                                            printf("Informe o que deseja altera");
                                            printf("Nome: digite 1");
                                            printf("Fornecedor: digite 2");
                                            printf("Marca: digite 3");
                                            printf("Preço de compra: digite 4");
                                            printf("Preço de venda: digite 5");
                                            printf("Quantidade em estoque: digite 6");
                                            printf("Voltar: digite 7");
                                            scanf("%d", &escolhaAttProduto);
                                            switch(escolhaAttProduto){
                                            case 1:
                                                printf("Informe o nome:\n");
                                                scanf("%s", produtos[i].nome);
                                                printf("Nome atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 2:
                                                printf("Informe o Fornecedor:\n");
                                                scanf("%s", produtos[i].fornecedor);
                                                printf("Fornecedor atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 3:
                                                printf("Informe a Marca:\n");
                                                scanf("%s", produtos[i].marca);
                                                printf("Marca atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 4:
                                                printf("Informe o preço de Compra:\n");
                                                scanf("%f", &produtos[i].precoDeCompra);
                                                printf("Preco de compra atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 5:
                                                printf("Informe o preço de venda:\n");
                                                scanf("%f", &produtos[i].precoDeVenda);
                                                printf("Preço de venda atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 6:
                                                printf("Informe a quantidade em estoque:\n");
                                                scanf("%d", &produtos[i].quantidadeEmEstoque);
                                                printf("Quantidade em estoque atualizado com sucesso!\n");
                                                Sleep(1000);
                                                break;
                                            case 7:
                                                printf("Retornando ao menu de produto!\n");
                                                Sleep(1000);
                                                break;
                                            default:
                                                printf("\n --- Entre com um valor válido! ---\n");
                                                Sleep(1000);
                                                break;
                                            }

                                        }while(escolhaAttProduto != 7);

                                    }
                                }
                                break;
                            case 3:
                                printf("Retornar ao menu principal\n");
                                break;
                            default:
                                break;
                            }
                        } while (menuProduto != 4);
                        break;
                    case 3:
                        limpar_tela();
                        printf("MENU VENDAS/ORÇAMENTOS\n");
                        printf("Digite 1 para fazer um orçamento!\n");
                        printf("Digite 2 para emitir um relatorio\n");
                        printf("Digite 3 para Retornar ao MENU PRINCIPAL\n");
                        do
                        {
                            scanf("%d", &menuVendas);
                            switch (menuVendas)
                            {
                            case 1:
                                printf("Informe o consumo medio do ultimo ano em KWh !\n");
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
                        limpar_tela();
                        printf("Logout realizado com sucesso!\n");
                        autenticado = 0;
                        break;
                    default:
                        break;
                    }
                } while (menuPrincipal != 4);
                break;
            }else{
                printf("\nLogin e/ou senha informados estão incorretos\n");
                break;
            }

        case 2:
            limpar_tela();
            printf("Sistema encerrado!\n");
            break;
        default:
            printf("Entre com um valor válidos\n");
            break;
        }

    } while (menuInicial != 2);

    return 0;
}
