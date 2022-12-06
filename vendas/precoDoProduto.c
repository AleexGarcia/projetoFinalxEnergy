float precoDoProduto(int tipo, int quantidadeRequisitada, Produto produtos[], int quantidadeDeProdutos ){
  for(int i = 0; i < quantidadeDeProdutos; i++){
    if(produtos[i].tipo == tipo && produtos[i].quantidadeEmEstoque >= quantidadeRequisitada){
      return produtos[i].precoDeVenda * quantidadeRequisitada;
    }
  }

  printf("\n Erro:Produto do tipo %d não encontrado em estoque ou estoque insuficiente! Favor checar estoque!\n", tipo );
  printf("Quantidade Necessaria: %d\n", quantidadeRequisitada);

  return 0;
}
