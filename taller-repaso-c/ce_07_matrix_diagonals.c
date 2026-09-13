/*
 ============================================================================
 File         : ce_07_matrix_diagonals.c
 Author       : Jeison Mendez
 Date         : 2026-09-12
 Description  : Generates a square matrix filled with random numbers, computes
                the sums of the main and secondary diagonals, and compares them.
 
 Key Concepts:
   - 2D arrays (matrices)
   - Main diagonal (i == j) and secondary diagonal (j == n - 1 - i)
   - Random matrix generation and formatted output

 Compilation:
   gcc ce_07_matrix_diagonals.c -o ce_07_matrix_diagonals
 
 Execution:
   ./ce_07_matrix_diagonals
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

void fillMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 1 + rand() % 20;
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int sumMainDiagonal(int matrix[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int sumSecondaryDiagonal(int matrix[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += matrix[i][N - 1 - i];
    }
    return sum;
}

int main() {
    srand((unsigned int)time(NULL));

    int matrix[N][N];
    fillMatrix(matrix);

    printf("=== Ejercicio 7: Matriz y Diagonales ===\n");
    printf("Matriz generada (%dx%d):\n", N, N);
    printMatrix(matrix);

    int mainSum = sumMainDiagonal(matrix);
    int secSum = sumSecondaryDiagonal(matrix);

    printf("\nAnálisis de Diagonales:\n");
    printf(" - Suma Diagonal Principal : %d\n", mainSum);
    printf(" - Suma Diagonal Secundaria: %d\n", secSum);

    if (mainSum > secSum) {
        printf(" -> Resultado: La diagonal principal es MAYOR (%d > %d)\n", mainSum, secSum);
    } else if (secSum > mainSum) {
        printf(" -> Resultado: La diagonal secundaria es MAYOR (%d > %d)\n", secSum, mainSum);
    } else {
        printf(" -> Resultado: Ambas diagonales son IGUALES (%d == %d)\n", mainSum, secSum);
    }

    return 0;
}
