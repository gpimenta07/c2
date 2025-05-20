#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} Carta;

// Função para calcular a densidade demográfica e o PIB per capita
void calcularIndicadores(Carta *carta) {
    carta->densidadeDemografica = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para imprimir os dados de uma carta
void exibirCarta(Carta c) {
    printf("País: %s\n", c.nomePais);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade demográfica: %.2f hab/km²\n", c.densidadeDemografica);
    printf("PIB per capita: %.2f\n", c.pibPerCapita);
    printf("------------------------------\n");
}

int main() {
    // Criação das duas cartas
    Carta carta1 = {"Brasil", 214000000, 8515767.0, 1868000.0, 50};
    Carta carta2 = {"Argentina", 46000000, 2780000.0, 500000.0, 35};

    // Cálculo dos indicadores
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    int opcao;

    printf("=== SUPER TRUNFO - COMPARAÇÃO ENTRE PAÍSES ===\n\n");
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("Carta 2:\n");
    exibirCarta(carta2);

    // Menu de escolha de atributo
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("6 - PIB per capita\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");

    // Comparação com switch
    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1.nomePais, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nomePais, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.populacao > carta1.populacao)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nomePais, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomePais, carta2.area);
            if (carta1.area > carta2.area)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.area > carta1.area)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.nomePais, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.nomePais, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.pib > carta1.pib)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos turísticos\n");
            printf("%s: %d pontos\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("%s: %d pontos\n", carta2.nomePais, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.nomePais, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", carta2.nomePais, carta2.densidadeDemografica);
            // Regra invertida: menor densidade vence
            if (carta1.densidadeDemografica < carta2.densidadeDemografica)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.densidadeDemografica < carta1.densidadeDemografica)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 6:
            printf("Atributo: PIB per capita\n");
            printf("%s: %.2f\n", carta1.nomePais, carta1.pibPerCapita);
            printf("%s: %.2f\n", carta2.nomePais, carta2.pibPerCapita);
            if (carta1.pibPerCapita > carta2.pibPerCapita)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.pibPerCapita > carta1.pibPerCapita)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente com um número de 1 a 6.\n");
            break;
    }

    // Pausa o terminal no Windows
    system("pause");

    return 0;
}
