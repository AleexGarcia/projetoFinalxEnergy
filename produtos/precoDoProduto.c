float precoDoProduto(int tipo, int quantidadeRequisitada, Produto produtos[], int quantidadeDeProdutos ){
  for(int i = 0; i < quantidadeDeProdutos; i++){
    printf("tipo: %d\n", produtos[i].tipo);
    printf("Quantidade em Estoque: %d - %d quantidade requisitada", produtos[i].quantidadeEmEstoque, quantidadeRequisitada);
    if(produtos[i].tipo == tipo && produtos[i].quantidadeEmEstoque >= quantidadeRequisitada){
      return produtos[i].precoDeVenda * quantidadeRequisitada;
    }
  }
  return 0;
}

//findEstoque(tipo,quantidade,arrayDeProdutos);
