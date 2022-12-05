void getProduto(Produto produtos[100] , int quantidadeDeProdutos, int exibicaoTotal){
   if(quantidadeDeProdutos > 0){
     for (int i = 0; i < quantidadeDeProdutos; i++)
      {
        if(exibicaoTotal == 0){
          printf("id: %d | nome: %s | fornecedor: %s | marca: %s tipo: %d  \n", produtos[i].id, produtos[i].nome, produtos[i].fornecedor, produtos[i].marca, produtos[i].tipo);
        }else if(exibicaoTotal == 1){
          printf("\n----------------------------------\n");
          printf(" id: %d \n nome: %s \n fornecedor: %s \n marca: %s \n tipo: %d \n", produtos[i].id, produtos[i].nome, produtos[i].fornecedor, produtos[i].marca, produtos[i].tipo);
          printf(" Preço de Compra: %0.2f\n", produtos[i].precoDeCompra);
          printf(" Preço de Venda: %0.2f\n", produtos[i].precoDeVenda);
          printf(" Quantidade em Estoque: %d\n", produtos[i].quantidadeEmEstoque);
          printf("\n----------------------------------\n");
        }else{
          printf("\nErro: ExibicaoTotal deve ser 1 ou 0, 1 para exibição Total\n");
        }
      }
   }else{
    printf("Nenhum produto cadastrado!\n");
   }

  }
