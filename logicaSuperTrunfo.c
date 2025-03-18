#include <stdio.h>

void compararAtributo(const char* atributo, const char* cidade1, const char* estado1, unsigned long pop1, const char* cidade2, const char* estado2, unsigned long pop2, int* pontos1, int* pontos2) {
    printf("\n");
    printf("Comparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s): %lu\n", cidade1, estado1, pop1);
    printf("Carta 2 - %s (%s): %lu\n", cidade2, estado2, pop2);
    printf("\n");

    // Comparando População, Área, PIB ou PIB per Capita
    if (pop1 > pop2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        (*pontos1)++;
    } else if (pop1 < pop2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        (*pontos2)++;
    } else {
        printf("Resultado: Empate!\n");
    }
    printf("\n");
}

int main() {
    // Exibe o título do jogo
    printf("Desafio Super Trunfo - Países 2\n\n");

    // Coleta os dados para as cartas
    char Estado1[41], CodigoCarta1[21], NomeCidade1[31];
    unsigned long Populacao1;
    int PontosTuristicos1;
    float Area1, PIB1, DensidadePopulacional1;

    printf("Carta 1\n");
    printf("Digite o Estado: ");
    scanf(" %[^\n]", Estado1);

    printf("Digite o Codigo da carta: ");
    scanf("%s", CodigoCarta1);
    while (getchar() != '\n');  // Limpa o buffer do teclado

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", NomeCidade1);

    printf("Digite o numero da Populacao: ");
    scanf("%lu", &Populacao1);

    printf("Digite a Area Km²: ");
    scanf("%f", &Area1);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &PIB1);

    printf("Digite número de Pontos Turisticos: ");
    scanf("%d", &PontosTuristicos1);

    // Cálculos para Densidade Populacional da primeira carta
    DensidadePopulacional1 = (Area1 > 0) ? (Populacao1 / Area1) : 0;

    // Declaração das variáveis para a segunda carta
    char Estado2[41], CodigoCarta2[21], NomeCidade2[31];
    unsigned long Populacao2;
    int PontosTuristicos2;
    float Area2, PIB2, DensidadePopulacional2;

    printf("\nCarta 2\n");
    printf("Digite o Estado: ");
    scanf(" %[^\n]", Estado2);

    printf("Digite o Codigo da carta: ");
    scanf("%s", CodigoCarta2);
    while (getchar() != '\n');  // Limpa o buffer do teclado

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", NomeCidade2);

    printf("Digite o numero da Populacao: ");
    scanf("%lu", &Populacao2);

    printf("Digite a area em km²: ");
    scanf("%f", &Area2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &PIB2);

    printf("Digite número de Pontos Turisticos: ");
    scanf("%d", &PontosTuristicos2);

    // Cálculos para Densidade Populacional da segunda carta
    DensidadePopulacional2 = (Area2 > 0) ? (Populacao2 / Area2) : 0;

    // Menu de escolha de atributos
    int atributo1, atributo2;
    do {
        printf("\nEscolha os dois atributos para comparar:\n");
        printf("\n1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Densidade Populacional\n");
    
        printf("\nEscolha o primeiro atributo (1-4): ");
        scanf("%d", &atributo1);
        printf("Escolha o segundo atributo (1-4): ");
        scanf("%d", &atributo2);
        printf("\n");
    
        // Valida se os atributos são válidos
        if (atributo1 < 1 || atributo1 > 4 || atributo2 < 1 || atributo2 > 4) {
            printf("Erro: Atributo inválido! Escolha valores entre 1 e 4.\n");
        }

        if (atributo1 == atributo2) {
            printf("Erro: Você não pode escolher o mesmo atributo duas vezes! Escolha novamente.\n");
        }

    } while ((atributo1 < 1 || atributo1 > 4 || atributo2 < 1 || atributo2 > 4) || atributo1 == atributo2);  // Continua pedindo os atributos enquanto forem inválidos ou iguais

    // Exibição dos dados coletados
    printf("\n================= EXIBINDO AS SUAS CARTAS =================\n");

    // Dados coletados Carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %s\n", Estado1);
    printf("Codigo da Carta: %s\n", CodigoCarta1);
    printf("Nome da Cidade: %s\n", NomeCidade1);
    printf("Populacao: %lu\n", Populacao1);
    printf("Area da cidade: %.2f km²\n", Area1);
    printf("PIB: %.2f bilhões de reais\n", PIB1);
    printf("Pontos Turisticos: %d\n", PontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", DensidadePopulacional1);
 
    // Dados coletados Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", Estado2);
    printf("Codigo da Carta: %s\n", CodigoCarta2);
    printf("Nome da Cidade: %s\n", NomeCidade2);
    printf("Populacao: %lu\n", Populacao2);
    printf("Area da cidade: %.2f km²\n", Area2);
    printf("PIB: %.2f bilhões de reais\n", PIB2);
    printf("Pontos Turisticos: %d\n", PontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", DensidadePopulacional2);
    
    // Inicializa os pontos
    int pontosCarta1 = 0, pontosCarta2 = 0;

    // Comparação do primeiro atributo
    switch (atributo1) {
        case 1:
            compararAtributo("População", NomeCidade1, Estado1, Populacao1, NomeCidade2, Estado2, Populacao2, &pontosCarta1, &pontosCarta2);
            break;
        case 2:
            compararAtributo("Área", NomeCidade1, Estado1, Area1, NomeCidade2, Estado2, Area2, &pontosCarta1, &pontosCarta2);
            break;
        case 3:
            compararAtributo("PIB", NomeCidade1, Estado1, PIB1, NomeCidade2, Estado2, PIB2, &pontosCarta1, &pontosCarta2);
            break;
        case 4:
            // Comparação especial para Densidade Populacional (menor vence)
            if (DensidadePopulacional1 < DensidadePopulacional2) {
                printf("Resultado: Carta 1 (%s) venceu! Menor Densidade Populacional.\n", NomeCidade1);
                pontosCarta1++;
            } else if (DensidadePopulacional1 > DensidadePopulacional2) {
                printf("Resultado: Carta 2 (%s) venceu! Menor Densidade Populacional.\n", NomeCidade2);
                pontosCarta2++;
            } else {
                printf("Resultado: Empate! Ambas as cidades têm a mesma Densidade Populacional.\n");
            }
            break;
    }

    // Comparação do segundo atributo
    switch (atributo2) {
        case 1:
            compararAtributo("População", NomeCidade1, Estado1, Populacao1, NomeCidade2, Estado2, Populacao2, &pontosCarta1, &pontosCarta2);
            break;
        case 2:
            compararAtributo("Área", NomeCidade1, Estado1, Area1, NomeCidade2, Estado2, Area2, &pontosCarta1, &pontosCarta2);
            break;
        case 3:
            compararAtributo("PIB", NomeCidade1, Estado1, PIB1, NomeCidade2, Estado2, PIB2, &pontosCarta1, &pontosCarta2);
            break;
        case 4:
            // Comparação especial para Densidade Populacional (menor vence)
            if (DensidadePopulacional1 < DensidadePopulacional2) {
                printf("Resultado: Carta 1 (%s) venceu! Menor Densidade Populacional.\n", NomeCidade1);
                pontosCarta1++;
            } else if (DensidadePopulacional1 > DensidadePopulacional2) {
                printf("Resultado: Carta 2 (%s) venceu! Menor Densidade Populacional.\n", NomeCidade2);
                pontosCarta2++;
            } else {
                printf("Resultado: Empate! Ambas as cidades têm a mesma Densidade Populacional.\n");
            }
            break;
    }

    // Resultado final
    printf("\n================= RESULTADO =================\n");
    printf("Pontos Carta 1: %d\n", pontosCarta1);
    printf("Pontos Carta 2: %d\n", pontosCarta2);

    if (pontosCarta1 > pontosCarta2) {
        printf("A Carta 1 venceu!\n");
    } else if (pontosCarta2 > pontosCarta1) {
        printf("A Carta 2 venceu!\n");
    } else {
        printf("Empate entre as cartas!\n");
    }

    return 0;
}
