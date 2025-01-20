#include <stdio.h>
#include <string.h> // Para usar strcspn

// Estrutura para armazenar dados de uma cidade
typedef struct {
    char codigo[4];                 // Código da Cidade
    char nome[30];                  // Nome da Cidade
    int populacao;                  // População da Cidade
    double area;                    // Área da Cidade
    double pib;                     // PIB da Cidade
    int ponto_t;                    // Pontos turísticos
    double densidade_Populacional;  // Densidade Populacional
    double pib_per_capita;          // PIB per capita
    double super_poder;             // Super Poder
} Cidade;

// Função para calcular o "Super Poder" de uma cidade
void calcular_super_poder(Cidade *cidade) {
    cidade->super_poder = cidade->populacao + cidade->area + cidade->pib + cidade->ponto_t
                          - cidade->densidade_Populacional + cidade->pib_per_capita;
}

// Função para ler os dados de uma cidade
void ler_dados_cidade(Cidade *cidade) {
    // Entrada do Código
    printf("Digite o código da cidade (A01, C03...): ");
    scanf("%3s", cidade->codigo);

    // Limpar buffer antes de fgets
    while (getchar() != '\n');

    // Entrada do Nome da Cidade
    printf("Digite o nome da cidade (até 25 caracteres): ");
    fgets(cidade->nome, sizeof(cidade->nome), stdin);
    cidade->nome[strcspn(cidade->nome, "\n")] = 0;

    // Entrada da População
    printf("Digite a população de %s (habitantes): ", cidade->nome);
    scanf("%d", &cidade->populacao);

    // Entrada da Área
    printf("Digite a área de %s (em km², exemplo: 1250.00): ", cidade->nome);
    scanf("%lf", &cidade->area);

    // Entrada do PIB
    printf("Digite o PIB de %s (em bilhões, exemplo: 350.93): ", cidade->nome);
    scanf("%lf", &cidade->pib);

    // Entrada do Número de Pontos Turísticos
    printf("Número de pontos turísticos em %s: ", cidade->nome);
    scanf("%d", &cidade->ponto_t);

    // Cálculo da densidade populacional
    if (cidade->area > 0) {
        cidade->densidade_Populacional = cidade->populacao / cidade->area;
    } else {
        cidade->densidade_Populacional = 0;
        printf("Aviso: Área inválida, densidade populacional definida como 0.\n");
    }

    // Cálculo do PIB per capita
    if (cidade->populacao > 0) {
        cidade->pib_per_capita = cidade->pib / cidade->populacao;
    } else {
        cidade->pib_per_capita = 0;
        printf("Aviso: População inválida, PIB per capita definido como 0.\n");
    }

    // Calcular Super Poder
    calcular_super_poder(cidade);
}

// Função para comparar duas cidades
void comparar_cidades(Cidade cidade1, Cidade cidade2) {
    printf("\n--- Comparando Cidades ---\n");

    // Densidade Populacional (vence a menor)
    printf("Densidade Populacional:\n");
    if (cidade1.densidade_Populacional < cidade2.densidade_Populacional) {
        printf("%s vence com densidade populacional menor (%.2f).\n", cidade1.nome, cidade1.densidade_Populacional);
    } else if (cidade1.densidade_Populacional > cidade2.densidade_Populacional) {
        printf("%s vence com densidade populacional menor (%.2f).\n", cidade2.nome, cidade2.densidade_Populacional);
    } else {
        printf("Empate na densidade populacional (%.2f).\n", cidade1.densidade_Populacional);
    }

    // População
    printf("\nPopulação:\n");
    if (cidade1.populacao > cidade2.populacao) {
        printf("%s vence com população maior (%d).\n", cidade1.nome, cidade1.populacao);
    } else if (cidade1.populacao < cidade2.populacao) {
        printf("%s vence com população maior (%d).\n", cidade2.nome, cidade2.populacao);
    } else {
        printf("Empate na população (%d).\n", cidade1.populacao);
    }

    // Área
    printf("\nÁrea:\n");
    if (cidade1.area > cidade2.area) {
        printf("%s vence com área maior (%.2f km²).\n", cidade1.nome, cidade1.area);
    } else if (cidade1.area < cidade2.area) {
        printf("%s vence com área maior (%.2f km²).\n", cidade2.nome, cidade2.area);
    } else {
        printf("Empate na área (%.2f km²).\n", cidade1.area);
    }

    // PIB per capita
    printf("\nPIB per capita:\n");
    if (cidade1.pib_per_capita > cidade2.pib_per_capita) {
        printf("%s vence com maior PIB per capita (%.2f).\n", cidade1.nome, cidade1.pib_per_capita);
    } else if (cidade1.pib_per_capita < cidade2.pib_per_capita) {
        printf("%s vence com maior PIB per capita (%.2f).\n", cidade2.nome, cidade2.pib_per_capita);
    } else {
        printf("Empate no PIB per capita (%.2f).\n", cidade1.pib_per_capita);
    }

    // Pontos Turísticos
    printf("\nPontos Turísticos:\n");
    if (cidade1.ponto_t > cidade2.ponto_t) {
        printf("%s vence com mais pontos turísticos (%d).\n", cidade1.nome, cidade1.ponto_t);
    } else if (cidade1.ponto_t < cidade2.ponto_t) {
        printf("%s vence com mais pontos turísticos (%d).\n", cidade2.nome, cidade2.ponto_t);
    } else {
        printf("Empate no número de pontos turísticos (%d).\n", cidade1.ponto_t);
    }

    // Super Poder
    printf("\nSuper Poder:\n");
    if (cidade1.super_poder > cidade2.super_poder) {
        printf("%s vence com maior Super Poder (%.2f).\n", cidade1.nome, cidade1.super_poder);
    } else if (cidade1.super_poder < cidade2.super_poder) {
        printf("%s vence com maior Super Poder (%.2f).\n", cidade2.nome, cidade2.super_poder);
    } else {
        printf("Empate no Super Poder (%.2f).\n", cidade1.super_poder);
    }
}

int main() {
    Cidade cidade1, cidade2;

    printf("Dados da primeira cidade:\n");
    ler_dados_cidade(&cidade1);

    printf("\nDados da segunda cidade:\n");
    ler_dados_cidade(&cidade2);

    comparar_cidades(cidade1, cidade2);

    return 0;
}
