/**
 * Exercise 4: Swapping Values by Reference Using Pointers
 * 
 * Description:
 *   Implements a swap function: void swap(int *a, int *b).
 *   Interchanges the contents of two integer variables via pass-by-reference
 *   using pointers. Demonstrates behavior before and after the swap.
 * 
 * Course: Parallel and Distributed Computing Fundamentals
 */

#include <stdio.h>

/**
 * Swaps two integers in place using pointers.
 * 
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int *a, int *b) {
    if (a == NULL || b == NULL) {
        return; // Guard against null pointer dereference
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    printf("========================================================\n");
    printf("     Exercise 4: Value Swapping with Pointers           \n");
    printf("========================================================\n");

    // Test case 1: Standard positive integers
    int x = 42;
    int y = 99;

    printf("[Test Case 1] Positive Integers:\n");
    printf("  Before swap:\n");
    printf("    x = %-5d (at address: %p)\n", x, (void *)&x);
    printf("    y = %-5d (at address: %p)\n", y, (void *)&y);

    swap(&x, &y);

    printf("  After swap(&x, &y):\n");
    printf("    x = %-5d (at address: %p)\n", x, (void *)&x);
    printf("    y = %-5d (at address: %p)\n", y, (void *)&y);
    printf("  Verification: %s\n\n", (x == 99 && y == 42) ? "PASSED" : "FAILED");

    // Test case 2: Negative and zero values
    int p = -15;
    int q = 0;

    printf("[Test Case 2] Negative and Zero:\n");
    printf("  Before swap:\n");
    printf("    p = %-5d (at address: %p)\n", p, (void *)&p);
    printf("    q = %-5d (at address: %p)\n", q, (void *)&q);

    swap(&p, &q);

    printf("  After swap(&p, &q):\n");
    printf("    p = %-5d (at address: %p)\n", p, (void *)&p);
    printf("    q = %-5d (at address: %p)\n", q, (void *)&q);
    printf("  Verification: %s\n\n", (p == 0 && q == -15) ? "PASSED" : "FAILED");

    printf("Explanation:\n");
    printf("  In C, arguments are passed by value by default.\n");
    printf("  Passing memory addresses (&x, &y) allows swap() to dereference\n");
    printf("  the pointers and modify the caller's stack frame directly.\n");
    printf("========================================================\n");

    return 0;
}
