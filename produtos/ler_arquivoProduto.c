int ler_arquivoProduto(Produto produtos[100])
{
	// abre o arquivo para leitura
	FILE * arq = fopen("/produtos/produtos.bin", "rb");

	if(arq != NULL)
	{
		int indice = 0;
		while(1)
		{
			Produto p;

			// fread ler os dados
			// retorna a quantidade de elementos lidos com sucesso
			size_t r = fread(&p, sizeof(Produto), 1, arq);

			// se retorno for menor que o count, então sai do loop
			if(r < 1)
				break;
			else
				produtos[indice++] = p;
		}
		fclose(arq); // fecha o arquivo
		return indice;
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}
