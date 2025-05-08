#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[10];
    char cidade[50];
    float populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

// Cadastrar carta
void cadastrarCarta(struct Carta *carta, int numero) {
    printf("\nCadastro da Carta %d:\n", numero);
    
    printf("Digite o estado: ");
    scanf("%s", carta->estado);
    
    printf("Digite o código da cidade: ");
    scanf("%s", carta->codigo);
    
    printf("Digite o nome da cidade: ");
    scanf("%s", carta->cidade);
    
    printf("Digite a população (em milhares): ");
    scanf("%f", &carta->populacao);
    
    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Exibir os dados de uma carta
void exibirCarta(struct Carta carta) {
    printf("\nDetalhes da Carta:\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %.2f mil habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

// Comparação
void compararCartas(struct Carta carta1, struct Carta carta2, char atributo[20]) {
    printf("\nResultado da Comparação (%s):\n", atributo);
    
    if (strcmp(atributo, "populacao") == 0) {
        if (carta1.populacao > carta2.populacao) {
            printf("%s tem maior população que %s\n", carta1.cidade, carta2.cidade);
        } else if (carta1.populacao < carta2.populacao) {
            printf("%s tem maior população que %s\n", carta2.cidade, carta1.cidade);
        } else {
            printf("As cidades têm a mesma população\n");
        }
    }
    else if (strcmp(atributo, "area") == 0) {
        if (carta1.area > carta2.area) {
            printf("%s tem maior área que %s\n", carta1.cidade, carta2.cidade);
        } else if (carta1.area < carta2.area) {
            printf("%s tem maior área que %s\n", carta2.cidade, carta1.cidade);
        } else {
            printf("As cidades têm a mesma área\n");
        }
    }
    else if (strcmp(atributo, "pib") == 0) {
        if (carta1.pib > carta2.pib) {
            printf("%s tem maior PIB que %s\n", carta1.cidade, carta2.cidade);
        } else if (carta1.pib < carta2.pib) {
            printf("%s tem maior PIB que %s\n", carta2.cidade, carta1.cidade);
        } else {
            printf("As cidades têm o mesmo PIB\n");
        }
    }
    else if (strcmp(atributo, "pontos_turisticos") == 0) {
        if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
            printf("%s tem mais pontos turísticos que %s\n", carta1.cidade, carta2.cidade);
        } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
            printf("%s tem mais pontos turísticos que %s\n", carta2.cidade, carta1.cidade);
        } else {
            printf("As cidades têm o mesmo número de pontos turísticos\n");
        }
    }
    else if (strcmp(atributo, "densidade") == 0) {
        float densidade1 = carta1.populacao / carta1.area;
        float densidade2 = carta2.populacao / carta2.area;
        
        if (densidade1 < densidade2) {
            printf("%s tem menor densidade populacional que %s\n", carta1.cidade, carta2.cidade);
        } else if (densidade1 > densidade2) {
            printf("%s tem menor densidade populacional que %s\n", carta2.cidade, carta1.cidade);
        } else {
            printf("As cidades têm a mesma densidade populacional\n");
        }
    }
    else {
        printf("Atributo inválido para comparação!\n");
    }
}

int main() {
    printf("=== Super Trunfo - Países ===\n");
    printf("Nível Novato - Comparação de Cartas\n\n");
    
    struct Carta carta1, carta2;
    
    // Cadastrar duas cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibir cartas cadastradas
    printf("\nCartas Cadastradas:");
    exibirCarta(carta1);
    exibirCarta(carta2);
    
    // Comparar cartas por diferentes atributos
    compararCartas(carta1, carta2, "populacao");
    compararCartas(carta1, carta2, "area");
    compararCartas(carta1, carta2, "pib");
    compararCartas(carta1, carta2, "pontos_turisticos");
    compararCartas(carta1, carta2, "densidade");
    
    return 0;
}