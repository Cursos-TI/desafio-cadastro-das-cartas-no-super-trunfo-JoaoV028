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
    char nome[30];  //Nome da Cidade
    int populacao;  //População da Cidade
    double area;    //Area da Cidade
    double pib;     //PIB da Cidade
    int ponto_t;    //pontos turísticos 

    //Novas Variáveis
    double densidade_Populacional = 0;
    double pib_per_capita =  0;
    
    //Entrada do Usuário

    //Código
    printf ("Digite o codigo da cidade (A01,C03...): ");
    scanf ("%3s", codigo);  

    //Limpar buffer antes de fgets
    while (getchar() != '\n');

    //Nome Da Cidade
    printf ("\nDigite o nome da cidade (até 25 caracteres): ");
    fgets  (nome, sizeof(nome), stdin);  
    
    //População
    printf ("Digite a populaçao de %s (Habitantes): ", nome);
    scanf ("%d", &populacao);   

    //Área
    printf ("\nDigite a área de %s(em km², exemplo: 1250.00): ", nome);
    scanf ("%lf", &area);   

    //PIB
    printf ("Digite o PIB de %s: (em bilhões, exemplo: 350.93)", nome);
    scanf ("%lf",&pib);

    //Pontos turísticos 
    printf ("Número de pontos turísticos em %s: ", nome);
    scanf ("%d", &ponto_t); 
    //Verificação e Cálculo das Propriedades
    if (area > 0) {
        densidade_Populacional = populacao / area;
    } else {
        printf("Erro: Área não pode ser zero ou negativa.\n");
    }

    if (populacao > 0) {
        pib_per_capita = pib / populacao;
    } else { printf ("Erro: População não pode ser zero ou negativa.\n");
    }


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
        printf ("\nDensidade populacional: %.2lf habitantes/km²\n", densidade_Populacional);
        printf ("\nPIB per Capita: %.2lf bilhões/habitantes\n", pib_per_capita);
    

    return 0;
}
