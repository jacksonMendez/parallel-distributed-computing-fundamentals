/**
 * Exercise 2: Sum of Array Elements Using Pointers
 * 
 * Description:
 *   Calculates the sum of all elements in an integer array using pointer
 *   arithmetic rather than array indexing syntax. Prints the elements and the
 *   final accumulated sum.
 * 
 * Course: Parallel and Distributed Computing Fundamentals
 */

#include <stdio.h>

#define SIZE 8

int main(void) {
    // Sample integer array
    int data[SIZE] = {12, 45, 7, 23, 89, 34, 56, 10};

    // Pointer pointing to the beginning of the array
    int *ptr = data;
    long long total_sum = 0;

    printf("========================================================\n");
    printf("     Exercise 2: Sum of Array Elements Using Pointers   \n");
    printf("========================================================\n");
    printf("Array base address: %p\n", (void *)ptr);
    printf("Number of elements: %d\n\n", SIZE);

    printf("Iterating through array with pointer arithmetic:\n");
    printf("%-7s | %-18s | %-7s | %-12s\n", "Index", "Address", "Value", "Running Sum");
    printf("--------------------------------------------------------\n");

    // Compute sum using pointer arithmetic *(ptr + i)
    for (int i = 0; i < SIZE; i++) {
        int current_val = *(ptr + i);
        total_sum += current_val;

        printf("[%2d]   | %-18p | %-7d | %-12lld\n", 
               i, (void *)(ptr + i), current_val, total_sum);
    }

    printf("--------------------------------------------------------\n");
    printf("Final accumulated sum: %lld\n", total_sum);
    printf("Verification (first + last element via ptr): %d + %d = %d\n",
           *ptr, *(ptr + (SIZE - 1)), *ptr + *(ptr + (SIZE - 1)));
    printf("========================================================\n");

    return 0;
}
