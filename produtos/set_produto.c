#include "find_produtoTipo.c"
int setProduto(Produto *produtos, int quantidadeProdutos, Produto produtosArray[])
{
    printf("Informe o tipo do produto:\n");
    printf("0 - Placa fotovoltaica, 1 - inversor, 2 - estrutura, 3 - cabeamento, 4 - conectores 5 - disjuntor\n");
    int tipo;
    scanf("%d",&tipo);
    fflush(stdin);
    if(findProdutoTipo(produtosArray,quantidadeProdutos,tipo)){

      produtos->tipo = tipo;

      if(produtos->tipo < 2 && produtos->tipo > -1){
        printf("Informe a potencia:\n");
        scanf("%d", &produtos->potencia);
        fflush(stdin);
      }else{
        produtos->potencia = 0;
      }

      printf("Informe o nome do produto:\n");
      fgets(produtos->nome, 24, stdin);
      fflush(stdin);

      printf("Informe o fornecedor:\n");
      fgets(produtos->fornecedor,24,stdin);
      fflush(stdin);

      printf("Informe a marca do produto:\n");
      fgets(produtos->marca,24,stdin);
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
      return 1;
    }else{
      printf("Produto ja cadastrado! Prossiga para area de atualização!\n");
      Sleep(2000);
      return 0;
    }

}
