void updateProduto(Produto *produtos)
{
  int escolhaAttProduto;
  do
  {
    limpar_tela();
    printf("Informe o que deseja altera");
    printf("Nome: digite 1");
    printf("Fornecedor: digite 2");
    printf("Marca: digite 3");
    printf("Preço de compra: digite 4");
    printf("Preço de venda: digite 5");
    printf("Quantidade em estoque: digite 6");
    printf("Voltar: digite 7");
    scanf("%d", &escolhaAttProduto);
    switch (escolhaAttProduto)
    {
    case 1:
      printf("Informe o nome:\n");
      scanf("%s", produtos->nome);
      fflush(stdin);
      printf("Nome atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 2:
      printf("Informe o Fornecedor:\n");
      scanf("%s", produtos->fornecedor);
      fflush(stdin);
      printf("Fornecedor atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 3:
      printf("Informe a Marca:\n");
      scanf("%s", produtos->marca);
      fflush(stdin);
      printf("Marca atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 4:
      printf("Informe o preço de Compra:\n");
      scanf("%f", &produtos->precoDeCompra);
      fflush(stdin);
      printf("Preco de compra atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 5:
      printf("Informe o preço de venda:\n");
      scanf("%f", &produtos->precoDeVenda);
      fflush(stdin);
      printf("Preço de venda atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 6:
      printf("Informe a quantidade em estoque:\n");
      scanf("%d", &produtos->quantidadeEmEstoque);
      fflush(stdin);
      printf("Quantidade em estoque atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 7:
      printf("Retornando ao menu de produto!\n");
      Sleep(1000);
      break;
    default:
      printf("\n --- Entre com um valor válido! ---\n");
      Sleep(1000);
      break;
    }
  } while (escolhaAttProduto != 7);
}
