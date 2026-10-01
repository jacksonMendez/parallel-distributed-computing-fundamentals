/**
 * Exercise 1: Accessing Array Elements Using Pointers
 * 
 * Description:
 *   Declares an array of 10 integers initialized with values from 1 to 10.
 *   Iterates through the array and prints each element's value and its memory
 *   address using pointer arithmetic: *(ptr + i).
 * 
 * Course: Parallel and Distributed Computing Fundamentals
 */

#include <stdio.h>

#define ARRAY_SIZE 10

int main(void) {
    // Declare and initialize an array of 10 integers (values 1 to 10)
    int numbers[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Pointer pointing to the base address of the array
    int *ptr = numbers;

    printf("========================================================\n");
    printf("  Exercise 1: Array Traversal with Pointer Arithmetic   \n");
    printf("========================================================\n");
    printf("Base array address: %p\n", (void *)ptr);
    printf("Element size: %zu bytes (sizeof(int))\n\n", sizeof(int));

    printf("%-7s | %-7s | %-18s | %-20s\n", "Index", "Value", "Memory Address", "Dereference Syntax");
    printf("--------------------------------------------------------\n");

    // Traverse the array using pointer arithmetic: *(ptr + i)
    for (int i = 0; i < ARRAY_SIZE; i++) {
        // (ptr + i) advances by i * sizeof(int) bytes
        // *(ptr + i) dereferences the calculated memory address
        printf("[%2d]   | %-7d | %-18p | *(ptr + %d)\n", 
               i, *(ptr + i), (void *)(ptr + i), i);
    }

    printf("--------------------------------------------------------\n");
    printf("Explanation:\n");
    printf("  Pointer arithmetic takes data type size into account.\n");
    printf("  Adding 1 to an (int *) advances the address by 4 bytes.\n");
    printf("========================================================\n");

    return 0;
}
