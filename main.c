#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include <math.h>
#include "limpaTela.c"
#include "interface/interface.c"
#include "menus/menuPrincipal.c"
#include "menus/menuUsuario.c"
#include "menus/menuProduto.c"
#include "menus/menuVendas.c"
#include "menus/menuAtualizacaoUsuario.c"
#include "usuarios/usuario.c"


void removaQuebraLinha(char texto[100])
{
    size_t ln = strlen(texto) - 1;
    if (*texto && texto[ln] == '\n')
    {
        texto[ln] = '\0';
    }
}

int calculaNumPlacasSol(float consumoMedioAnual, float potenciaPlaca)
{

    return ceil(consumoMedioAnual / (potenciaPlaca * 5 * 0.8 * 30));
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    // Registro do numero de clientes, usuarios e produtos cadastrados.
    int quantidadeUser = 2, quantidadeProdutos = 0, quantidadeClientes = 0;
    // variaveis auxiliares de dados recebidos pelo usuario
    char loginRecebido[25], senhaRecebida[25], nomeClienteRecebido[25], nomeProdutoRecebido[25];
    int idUsarioRecebido;
    // variaveis para controle de menus e autenticacao de usuario
    int menuInicial, menuPrincipal, menuUser, menuProduto, menuVendas, autenticado = 0, acesso;
    // array de armazenamento de usuarios, clientes e produtos
    Usuario usuarios[100];
    Produto produtos[100];
    Cliente clientes[100];

    FILE *fp;
    // preenchendo o array de produtos utilizando um arquivo externo
    fp = fopen("produtos.txt", "r");
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            printf("%d", quantidadeProdutos);
            fgets(produtos[quantidadeProdutos].nome, 99, fp);
            fflush(stdin);
            removaQuebraLinha(produtos[quantidadeProdutos].nome);
            fgets(produtos[quantidadeProdutos].fornecedor, 99, fp);
            fflush(stdin);
            removaQuebraLinha(produtos[quantidadeProdutos].fornecedor);
            fgets(produtos[quantidadeProdutos].marca, 99, fp);
            fflush(stdin);
            removaQuebraLinha(produtos[quantidadeProdutos].marca);
            char aux[25];
            fgets(aux, 25, fp);
            fflush(stdin);
            produtos[quantidadeProdutos].precoDeCompra = atoi(aux);
            fgets(aux, 25, fp);
            fflush(stdin);
            produtos[quantidadeProdutos].precoDeVenda = atoi(aux);
            fgets(aux, 25, fp);
            fflush(stdin);
            produtos[quantidadeProdutos].quantidadeEmEstoque = atoi(aux);
            produtos[quantidadeProdutos].id = quantidadeProdutos;
            quantidadeProdutos++;
        }
        quantidadeProdutos -= 1;
    }
    fclose(fp);
    // definindo os usuarios
    strcpy(usuarios[0].login, "admin");
    strcpy(usuarios[0].senha, "12345");
    strcpy(usuarios[0].nome, "admin");
    strcpy(usuarios[0].sobrenome, "admin");
    strcpy(usuarios[0].telefone, "99999999999");
    usuarios[0].id = 1;
    usuarios[0].acesso = 1;

    strcpy(usuarios[1].login, "funcionario");
    strcpy(usuarios[1].senha, "12345");
    strcpy(usuarios[1].telefone, "99999999999");
    strcpy(usuarios[1].nome, "funcionario");
    strcpy(usuarios[1].sobrenome, "funcionario");
    usuarios[1].acesso = 0;
    usuarios[1].id = 2;

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
                                for (int i = 0; i < quantidadeClientes; i++)
                                {
                                    if (!strcmp(nomeClienteRecebido, clientes[i].nome))
                                    {

                                        int escolhaAttCliente;
                                        do
                                        {
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
                                            switch (escolhaAttCliente)
                                            {
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
                                                printf("Informe o endereÃ§o:\n");
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

                                        } while (escolhaAttCliente != 7);
                                    }
                                }
                                break;
                            case 3:
                                setUsuario(&usuarios[quantidadeUser]);
                                quantidadeUser++;
                                break;
                            case 4:
                                getUsuarios(usuarios,quantidadeUser);
                                printf("Digite o id referente ao usuario que deseja atualizar ou 0 para retornar:\n ");
                                scanf("%d", &idUsarioRecebido);
                                if (idUsarioRecebido != 0)
                                {
                                    int index = findIndex(usuarios, quantidadeUser, idUsarioRecebido);
                                    int escolhaAttUsuario;
                                    do
                                    {
                                        exibeMenuAtualizacaoUsuario(usuarios[index].nome);
                                        scanf("%d", &escolhaAttUsuario);
                                        switch (escolhaAttUsuario)
                                        {
                                        case 1:
                                            printf("Informe o login:\n");
                                            scanf("%s", usuarios[index].login);
                                            printf("Login atualizado com sucesso!\n");
                                            Sleep(1000);
                                            break;
                                        case 2:
                                            printf("Informe o senha:\n");
                                            scanf("%s", usuarios[index].senha);
                                            printf("Senha atualizado com sucesso!\n");
                                            Sleep(1000);
                                            break;
                                        case 3:
                                            printf("Informe o acesso:\n");
                                            scanf("%d", &usuarios[index].acesso);
                                            printf("Acesso atualizado com sucesso!\n");
                                            Sleep(1000);
                                            break;
                                        case 4:
                                            printf("Informe o nome:\n");
                                            scanf("%s", usuarios[index].nome);
                                            printf("Nome atualizado com sucesso!\n");
                                            Sleep(1000);
                                            break;
                                        case 5:
                                            printf("Informe o Sobrenome:\n");
                                            scanf("%s", usuarios[index].sobrenome);
                                            printf("Sobrenome atualizado com sucesso!\n");
                                            Sleep(1000);
                                            break;
                                        case 6:
                                            printf("Informe o endereço:\n");
                                            scanf("%s", usuarios[index].endereco);
                                            printf("Endereço atualizado com sucesso!\n");
                                            Sleep(1000);
                                            break;
                                        case 7:
                                            printf("Informe a data de nascimento:\n");
                                            scanf("%s", usuarios[index].dataDeNascimento);
                                            printf("Data de nascimento atualizado com sucesso!\n");
                                            Sleep(1000);
                                            break;
                                        case 8:
                                            printf("Informe o telefone:\n");
                                            scanf("%s", usuarios[index].telefone);
                                            printf("Telefone atualizado com sucesso!\n");
                                            Sleep(1000);
                                            break;
                                        case 9:
                                            printf("Informe a renda do cliente:\n");
                                            scanf("%f", &usuarios[index].salario);
                                            printf("Renda atualizado com sucesso!\n");
                                            Sleep(1000);
                                            break;
                                        case 10:
                                            printf("Retornando ao menu de usuario!\n");
                                            Sleep(1000);
                                            break;
                                        default:
                                            printf("\n --- Entre com um valor vÃ¡lido! ---\n");
                                            Sleep(1000);
                                            break;
                                        }
                                    } while (escolhaAttUsuario != 10);
                                    index = 0;
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
                                // abrindo um txt para guardar os dados
                                fp = fopen("produtos.txt", "a+");
                                printf("Informe o nome do produto:\n");
                                scanf("%s", produtos[quantidadeProdutos].nome);
                                // gravando o dado obtido no arquivo
                                fprintf(fp, "%s\n", produtos[quantidadeProdutos].nome);
                                fflush(stdin);
                                printf("Informe o fornecedor:\n");
                                scanf("%s", produtos[quantidadeProdutos].fornecedor);
                                fprintf(fp, "%s\n", produtos[quantidadeProdutos].fornecedor);
                                fflush(stdin);
                                printf("Informe a marca do produto:\n");
                                scanf("%s", produtos[quantidadeProdutos].marca);
                                fprintf(fp, "%s\n", produtos[quantidadeProdutos].marca);
                                fflush(stdin);
                                printf("Informe o preço de compra:\n");
                                scanf("%f", &produtos[quantidadeProdutos].precoDeCompra);
                                fprintf(fp, "%f\n", produtos[quantidadeProdutos].precoDeCompra);
                                fflush(stdin);
                                printf("Informe o preço de venda:\n");
                                scanf("%f", &produtos[quantidadeProdutos].precoDeVenda);
                                fprintf(fp, "%f\n", produtos[quantidadeProdutos].precoDeVenda);
                                fflush(stdin);
                                printf("Informe o quantidade comprada:\n");
                                scanf("%d", &produtos[quantidadeProdutos].quantidadeEmEstoque);
                                fprintf(fp, "%d\n", produtos[quantidadeProdutos].quantidadeEmEstoque);
                                fflush(stdin);
                                produtos[quantidadeProdutos].id = quantidadeProdutos;
                                quantidadeProdutos++;
                                // fechando o arquivo
                                fclose(fp);
                                break;
                            case 2:
                                printf("Digite o nome do produto: ");
                                scanf("%s", nomeProdutoRecebido);
                                for (int i = 0; i < quantidadeProdutos; i++)
                                {
                                    if (!strcmp(nomeProdutoRecebido, produtos[i].nome))
                                    {

                                        int escolhaAttProduto;
                                        do
                                        {
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
                                            switch (escolhaAttProduto)
                                            {
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
                                                printf("\n --- Entre com um valor vÃ¡lido! ---\n");
                                                Sleep(1000);
                                                break;
                                            }
                                        } while (escolhaAttProduto != 7);
                                    }
                                    else
                                    {
                                        printf("Produto não encontrado!\n");
                                        Sleep(1000);
                                    }
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
                            float consumoEnergeticoMedio, potenciaDePico;
                            int potenciaDaPlaca, numeroDePlacas;
                            exibeMenuVenda(acesso,&menuVendas);
                            switch (menuVendas)
                            {
                            case 1:
                                printf("Informe o consumo medio do ultimo ano em KWh:\n");
                                scanf("%f", &consumoEnergeticoMedio);
                                fflush(stdin);
                                printf("Informe o numero da potencia da placa:\n");
                                scanf("%d", &potenciaDaPlaca);
                                fflush(stdin);
                                numeroDePlacas = calculaNumPlacasSol(consumoEnergeticoMedio, potenciaDaPlaca);
                                potenciaDePico = numeroDePlacas * potenciaDaPlaca;
                                printf("Numero de Placas de %d WP: %d\n", potenciaDaPlaca, numeroDePlacas);
                                printf("Potencia minima do inversor em KW: %f\n", potenciaDePico);
                                printf("Estruta para as placas");
                                printf("Cabeamento");
                                printf("conectores");
                                printf("Deseja concluir a compra? Digite 1 para confirmar e 0 para retornar.");

                                break;
                            case 2:
                                printf("Emitir um relatorio\n");
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
