
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
      printf("Senha atual: %s\n", usuarios->senha);
      printf("Informe o senha:\n");
      scanf("%s", usuarios->senha);
      fflush(stdin);
      printf("Senha atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 2:
      printf("Acesso atual: %d\n", usuarios->acesso);
      printf("Informe o acesso:\n");
      scanf("%d", &usuarios->acesso);
      fflush(stdin);
      printf("Acesso atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 3:
      printf("Nome atual: %s\n", usuarios->nome);
      printf("Informe o nome:\n");
      fgets(usuarios->nome,24,stdin);
      removaQuebraLinha(usuarios->nome);
      fflush(stdin);
      printf("Nome atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 4:
      printf("Sobrenome atual: %s\n", usuarios->sobrenome);
      printf("Informe o Sobrenome:\n");
      fgets(usuarios->sobrenome,24,stdin);
      removaQuebraLinha(usuarios->sobrenome);
      fflush(stdin);
      printf("Sobrenome atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 5:
      printf("Endereço atual: %s\n", usuarios->endereco);
      printf("Informe o endereço:\n");
      fgets(usuarios->endereco,99,stdin);
      removaQuebraLinha(usuarios->endereco);
      fflush(stdin);
      printf("Endereço atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 6:
      printf("Data de nascimento atual: %s\n", usuarios->dataDeNascimento);
      printf("Informe a data de nascimento:\n");
      scanf("%s", usuarios->dataDeNascimento);
      fflush(stdin);
      printf("Data de nascimento atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 7:
      printf("Telefone atual: %s\n", usuarios->telefone);
      printf("Informe o telefone:\n");
      scanf("%s", usuarios->telefone);
      fflush(stdin);
      printf("Telefone atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 8:
      printf("Salario atual: %f\n", usuarios->salario);
      printf("Informe a salario do usuario:\n");
      scanf("%f", &usuarios->salario);
      fflush(stdin);
      printf("Renda atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 9:
      printf("CPF atual: %s\n", usuarios->cpf);
      printf("Informe o CPF do usuario:\n");
      scanf("%s", usuarios->cpf);
      fflush(stdin);
      printf("CPF atualizado com sucesso!\n");
      Sleep(1000);
      break;
    case 10:
      printf("Retornando ao menu de usuario!\n");
      Sleep(1000);
      break;
    default:
      printf("\n --- Entre com um valor válido! ---\n");
      Sleep(1000);
      break;
    }
  } while (escolhaAttUsuario != 10);
}
