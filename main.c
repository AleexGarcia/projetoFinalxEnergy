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
#include "usuarios/deletar_usuario.c"
#include "produtos/find_produto.c"
#include "produtos/get_produto.c"
#include "produtos/set_produto.c"
#include "produtos/update_produto.c"
#include "produtos/ler_arquivoProduto.c"
#include "produtos/escrever_arquivoProduto.c"
#include "produtos/delete_produto.c"
#include "vendas/escrever_arquivoVenda.c"
#include "vendas/getVendas.c"
#include "vendas/ler_arquivoVenda.c"
#include "vendas/setVenda.c"
#include "vendas/getFaturamento.c"
#include "vendas/getLucro.c"

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
                                getCliente(clientes, quantidadeClientes,0);
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
                                getCliente(clientes,quantidadeClientes,1);
                                break;
                            case 4:
                                setUser(&usuarios[quantidadeUser],quantidadeUser, usuarios);
                                quantidadeUser++;
                                escreverArquivoUsuario(usuarios, quantidadeUser);
                                break;
                            case 5:
                                getUser(usuarios,quantidadeUser,0);
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
                            case 7:
                                getUser(usuarios,quantidadeUser,0);
                                printf("Digite o id referente ao usuario que deseja deletar ou 0 para retornar:\n ");
                                scanf("%d", &idUsarioRecebido);
                                if(idUsarioRecebido != 0){
                                    int index = findUser(usuarios, quantidadeUser,idUsarioRecebido);
                                    if(index != -1){
                                        deleteUsuario(index, usuarios, &quantidadeUser);
                                        escreverArquivoUsuario(usuarios,quantidadeUser);
                                    }
                                }else{
                                    printf("Id inválido!\n");
                                }
                                break;
                            case 8:
                                getUser(usuarios,quantidadeUser,1);
                                break;
                            case 9:
                                printf("Retornando ao menu anterior!\n");
                                Sleep(2000);
                                break;
                            default:
                                break;
                            }
                        } while (menuUser != 9);
                        break;
                    case 2:

                        do
                        {
                            exibeMenuProduto();
                            scanf("%d", &menuProduto);
                            switch (menuProduto)
                            {
                            case 1:
                                setProduto(&produtos[quantidadeProdutos],quantidadeProdutos,produtos);
                                quantidadeProdutos++;
                                escreverArquivoProduto(produtos, quantidadeProdutos);
                                break;
                            case 2:
                                getProduto(produtos,quantidadeProdutos,0);
                                printf("Digite o id do produto que deseja atualizar ou digite 0 para voltar\n: ");
                                scanf("%d", &idProdutoRecebido);
                                if(idProdutoRecebido != 0){
                                    int index = findProduto(produtos,quantidadeProdutos,idProdutoRecebido);
                                    if(index != -1){
                                        updateProduto(&produtos[index]);
                                        escreverArquivoProduto(produtos, quantidadeProdutos);
                                    }
                                }else if(idProdutoRecebido == 0){
                                    printf("Retornando!");
                                }else{
                                    printf("Id inválido!\n");
                                }
                                break;
                            case 3:
                                getProduto(produtos,quantidadeProdutos,0);
                                printf("Digite o id do produto que deseja deletar ou digite 0 para voltar\n: ");
                                scanf("%d", &idProdutoRecebido);
                                if(idProdutoRecebido != 0){
                                    int index = findProduto(produtos,quantidadeProdutos,idProdutoRecebido);
                                    if(index != -1){
                                        deleteProduto(index , produtos, &quantidadeProdutos);
                                        escreverArquivoProduto(produtos, quantidadeProdutos);
                                    }
                                }else if(idProdutoRecebido == 0){
                                    printf("Retornando!");
                                }else{
                                    printf("Id inválido!\n");
                                }
                                break;
                            case 4:
                                getProduto(produtos,quantidadeProdutos,1);
                                break;
                            case 5:
                                printf("Retornar ao menu principal\n");
                                break;
                            default:
                                printf("Informe um valor válido\n");
                                break;
                            }
                        } while (menuProduto != 5);
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
                                    limpar_tela();
                                    printf("Venda realizada com sucesso!\n");
                                    Sleep(2000);
                                }
                                break;
                            case 2:
                                printf("RELATORIOS DE VENDA\n");
                                int d;
                                do{
                                    limpar_tela();
                                    printf("Listar todas as vendas: digite 1\n");
                                    printf("Faturamento até o momento: digite 2\n");
                                    printf("Projeção de receita: digite 3\n");
                                    printf("Para retornar: digite 4\n");
                                    scanf("%d", &d);
                                    if(d == 1){
                                        getVenda(vendas,quantidadeVendas);
                                        int pausa;
                                        printf("\n Precione enter para retornar \n");
                                        scanf("%d",&pausa);
                                    }else if(d == 2){
                                        getFaturamento(vendas,quantidadeVendas);
                                        int pausa;
                                        printf("\n Precione enter para retornar \n");
                                        scanf("%d",&pausa);
                                    }else if(d == 3){
                                        getLucro(vendas,quantidadeVendas);
                                        int pausa;
                                        printf("\n Precione enter para retornar \n");
                                        scanf("%d",&pausa);
                                    }else if(d == 4){
                                        printf("Saindo!\n");
                                        Sleep(2000);
                                    }else{
                                        printf("Valor inválido!\n");
                                    }
                                }while(d != 4);
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
