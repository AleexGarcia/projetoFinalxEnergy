void setProduto(Produto *produtos, FILE *fp, int quantidadeProdutos)
{
  printf("Informe o nome do produto:\n");
  scanf("%s", produtos->nome);
  // gravando o dado obtido no arquivo
  fprintf(fp, "%s\n", produtos->nome);
  fflush(stdin);
  printf("Informe o fornecedor:\n");
  scanf("%s", produtos->fornecedor);
  fprintf(fp, "%s\n", produtos->fornecedor);
  fflush(stdin);
  printf("Informe a marca do produto:\n");
  scanf("%s", produtos->marca);
  fprintf(fp, "%s\n", produtos->marca);
  fflush(stdin);
  printf("Informe o preço de compra:\n");
  scanf("%f", &produtos->precoDeCompra);
  fprintf(fp, "%f\n", produtos->precoDeCompra);
  fflush(stdin);
  printf("Informe o preço de venda:\n");
  scanf("%f", &produtos->precoDeVenda);
  fprintf(fp, "%f\n", produtos->precoDeVenda);
  fflush(stdin);
  printf("Informe o quantidade comprada:\n");
  scanf("%d", &produtos->quantidadeEmEstoque);
  fprintf(fp, "%d\n", produtos->quantidadeEmEstoque);
  fflush(stdin);
  produtos->id = quantidadeProdutos;
}
