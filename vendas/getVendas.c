void getVenda(Relatorio vendas[100], int quantidadeVendas)
{
    if(quantidadeVendas > 0){

            for (int i = 0; i < quantidadeVendas; i++)
            {
                printf("\n--------------- ID=%d ---------------\n", vendas[i].id);
                printf("Numero de placas: %d | preço R$ %.2f\n", vendas[i].quantidadeDePlacas, vendas[i].precoPlacas);
                printf("---------------------------------\n");
                printf("Numero de Inversor: %d | preço R$ %.2f\n", vendas[i].quantidadeDeInversores, vendas[i].precoInversor);
                printf("---------------------------------\n");
                printf("Numero de estruturas: %d | preço R$ %.2f\n", vendas[i].quantidadeDeEstrutura, vendas[i].precoEstrutura);
                printf("---------------------------------\n");
                printf("Numero de cabeamento: %d | preço R$ %.2f\n", vendas[i].quantidadeDeCabeamento, vendas[i].precoCabeamento);
                printf("---------------------------------\n");
                printf("Numero de conectores: %d | preço R$ %.2f\n", vendas[i].quantidadeDeConectores, vendas[i].precoConector);
                printf("---------------------------------\n");
                printf("Numero de disjuntores: %d | preço R$ %.2f\n", vendas[i].quantidadeDeDisjuntores, vendas[i].precoDisjuntor);
                printf("---------------------------------\n");
                printf("Custo total: R$ %.2f\n", vendas[i].custoTotal);
                printf("Preço total: R$ %.2f\n", vendas[i].precoTotal);
                printf("Lucro: R$ %.2f\n", vendas[i].precoTotal - vendas[i].custoPlacas);
                printf("---------------------------------\n");
            }
        }else{
                printf("Nenhuma venda realizada!\n");
        }
}
