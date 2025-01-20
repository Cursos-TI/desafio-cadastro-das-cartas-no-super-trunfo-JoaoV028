#include <stdio.h>
#include <string.h> // Para usar strcspn


// Estrutura para armazenar dados de uma cidade
typedef struct{

    //Criação das Variáveis
    char codigo[4];                 //Código da Cidade
    char nome[30];                  //Nome da Cidade
    int populacao;                  //População da Cidade
    double area;                    //Area da Cidade
    double pib;                     //PIB da Cidade
    int ponto_t;                    //pontos turísticos 
    double densidade_Populacional;  // Densidade Populacional
    double pib_per_capita;          // PIB per capita
} Cidade;


// Função para ler os dados de uma cidade
void ler_dados_cidade(Cidade *cidade) {
    
    // Entrada do Código
    printf ("Digite o codigo da cidade (A01,C03...): ");
    scanf ("%3s", cidade->codigo);  

    //Limpar buffer antes de fgets
    while (getchar() != '\n');

    // Entrada do Nome da Cidade
    printf ("\nDigite o nome da cidade (até 25 caracteres): ");
    fgets  (cidade->nome, sizeof(cidade->nome), stdin);  
    
    //Remover o '\n' do fgets
    cidade->nome[strcspn(cidade->nome, "\n")] = 0;

    // Entrada da População
    printf ("\nDigite a populaçao de %s (Habitantes): ", cidade->nome);
    scanf ("%d", &cidade->populacao);   

    // Entrada da Área
    printf ("\nDigite a área de %s (em km², exemplo: 1250.00): ", cidade->nome);
    scanf ("%lf", &cidade->area);   

    // Entrada do PIB
    printf ("\nDigite o PIB de %s (em bilhões, exemplo: 350.93): ", cidade->nome);
    scanf (" %lf", &cidade->pib);

    // Entrada do Número de Pontos Turísticos 
    printf ("\nNúmero de pontos turísticos em %s: ", cidade->nome);
    scanf (" %d", &cidade->ponto_t);

    // Cálculo da densidade populacional
    if (cidade->area > 0) {
        cidade->densidade_Populacional = cidade->populacao / cidade->area;
    } else {
        printf("Erro: Área não pode ser zero ou negativa.\n");
    }

    // Cálculo do PIB per capita
    if (cidade->populacao > 0) {
        cidade->pib_per_capita = cidade->pib / cidade->populacao;
    } else { printf ("Erro: População não pode ser zero ou negativa.\n");

        }
    
    }
    
    // Função para comparar duas cidades
    void comparar_cidades(Cidade cidade1, Cidade cidade2) {

    // Comparação de População
    printf ("Comparando cidades: \n");
        if (cidade1.populacao > cidade2.populacao) {
            printf ("%s tem mais habitantes que %s.\n", cidade1.nome, cidade2.nome);
        } else if (cidade1.populacao < cidade2.populacao) {
            printf ("%s tem mais habitantes que %s.\n", cidade2.nome, cidade1.nome);
        } else {
            printf ("%s e %s tem a mesma população.\n", cidade1.nome, cidade2.nome);
        }
    
    // Comparação de Área
        printf ("Área: \n");
        if (cidade1.area > cidade2.area) {
            printf ("%s tem mais área que %s.\n", cidade1.nome, cidade2.nome);
        } else if (cidade1.area < cidade2.area) {
            printf ("%s tem mais área que %s.\n", cidade2.nome, cidade1.nome);
        } else {
            printf ("%s e %s tem a mesma área.\n", cidade1.nome, cidade2.nome);
        }

    // Comparação de PIB per capita
        printf("\nPIB per capita:\n");
        if (cidade1.pib_per_capita > cidade2.pib_per_capita) {
            printf("%s tem maior PIB per capita (%.2f) que %s (%.2f).\n", cidade1.nome, cidade1.pib_per_capita, cidade2.nome, cidade2.pib_per_capita);
        } else if (cidade1.pib_per_capita < cidade2.pib_per_capita) {
            printf("%s tem maior PIB per capita (%.2f) que %s (%.2f).\n", cidade2.nome, cidade2.pib_per_capita, cidade1.nome, cidade1.pib_per_capita);
        } else {
            printf("%s e %s têm o mesmo PIB per capita (%.2f).\n", cidade1.nome, cidade2.nome, cidade1.pib_per_capita);
        }
    
    }

int main() {

    Cidade cidade1, cidade2;

    printf ("Dados da primeira cidade: \n");
    ler_dados_cidade(&cidade1);

    printf ("\nDados da segunda cidade: \n");
    ler_dados_cidade(&cidade2);

    comparar_cidades(cidade1, cidade2);


    return 0;
}
