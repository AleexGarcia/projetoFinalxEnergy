void exibeMenuVenda(int acesso, int *menuVendas)
{
  int menu;
  limpar_tela();
  printf("MENU VENDAS/ORÇAMENTOS\n");
  printf("Digite 1 para fazer um orçamento!\n");
  if (acesso != 1)
  {
    printf("Digite 2 para Retornar ao MENU PRINCIPAL\n");
    scanf("%d", &menu);
    if (menu == 2)
    {
      menu = 3;
    }
    else if (menu == 3)
    {
      menu = 4;
    }
  }
  else
  {
    printf("Digite 2 para Emitir um relatorio de vendas\n");
    printf("Digite 3 para Retornar ao MENU PRINCIPAL\n");
    scanf("%d", &menu);
  }
  *menuVendas = menu;
}
