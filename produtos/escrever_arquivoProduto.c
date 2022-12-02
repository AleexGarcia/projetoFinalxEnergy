void escreverArquivoProduto(Produto produtos[], int quantidadeDeProdutos)
{
	int i;
	//int len_vet = sizeof(produtos) - 1; // tamanho do vetor
	FILE * arq;

	// abre o arquivo para escrita,destruindo os dados e escrevendo dnovo atualizado
	arq = fopen("produtos.bin", "w+b");

	if(arq != NULL)
	{
		for(i = 0; i < quantidadeDeProdutos; i++)
			// escreve cada elemento do vetor no arquivo
			fwrite(&produtos[i], sizeof(Produto), 1, arq);
		fclose(arq); // aborta o programa
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
	}
}
