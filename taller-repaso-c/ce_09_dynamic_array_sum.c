/*
 ============================================================================
 File         : ce_09_dynamic_array_sum.c
 Author       : Jeison Mendez
 Date         : 2026-09-12
 Description  : Dynamically allocates memory for an array of integers, reads or
                populates the array elements, and calculates their total sum.
 
 Key Concepts:
   - Dynamic memory allocation (malloc)
   - Pointer memory check (NULL verification)
   - Proper memory deallocation (free)

 Compilation:
   gcc ce_09_dynamic_array_sum.c -o ce_09_dynamic_array_sum
 
 Execution:
   ./ce_09_dynamic_array_sum
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int calculateSum(const int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int n = 6;
    int initialValues[] = {12, 45, 67, 23, 89, 34};

    printf("=== Ejercicio 9: Memoria Dinámica con Arreglos ===\n");
    printf("Reservando memoria dinámicamente para %d elementos...\n", n);

    int *dynamicArr = (int *)malloc((size_t)n * sizeof(int));

    if (dynamicArr == NULL) {
        fprintf(stderr, "¡Error: Falló la reserva de memoria dinámica!\n");
        return 1;
    }

    printf("Llenando el arreglo dinámico con valores: ");
    for (int i = 0; i < n; i++) {
        dynamicArr[i] = initialValues[i];
        printf("%d ", dynamicArr[i]);
    }
    printf("\n");

    int totalSum = calculateSum(dynamicArr, n);
    printf("Suma total de los elementos: %d\n", totalSum);

    free(dynamicArr);
    dynamicArr = NULL;
    printf("Memoria dinámica liberada exitosamente.\n");

    return 0;
}
