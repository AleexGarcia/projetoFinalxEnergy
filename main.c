#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include <math.h>
#include "interface/interface.c"
#include "limpaTela.c"
#include "remove_quebraLinha.c"
#include "menus/menuPrincipal.c"
#include "menus/menuUsuario.c"
#include "menus/menuProduto.c"
#include "menus/menuVendas.c"
#include "menus/menuAtualizacaoUsuario.c"
#include "clientes/find_cliente.c"
#include "clientes/get_cliente.c"
#include "clientes/set_cliente.c"
#include "clientes/update_cliente.c"
#include "clientes/ler_arquivoClientes.c"
#include "clientes/escrever_arquivoClientes.c"
#include "usuarios/find_user.c"
#include "usuarios/get_user.c"
#include "usuarios/set_user.c"
#include "usuarios/update_user.c"
#include "usuarios/ler_arquivoUsuario.c"
#include "usuarios/escrever_arquivoUsuario.c"
#include "produtos/find_produto.c"
#include "produtos/get_produto.c"
#include "produtos/set_produto.c"
#include "produtos/update_produto.c"
#include "produtos/ler_arquivoProduto.c"
#include "produtos/escrever_arquivoProduto.c"
#include "produtos/precoDoProduto.c"
#include "vendas/escrever_arquivoVenda.c"
#include "vendas/getVendas.c"
#include "vendas/ler_arquivoVenda.c"
#include "vendas/setVenda.c"


int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    // Registro do numero de clientes, usuarios e produtos cadastrados.
    int quantidadeUser = 0, quantidadeProdutos = 0, quantidadeClientes = 0, quantidadeVendas = 0;
    // variaveis auxiliares de dados recebidos pelo usuario
    char loginRecebido[25], senhaRecebida[25];
    int idUsarioRecebido, idDoCliente, idProdutoRecebido, resposta;
    // variaveis para controle de menus e autenticacao de usuario
    int menuInicial, menuPrincipal, menuUser, menuProduto, menuVendas, autenticado = 0, acesso;
    // array de armazenamento de usuarios, clientes e produtos
    Usuario usuarios[100];
    Produto produtos[100];
    Cliente clientes[100];
    Relatorio vendas[100];
    //lendo arquivos binarios de arrays de structs e guardando a quantidade de valores lidos
    quantidadeClientes = ler_arquivoCliente(clientes);
    quantidadeProdutos = ler_arquivoProduto(produtos);
    quantidadeUser = ler_arquivoUsuario(usuarios);
    quantidadeVendas = ler_arquivoVenda(vendas);

    do
    {
        printf("MENU INICIAL \n Digite 1 p/ login. \n Digite 2 p/ Sair do Sistema.\n");
        scanf("%d", &menuInicial);
        switch (menuInicial)
        {
        case 1:
            // recebendo login e senha
            printf("Login:\n ");
            scanf("%s", loginRecebido);
            printf("Senha:\n ");
            scanf("%s", senhaRecebida);
            // verificando se existe um user c/ este login e senha alterando autenticado = 1;
            for (int i = 0; i < quantidadeUser; i++)
            {
                if (!strcmp(loginRecebido, usuarios[i].login) && !strcmp(senhaRecebida, usuarios[i].senha))
                {
                    autenticado = 1;
                    acesso = usuarios[i].acesso;
                    limpar_tela();
                    break;
                }
            }

            if (autenticado == 1)
            {
                do
                {
                    exibeMenuPrincipal();
                    scanf("%d", &menuPrincipal);
                    switch (menuPrincipal)
                    {
                    case 1:
                        do
                        {
                            exibeMenuUsuario(acesso, &menuUser);
                            switch (menuUser)
                            {
                            case 1:
                                setCliente(&clientes[quantidadeClientes], quantidadeClientes);
                                quantidadeClientes++;
                                escreverArquivoCliente(clientes, quantidadeClientes);
                                break;
                            case 2:
                                getCliente(clientes, quantidadeClientes);
                                printf("Digite a id do cliente ou 0 para voltar! \n");
                                scanf("%d", &idDoCliente);
                                if(idDoCliente != 0){
                                    int index = findCliente(clientes,quantidadeClientes,idDoCliente);
                                    if(index != - 1){
                                        updateCliente(&clientes[index]);
                                        escreverArquivoCliente(clientes, quantidadeClientes);
                                    }
                                }else{
                                    printf("Id inválido!\n");
                                }
                                break;
                            case 3:
                                setUser(&usuarios[quantidadeUser],quantidadeUser, usuarios);
                                quantidadeUser++;
                                escreverArquivoUsuario(usuarios, quantidadeUser);
                                break;
                            case 4:
                                getUser(usuarios,quantidadeUser);
                                printf("Digite o id referente ao usuario que deseja atualizar ou 0 para retornar:\n ");
                                scanf("%d", &idUsarioRecebido);
                                if(idUsarioRecebido != 0){
                                    int index = findUser(usuarios, quantidadeUser,idUsarioRecebido);
                                    if(index != -1){
                                        updateUser(&usuarios[index]);
                                        escreverArquivoUsuario(usuarios,quantidadeUser);
                                    }
                                }else{
                                    printf("Id inválido!\n");
                                }
                                break;
                            default:
                                break;
                            }
                        } while (menuUser != 5);
                        break;
                    case 2:

                        do
                        {
                            exibeMenuProduto();
                            scanf("%d", &menuProduto);
                            switch (menuProduto)
                            {
                            case 1:
                                setProduto(&produtos[quantidadeProdutos],quantidadeProdutos);
                                quantidadeProdutos++;
                                escreverArquivoProduto(produtos, quantidadeProdutos);
                                break;
                            case 2:
                                getProduto(produtos,quantidadeProdutos);
                                printf("Digite o id do produto que deseja atualizar ou digite 0 para voltar\n: ");
                                scanf("%d", &idProdutoRecebido);
                                if(idProdutoRecebido != 0){
                                    int index = findProduto(produtos,quantidadeProdutos,idProdutoRecebido);
                                    if(index != -1){
                                        updateProduto(&produtos[index]);
                                        escreverArquivoProduto(produtos, quantidadeProdutos);
                                    }
                                }else{
                                    printf("Id inválido!\n");
                                }
                                break;
                            case 3:
                                printf("Retornar ao menu principal\n");
                                break;
                            default:
                                printf("Informe um valor válido\n");
                                break;
                            }
                        } while (menuProduto != 3);
                        break;
                    case 3:
                        do
                        {

                            exibeMenuVenda(acesso,&menuVendas);
                            switch (menuVendas)
                            {
                            case 1:
                                resposta = setVenda(&vendas[quantidadeVendas],quantidadeVendas,produtos,quantidadeProdutos);
                                if(resposta){
                                    quantidadeVendas++;
                                    escreverArquivoVenda(vendas,quantidadeVendas);
                                }
                                break;
                            case 2:
                                printf("RELATORIOS DE VENDA\n");
                                getVenda(vendas,quantidadeVendas);
                                int d;
                                printf("Aperte enter para voltar!\n");
                                scanf("%d", &d);
                                break;
                            case 3:
                                printf("Voltando para o menu principal\n");
                                break;
                            default:
                                printf("Entre com um número válido!\n");
                                break;
                            }
                        } while (menuVendas != 3);
                        break;
                    case 4:
                        limpar_tela();
                        printf("Logout realizado com sucesso!\n");
                        autenticado = 0;
                        acesso = 0;
                        break;
                    default:
                        break;
                    }
                } while (menuPrincipal != 4);
                break;
            }
            else
            {
                printf("\nLogin e/ou senha informados estÃ£o incorretos\n");
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
