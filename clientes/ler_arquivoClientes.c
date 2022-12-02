int ler_arquivoCliente(Cliente clientes[100])
{
	// abre o arquivo para leitura
	FILE * arq = fopen("clientes.bin", "rb");

	if(arq != NULL)
	{
		int indice = 0;
		while(1)
		{
			Cliente p;

			// fread ler os dados
			// retorna a quantidade de elementos lidos com sucesso
			size_t r = fread(&p, sizeof(Cliente), 1, arq);
			printf("i");
			// se retorno for menor que o count, então sai do loop
			if(r < 1)
				break;
			else
				clientes[indice++] = p;
		}
		fclose(arq); // fecha o arquivo
		return indice;
	}
	else
	{
		printf("Erro ao abrir o arquivo clientes.bin para leitura!\n");
		printf("Ou é o primeiro acesso e o arquivo não foi criado!\n");
		return 0;
	}
}
