#include "../calculaNumPlacas.c"
#include "precoDoProduto.c"
#include "custoDoProduto.c"
#include "reduzirEstoque.c"

int setVenda(Relatorio *vendas, int quantidadeDeVendas, Produto produtos[], int quantidadeProdutos, Relatorio vendasArray[100])
{
    float consumoEnergeticoMedio;
    int numeroDePlacas, compra, numEstruturas, numDisjuntores, numConectores, numCabeamento, numInversor, formaDePagamento;
    int t = 0;
    printf("Informe o consumo medio do ultimo ano em KWh:\n");

    do{
        if(t > 0){
            printf("Erro: Consumo energetico deve ser maior que 0\n");
        }
        scanf("%f", &consumoEnergeticoMedio);
        fflush(stdin);
        t++;
    }while(consumoEnergeticoMedio <= 0 );
    numeroDePlacas = calculaNumPlacasSol(consumoEnergeticoMedio);
    numInversor = numeroDePlacas;
    numEstruturas = numeroDePlacas;
    numCabeamento = 2 * (numeroDePlacas / numeroDePlacas);
    numConectores = (int)2 * (numeroDePlacas);
    numDisjuntores = (int)3 * (numeroDePlacas / numeroDePlacas);

    float precoDasPlacas = precoDoProduto(0, numeroDePlacas, produtos, quantidadeProdutos);
    float precoDoInversor = precoDoProduto(1, numInversor, produtos, quantidadeProdutos);
    float precoDaEstrutura = precoDoProduto(2, numEstruturas, produtos, quantidadeProdutos);
    float precoDoCabeamento = precoDoProduto(3, numCabeamento, produtos, quantidadeProdutos);
    float precoDosConectores = precoDoProduto(4, numConectores, produtos, quantidadeProdutos);
    float precoDosDisjuntores = precoDoProduto(5, numDisjuntores, produtos, quantidadeProdutos);

    if (precoDasPlacas > 0 && precoDoInversor > 0 &&
        precoDaEstrutura > 0 && precoDoCabeamento > 0 &&
        precoDosConectores > 0 && precoDosDisjuntores > 0)
    {
        float precoTotal = precoDasPlacas + precoDaEstrutura + precoDoInversor + precoDoCabeamento + precoDosConectores + precoDosDisjuntores;

        printf("\n---------------------------------\n");
        printf("Numero de placas: %d | pre�o R$ %.2f\n", numeroDePlacas, precoDasPlacas);
        printf("---------------------------------\n");
        printf("Numero de Inversor: %d | pre�o R$ %.2f\n", numInversor, precoDoInversor);
        printf("---------------------------------\n");
        printf("Numero de estruturas: %d | pre�o R$ %.2f\n", numEstruturas, precoDaEstrutura);
        printf("---------------------------------\n");
        printf("Numero de cabeamento: %d | pre�o R$ %.2f\n", numCabeamento, precoDoCabeamento);
        printf("---------------------------------\n");
        printf("Numero de conectores: %d | pre�o R$ %.2f\n", numConectores, precoDosConectores);
        printf("---------------------------------\n");
        printf("Numero de disjuntores: %d | pre�o R$ %.2f\n", numDisjuntores, precoDosDisjuntores);
        printf("---------------------------------\n");
        printf("Pre�o total: %.2f\n", precoTotal);
        printf("---------------------------------\n");
        float precoAVista = precoTotal * 0.9;
        float precoAPrazoCartao = precoTotal * 1.15;
        float precoAPrazoFinancimento = precoTotal * 1.5;
        printf("Pre�o a vista: R$%.2f\n", precoAVista);
        printf("---------------------------------\n");
        printf("Pre�o no cart�o em 10x: R$ %.2f 10 x R$ %.2f \n", precoAPrazoCartao , precoAPrazoCartao / 10);
        printf("---------------------------------\n");
        printf("Pre�o financiamento em 18x: R$ %.2f 18 x R$ %.2f \n", precoAPrazoFinancimento , precoAPrazoFinancimento / 18);
        printf("---------------------------------\n");
        printf("O prazo de 15 dias para a analise do projeto pela concenssion�ria.\n");
        printf("---------------------------------\n");
        printf("A instala��o do sistema se d� apos a analise em at� 7 dias uteis apos a aprova��o.\n");
        printf("---------------------------------\n");
        printf("H� mais um prazo de 7 dias para a vistoria pela concenssionaria!\n");
        printf("---------------------------------\n");
        printf("E mais 34 dias para que ela troque o relogio medidor do im�vel!\n");
        printf("---------------------------------\n");
        printf("Totalizando 63 dias desde o inico do processo.\n");
        printf("---------------------------------\n");

        printf("Deseja concluir a compra? Digite 1 para confirmar e 0 para retornar.\n");
        scanf("%d", &compra);


        if(compra == 1){
            int i = 0;

            do{
                if(i > 0 ){
                    printf("Informe um valor v�lido!\n");
                }
                printf("Qual a forma de pagamento?\n Digite 1: � vista \n Digite 2: Cart�o de cr�dito \n Digite 3: Financimento\n");
                scanf("%d", &formaDePagamento);
                i++;
            }while(formaDePagamento < 1 || formaDePagamento > 3);

            reduzirEstoque(0,numeroDePlacas,produtos,quantidadeProdutos);
            reduzirEstoque(1,numInversor,produtos,quantidadeProdutos);
            reduzirEstoque(2,numEstruturas,produtos,quantidadeProdutos);
            reduzirEstoque(3,numCabeamento,produtos,quantidadeProdutos);
            reduzirEstoque(4,numConectores,produtos,quantidadeProdutos);
            reduzirEstoque(5,numDisjuntores,produtos,quantidadeProdutos);

            float custoDasPlacas = custoDoProduto(0,numeroDePlacas,produtos,quantidadeProdutos);
            float custoDosInversores = custoDoProduto(1,numInversor,produtos,quantidadeProdutos);
            float custoDaEstrutura = custoDoProduto(2,numEstruturas,produtos,quantidadeProdutos);
            float custoDoCabeamento = custoDoProduto(3,numCabeamento,produtos,quantidadeProdutos);
            float custoDosConectores = custoDoProduto(4,numConectores,produtos,quantidadeProdutos);
            float custoDosDisjuntores = custoDoProduto(5,numDisjuntores,produtos,quantidadeProdutos);

            float custoTotal = custoDasPlacas + custoDosInversores + custoDaEstrutura + custoDoCabeamento + custoDosConectores + custoDosDisjuntores;

            vendas->precoCabeamento = precoDoCabeamento;
            vendas->precoConector = precoDosConectores;
            vendas->precoDisjuntor = precoDosDisjuntores;
            vendas->precoEstrutura = precoDaEstrutura;
            vendas->precoInversor = precoDoInversor;
            vendas->precoPlacas = precoDasPlacas;

            if(formaDePagamento == 1){
                vendas->precoTotal = precoAVista;
                }else if(formaDePagamento == 2){
                vendas->precoTotal = precoAPrazoCartao;
                }else{
                vendas->precoTotal = precoAPrazoFinancimento;
            }

            vendas->custoCabeamento = custoDoCabeamento;
            vendas->custoConector = custoDosConectores;
            vendas->custoDisjuntor = custoDosDisjuntores;
            vendas->custoEstrutura = custoDaEstrutura;
            vendas->custoInversor = custoDosInversores;
            vendas->custoPlacas = custoDasPlacas;
            vendas->custoTotal = custoTotal;

            vendas->lucro = vendas->precoTotal - vendas->custoTotal;

            vendas->quantidadeDeCabeamento = numCabeamento;
            vendas->quantidadeDeConectores = numConectores;
            vendas->quantidadeDeDisjuntores = numDisjuntores;
            vendas->quantidadeDeEstrutura = numEstruturas;
            vendas->quantidadeDeInversores = numInversor;
            vendas->quantidadeDePlacas = numeroDePlacas;
            if(quantidadeDeVendas == 0){
                vendas->id = quantidadeDeVendas + 1;
            }else{
                vendas->id = vendasArray[quantidadeDeVendas - 1].id + 1;
            }

            return 1;

        }

    }else{

        printf("\nDigite 0 para retornar!\n");
        int pausa;
        scanf("%d", &pausa);
    }
    return 0;
}
