void deleteUsuario(int index, Usuario usuarios[], int *quantidadeDeUser){
  int vetorLenght = *quantidadeDeUser;
  for(int i = index; i < vetorLenght ;i++){
    if(i != vetorLenght - 1){
      usuarios[i] = usuarios[i+1];
    }
  }
  *quantidadeDeUser-=1;
}
