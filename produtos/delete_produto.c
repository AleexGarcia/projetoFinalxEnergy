void deleteProduto(int index, Produto produtos[], int *quantidadeDeProdutos){
  int vetorLenght = *quantidadeDeProdutos;
  for(int i = index; i < vetorLenght ;i++){
    if(i != vetorLenght - 1){
      produtos[i] = produtos[i+1];
    }
  }
  *quantidadeDeProdutos-=1;
}
