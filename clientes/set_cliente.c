void setCliente(Cliente *clientes, int quantidadeClientes, Cliente clientesArray[])
{
  printf("Informe o nome:\n");
  fflush(stdin);
  fgets(clientes->nome,24,stdin);
  removaQuebraLinha(clientes->nome);
  fflush(stdin);
  printf("Informe o sobrenome:\n");
  fgets(clientes->sobrenome,24,stdin);
  removaQuebraLinha(clientes->sobrenome);
  fflush(stdin);
  printf("Informe o cpf:\n");
  scanf("%s", clientes->cpf);
  fflush(stdin);
  printf("Informe o endereco:\n");
  fgets(clientes->endereco,99,stdin);
  removaQuebraLinha(clientes->endereco);
  fflush(stdin);
  printf("Informe o telefone:\n");
  scanf("%s", clientes->telefone);
  fflush(stdin);
  printf("Informe o telefone:\n");
  scanf("%s", clientes->dataDeNascimento);
  printf("Informe o renda:\n");
  scanf("%f", &clientes->renda);
  if(quantidadeClientes == 0){
    clientes->id = quantidadeClientes + 1;
    }else{
    clientes->id = clientesArray[quantidadeClientes - 1].id + 1;
  }
}
