void escreverArquivoCliente(Cliente clientes[], int quantidadeDeClientes)
{
	int i;
	//int len_vet = sizeof(clientes) - 1; // tamanho do vetor
	FILE * arq;
//	printf("%d",len_vet);
	// abre o arquivo para escrita,destruindo os dados e escrevendo dnovo atualizado
	arq = fopen("clientes.bin", "w+b");

	if(arq != NULL)
	{
		for(i = 0; i < quantidadeDeClientes; i++)
			// escreve cada elemento do vetor no arquivo
			fwrite(&clientes[i], sizeof(Cliente), 1, arq);
		fclose(arq); // aborta o programa
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
	}
}
