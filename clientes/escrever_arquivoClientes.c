void escreverArquivoCliente(Cliente clientes[])
{
	int i;
	int len_vet = sizeof(clientes) - 1; // tamanho do vetor
	FILE * arq;

	// abre o arquivo para escrita,destruindo os dados e escrevendo dnovo atualizado
	arq = fopen("clientes.bin", "w+b");

	if(arq != NULL)
	{
		for(i = 0; i < len_vet; i++)
			// escreve cada elemento do vetor no arquivo
			fwrite(&clientes[i], sizeof(Cliente), 1, arq);
		fclose(arq); // aborta o programa
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
	}
}
