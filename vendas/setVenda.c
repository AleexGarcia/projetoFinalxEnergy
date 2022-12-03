#include "../calculaNumPlacas.c"

int setVenda(Relatorio *vendas, int quantidadeDeVendas, Produto produtos[], int quantidadeProdutos)
{
    float consumoEnergeticoMedio, potenciasDePico;
    int numeroDePlacas, compra;
    int numEstruturas, numDisjuntores, numConectores, numCabeamento, numInversor;

    printf("Informe o consumo medio do ultimo ano em KWh:\n");
    scanf("%f", &consumoEnergeticoMedio);
    fflush(stdin);
    numeroDePlacas = calculaNumPlacasSol(consumoEnergeticoMedio);
    int potencias = 340;

    potenciasDePico = numeroDePlacas * potencias;
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
        printf("Numero de Inversor: %d | preço %f\n", numInversor, precoDasPlacas);
        printf("---------------------------------\n");
        printf("Numero de estruturas: %d | preço %f\n", numEstruturas, precoDasPlacas);
        printf("---------------------------------\n");
        printf("Numero de cabeamento: %d | preço %f\n", numCabeamento, precoDasPlacas);
        printf("---------------------------------\n");
        printf("Numero de conectores: %d | preço %f\n", numConectores, precoDasPlacas);
        printf("---------------------------------\n");
        printf("Numero de disjuntores: %d | preço %f\n", numDisjuntores, precoDasPlacas);
        printf("---------------------------------\n");
        printf("Preço total: %f\n", precoTotal);
        printf("---------------------------------\n");

        printf("Deseja concluir a compra? Digite 1 para confirmar e 0 para retornar.\n");
        scanf("%d", &compra);
        if(compra == 1){

          vendas->precoCabeamento = precoDoCabeamento;
          vendas->precoConector = precoDoCabeamento;
          vendas->precoDisjuntor = precoDoCabeamento;
          vendas->precoEstrutura = precoDoCabeamento;
          vendas->precoInversor = precoDoCabeamento;
          vendas->precoPlacas = precoDoCabeamento;
          vendas->precoTotal = precoDoCabeamento;

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
