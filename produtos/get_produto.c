void getProduto(Produto produtos[100] , int quantidadeDeProdutos){
   for (int i = 0; i < quantidadeDeProdutos; i++)
    {
        printf("id: %d | nome: %s | fornecedor: %s | marca: %s tipo: %d  \n", produtos[i].id, produtos[i].nome, produtos[i].fornecedor, produtos[i].marca, produtos[i].tipo);
    }


}
