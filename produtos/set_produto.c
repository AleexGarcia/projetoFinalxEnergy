void setProduto(Produto *produtos, int quantidadeProdutos)
{
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
  produtos->id = quantidadeProdutos;
}
