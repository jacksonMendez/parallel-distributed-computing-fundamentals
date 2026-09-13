/*
 ============================================================================
 File         : ce_04_factorial_parity.c
 Author       : Jeison Mendez
 Date         : 2026-09-12
 Description  : Calculates the factorial of a positive integer using loops
                and checks whether the resulting factorial is even or odd.
 
 Key Concepts:
   - For and While iteration loops
   - Modulo operator (%) for parity check
   - Handling integer results with unsigned long long

 Compilation:
   gcc ce_04_factorial_parity.c -o ce_04_factorial_parity
 
 Execution:
   ./ce_04_factorial_parity
 ============================================================================
*/

#include <stdio.h>
#include <stdbool.h>

unsigned long long calculateFactorial(int n) {
    if (n < 0) {
        return 0;
    }
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

bool isEven(unsigned long long n) {
    return (n % 2 == 0);
}

int main() {
    int testNumbers[] = {0, 1, 4, 5, 7};
    int totalTests = sizeof(testNumbers) / sizeof(testNumbers[0]);

    printf("=== Ejercicio 4: Factorial y Paridad ===\n");

    for (int i = 0; i < totalTests; i++) {
        int n = testNumbers[i];
        unsigned long long fact = calculateFactorial(n);
        bool even = isEven(fact);

        printf("Factorial de %d! = %llu -> Paridad: %s\n", 
               n, fact, even ? "PAR" : "IMPAR");
    }

    return 0;
}
