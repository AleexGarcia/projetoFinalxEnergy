void updateCliente(Cliente *clientes)
{
  int escolhaAttCliente;
  do
  {
    limpar_tela();
    printf("Informe o que deseja altera\n");
    printf("Nome: digite 1\n");
    printf("Sobrenome: digite 2\n");
    printf("Endereço: digite 3\n");
    printf("Data de Nascimento: digite 4\n");
    printf("Telefone: digite 5\n");
    printf("Renda: digite 6\n");
    printf("cpf: digite 7\n");
    printf("Voltar: digite 8\n");
    scanf("%d", &escolhaAttCliente);
    switch (escolhaAttCliente)
    {
    case 1:
      printf("Nome atual: %s\n", clientes->nome);
      printf("Informe o nome:\n");
      fflush(stdin);
      fgets(clientes->nome,24,stdin);
      removaQuebraLinha(clientes->nome);
      fflush(stdin);
      printf("Nome atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 2:
      printf("Sobrenome atual: %s\n", clientes->sobrenome);
      printf("Informe o Sobrenome:\n");
      fflush(stdin);
      fgets(clientes->sobrenome,24,stdin);
      removaQuebraLinha(clientes->sobrenome);
      fflush(stdin);
      printf("Sobrenome atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 3:
      printf("Endereço atual: %s\n", clientes->endereco);
      printf("Informe o endereço:\n");
      fflush(stdin);
      fgets(clientes->endereco,99,stdin);
      fflush(stdin);
      printf("Endereço atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 4:
      printf("Data de nascimento atual %s\n", clientes->dataDeNascimento);
      printf("Informe a data de nascimento:\n");
      scanf("%s", clientes->dataDeNascimento);
      fflush(stdin);
      printf("Data de nascimento atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 5:
      printf("Telefone Atual: %s\n", clientes->telefone);
      printf("Informe o telefone:\n");
      scanf("%s", clientes->telefone);
      fflush(stdin);
      printf("Telefone atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 6:
      printf("Renda Atual: %f\n", clientes->renda);
      printf("Informe a renda do cliente:\n");
      scanf("%f", &clientes->renda);
      fflush(stdin);
      printf("Renda atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 7:
      printf("CPF Atual: %s\n", clientes->cpf);
      printf("Informe o cpf do cliente:\n");
      scanf("%s", clientes->cpf);
      fflush(stdin);
      printf("Cpf atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 8:
      printf("Retornando ao menu de usuario!\n");
      Sleep(1000);
      break;
    default:
      printf("\n --- Entre com um valor válido! ---\n");
      Sleep(1000);
      break;
    }

  } while (escolhaAttCliente != 8);
}
