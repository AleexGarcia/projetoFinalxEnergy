
typedef struct
{
    int id;
    char nome[25];
    char fornecedor[25];
    char marca[25];
    int tipo;
    //0 - placaFotoVoltaica  1- inversor, 2- estrutura, 3- cabeamento, 4- conectores 5-disjuntor;
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
    int id;
    char nome[25];
    char sobrenome[25];
    char endereco[100];
    char dataDeNascimento[10];
    char telefone[11];
    float renda;
} Cliente;

typedef struct
{
    int quantidadeDePlacas;
    float precoPlacas;
    int quantidadeDeInversores;
    float precoInversor;
    int quantidadeDeConectores;
    float precoConector;
    int quantidadeDeDisjuntores;
    float precoDisjuntor;
    int quantidadeDeCabeamento;
    float precoCabeamento;
    int quantidadeDeEstrutura;
    float precoEstrutura;
    float precoTotal;
    int id;

} Relatorio;


