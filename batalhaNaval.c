#include <stdio.h>
// Desafio Batalha Naval 
int main() {
    // Tabuleiro 
    int tabuleiro[10][10] = {0};
    
    // Tamanho fixo dos navios
    int tamanho = 3;

    // Coordenadas iniciais dos navios
    int linha_h = 2, coluna_h = 4;       // Horizontal
    int linha_v = 5, coluna_v = 1;       // Vertical
    int linha_d1 = 0, coluna_d1 = 0;     // Diagonal ↘
    int linha_d2 = 2, coluna_d2 = 9;     // Diagonal ↙

    // Posicionamento horizontal
    if (coluna_h + tamanho <= 10) {
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha_h][coluna_h + i] == 3) return 1;
            tabuleiro[linha_h][coluna_h + i] = 3;
        }
    } else {
        return 1;
    }

    // Posicionamento vertical
    if (linha_v + tamanho <= 10) {
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha_v + i][coluna_v] == 3) return 1;
            tabuleiro[linha_v + i][coluna_v] = 3;
        }
    } else {
        return 1;
    }

    // Posicionamento diagonal ↘
    if (linha_d1 + tamanho <= 10 && coluna_d1 + tamanho <= 10) {
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha_d1 + i][coluna_d1 + i] == 3) return 1;
            tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
        }
    } else {
        return 1;
    }

    // Posicionamento diagonal ↙
    if (linha_d2 + tamanho <= 10 && coluna_d2 - (tamanho - 1) >= 0) {
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha_d2 + i][coluna_d2 - i] == 3) return 1;
            tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
        }
    } else {
        return 1;
    }

    // Exibição do tabuleiro 10x10
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
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

 