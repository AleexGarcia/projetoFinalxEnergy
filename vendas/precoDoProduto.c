float precoDoProduto(int tipo, int quantidadeRequisitada, Produto produtos[], int quantidadeDeProdutos ){
  for(int i = 0; i < quantidadeDeProdutos; i++){
    if(produtos[i].tipo == tipo && produtos[i].quantidadeEmEstoque >= quantidadeRequisitada){
      return produtos[i].precoDeVenda * quantidadeRequisitada;
    }
  }
  return 0;
}
