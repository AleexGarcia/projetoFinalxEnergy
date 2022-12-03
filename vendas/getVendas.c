void getVenda(Relatorio vendas[100], int quantidadeVendas)
{
    for (int i = 0; i < quantidadeVendas; i++)
    {
        printf("\n---------------------------------\n");
        printf("Numero de placas: %d | preço %f\n", vendas[i].quantidadeDePlacas, vendas[i].precoPlacas);
        printf("---------------------------------\n");
        printf("Numero de Inversor: %d | preço %f\n", vendas[i].quantidadeDeInversores, vendas[i].precoInversor);
        printf("---------------------------------\n");
        printf("Numero de estruturas: %d | preço %f\n", vendas[i].quantidadeDeEstrutura, vendas[i].precoEstrutura);
        printf("---------------------------------\n");
        printf("Numero de cabeamento: %d | preço %f\n", vendas[i].quantidadeDeCabeamento, vendas[i].precoCabeamento);
        printf("---------------------------------\n");
        printf("Numero de conectores: %d | preço %f\n", vendas[i].quantidadeDeConectores, vendas[i].precoConector);
        printf("---------------------------------\n");
        printf("Numero de disjuntores: %d | preço %f\n", vendas[i].quantidadeDeDisjuntores, vendas[i].precoDisjuntor);
        printf("---------------------------------\n");
        printf("Preço total: %f\n", vendas[i].precoTotal);
        printf("---------------------------------\n");
    }
}
