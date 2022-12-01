
void updateUser(Usuario *usuarios)
{
  int escolhaAttUsuario;
  do
  {
    exibeMenuAtualizacaoUsuario(usuarios->nome);
    scanf("%d", &escolhaAttUsuario);
    switch (escolhaAttUsuario)
    {
    case 1:
      printf("Informe o senha:\n");
      scanf("%s", usuarios->senha);
      fflush(stdin);
      printf("Senha atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 2:
      printf("Informe o acesso:\n");
      scanf("%d", &usuarios->acesso);
      fflush(stdin);
      printf("Acesso atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 3:
      printf("Informe o nome:\n");
      scanf("%s", usuarios->nome);
      fflush(stdin);
      printf("Nome atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 4:
      printf("Informe o Sobrenome:\n");
      scanf("%s", usuarios->sobrenome);
      fflush(stdin);
      printf("Sobrenome atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 5:
      printf("Informe o endereço:\n");
      scanf("%s", usuarios->endereco);
      fflush(stdin);
      printf("Endereço atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 6:
      printf("Informe a data de nascimento:\n");
      scanf("%s", usuarios->dataDeNascimento);
      fflush(stdin);
      printf("Data de nascimento atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 7:
      printf("Informe o telefone:\n");
      scanf("%s", usuarios->telefone);
      fflush(stdin);
      printf("Telefone atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 8:
      printf("Informe a renda do cliente:\n");
      scanf("%f", &usuarios->salario);
      fflush(stdin);
      printf("Renda atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 9:
      printf("Retornando ao menu de usuario!\n");
      Sleep(1000);
      break;
    default:
      printf("\n --- Entre com um valor válido! ---\n");
      Sleep(1000);
      break;
    }
  } while (escolhaAttUsuario != 9);
}
