
void getUser( Usuario usuarios[100], int quantidadeUsuarios, int exibicaoTotal){
    if(quantidadeUsuarios > 0){
      for (int i = 0; i < quantidadeUsuarios; i++)
      {
        if(exibicaoTotal == 0){
          printf("id: %d \n nome: %s \n sobrenome: %s cpf: %d \n",
            usuarios[i].id, usuarios[i].nome, usuarios[i].sobrenome, usuarios[i].cpf);
          printf("------------------------------------------------\n");
        }else if(exibicaoTotal == 1){
          printf("\n------------------------------------------------------------------\n");
          printf("id: %d \n nome: %s \n sobrenome: %s cpf: %d \n telefone: %s \n salario: %f \n endereço: %s \n data de nascimento: %s \n login: %s \n acesso %d  \n",
            usuarios[i].id, usuarios[i].nome, usuarios[i].sobrenome,usuarios[i].cpf, usuarios[i].telefone,
            usuarios[i].salario,usuarios[i].endereco,usuarios[i].dataDeNascimento,
            usuarios[i].login, usuarios[i].acesso);
          printf("\n------------------------------------------------------------------\n");
        }else{
          printf("Erro: ExibicaoTotal deve ser 1 ou 0, 1 para exibição Total\n");
        }

      }
    }
}


