
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
    char dataDeNascimento[12];
    char telefone[12];
    float salario;
    char login[25];
    char senha[25];
    int acesso;
    char cpf[12];
    int id;

} Usuario;
typedef struct
{
    int id;
    char nome[25];
    char sobrenome[25];
    char endereco[100];
    char dataDeNascimento[11];
    char telefone[12];
    float renda;
    char cpf[12];
} Cliente;

typedef struct
{
    int quantidadeDePlacas;
    float precoPlacas;
    float custoPlacas;
    int quantidadeDeInversores;
    float precoInversor;
    float custoInversor;
    int quantidadeDeConectores;
    float precoConector;
    float custoConector;
    int quantidadeDeDisjuntores;
    float precoDisjuntor;
    float custoDisjuntor;
    int quantidadeDeCabeamento;
    float precoCabeamento;
    float custoCabeamento;
    int quantidadeDeEstrutura;
    float precoEstrutura;
    float custoEstrutura;
    float precoTotal;
    float custoTotal;
    float lucro;
    int id;

} Relatorio;


