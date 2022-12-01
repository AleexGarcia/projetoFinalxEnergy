int findCliente(Cliente clientes[100], int quantidadeDeClientes, int id){
  for(int i = 0; i < quantidadeDeClientes; i++){
    if(clientes[i].id == id){
      return i;
    }
  }
  return -1;
}
