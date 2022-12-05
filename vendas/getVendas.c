void getVenda(Relatorio vendas[100], int quantidadeVendas)
{
    for (int i = 0; i < quantidadeVendas; i++)
    {
        printf("\n---------------------------------\n");
        printf("Numero de placas: %d | pre�o %.2f\n", vendas[i].quantidadeDePlacas, vendas[i].precoPlacas);
        printf("---------------------------------\n");
        printf("Numero de Inversor: %d | pre�o %.2f\n", vendas[i].quantidadeDeInversores, vendas[i].precoInversor);
        printf("---------------------------------\n");
        printf("Numero de estruturas: %d | pre�o %.2f\n", vendas[i].quantidadeDeEstrutura, vendas[i].precoEstrutura);
        printf("---------------------------------\n");
        printf("Numero de cabeamento: %d | pre�o %.2f\n", vendas[i].quantidadeDeCabeamento, vendas[i].precoCabeamento);
        printf("---------------------------------\n");
        printf("Numero de conectores: %d | pre�o %.2f\n", vendas[i].quantidadeDeConectores, vendas[i].precoConector);
        printf("---------------------------------\n");
        printf("Numero de disjuntores: %d | pre�o %.2f\n", vendas[i].quantidadeDeDisjuntores, vendas[i].precoDisjuntor);
        printf("---------------------------------\n");
        printf("Custo total: %.2f\n", vendas[i].custoTotal);
        printf("Pre�o total: %.2f\n", vendas[i].precoTotal);
        printf("Lucro: %.2f\n", vendas[i].precoTotal - vendas[i].custoPlacas);
        printf("---------------------------------\n");
    }
}
