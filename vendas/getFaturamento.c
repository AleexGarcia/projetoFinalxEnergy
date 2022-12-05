void getFaturamento(Relatorio vendas[], int quantidadeDeVendas){
  float faturamento;
  for(int i = 0; i < quantidadeDeVendas; i++){
    faturamento += vendas[i].custoTotal;
  }
  printf("Faturamento: %.2f \n",faturamento);
}
