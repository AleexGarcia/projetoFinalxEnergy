void getCliente(Cliente clientes[100] , int quantidadeDeClientes){
   for (int i = 0; i < quantidadeDeClientes; i++)
    {
        printf("id: %d | nome: %s | sobrenome: %s | telefone: %s \n", clientes[i].id, clientes[i].nome, clientes[i].sobrenome, clientes[i].telefone);
    }


}
