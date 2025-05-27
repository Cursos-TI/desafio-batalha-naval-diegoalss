#include <stdio.h>
//jogo batalha naval


// Função que retorna o valor absoluto (substitui abs)
int modulo(int x) {
    return x < 0 ? -x : x;
}

// Aplica a matriz de habilidade ao tabuleiro em uma origem específica
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[5][5], int origem_linha, int origem_coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origem_linha - 2 + i;
                int coluna = origem_coluna - 2 + j;
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    if (tabuleiro[linha][coluna] != 3) {
                        tabuleiro[linha][coluna] = 5; // Marca como área afetada
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[10][10] = {0};
    int tamanho = 3;

    // Posições fixas dos navios
    int linha_h = 2, coluna_h = 4;
    int linha_v = 5, coluna_v = 1;
    int linha_d1 = 0, coluna_d1 = 0;
    int linha_d2 = 2, coluna_d2 = 9;

    if (coluna_h + tamanho <= 10)
        for (int i = 0; i < tamanho; i++) tabuleiro[linha_h][coluna_h + i] = 3;

    if (linha_v + tamanho <= 10)
        for (int i = 0; i < tamanho; i++) tabuleiro[linha_v + i][coluna_v] = 3;

    if (linha_d1 + tamanho <= 10 && coluna_d1 + tamanho <= 10)
        for (int i = 0; i < tamanho; i++) tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;

    if (linha_d2 + tamanho <= 10 && coluna_d2 - (tamanho - 1) >= 0)
        for (int i = 0; i < tamanho; i++) tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;

    // Matrizes de habilidades (5x5)
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Cone (forma triangular com base para baixo)
    for (int i = 0; i < 5; i++)
        for (int j = 2 - i; j <= 2 + i; j++)
            if (j >= 0 && j < 5)
                cone[i][j] = 1;

    // Cruz (horizontal e vertical com centro)
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1;
        cruz[i][2] = 1;
    }

    // Octaedro (forma de losango)
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (modulo(2 - i) + modulo(2 - j) <= 2)
                octaedro[i][j] = 1;

    // Aplica habilidades em posições distintas
    aplicarHabilidade(tabuleiro, cone, 1, 2);       // Cone no topo esquerdo
    aplicarHabilidade(tabuleiro, cruz, 7, 2);       // Cruz em baixo à esquerda
    aplicarHabilidade(tabuleiro, octaedro, 6, 7);   // Octaedro no canto direito

    // Exibe tabuleiro com legenda
    printf("Legenda: 0=Água  3=Navio  5=Habilidade\n\n");
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

 