#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CARTAS 32
// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio
    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.
    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }
    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.
    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

typedef struct {
    char estado;
    int codigo;
    char nome_cidade[50];
    long long populacao;
    double area;
    long long pib;
    int pontos_turisticos;
    double densidade;
    double pib_per_capita;
} Carta;

void calcular_metricas(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = (double)c->pib / c->populacao;
}

void cadastrar_carta(Carta *c) {
    printf("\n--- Cadastro de Nova Carta ---\n");
    
    // Estado (A-H)
    do {
        printf("Estado (A-H): ");
        scanf(" %c", &c->estado);
        c->estado = toupper(c->estado);
    } while(c->estado < 'A' || c->estado > 'H');
    
    // Código (1-4)
    do {
        printf("Código da cidade (1-4): ");
        scanf("%d", &c->codigo);
    } while(c->codigo < 1 || c->codigo > 4);
    
    // Nome da cidade
    printf("Nome da cidade: ");
    scanf(" %[^\n]", c->nome_cidade);
    
    // Dados numéricos
    printf("População: ");
    scanf("%lld", &c->populacao);
    
    printf("Área (km²): ");
    scanf("%lf", &c->area);
    
    printf("PIB: ");
    scanf("%lld", &c->pib);
    
    printf("Pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);
    
    // Calcular métricas derivadas
    calcular_metricas(c);
}

void exibir_carta(Carta c) {
    printf("\n--- Carta %c%02d ---\n", c.estado, c.codigo);
    printf("Cidade: %s\n", c.nome_cidade);
    printf("População: %lld hab\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %lld\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade: %.2f hab/km²\n", c.densidade);
    printf("PIB per capita: %.2f\n", c.pib_per_capita);
}

void comparar_atributo(Carta c1, Carta c2, int atributo, char *nome_atributo, int menor_vence) {
    printf("\nComparando %s:\n", nome_atributo);
    
    double valor1, valor2;
    
    switch(atributo) {
        case 1: valor1 = c1.populacao; valor2 = c2.populacao; break;
        case 2: valor1 = c1.area; valor2 = c2.area; break;
        case 3: valor1 = c1.pib; valor2 = c2.pib; break;
        case 4: valor1 = c1.pontos_turisticos; valor2 = c2.pontos_turisticos; break;
        case 5: valor1 = c1.densidade; valor2 = c2.densidade; break;
        case 6: valor1 = c1.pib_per_capita; valor2 = c2.pib_per_capita; break;
    }
    
    if ((menor_vence && valor1 < valor2) || (!menor_vence && valor1 > valor2)) {
        printf("%s (%c%02d) vence com %.2f\n", c1.nome_cidade, c1.estado, c1.codigo, valor1);
    } else if ((menor_vence && valor2 < valor1) || (!menor_vence && valor2 > valor1)) {
        printf("%s (%c%02d) vence com %.2f\n", c2.nome_cidade, c2.estado, c2.codigo, valor2);
    } else {
        printf("Empate em %.2f\n", valor1);
    }
}

void menu_comparacao() {
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1. População (maior vence)\n");
    printf("2. Área (maior vence)\n");
    printf("3. PIB (maior vence)\n");
    printf("4. Pontos Turísticos (maior vence)\n");
    printf("5. Densidade Populacional (menor vence)\n");
    printf("6. PIB per capita (maior vence)\n");
    printf("7. Comparar dois atributos\n");
    printf("0. Sair\n");
}

int main() {
    Carta cartas[MAX_CARTAS];
    int num_cartas = 0;
    int opcao;
    
    printf("=== SUPER TRUNFO - PAÍSES ===\n");
    
    // Cadastro inicial de 2 cartas para teste
    printf("\nCadastre a primeira carta:");
    cadastrar_carta(&cartas[num_cartas++]);
    
    printf("\nCadastre a segunda carta:");
    cadastrar_carta(&cartas[num_cartas++]);
    
    do {
        // Exibir cartas disponíveis
        printf("\nCartas cadastradas:\n");
        for (int i = 0; i < num_cartas; i++) {
            printf("%d. %c%02d - %s\n", i+1, cartas[i].estado, cartas[i].codigo, cartas[i].nome_cidade);
        }
        
        // Selecionar cartas para comparar
        int carta1_idx, carta2_idx;
        printf("\nSelecione duas cartas para comparar (1-%d): ", num_cartas);
        scanf("%d %d", &carta1_idx, &carta2_idx);
        
        if (carta1_idx < 1 || carta1_idx > num_cartas || carta2_idx < 1 || carta2_idx > num_cartas) {
            printf("Seleção inválida!\n");
            continue;
        }
        
        Carta c1 = cartas[carta1_idx-1];
        Carta c2 = cartas[carta2_idx-1];
        
        // Menu de comparação
        int atributo1, atributo2;
        do {
            menu_comparacao();
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);
            
            switch(opcao) {
                case 1: case 2: case 3: case 4: case 6:
                    comparar_atributo(c1, c2, opcao, 
                        opcao == 1 ? "População" : 
                        opcao == 2 ? "Área" : 
                        opcao == 3 ? "PIB" : 
                        opcao == 4 ? "Pontos Turísticos" : "PIB per capita", 0);
                    break;
                case 5:
                    comparar_atributo(c1, c2, opcao, "Densidade Populacional", 1);
                    break;
                case 7:
                    printf("Escolha o primeiro atributo (1-6): ");
                    scanf("%d", &atributo1);
                    printf("Escolha o segundo atributo (1-6): ");
                    scanf("%d", &atributo2);
                    
                    if (atributo1 >= 1 && atributo1 <= 6 && atributo2 >= 1 && atributo2 <= 6) {
                        comparar_atributo(c1, c2, atributo1, 
                            atributo1 == 1 ? "População" : 
                            atributo1 == 2 ? "Área" : 
                            atributo1 == 3 ? "PIB" : 
                            atributo1 == 4 ? "Pontos Turísticos" : 
                            atributo1 == 5 ? "Densidade Populacional" : "PIB per capita", 
                            atributo1 == 5);
                        
                        comparar_atributo(c1, c2, atributo2, 
                            atributo2 == 1 ? "População" : 
                            atributo2 == 2 ? "Área" : 
                            atributo2 == 3 ? "PIB" : 
                            atributo2 == 4 ? "Pontos Turísticos" : 
                            atributo2 == 5 ? "Densidade Populacional" : "PIB per capita", 
                            atributo2 == 5);
                    } else {
                        printf("Atributos inválidos!\n");
                    }
                    break;
                case 0:
                    printf("Retornando ao menu principal...\n");
                    break;
                default:
                    printf("Opção inválida!\n");
            }
        } while(opcao != 0);
        
    } while(1);
    
    return 0;
}
