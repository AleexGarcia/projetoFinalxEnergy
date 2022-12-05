#include "../calculaNumPlacas.c"
#include "precoDoProduto.c"
#include "custoDoProduto.c"
#include "reduzirEstoque.c"

int setVenda(Relatorio *vendas, int quantidadeDeVendas, Produto produtos[], int quantidadeProdutos)
{
    float consumoEnergeticoMedio;
    int numeroDePlacas, compra, numEstruturas, numDisjuntores, numConectores, numCabeamento, numInversor, formaDePagamento;

    printf("Informe o consumo medio do ultimo ano em KWh:\n");
    scanf("%f", &consumoEnergeticoMedio);
    fflush(stdin);

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
        printf("Numero de placas: %d | preço %f\n", numeroDePlacas, precoDasPlacas);
        printf("---------------------------------\n");
        printf("Numero de Inversor: %d | preço %f\n", numInversor, precoDoInversor);
        printf("---------------------------------\n");
        printf("Numero de estruturas: %d | preço %f\n", numEstruturas, precoDaEstrutura);
        printf("---------------------------------\n");
        printf("Numero de cabeamento: %d | preço %f\n", numCabeamento, precoDoCabeamento);
        printf("---------------------------------\n");
        printf("Numero de conectores: %d | preço %f\n", numConectores, precoDosConectores);
        printf("---------------------------------\n");
        printf("Numero de disjuntores: %d | preço %f\n", numDisjuntores, precoDosDisjuntores);
        printf("---------------------------------\n");
        printf("Preço total: %f.2\n", precoTotal);

        float precoAVista = precoTotal * 0.9;
        float precoAPrazoCartao = precoTotal * 1.15;
        float precoAPrazoFinancimento = precoTotal * 1.5;

        printf("Preço a vista: %f.2\n", precoAVista);
        printf("Preço no cartão em 10x: %f 10 x %.2f \n", precoAPrazoCartao , precoAPrazoCartao / 10);
        printf("Preço financiamento em 18x: %f 18 x %.2f \n", precoAPrazoFinancimento , precoAPrazoFinancimento / 18);
        printf("O prazo de 15 dias para a analise do projeto pela concenssionária.\n");
        printf("A instalação do sistema se dá apos a analise em até 7 dias uteis apos a aprovação.\n");
        printf("Há mais um prazo de 7 dias para a vistoria pela concenssionaria!\n");
        printf("E mais 34 dias para que ela troque o relogio medidor do imóvel!\n");
        printf("Totalizando 63 dias desde o inico do processo.\n")
        printf("---------------------------------\n");

        printf("Deseja concluir a compra? Digite 1 para confirmar e 0 para retornar.\n");
        scanf("%d", &compra);
        int i = 0;
        do{
             if(i > 0 ){
                printf("Informe um valor válido!\n");
            }
            printf("Qual a forma de pagamento?\n Digite 1: à vista \n Digite 2: Cartão de crédito \n Digite 3: Financimento\n");
            scanf("%d", &formaDePagamento);
            i++;
        }while(formaDePagamento < 1 || formaDePagamento > 3);

        if(compra == 1){

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
          vendas->id = quantidadeDeVendas + 1;

          return 1;

        }

    }
    return 0;
}
