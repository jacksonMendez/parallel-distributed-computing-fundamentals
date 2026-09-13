/*
 ============================================================================
 File         : ce_02_pointer_swap.c
 Author       : Jeison Mendez
 Date         : 2026-09-12
 Description  : Swaps the values of two integer variables using pointers to
                demonstrate pass-by-reference vs pass-by-value in C.
 
 Key Concepts:
   - Pointer syntax (*, &)
   - Pass-by-reference mechanism
   - Swapping values in memory

 Compilation:
   gcc ce_02_pointer_swap.c -o ce_02_pointer_swap
 
 Execution:
   ./ce_02_pointer_swap
 ============================================================================
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 42;
    int y = 99;

    printf("=== Ejercicio 2: Intercambio de Valores con Punteros ===\n");
    printf("Antes del intercambio:\n");
    printf("  x = %d (dirección de memoria: %p)\n", x, (void*)&x);
    printf("  y = %d (dirección de memoria: %p)\n", y, (void*)&y);

    swap(&x, &y);

    printf("\nDespués del intercambio:\n");
    printf("  x = %d (dirección de memoria: %p)\n", x, (void*)&x);
    printf("  y = %d (dirección de memoria: %p)\n", y, (void*)&y);

    return 0;
}
