/**
 * Exercise 5: Character String Traversal Using Pointer Incrementation
 * 
 * Description:
 *   Declares a null-terminated string and traverses it using pointer increment
 *   (ptr++) until encountering the null terminator ('\0').
 *   Prints each character, its ASCII decimal value, and its memory address.
 * 
 * Course: Parallel and Distributed Computing Fundamentals
 */

#include <stdio.h>

int main(void) {
    char text[] = "OpenMP & Pointers";
    const char *ptr = text;
    int index = 0;

    printf("========================================================\n");
    printf("     Exercise 5: String Traversal with Pointer (ptr++)  \n");
    printf("========================================================\n");
    printf("Original string: \"%s\"\n", text);
    printf("String start address: %p\n", (void *)text);
    printf("Character element size: %zu byte (sizeof(char))\n\n", sizeof(char));

    printf("%-7s | %-18s | %-9s | %-10s\n", "Offset", "Memory Address", "Character", "ASCII Code");
    printf("--------------------------------------------------------\n");

    // Traverse string using pointer arithmetic (ptr++) until null terminator '\0'
    while (*ptr != '\0') {
        printf("[%2d]   | %-18p | '%c'       | %-10d\n", 
               index, (void *)ptr, *ptr, (int)(unsigned char)(*ptr));
        ptr++;    // Advance pointer to the next contiguous byte in memory
        index++;
    }

    // Display the null terminator explicitly
    printf("[%2d]   | %-18p | '\\0'      | %-10d (Null terminator)\n", 
           index, (void *)ptr, (int)(unsigned char)(*ptr));

    printf("--------------------------------------------------------\n");
    printf("Total printable characters processed: %d\n", index);
    printf("Total bytes consumed (including '\\0'): %d\n", index + 1);
    printf("========================================================\n");

    return 0;
}
