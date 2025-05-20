#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[30];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular densidade populacional e PIB per capita
void calcularIndicadores(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir os dados da carta
void exibirCarta(struct Carta carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n\n", carta.pibPerCapita);
}

int main() {
    // Declaração das duas cartas
    struct Carta carta1 = {"SP", "SP01", "São Paulo", 12300000, 1521.11, 230000.0, 25};
    struct Carta carta2 = {"RJ", "RJ01", "Rio de Janeiro", 6000000, 1182.30, 120000.0, 18};

    // Calcula os indicadores de cada carta
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibe as cartas
    printf("Carta 1:\n");
    exibirCarta(carta1);
    
    printf("Carta 2:\n");
    exibirCarta(carta2);

    // ======= COMPARAÇÃO: escolha aqui o atributo =======
    // Vamos comparar a POPULAÇÃO (maior vence)
    printf("Comparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    // Estrutura de decisão para comparação
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
