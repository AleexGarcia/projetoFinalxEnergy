
void getUser( Usuario usuarios[100], int quantidadeUsuarios){
    for (int i = 0; i < quantidadeUsuarios; i++)
    {
        printf("id: %d | nome: %s | sobrenome: %s | telefone: %s \n", usuarios[i].id, usuarios[i].nome, usuarios[i].sobrenome, usuarios[i].telefone);
    }
}
