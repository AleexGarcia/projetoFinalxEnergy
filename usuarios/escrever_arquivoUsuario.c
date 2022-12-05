void escreverArquivoUsuario(Usuario usuarios[100], int quantidadeDeUsuarios)
{
	int i;
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

	}
}
