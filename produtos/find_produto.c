int findProduto(Produto produtos[100], int quantidadeDeProdutos, int id){
  for(int i = 0; i < quantidadeDeProdutos; i++){
    if(produtos[i].id == id){
      return i;
    }
  }
  return -1;
}
