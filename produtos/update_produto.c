void updateProduto(Produto *produtos)
{
  int escolhaAttProduto;
  do
  {
    limpar_tela();
    printf("Informe o que deseja altera\n");
    printf("Nome: digite 1\n");
    printf("Fornecedor: digite 2\n");
    printf("Marca: digite 3\n");
    printf("Preço de compra: digite 4\n");
    printf("Preço de venda: digite 5\n");
    printf("Quantidade em estoque: digite 6\n");
    printf("Voltar: digite 7\n");
    scanf("%d", &escolhaAttProduto);
    switch (escolhaAttProduto)
    {
    case 1:
      printf("Nome atual: %s \n", produtos->nome);
      printf("Informe o nome: \n");
      fflush(stdin);
      fgets(produtos->nome,24,stdin);
      fflush(stdin);
      removaQuebraLinha(produtos->nome);
      printf("Nome atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 2:
      printf("Fornecedor atual: %s\n", produtos->fornecedor);
      printf("Informe o Fornecedor:\n");
      fflush(stdin);
      fgets(produtos->fornecedor,24,stdin);
      removaQuebraLinha(produtos->fornecedor);
      fflush(stdin);
      printf("Fornecedor atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 3:
      printf("Marca atual: %s\n", produtos->marca);
      printf("Informe a Marca:\n");
      fflush(stdin);
      fgets(produtos->marca,24,stdin);
      removaQuebraLinha(produtos->marca);
      fflush(stdin);
      printf("Marca atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 4:
      printf("Preço de compra atual: %.2f\n", produtos->precoDeCompra);
      printf("Informe o preço de Compra:\n");
      scanf("%f", &produtos->precoDeCompra);
      fflush(stdin);
      printf("Preco de compra atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 5:
      printf("Preço de venda atual: %.2f\n", produtos->precoDeVenda);
      printf("Informe o preço de venda:\n");
      scanf("%f", &produtos->precoDeVenda);
      fflush(stdin);
      printf("Preço de venda atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 6:
      printf("Quantidade atual: %d\n", produtos->quantidadeEmEstoque);
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
