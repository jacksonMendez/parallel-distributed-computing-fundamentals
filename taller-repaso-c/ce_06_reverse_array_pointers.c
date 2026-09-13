/*
 ============================================================================
 File         : ce_06_reverse_array_pointers.c
 Author       : Jeison Mendez
 Date         : 2026-09-12
 Description  : Reverses the elements of an integer array in place using pointer
                arithmetic instead of array indexing.
 
 Key Concepts:
   - Pointer arithmetic (ptr++, ptr--)
   - In-place array modification
   - Two-pointer approach (start pointer and end pointer)

 Compilation:
   gcc ce_06_reverse_array_pointers.c -o ce_06_reverse_array_pointers
 
 Execution:
   ./ce_06_reverse_array_pointers
 ============================================================================
*/

#include <stdio.h>

void reverseArrayWithPointers(int *arr, int size) {
    if (arr == NULL || size <= 1) {
        return;
    }

    int *ptrStart = arr;
    int *ptrEnd = arr + size - 1;

    while (ptrStart < ptrEnd) {
        int temp = *ptrStart;
        *ptrStart = *ptrEnd;
        *ptrEnd = temp;

        ptrStart++;
        ptrEnd--;
    }
}

void printArray(const int *arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("]\n");
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("=== Ejercicio 6: Invertir un Arreglo con Punteros ===\n");
    printf("Arreglo original : ");
    printArray(numbers, size);

    reverseArrayWithPointers(numbers, size);

    printf("Arreglo invertido: ");
    printArray(numbers, size);

    return 0;
}
