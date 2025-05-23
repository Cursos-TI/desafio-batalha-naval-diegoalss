#include <stdio.h>

// Desafio Batalha Naval - MateCheck
int main() {
    // Tabuleiro 10x10 inicializado 
    int tabuleiro[10][10] = {0};

    // Navios com tamanho fixo 3
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais
    int linha_h = 2;
    int coluna_h = 4;
    int linha_v = 5;
    int coluna_v = 1;

    // Verificação de limites e posicionamento do navio horizontal
    if (coluna_h + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_h][coluna_h + i] == 3) {
                return 1;
            }
            tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
        }
    } else {
        return 1; 
    }

    // Verificação de limites e posicionamento do navio vertical
    if (linha_v + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_v + i][coluna_v] == 3) {
                return 1; 
            }
            tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
        }
    } else {
        return 1;
    }

    // Exibição do tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
