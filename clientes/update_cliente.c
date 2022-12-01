void updateCliente(Cliente *clientes)
{
  int escolhaAttCliente;
  do
  {
    limpar_tela();
    printf("Informe o que deseja altera");
    printf("Nome: digite 1");
    printf("Sobrenome: digite 2");
    printf("Endereço: digite 3");
    printf("Data de Nascimento: digite 4");
    printf("Telefone: digite 5");
    printf("Renda: digite 6");
    printf("Voltar: digite 7");
    scanf("%d", &escolhaAttCliente);
    switch (escolhaAttCliente)
    {
    case 1:
      printf("Informe o nome:\n");
      scanf("%s", clientes->nome);
      fflush(stdin);
      printf("Nome atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 2:
      printf("Informe o Sobrenome:\n");
      scanf("%s", clientes->sobrenome);
      fflush(stdin);
      printf("Sobrenome atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 3:
      printf("Informe o endereÃ§o:\n");
      scanf("%s", clientes->endereco);
      fflush(stdin);
      printf("Endereço atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 4:
      printf("Informe a data de nascimento:\n");
      scanf("%s", clientes->dataDeNascimento);
      fflush(stdin);
      printf("Data de nascimento atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 5:
      printf("Informe o telefone:\n");
      scanf("%s", clientes->telefone);
      fflush(stdin);
      printf("Telefone atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 6:
      printf("Informe a renda do cliente:\n");
      scanf("%f", &clientes->renda);
      fflush(stdin);
      printf("Renda atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 7:
      printf("Retornando ao menu de usuario!\n");
      Sleep(1000);
      break;
    default:
      printf("\n --- Entre com um valor válido! ---\n");
      Sleep(1000);
      break;
    }

  } while (escolhaAttCliente != 7);
}
