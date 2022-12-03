float precoDoProduto(int tipo, int quantidadeRequisitada, Produto produtos[], int quantidadeDeProdutos ){
  for(int i = 0; i < quantidadeDeProdutos; i++){
    if(produtos[i].tipo == tipo && produtos[i].quantidadeEmEstoque >= quantidadeRequisitada){
      return produtos[i].precoDeVenda * quantidadeRequisitada;
    }else{
      printf("Não há quantidade suficiente em estoque!\n");
      return 0;
    }
  }

}

//findEstoque(tipo,quantidade,arrayDeProdutos);
