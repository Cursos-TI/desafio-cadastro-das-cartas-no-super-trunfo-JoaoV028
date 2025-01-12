#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {

    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    

    //Criação das Variáveis 
    char codigo[4]; //Código da Cidade
    char nome[26];  //Nome da Cidade
    int populacao;  //População da Cidade
    double area;    //Area da Cidade
    double pib;     //PIB da Cidade
    int ponto_t;    //pontos turísticos 

    
    //Entrada do Usuário

    printf ("Digite o codigo da cidade (A01,C03...): ");
    scanf ("%3s", codigo);  //Código

    printf ("\nDigite o nome da cidade (até 25 caracteres): ");
    scanf  ("%25s", nome);  //Nome

    printf ("Digite a populaçao de %s (Habitantes): ", nome);
    scanf ("%d", &populacao);   //População

    printf ("\nDigite a área de %s(em km², exemplo: 1250.00): ", nome);
    scanf ("%lf", &area);   //Área 

    printf ("Digite o PIB de %s: (em bilhões, exemplo: 350.93)", nome);
    scanf ("%lf",&pib); //PIB

    printf ("Número de pontos turísticos em %s: ", nome);
    scanf ("%d", &ponto_t); //Pontos turísticos 


        //Saida de Dados
        printf ("\n========================");
        printf ("\nDADOS DA CIDADE\n");
        printf ("========================\n");
        printf ("\nCódigo da cidade: %s.", codigo);
        printf ("\nNome da cidade: %s", nome);
        printf ("\nPopulação de %s: %d", nome, populacao);
        printf ("\nÁrea aproximada de %s: %.2lfkm²", nome, area);
        printf ("\nPIB de %s: %.2f", nome, pib);
        printf ("\nPontos turísticos em %s: %d\n", nome , ponto_t);
    

    return 0;
}
