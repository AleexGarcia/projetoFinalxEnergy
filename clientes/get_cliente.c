void getCliente(Cliente clientes[100] , int quantidadeDeClientes, int exibicaoTotal){
   if(quantidadeDeClientes > 0){

     for (int i = 0; i < quantidadeDeClientes; i++)
      {
          if(exibicaoTotal == 0){
            printf("id: %d | nome: %s | sobrenome: %s | telefone: %s \n", clientes[i].id, clientes[i].nome, clientes[i].sobrenome, clientes[i].telefone);
          }else if(exibicaoTotal == 1){
            printf("\n-----------------------------\n");
            printf("id: %d \n Nome: %s \n Sobrenome: %s \n Telefone: %s \n", clientes[i].id, clientes[i].nome, clientes[i].sobrenome, clientes[i].telefone);
            printf("Cpf %d \n Data de Nascimento: %s \n Endereço: %s \n Renda: %.2f ", clientes[i].cpf, clientes[i].dataDeNascimento, clientes[i].endereco, clientes[i].renda);
            printf("\n-----------------------------\n");
          }else{
          printf("Erro: ExibicaoTotal deve ser 1 ou 0, 1 para exibição Total\n");
        }
      }

   }

}

