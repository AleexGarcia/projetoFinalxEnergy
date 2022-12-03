
void getUser( Usuario usuarios[100], int quantidadeUsuarios){
    for (int i = 0; i < quantidadeUsuarios; i++)
    {
        printf("id: %d | nome: %s | sobrenome: %s | telefone: %s | salario: %f | \n endereço: %s | data de nascimento: %s | login: %s | acesso %d  \n",
          usuarios[i].id, usuarios[i].nome, usuarios[i].sobrenome, usuarios[i].telefone,
          usuarios[i].salario,usuarios[i].endereco,usuarios[i].dataDeNascimento,
          usuarios[i].login, usuarios[i].acesso);
        printf("\n------------------------------------------------------------------\n");
    }
}

