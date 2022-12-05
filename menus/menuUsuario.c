
    void exibeMenuUsuario(int acesso,int *menuUser)
    {
        int menu;
        limpar_tela();
        printf("MENU USUARIOS\n");
        printf("Digite 1 para Cadastrar novo cliente\n");
        printf("Digite 2 para Atualizar cadastro de cliente\n");
        printf("Digite 3 para Listar todos os clientes\n");
        if (acesso != 1)
        {
            printf("Digite 4 para Retornar ao MENU PRINCIPAL\n");
            scanf("%d", &menu);
            if (menu == 4)
            {
                menu = 8;
            }
            else if (menu > 4)
            {
                menu = 9;
            }
        }
        else
        {
            printf("Digite 4 para Cadastrar novo usuarios\n");
            printf("Digite 5 para Atualizar cadastro de usuarios\n");
            printf("Digite 6 para Deletar um usuario\n");
            printf("Digite 7 para listar todos os usuarios\n");
            printf("Digite 8 para Retornar ao MENU PRINCIPAL\n");
            scanf("%d", &menu);

        }
        *menuUser = menu;
    }
