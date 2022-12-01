
typedef struct
{
    int id;
    char nome[25];
    char fornecedor[25];
    char marca[25];
    int potencia;
    float precoDeCompra;
    float precoDeVenda;
    int quantidadeEmEstoque;
} Produto;

typedef struct
{
    char nome[25];
    char sobrenome[25];
    char endereco[100];
    char dataDeNascimento[10];
    char telefone[11];
    float salario;
    char login[20];
    char senha[20];
    int acesso;
    int id;

} Usuario;
typedef struct
{
    char nome[25];
    char sobrenome[25];
    char endereco[100];
    char dataDeNascimento[10];
    char telefone[11];
    float renda;
} Cliente;
