void escreverArquivoUsuario(Usuario usuarios[], int quantidadeDeUsuarios)
{
	int i;
	int len_vet = sizeof(usuarios) - 1; // tamanho do vetor
	FILE * arq;

	// abre o arquivo para escrita,destruindo os dados e escrevendo dnovo atualizado
	arq = fopen("usuarios.bin", "w+b");

	if(arq != NULL)
	{
		for(i = 0; i < quantidadeDeUsuarios; i++)
			// escreve cada elemento do vetor no arquivo
			fwrite(&usuarios[i], sizeof(Usuario), 1, arq);
		fclose(arq); // aborta o programa
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}
