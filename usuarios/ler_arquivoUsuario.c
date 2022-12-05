int ler_arquivoUsuario(Usuario usuarios[100])
{
	// abre o arquivo para leitura
	FILE * arq = fopen("usuarios.bin", "rb");

	if(arq != NULL)
	{
		int indice = 0;
		while(1)
		{
			Usuario p;

			// fread ler os dados
			// retorna a quantidade de elementos lidos com sucesso
			size_t r = fread(&p, sizeof(Usuario), 1, arq);

			// se retorno for menor que o count, então sai do loop
			if(r < 1)
				break;
			else
				usuarios[indice++] = p;
		}
		fclose(arq); // fecha o arquivo
		return indice;
	}
	else
	{
		printf("\nErro ao abrir o arquivo usuarios.bin para leitura!\n");
		printf("Ou é o primeiro acesso e o arquivo não foi criado!\n");

		strcpy(usuarios[0].login, "admin");
    strcpy(usuarios[0].senha, "12345");
    strcpy(usuarios[0].nome, "admin");
    strcpy(usuarios[0].sobrenome, "admin");
    strcpy(usuarios[0].telefone, "99999999999");
    strcpy(usuarios[0].cpf, "99999999999");
    usuarios[0].id = 1;
    usuarios[0].acesso = 1;


    strcpy(usuarios[1].login, "funcionario");
    strcpy(usuarios[1].senha, "12345");
    strcpy(usuarios[1].telefone, "99999999999");
    strcpy(usuarios[1].nome, "funcionario");
    strcpy(usuarios[1].sobrenome, "funcionario");
    strcpy(usuarios[1].cpf, "99999999999");
    usuarios[1].acesso = 0;
    usuarios[1].id = 2;

    return 2;
	}
}
