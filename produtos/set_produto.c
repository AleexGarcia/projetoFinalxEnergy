void setProduto(Produto *produtos, int quantidadeProdutos)
{
  printf("Informe o tipo do produto:\n");
  printf("0 - Placa fotovoltaica, 1 - inversor, 2 - estrutura, 3 - cabeamento, 4 - conectores 5 - disjuntor\n");
  scanf("%d", &produtos->tipo);
  fflush(stdin);

  if(produtos->tipo < 2 && produtos->tipo > -1){
    printf("Informe a potencia se houver:\n");
    scanf("%d", &produtos->potencia);
    fflush(stdin);
  }else{
    produtos->potencia = 0;
  }

  printf("Informe o nome do produto:\n");
  scanf("%s", produtos->nome);
  fflush(stdin);

  printf("Informe o fornecedor:\n");
  scanf("%s", produtos->fornecedor);
  fflush(stdin);

  printf("Informe a marca do produto:\n");
  scanf("%s", produtos->marca);
  fflush(stdin);

  printf("Informe o preço de compra:\n");
  scanf("%f", &produtos->precoDeCompra);
  fflush(stdin);

  printf("Informe o preço de venda:\n");
  scanf("%f", &produtos->precoDeVenda);
  fflush(stdin);

  printf("Informe o quantidade comprada:\n");
  scanf("%d", &produtos->quantidadeEmEstoque);
  fflush(stdin);

  produtos->id = quantidadeProdutos + 1;
}
