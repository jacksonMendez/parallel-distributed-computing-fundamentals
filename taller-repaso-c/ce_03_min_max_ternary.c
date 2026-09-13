/*
 ============================================================================
 File         : ce_03_min_max_ternary.c
 Author       : Jeison Mendez
 Date         : 2026-09-12
 Description  : Determines the maximum and minimum values among three integers
                using ternary operators and modular functions.
 
 Key Concepts:
   - Ternary operator (condition ? expr1 : expr2)
   - Nested ternary evaluation
   - Return values from functions

 Compilation:
   gcc ce_03_min_max_ternary.c -o ce_03_min_max_ternary
 
 Execution:
   ./ce_03_min_max_ternary
 ============================================================================
*/

#include <stdio.h>

int findMax(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int findMin(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int main() {
    int num1 = 25;
    int num2 = 7;
    int num3 = 48;

    printf("=== Ejercicio 3: Mayor y Menor con Operadores Ternarios ===\n");
    printf("Números ingresados: %d, %d, %d\n", num1, num2, num3);

    int maximum = findMax(num1, num2, num3);
    int minimum = findMin(num1, num2, num3);

    printf("El valor mayor es: %d\n", maximum);
    printf("El valor menor es: %d\n", minimum);

    return 0;
}
