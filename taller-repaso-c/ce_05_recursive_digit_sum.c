/*
 ============================================================================
 File         : ce_05_recursive_digit_sum.c
 Author       : Jeison Mendez
 Date         : 2026-09-12
 Description  : Implements a recursive function that calculates the sum of all
                digits of a positive integer.
 
 Key Concepts:
   - Recursive function calls & base cases
   - Integer division (/) and modulo (%) arithmetic
   - Call stack execution flow

 Compilation:
   gcc ce_05_recursive_digit_sum.c -o ce_05_recursive_digit_sum
 
 Execution:
   ./ce_05_recursive_digit_sum
 ============================================================================
*/

#include <stdio.h>

int sumDigitsRecursive(int number) {
    if (number < 0) {
        number = -number;
    }
    if (number == 0) {
        return 0;
    }
    return (number % 10) + sumDigitsRecursive(number / 10);
}

int main() {
    int testCases[] = {1234, 98765, 5, 4002};
    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    printf("=== Ejercicio 5: Recursividad con Suma de Dígitos ===\n");

    for (int i = 0; i < numTestCases; i++) {
        int val = testCases[i];
        int sum = sumDigitsRecursive(val);
        printf("Suma de los dígitos de %d = %d\n", val, sum);
    }

    return 0;
}
