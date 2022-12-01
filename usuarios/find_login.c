int findLogin(Usuario usuarios[100], int quantidadeDeUsuarios, char *login){
  for(int i = 0; i < quantidadeDeUsuarios; i++){
    if(usuarios[i].login == login){
      printf("Este login ja existe!\n");
      printf("Informe um login válido!\n");
      return 1;
    }
  }
  return 0;
}
