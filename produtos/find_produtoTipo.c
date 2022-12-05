int findProdutoTipo(Produto produtos[], int quantidadeDeProdutos, int tipo){
  if(quantidadeDeProdutos > 0){
    for(int i = 0; i < quantidadeDeProdutos; i++){
      if(produtos[i].tipo == tipo){
        return 0;
      }
    }
  }
  return 1;
}
