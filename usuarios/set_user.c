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
    fflush(stdin);
    fgets(user->nome,24,stdin);
    removaQuebraLinha(user->nome);
    fflush(stdin);
    printf("Informe o sobrenome:\n");
    fgets(user->sobrenome,24,stdin);
    removaQuebraLinha(user->sobrenome);
    fflush(stdin);
    printf("Informe o cpf:\n");
    scanf("%s", user->cpf);
    fflush(stdin);
    printf("Informe o endereco:\n");
    fgets(user->endereco,99,stdin);
    removaQuebraLinha(user->endereco);
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
    if(quantidadeUser == 0){
         user->id = quantidadeUser + 1;
        }else{
        user->id = usuarios[quantidadeUser - 1].id + 1;
    }

}
