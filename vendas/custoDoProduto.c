float custoDoProduto(int tipo, int quantidadeRequisitada, Produto produtos[], int quantidadeDeProdutos ){
  for(int i = 0; i < quantidadeDeProdutos; i++){
    if(produtos[i].tipo == tipo && produtos[i].quantidadeEmEstoque >= quantidadeRequisitada){
      return produtos[i].precoDeCompra * quantidadeRequisitada;
    }
  }
  return 0;
}
