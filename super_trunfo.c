#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

void imprimirCarta(Carta carta) {
    printf("\n--- %s ---\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidadeDemografica);
}

void exibirMenuAtributos(int atributosEscolhidos[6]) {
    printf("\nEscolha um atributo para comparação:\n");
    if (!atributosEscolhidos[0]) printf("1. População\n");
    if (!atributosEscolhidos[1]) printf("2. Área\n");
    if (!atributosEscolhidos[2]) printf("3. PIB\n");
    if (!atributosEscolhidos[3]) printf("4. Pontos Turísticos\n");
    if (!atributosEscolhidos[4]) printf("5. Densidade Demográfica\n");
    printf("Escolha: ");
}

float obterValorAtributo(Carta carta, int opcao) {
    switch (opcao) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontosTuristicos;
        case 5: return carta.densidadeDemografica;
        default: return -1;
    }
}

int vencedorPorAtributo(float v1, float v2, int atributo) {
    if (atributo == 5) {
        // Menor valor vence para densidade demográfica
        return (v1 < v2) ? 1 : (v2 < v1) ? 2 : 0;
    } else {
        return (v1 > v2) ? 1 : (v2 > v1) ? 2 : 0;
    }
}

void compararCartas(Carta c1, Carta c2) {
    int atributosEscolhidos[6] = {0};
    int atributo1, atributo2;

    // Escolha do primeiro atributo
    do {
        exibirMenuAtributos(atributosEscolhidos);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5 || atributosEscolhidos[atributo1 - 1]) {
            printf("Atributo inválido!\n");
        }
    } while (atributo1 < 1 || atributo1 > 5 || atributosEscolhidos[atributo1 - 1]);
    atributosEscolhidos[atributo1 - 1] = 1;

    // Escolha do segundo atributo
    do {
        exibirMenuAtributos(atributosEscolhidos);
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributosEscolhidos[atributo2 - 1]) {
            printf("Atributo inválido ou já escolhido!\n");
        }
    } while (atributo2 < 1 || atributo2 > 5 || atributosEscolhidos[atributo2 - 1]);

    float valor1_attr1 = obterValorAtributo(c1, atributo1);
    float valor2_attr1 = obterValorAtributo(c2, atributo1);
    float valor1_attr2 = obterValorAtributo(c1, atributo2);
    float valor2_attr2 = obterValorAtributo(c2, atributo2);

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // Resultado da rodada
    int resultadoFinal = (soma1 > soma2) ? 1 : (soma2 > soma1) ? 2 : 0;

    printf("\n================== RESULTADO ==================\n");
    printf("Carta 1: %s | Carta 2: %s\n", c1.nome, c2.nome);

    printf("Atributo 1: %d -> %s: %.2f x %.2f\n", atributo1,
           (atributo1 == 1) ? "População" :
           (atributo1 == 2) ? "Área" :
           (atributo1 == 3) ? "PIB" :
           (atributo1 == 4) ? "Pontos Turísticos" : "Densidade Demográfica",
           valor1_attr1, valor2_attr1);

    printf("Atributo 2: %d -> %s: %.2f x %.2f\n", atributo2,
           (atributo2 == 1) ? "População" :
           (atributo2 == 2) ? "Área" :
           (atributo2 == 3) ? "PIB" :
           (atributo2 == 4) ? "Pontos Turísticos" : "Densidade Demográfica",
           valor1_attr2, valor2_attr2);

    printf("Soma dos atributos:\n%s: %.2f\n%s: %.2f\n", c1.nome, soma1, c2.nome, soma2);

    if (resultadoFinal == 1) {
        printf("Resultado: %s venceu!\n", c1.nome);
    } else if (resultadoFinal == 2) {
        printf("Resultado: %s venceu!\n", c2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }
    printf("===============================================\n");
}

int main() {
    // Cartas pré-definidas
    Carta brasil = {"Brasil", 213000000, 8515767.0, 2200.0, 10, 25.0};
    Carta japao = {"Japão", 126000000, 377975.0, 5000.0, 12, 334.0};

    printf("Bem-vindo ao Super Trunfo dos Países!\n");
    imprimirCarta(brasil);
    imprimirCarta(japao);

    compararCartas(brasil, japao);

    return 0;
}
