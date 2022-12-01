void setCliente(Cliente *clientes, int quantidadeClientes)
{
  printf("Informe o nome:\n");
  scanf("%s", clientes->nome);
  fflush(stdin);
  printf("Informe o sobrenome:\n");
  scanf("%s", clientes->sobrenome);
  fflush(stdin);
  printf("Informe o endereco:\n");
  scanf("%s", clientes->endereco);
  fflush(stdin);
  printf("Informe o telefone:\n");
  scanf("%s", clientes->telefone);
  fflush(stdin);
  printf("Informe o renda:\n");
  scanf("%f", &clientes->renda);
  clientes->id = quantidadeClientes;
}
