void escreverArquivoVenda(Relatorio vendas[], int quantidadeDeVendas)
{
	int i;
	//int len_vet = sizeof(vendas) - 1; // tamanho do vetor
	FILE * arq;

	// abre o arquivo para escrita,destruindo os dados e escrevendo dnovo atualizado
	arq = fopen("vendas.bin", "w+b");

	if(arq != NULL)
	{
		for(i = 0; i < quantidadeDeVendas; i++)
			// escreve cada elemento do vetor no arquivo
			fwrite(&vendas[i], sizeof(Relatorio), 1, arq);
		fclose(arq); // aborta o programa
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}
