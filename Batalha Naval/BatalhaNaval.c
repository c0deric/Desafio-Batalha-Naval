#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Inicializa o tabuleiro com agua (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Verifica se o navio pode ser posicionado sem sair do tabuleiro e sem sobreposicao
int podePosicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int tipo) {
    if (linha < 0 || coluna < 0) return 0;
    if (tipo == 0) { // Horizontal
        if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }
    } else { // Vertical
        if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    }
    return 1;
}

// Posiciona o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int tipo) {
    if (tipo == 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    } else {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Imprime o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Solicita ao usuario uma coordenada e valida o posicionamento
void pedirEPosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], char* nomeNavio, int tipo) {
    int linha, coluna;
    int sucesso = 0;

    while (!sucesso) {
        printf("\nDigite as coordenadas para o navio %s (%s - tamanho %d)\n", nomeNavio,
               (tipo == 0 ? "horizontal" : "vertical"), TAM_NAVIO);
        printf("Linha (0 a %d): ", TAM_TABULEIRO - 1);
        scanf("%d", &linha);
        printf("Coluna (0 a %d): ", TAM_TABULEIRO - 1);
        scanf("%d", &coluna);

        if (podePosicionarNavio(tabuleiro, linha, coluna, tipo)) {
            posicionarNavio(tabuleiro, linha, coluna, tipo);
            printf("Navio %s posicionado com sucesso!\n", nomeNavio);
            sucesso = 1;
        } else {
            printf("Posicao invalida! Tente novamente.\n");
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    printf("=== BATALHA NAVAL - POSICIONAMENTO DE NAVIOS ===\n");

    // Primeiro navio: Horizontal
    pedirEPosicionar(tabuleiro, "1 (Horizontal)", 0);

    // Segundo navio: Vertical
    pedirEPosicionar(tabuleiro, "2 (Vertical)", 1);

    // Mostra o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}

