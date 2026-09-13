/*
 ============================================================================
 File         : ce_01_prime_numbers_array.c
 Author       : Jeison Mendez
 Date         : 2026-09-12
 Description  : Generates an array of random integers and counts how many
                numbers in the array are prime.
 
 Key Concepts:
   - Global constants (#define)
   - Standard C libraries (<stdio.h>, <stdlib.h>, <stdbool.h>, <time.h>)
   - Function documentation and modularity

 Compilation:
   gcc ce_01_prime_numbers_array.c -o ce_01_prime_numbers_array
 
 Execution:
   ./ce_01_prime_numbers_array
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 12
#define MIN_VAL 1
#define MAX_VAL 50

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void fillRandomArray(int *arr, int size, int minVal, int maxVal) {
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

int countPrimes(const int *arr, int size) {
    int primeCount = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            primeCount++;
        }
    }
    return primeCount;
}

void printArray(const int *arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    srand((unsigned int)time(NULL));

    int numbers[ARRAY_SIZE];
    fillRandomArray(numbers, ARRAY_SIZE, MIN_VAL, MAX_VAL);

    printf("=== Ejercicio 1: Números Primos en un Arreglo ===\n");
    printf("Arreglo generado: ");
    printArray(numbers, ARRAY_SIZE);

    printf("Detalle de números primos:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (isPrime(numbers[i])) {
            printf(" - Posición %d: %d es PRIMO\n", i, numbers[i]);
        }
    }

    int totalPrimes = countPrimes(numbers, ARRAY_SIZE);
    printf("Cantidad total de números primos encontrados: %d\n", totalPrimes);

    return 0;
}
