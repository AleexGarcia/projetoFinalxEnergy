#include "find_login.c"
void setUser(Usuario *user, int quantidadeUser, Usuario usuarios[100])
{
    char loginAux[25];
    do{
        printf("Informe o login:\n");
        scanf("%s", loginAux);
        fflush(stdin);
    } while(findLogin(usuarios,quantidadeUser,loginAux));
    strcpy(user->login, loginAux);
    printf("Informe a senha:\n");
    scanf("%s", user->senha);
    fflush(stdin);
    printf("Informe o tipo de acesso: \n 0 - funcionario \n 1 - administrador :\n");
    scanf("%d", &user->acesso);
    fflush(stdin);
    printf("Informe o nome:\n");
    scanf("%s", user->nome);
    fflush(stdin);
    printf("Informe o sobrenome:\n");
    scanf("%s", user->sobrenome);
    fflush(stdin);
    printf("Informe o endereco:\n");
    scanf("%s", user->endereco);
    fflush(stdin);
    printf("Informe a data de nascimento:\n");
    scanf("%s", user->dataDeNascimento);
    fflush(stdin);
    printf("Informe o telefone:\n");
    scanf("%s", user->telefone);
    fflush(stdin);
    printf("Informe o salario:\n");
    scanf("%f", &user->salario);
    fflush(stdin);
    user->id = quantidadeUser + 1;
}
