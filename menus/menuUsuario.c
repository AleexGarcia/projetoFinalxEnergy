
    void exibeMenuUsuario(int acesso,int *menuUser)
    {
        int menu;
        limpar_tela();
        printf("MENU USUARIOS\n");
        printf("Digite 1 para Cadastrar novo cliente\n");
        printf("Digite 2 para Atualizar cadastro de cliente\n");
        if (acesso != 1)
        {
            printf("Digite 3 para Retornar ao MENU PRINCIPAL\n");
            scanf("%d", &menu);
            if (menu == 3)
            {
                *menuUser = 5;
            }
            else if (menu == 4)
            {
                *menuUser = 6;
            }
        }
        else
        {
            printf("Digite 3 para Cadastrar novo usuarios\n");
            printf("Digite 4 para Atualizar cadastro de usuarios\n");
            printf("Digite 5 para Retornar ao MENU PRINCIPAL\n");
            scanf("%d", &menu);
        }
        *menuUser = menu;
    }
