void getLucro(Relatorio vendas[], int quantidadeDeVendas){
  float lucro;
  for(int i = 0; i < quantidadeDeVendas; i++){
    lucro += vendas[i].lucro;
  }
  printf("Projeção de receita: %.2f \n", lucro);
}
