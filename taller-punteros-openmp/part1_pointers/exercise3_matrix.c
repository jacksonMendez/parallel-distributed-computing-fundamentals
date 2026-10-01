/**
 * Exercise 3: Dynamic 3x3 Matrix with Pointer-to-Pointer
 * 
 * Description:
 *   Allocates a dynamic 3x3 matrix using an int** double pointer.
 *   Populates the cells with values and accesses them strictly via
 *   pointer-to-pointer arithmetic: *(*(matrix + i) + j).
 *   Displays the matrix contents, cell memory addresses, and properly
 *   frees all allocated heap memory.
 * 
 * Course: Parallel and Distributed Computing Fundamentals
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int main(void) {
    printf("========================================================\n");
    printf("  Exercise 3: Dynamic Matrix Using Pointer-to-Pointer   \n");
    printf("========================================================\n");

    // Step 1: Allocate array of row pointers (int*)
    int **matrix = (int **)malloc(ROWS * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for row pointers.\n");
        return 1;
    }

    // Step 2: Allocate memory for each row (array of int)
    for (int i = 0; i < ROWS; i++) {
        *(matrix + i) = (int *)malloc(COLS * sizeof(int));
        if (*(matrix + i) == NULL) {
            fprintf(stderr, "Error: Failed to allocate row %d.\n", i);
            // Free any previously allocated rows before exiting
            for (int k = 0; k < i; k++) {
                free(*(matrix + k));
            }
            free(matrix);
            return 1;
        }
    }

    // Step 3: Populate matrix using pointer arithmetic
    int counter = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(*(matrix + i) + j) = counter++;
        }
    }

    // Step 4: Display row pointer layout in memory
    printf("Row pointer addresses on heap:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("  Row %d pointer address: %p -> points to row start: %p\n",
               i, (void *)(matrix + i), (void *)(*(matrix + i)));
    }
    printf("\n");

    // Step 5: Display matrix values in 2D grid format
    printf("Matrix contents *(*(matrix + i) + j):\n");
    for (int i = 0; i < ROWS; i++) {
        printf("  [ ");
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", *(*(matrix + i) + j));
        }
        printf("]\n");
    }
    printf("\n");

    // Step 6: Detailed breakdown of values and memory addresses per cell
    printf("Detailed element map:\n");
    printf("%-8s | %-7s | %-18s | %-25s\n", "Cell", "Value", "Memory Address", "Pointer Expression");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("[%d][%d]    | %-7d | %-18p | *(*(matrix + %d) + %d)\n",
                   i, j, *(*(matrix + i) + j), 
                   (void *)(*(matrix + i) + j), i, j);
        }
    }
    printf("----------------------------------------------------------------\n");

    // Step 7: Free allocated memory
    for (int i = 0; i < ROWS; i++) {
        free(*(matrix + i));
        *(matrix + i) = NULL;
    }
    free(matrix);
    matrix = NULL;

    printf("Memory cleanup: All rows and row pointers successfully freed.\n");
    printf("========================================================\n");

    return 0;
}
